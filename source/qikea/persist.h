
#ifndef _persist_h_
#define _persist_h_

void persist_rdonly();
void persist_rdwr();

const char *persist_get( const char *key );
const char *persist_set( const char *key, const char *val );

#endif // _persist_h_

