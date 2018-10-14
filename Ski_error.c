#include "SkiffScript.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

word isFunnyMsgOpen;

void interpreteError(char const* errormsg)
{
    printf(errormsg);
    disposeVariable();
    exit(1);
}

void ski_exit(dword num)
{
    disposeVariable();
    disposeFunction();
    disposeInterpreter();
    exit(num);
}

void ski_error(const char* errmsg,const char* funnymsg,int line_number, ...)
{
    FILE* fp;
    va_list ap;
    char msg0[128],msg1[128];
    
    va_start(ap,line_number);
    vsprintf(msg0,errmsg,ap);
    vsprintf(msg1,funnymsg,ap);
    printf("Error in line %d:\n%s\n",line_number,isFunnyMsgOpen == 0?msg0: msg1);
    va_end(ap);
    ski_exit(1);
}