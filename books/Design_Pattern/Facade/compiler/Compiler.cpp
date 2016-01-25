/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include "Compiler.h"
#include "Scanner.h"
#include "Parser.h"
#include "GenMidCode.h"
#include "GenMachineCode.h"

void CCompiler::Run(){
    CScanner scanner;
    CParser parser;
    CGenMidCode genMidCode;
    CGenMachineCode genMacCode;
    scanner.Scan();
    parser.Parser();
    genMidCode.GenCode();
    genMacCode.GenCode();
}
