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

#undef NDEBUG
#include <assert.h>


#include "_BDATA.cpp"




//==============================================================================
// standard IDB list classes
//

_IDB_ENTRY::_IDB_ENTRY()
{
}

_IDB_ENTRY::~_IDB_ENTRY()
{
}

_IDB_LIST::_IDB_LIST()
{
	entry_list	= NULL;
	entry_max	= 0;
	entry_num	= 0;
}

_IDB_LIST::~_IDB_LIST()
{
	if( entry_list != NULL )
		delete [] entry_list;

	entry_list = NULL;
}

long _IDB_LIST::count()
{
	return entry_num;
}

void _IDB_LIST::clean()
{
	while( count() )
		delete del_entry( 0 );
}

bool _IDB_LIST::grow()
{
	// allocate a new stack of pointers that will
	// be larger that the last by GROW_SIZE

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	IDB_ENTRY ** new_entry_list = new IDB_ENTRY * [ entry_max + GROW_SIZE ];

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	if( new_entry_list == NULL )
		return false;

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	// initialize our new stack of pointers to null and

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	memset(
		new_entry_list,
		0,
		( entry_max + GROW_SIZE ) * sizeof( IDB_ENTRY * ) );

	// copy our old pointer stack to our new pointer stack 

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	memcpy(
		new_entry_list,
		entry_list,
		entry_max * sizeof( IDB_ENTRY * ) );

	// free our old pointer stack

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	if( entry_list != NULL )
		delete [] entry_list;
	entry_list=NULL;

//    fprintf(stderr,"\n%s:%d",__FILE__,__LINE__);

	//replace it with our new larger pointer stack

	entry_list = new_entry_list;

	// store our new item_capacity

	entry_max += GROW_SIZE;

	return true;
}

bool _IDB_LIST::add_entry( IDB_ENTRY * entry )
{
	// sanity check for valid pointer

	if( entry == NULL )
		return false;

	// make sure we have enough room in our stack,
	// grow if neccesary

	if( entry_num == entry_max )
		if( !grow() )
			return false;

	// store our new string in the next available
	// slot in the stack

	entry_list[ entry_num ] = entry;

	// increment our list count

	entry_num++;

	return true;
}

bool _IDB_LIST::del_entry( IDB_ENTRY * entry )
{
	// sanity check for valid pointer

	if( entry == NULL )
		return false;

	// attempt to match our item to an item
	// in our stack

	long index = 0;
	while( 1 )
	{
		// check for a match
		
		if( entry_list[ index ] == entry )
			break;
	
		// if we have exausted all pointers in our
		// stack then return false
		
		if( index == ( entry_num - 1 ) )
			return false;
			
		index++;		
	}
		
	// copy the trailing pointers in our list
	// to fill the empty slot
	
	int trailing_pointers = entry_num - index - 1;
	if( trailing_pointers )
		memmove(
			&entry_list[ index ],
			&entry_list[ index + 1 ],
			trailing_pointers * sizeof( IDB_ENTRY * ) );
		
	// null previously last used pointer in
	// list and decrement count
	
	entry_list[ entry_num - 1 ] = 0;
	entry_num--;
	
	return true;
}

IDB_ENTRY * _IDB_LIST::del_entry( int index )
{
	// sanity check for valid index
	
	if( ( index >= entry_num ) ||
		( index < 0 ) )
		return NULL;

	// store the item for return

	IDB_ENTRY * entry = entry_list[ index ];

	// copy the trailing pointers in our list
	// to fill the empty slot
	
	int trailing_pointers = entry_num - index - 1;
	if( trailing_pointers )
		memmove(
			&entry_list[ index ],
			&entry_list[ index + 1 ],
			trailing_pointers * sizeof( IDB_ENTRY * ) );
		
	// null previously last used pointer in
	// list and decrement count
	
	entry_list[ entry_num - 1 ] = 0;
	entry_num--;

	return entry;
}

IDB_ENTRY * _IDB_LIST::get_entry( int index )
{
	// sanity check for valid index
	
	if( ( index >= entry_num ) ||
		( index < 0 ) )
		return NULL;

	// return the requested item

	return entry_list[ index ];
}

