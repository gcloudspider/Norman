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

#include "ILetterProcess.h"
#include "LetterProcesslmpl.h"
#include "ModenPostOffice.h"

void DoltByPostOffice(){
    CModenPostOffice modenPostOffice;
    string context = "Hello,it's me do you know who i am? I'm your old over I'd like to ....";
    string address = "Happy Road No.666 Beijing City .China.";
    modenPostOffice.SendLetter(context,address);
}

void DoLtYourself(){
    ILetterProcess *pLetterProcess = new CLetterProcesslmpl();
    pLetterProcess->WriteContext("Hello it's me .do you know who i am?I'm you old lover.I'd like to ...");
    pLetterProcess->FillEnvelope("Happy Road No.666. Beijing City.China");
    pLetterProcess->LetterIntoEnvelope();
    pLetterProcess->SendLetter();

    delete pLetterProcess;
}

int main(int argc,char* argv[]){
    DoltByPostOffice();

    DoLtYourself();

    return 0;
}
