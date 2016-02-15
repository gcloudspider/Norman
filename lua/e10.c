//Lua程序或调用Lua主要有两种方式
//通过命令行执行lua命令
//通过lua的C库
#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>

int main(){
    int Buffer = 256;
    char line[Buffer];
    lua_State *L = lua_open();
    while(fgets(line,sizeof(line),stdin)!=0){
        lua_dostring(L,line);
        lua_close(L);
    }
    return 0;
}


