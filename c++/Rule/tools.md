###################################################
#### Create Date:2016年01月17日 星期日 11时15分10秒
####
####Author:Norman
####
####Description: 用合适工具分析代码
###################################################

####错误代码:
    BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved){
        .....
        CreateThread(NULL,0,ParentMonitorThreadProc,(LPVOID)dwParentProcessid,0,&dwThreadld);
        .....
    }

####解释:
    PVS-Studio开发工具分析出,DLLMain 函数能正常执行的操作非常有限,很多依赖DLL库并没有被加载,所以不能直接在DLLMain里就直接执行任意操作

    PVS-Studio静态分析工具捕获,CreateThread方法不应该在DllMain方法中调用
