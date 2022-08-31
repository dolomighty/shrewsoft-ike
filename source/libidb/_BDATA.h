
#define BDATA_ALL		~0

typedef class DLX _BDATA
{
	protected:

	unsigned char *	data_buff;
	size_t			data_real;
	size_t			data_size;
	size_t			data_oset;

	size_t			grow( size_t new_size = ~0 );

	public:

	_BDATA &		operator =( _BDATA & bdata );
	bool			operator ==( _BDATA & bdata );
	bool			operator !=( _BDATA & bdata );

	_BDATA();
	_BDATA( _BDATA & bdata );
	virtual ~_BDATA();

	size_t			oset();
	size_t			oset( size_t new_oset );
	size_t			size();
	size_t			size( size_t new_size );

	char *			text();
	unsigned char *	buff();

	bool	hex_encode( bool upper_case = false );
	bool	hex_decode();

	bool	base64_encode();
	bool	base64_decode();

	bool set( _BDATA & bdata, size_t oset = 0 );
	bool set( int value, size_t size, size_t oset = 0 );
	bool set( void * buff, size_t size, size_t oset = 0 );
	bool set( char * buff, size_t size, size_t oset = 0 );
	bool set( const char * buff, size_t size, size_t oset = 0 );

	bool ins( _BDATA & bdata, size_t oset = 0 );
	bool ins( int value, size_t size, size_t oset = 0 );
	bool ins( void * buff, size_t size, size_t oset = 0 );
	bool ins( char * buff, size_t size, size_t oset = 0 );
	bool ins( const char * buff, size_t size, size_t oset = 0 );

	bool add( _BDATA & bdata );
	bool add( int value, size_t size );
	bool add( void * buff, size_t size );
	bool add( char * buff, size_t size );
	bool add( const char * buff, size_t size );

	// per leggibilità
	bool asciiz(){ return add( "", 1 ); }

	bool get( _BDATA & bdata, size_t size = BDATA_ALL );
	bool get( void * buff, size_t size );
	bool get( char * buff, size_t size );

	void del( bool null = false );

	bool file_load( FILE * fp );
	bool file_load( const char * path );
	bool file_save( FILE * fp );
	bool file_save( const char * path );

	void print();

}BDATA, *PBDATA;


