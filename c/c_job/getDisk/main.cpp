#include <stdio.h>
#include "diskInfo.h"
#include <iostream>
namespace qhy{

int main() {
    CDiskInfo diskinfo;
    std::cout << diskinfo.getTotalSize()<<std::endl;   
    return 0;    
}
}
