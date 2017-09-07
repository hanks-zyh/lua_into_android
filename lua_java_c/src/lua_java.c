/*
 * lua_java.c
 *
 *  Created on: 2017Äê9ÔÂ4ÈÕ
 *      Author: hanks
 */


#include <stdio.h>
#include "lua_java_Main.h"
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"

void dump(lua_State * L){
	int n = lua_gettop(L);
	int i;

	for(i=1;i<=n;i++){
		int type = lua_type(L,i);
		switch(type){
		case LUA_TNUMBER:
			printf("%d : %g\n",i, lua_tonumber(L,i) );
			break;

		case LUA_TSTRING:
			printf("%d : %s\n",i, lua_tostring(L,i) );
			break;

		case LUA_TBOOLEAN:
			printf("%d : %s\n",i, lua_toboolean(L,i)?"true":"false" );
			break;

		case LUA_TFUNCTION:
			printf("%d : function\n",i );
			break;

		default:
			printf("%d : %d\n",i, type);
			break;
		}
	}
}


JNIEXPORT void JNICALL Java_lua_1java_Main_doFile
  (JNIEnv * env, jclass job, jstring file_path){

	const char * filePath = (*env)->GetStringUTFChars(env,file_path,NULL);
	printf("Java_lua_1java_Main_doFile: %s\n",filePath);

	lua_State * L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L,filePath);
	dump(L);
	lua_close(L);
}

