

#include "persist.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>


#undef NDEBUG
#include <assert.h>



static std::unordered_map<std::string,std::string> persist;
static bool rdwr = true;



void persist_rdonly(){
	rdwr = false;
}

void persist_rdwr(){
	rdwr = true;
}


const char *get_persist_path(){
	static std::string persist_path="";
	if(persist_path.size()>0)return persist_path.c_str();

	// locate user home directory

	struct passwd *pwd;
	assert(pwd=getpwuid(getuid()));
	persist_path = std::string(pwd->pw_dir)+"/.ike/persist";
	
	return persist_path.c_str();
}


static void load_all(){
	FILE *f = fopen(get_persist_path(),"rb");
	if(!f)return;
	persist.clear();
	for(;;){
		char line[256];
		if(!fgets(line,sizeof(line),f))break;
		const char *key = strtok(line," \n");
		if(!key)break;
		const char *val = strtok(0," \n");
		if(!key)break;
		persist[key]=val;
//	    printf("%s %s\n",key,val);
	}
	fclose(f);
}


static void save_all(){
	if(!rdwr)return;
	FILE *f = fopen(get_persist_path(),"wb");
	if(!f)return;
	for( auto& it: persist) {
	    auto line = it.first+" "+it.second+"\n";
	    fputs(line.c_str(),f);
//	    printf("%s",line.c_str());
	}	
	fclose(f);
}


const char *persist_get( const char *key ){
	load_all();
//    printf("%s\n",persist[key].c_str());
	return persist[key].c_str();
}

const char *persist_set( const char *key, const char *val ){
	const char *prev = persist_get(key);
	persist[key]=val;
	save_all();
	return prev;
} 

