/*
 ============================================================================
 Name        : c_lua.c
 Author      : c
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lua/lauxlib.h"
#include "lua/lua.h"
#include "lua/lualib.h"

void dump(lua_State * L) {
	int n = lua_gettop(L);
	int i;

	for (i = 1; i <= n; i++) {
		int type = lua_type(L, i);
		switch (type) {
		case LUA_TNUMBER:
			printf("%d : %g\n", i, lua_tonumber(L, i));
			break;

		case LUA_TSTRING:
			printf("%d : %s\n", i, lua_tostring(L, i));
			break;

		case LUA_TBOOLEAN:
			printf("%d : %s\n", i, lua_toboolean(L, i) ? "true" : "false");
			break;

		case LUA_TFUNCTION:
			printf("%d : function\n", i);
			break;

		default:
			printf("%d : %s\n", i, type);
			break;
		}
	}
}

int add(lua_State *L) {
	double n1 = lua_tonumber(L, -1);
	double n2 = lua_tonumber(L, -2);
	lua_pushnumber(L, n1 + n2);
	return 1; // 返回值代表该函数的返回值个数
}

void c_call_lua() {

	lua_State * L = luaL_newstate(); // 创建 Lua 与 C 进行数据交互的堆栈并返回指针 L；

	luaL_openlibs(L);                //为堆栈加载所有的标准 Lua 库，支持脚本在 C 应用中执行

	//luaL_dostring(L, "print('from dostring')");  // 执行 lua 脚本

	//luaL_dofile(L,"D:\\eclipse-workspace\\c_lua\\src\\a.lua");          //执行整个 Lua 脚本文件 a.lua

	luaL_loadfile(L, "D:\\eclipse-workspace\\c_lua\\src\\a.lua");
	lua_pcall(L, 0, 0, 0);

	lua_getglobal(L, "power");
	lua_pushinteger(L, 2);
	lua_pushinteger(L, 10);
	//dump(L);

	lua_call(L, 2, 1);

	//dumpStack(L);
	int res = lua_tonumber(L, -1);  // 取出栈顶结果
	printf("power:%d", res);

	lua_close(L);                   //函数关闭堆栈，释放资源

}

void lua_call_c() {
	lua_State * L = luaL_newstate();
	luaL_openlibs(L);
	lua_register(L, "add", add);
	luaL_dofile(L, "D:\\eclipse-workspace\\c_lua\\src\\a.lua");
	lua_close(L);
}

int main(void) {

//	c_call_lua();
	lua_call_c();
	return 0;
}
