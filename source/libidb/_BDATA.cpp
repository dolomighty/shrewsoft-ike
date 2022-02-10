/*
 * Copyright (c) 2007
 *      Shrew Soft Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Redistributions in any form must be accompanied by information on
 *    how to obtain complete source code for the software and any
 *    accompanying software that uses the software.  The source code
 *    must either be included in the distribution or be available for no
 *    more than the cost of distribution plus a nominal fee, and must be
 *    freely redistributable under reasonable conditions.  For an
 *    executable file, complete source code means the source code for all
 *    modules it contains.  It does not include source code for modules or
 *    files that typically accompany the major components of the operating
 *    system on which the executable file runs.
 *
 * THIS SOFTWARE IS PROVIDED BY SHREW SOFT INC ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT, ARE DISCLAIMED.  IN NO EVENT SHALL SHREW SOFT INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 * AUTHOR : Matthew Grooms
 *          mgrooms@shrew.net
 *
 */

#include "libidb.h"
#include "base64.h"
#include <ctype.h>

#undef NDEBUG
#include <assert.h>



//==============================================================================
// basic data class




_BDATA & _BDATA::operator =( _BDATA & bdata )
{
	del();
	set( bdata );
	return *this;
}



bool _BDATA::operator ==( _BDATA & bdata )
{
	if( bdata.size() != size() )
		return false;
	return ( memcmp( bdata.buff(), buff(), size() ) == 0 );
}



bool _BDATA::operator !=( _BDATA & bdata )
{
	return !( *this == bdata );
}



_BDATA::_BDATA()
{
//	printf("\nconstr");
	data_buff = NULL;
	data_real = 0;
	data_size = 0;
	data_oset = 0;
}



_BDATA::_BDATA( _BDATA & bdata )
{
	_BDATA();
	*this = bdata;
}



_BDATA::~_BDATA()
{
//	printf("\ndestr");
	del( true );
}



size_t _BDATA::grow( size_t new_real )
{
	if( new_real >= 1024*1024 ) return data_real;
	if( new_real <= data_real ) return data_real;

	assert(new_real > data_real);

	unsigned char * new_buff = new unsigned char[ new_real ];
	assert(new_buff);

	if( data_buff )
	{
		memcpy( new_buff, data_buff, data_real );
		assert(data_buff);
		delete [] data_buff;
	}

	data_buff = new_buff;
	data_real = new_real;

	return data_real;
}



size_t _BDATA::size()
{
	if( data_oset > data_size )
		data_oset = data_size;
	return data_size;
}


size_t _BDATA::size( size_t new_size )
{
	if( grow( new_size ) < new_size )
		return data_size;
	data_size = new_size;
	return size();
}




size_t _BDATA::oset( size_t new_oset )
{
	if( data_size >= new_oset )
		data_oset = new_oset;
	return data_oset;
}


size_t _BDATA::oset()
{
	return data_oset;
}









char * _BDATA::text()
{
	return ( char * ) data_buff;
}



unsigned char * _BDATA::buff()
{
	return data_buff;
}



//bool _BDATA::hex_encode( bool upper_case )
//{
//	BDATA	hex_temp;
//	size_t	hex_oset = 0;
//
//	while( hex_oset < data_size )
//	{
//		uint8_t temp1 = data_buff[ hex_oset++ ];
//		uint8_t temp2 = temp1 >> 4;
//		uint8_t temp3 = temp1 & 0xf;
//
//		if( temp2 <= 9 )
//			temp2 += 48;
//		else
//		{
//			if( upper_case )
//				temp2 += 55;
//			else
//				temp2 += 87;
//		}
//
//		hex_temp.add( temp2, 1 );
//
//		if( temp3 <= 9 )
//			temp3 += 48;
//		else
//		{
//			if( upper_case )
//				temp3 += 55;
//			else
//				temp3 += 87;
//		}
//
//		hex_temp.add( temp3, 1 );
//	}
//
//	*this = hex_temp;
//
//	return true;
//}



bool _BDATA::hex_decode()
{
	BDATA	hex_temp;
	size_t	hex_oset = 0;

	if( size() & 1 )
		return false;

	while( hex_oset < data_size )
	{
		uint8_t temp1 = data_buff[ hex_oset++ ];
		uint8_t temp2 = data_buff[ hex_oset++ ];

		if( ( temp1 >= 48 ) && ( temp1 <= 57 ) )
			temp1 -= 48;
		if( ( temp1 >= 65 ) && ( temp1 <= 70 ) )
			temp1 -= 55;
		if( ( temp1 >= 97 ) && ( temp1 <= 102 ) )
			temp1 -= 87;

		if( ( temp2 >= 48 ) && ( temp2 <= 57 ) )
			temp2 -= 48;
		if( ( temp2 >= 65 ) && ( temp2 <= 70 ) )
			temp2 -= 55;
		if( ( temp2 >= 97 ) && ( temp2 <= 102 ) )
			temp2 -= 87;

		int temp3 = ( temp1 << 4 ) | temp2;

		hex_temp.add( temp3, 1 );
	}

	hex_temp.size( data_size >> 1 );

	*this = hex_temp;

	return true;
}



bool _BDATA::base64_encode()
{
	BDATA	b64_temp;
	size_t	b64_size;

	if( !b64_temp.size( size() * 2 + 2 ) )
		return false;

	b64_size = b64_ntop(
					buff(),
					( long ) size(),
					b64_temp.text(),
					( long ) b64_temp.size() );

	if( b64_size == -1 )
		return false;

	b64_temp.size( b64_size + 1 );
	b64_temp.buff()[ b64_size ] = 0;

	*this = b64_temp;

	return true;
}



bool _BDATA::base64_decode()
{
	BDATA	b64_temp;
	size_t	b64_size;

	if( !b64_temp.size( size() ) )
		return false;

	b64_size = b64_pton(
					text(),
					b64_temp.buff(),
					( long ) b64_temp.size() );

	if( b64_size == -1 )
		return false;

	b64_temp.size( b64_size );

	*this = b64_temp;

	return true;
}



bool _BDATA::set( _BDATA & bdata, size_t oset )
{
	// sovrascrive
	return set( ( char * ) bdata.buff(), bdata.size(), oset );
}



bool _BDATA::set( int value, size_t size, size_t oset )
{
	// sovrascrive
	if( !set( ( void * ) NULL, size ) )
		return false;

	memset( data_buff + oset, value, size );

	print();
	return true;
}



bool _BDATA::set( void * buff, size_t size, size_t oset )
{
	// sovrascrive
	size_t new_size = oset + size;

	if( grow( new_size ) < new_size )
		return false;

	if( buff != NULL ){
		assert(data_buff);
		memcpy( data_buff + oset, buff, size );
	}

	if( data_size < new_size )
		data_size = new_size;

	print();
	return true;
}



bool _BDATA::set( char * buff, size_t size, size_t oset )
{
	return set( ( void * ) buff, size, oset );
}



bool _BDATA::set( const char * buff, size_t size, size_t oset )
{
	return set( ( void * ) buff, size, oset );
}



bool _BDATA::ins( _BDATA & bdata, size_t oset )
{
//    fprintf(stderr,"\n%s:%d &bdata %lx oset %ld"
//        ,__FILE__
//        ,__LINE__
//        , (long int)&bdata
//        , oset
//    );

	return ins( bdata.buff(), bdata.size(),	oset );
}



bool _BDATA::ins( int value, size_t size, size_t oset )
{
//	fprintf(stderr,"%d ",__LINE__);
//	fprintf(stderr,"value %ld size %ld",value,size);

	// con null fa solo spazio
	if( !ins( ( void * ) NULL, size, oset ) )
		return false;

	assert( data_buff );
	assert( oset >= 0 );
	assert( size >= 1 );

	// riempie lo spazio 
	memset( data_buff + oset, value, size );

	print();
	return true;
}



bool _BDATA::ins( void * buff, size_t size, size_t oset )
{
	// insert reale
	// sposta i bytes a destra di oset
	// in caso, copia buff nello spazio liberato

//	fprintf(stderr,"%d ",__LINE__);
//	char *c = (char*)buff;
//	for( int i=0; i<size; i++, c++ ){
//		fprintf(stderr,"%c",*c);
//	}

	size_t new_size = data_size + size;

	if( new_size < ( oset + size ))
		new_size = ( oset + size );

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	if( grow( new_size ) < new_size )
		return false;

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	if( oset < data_size )
		memmove(
			data_buff + oset + size,
			data_buff + oset,
			data_size - oset );

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	if( buff )
		memcpy(	data_buff + oset, buff, size );

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	if( data_size < new_size )
		data_size = new_size;

	print();
	return true;
}



bool _BDATA::ins( char * buff, size_t size, size_t oset )
{
	// insert reale
//	char *c = buff;
//	for( int i=0; i<size; i++, c++ ){
//		fprintf(stderr,"%c",*c);
//	}
	return ins( ( void * ) buff, size, oset );
}



bool _BDATA::ins( const char * buff, size_t size, size_t oset )
{
	// insert reale
//	char *c = (char*)buff;
//	for( int i=0; i<size; i++, c++ ){
//		fprintf(stderr,"%c",*c);
//	}
	return ins( ( void * ) buff, size, oset );
}



bool _BDATA::add( _BDATA & bdata )
{
	// appende
	return add( bdata.buff(), bdata.size());
}



bool _BDATA::add( int value, size_t size )
{
	// OKKIO, NON APPENDE
	// sovrascrive gli ultimi size bytes 

	if( !add( ( void * ) NULL, size ) )
		return false;

	memset( data_buff + data_size - size, value, size );

	return true;
}



bool _BDATA::add( void * buff, size_t size )
{
	// appende
	size_t new_size = data_size + size;

	if( grow( new_size ) < new_size )
		return false;

	if( buff )
		memcpy( data_buff + data_size, buff, size );

	data_size = new_size;

	return true;
}



bool _BDATA::add( char * buff, size_t size )
{
	// appende
	return add( ( void * ) buff, size );
}



bool _BDATA::add( const char * buff, size_t size )
{
	// appende
	return add( ( void * ) buff, size );
}



bool _BDATA::get( _BDATA & bdata, size_t size )
{
	size_t left = data_size - data_oset;

	if( size == BDATA_ALL )
		size = left;

	if( size > left )
		return false;

	bdata.size( size );

	return get( bdata.buff(), bdata.size());
}



bool _BDATA::get( char * buff, size_t size )
{
	// fa quello che dice
	return get( ( void * ) buff, size );
}



bool _BDATA::get( void * buff, size_t size )
{
	// fa quello che dice
	if( size > ( data_size - data_oset ) )
		return false;

	// copy the user requested data

	if( buff )
		memcpy( buff, data_buff + data_oset, size );

	// set our new offset

	data_oset += size;

	return true;
}


void _BDATA::del( bool null )
{
	if( data_buff )
	{
		memset( data_buff, 0, data_real );
		delete [] data_buff;
	}

	data_buff = NULL;
	data_real = 0;
	data_size = 0;
	data_oset = 0;
}










bool _BDATA::file_load( FILE * fp )
{
	if( fp == NULL )
		return false;

	del();

	while( true )
	{
		int next = fgetc( fp );
		if( next == EOF )
			break;

		add( next, 1 );
	}

	return ( data_size > 0 );
}

bool _BDATA::file_load( const char * path )
{

#ifdef WIN32

	FILE * fp;
	if( fopen_s( &fp, path, "rb" ) )
		return false;

#else

	FILE * fp = fopen( path, "r" );
	if( fp == NULL )
		return false;

#endif

	bool result = file_load( fp );

	fclose( fp );

	return result;
}






//bool _BDATA::file_save( FILE * fp )
//{
//	if( fp == NULL )
//		return false;
//
//	size_t count = data_size;
//	size_t index = 0;
//
//	for( ; index < count; index++ )
//		fputc( data_buff[ index ], fp );
//
//	return true;
//}
//
//bool _BDATA::file_save( const char * path )
//{
//
//#ifdef WIN32
//
//	FILE * fp;
//	if( fopen_s( &fp, path, "wb" ) )
//		return false;
//
//#else
//
//	FILE * fp = fopen( path, "w" );
//	if( fp == NULL )
//		return false;
//
//#endif
//
//	bool result = file_save( fp );
//
//	fclose( fp );
//
//	return result;
//}



void _BDATA::print()
{
//	printf("data_size %ld [",data_size);
//	unsigned char *c = data_buff;
//	for( int i=0; i<data_size; i++, c++ ){
//		if(*c<' '  ){ printf("%%%02X",*c); continue; }
//		if(*c>=0x80){ printf("%%%02X",*c); continue; }
//		printf("%c",*c);
//	}
//	printf("]\n");
}



//int main(){
//	BDATA b;
////	b.ins("",0);	
////	b.ins("123",3);
////	b.ins("456",3,10);
////	b.ins("789",3,5);
//	b.add("abc",3);
//	b.print();
//	return 0;
//}





/*



c++ -I.. -o main _BDATA.cpp base64.cpp && ./main



*/

