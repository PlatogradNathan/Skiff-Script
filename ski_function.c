//skiff script function section
#include "skiffscript.h"
#include <stdlib.h>
#include<string.h>

/*****************************************************
 * The standard formats of native C Functions        *
 * SKI_VALUE function_name(int argc,SKI_VALUE* argv);*
 * SKI_VALUE : returned value of this func           *
 * argc : the number of the parameter(s)             *
 * argv: each parameter                              *
 * **************************************************/

Function* function_header;
Function* function_last;

SKI_VALUE return_value;

extern int executed_line_number;

void initializeFunction()
{
    function_count = 0;
    function_header = (Function*)malloc(sizeof(Function));
    function_header->next = NULL;
    function_last = function_header;
}

void regsiteNativeFunction(char* func_name,struct _SKI_VALUE (*func)())
{
    function_last->next = (Function*)malloc(sizeof(Function));
    function_last->next->func_name = func_name;
    function_last->next->native = func;
    function_last->next->type = NATIVE_FUNCTION;
    function_last = function_last->next;
    function_last->next = NULL;
    return;
}

LocalEnvironment* regsiteFunction(char* func_name,Parameter* para)
{
    Function* func;
    LocalEnvironment* result;

    func = (Function*)malloc(sizeof(Function));
    func->func_name = func_name;
    func->type = NORMAL_FUNCTION;

    func->user_define_func.env = (LocalEnvironment*)malloc(sizeof(LocalEnvironment));
    initializeLocalVar(func->user_define_func.env);
    func->user_define_func.env->local_type = LOCAL_FUNCTION;

    func->user_define_func.env->block = (Block*)malloc(sizeof(Block));
    func->user_define_func.env->block->statements = (Statement*)malloc(sizeof(Statement));
    func->user_define_func.env->block->statement_last = func->user_define_func.env->block->statements;
    func->user_define_func.env->block->statement_last->next = NULL;

    func->para = para;

    function_last->next = func;
    function_last = function_last->next;
    function_last->next = NULL;

    result = func->user_define_func.env;

    return result;
}

int getArgc(Parameter* para)
{
    Parameter* iterator;
    int n = 0;
    for(iterator = para;iterator;iterator = iterator->next)
    {
        n++;
    }
    return n;
}

SKI_VALUE* getArgv(LocalEnvironment* env,int argc,Parameter* para)
{
    SKI_VALUE* argv;
    Parameter* iterator;
    argv = (SKI_VALUE*)malloc(sizeof(SKI_VALUE) * argc);
    iterator = para;
    for (int i = 0;i < argc;i++)
    {
        argv[i] = execute(env,iterator->stat);
        iterator = iterator->next;
    }
    return argv;
}

Function* findFunction(char* func_name)
{
    Function* iterator;
    for(iterator = function_header->next;iterator != NULL;iterator = iterator->next)
    {
        if (strcmp(iterator->func_name,func_name) == 0)
        {
            return iterator;
        }
    }
    return NULL;
}

SKI_VALUE callFunction(LocalEnvironment* env,Function* func,Parameter* para)
{
    int excepted_argc,argc,i;
    SKI_VALUE *argv;
    Parameter* iterator;

    excepted_argc = getArgc(para);
    argc = getArgc(func->para);
    if (excepted_argc != argc)
    {
        if (excepted_argc > argc) {
            ski_error("Too few arguments in function:%s",
            "Too few arguments in function:%s",executed_line_number,func->func_name);
        } else {
            ski_error("Too many arguments in function:%s",
            "Too many arguments in function:%s",executed_line_number,func->func_name);
        }
    }
    else
    {
        argv = getArgv(env,argc,para);
        iterator = func->para;
        //create each argument
        for(i = 0; i < argc;i++)
        {
            addVariable(func->user_define_func.env,iterator->stat->value);
            valueVariable(func->user_define_func.env,iterator->stat->value->id_name,getIdentifier(argv[i]));
            iterator = iterator->next;
        }
        //call function
        executeStatments(func->user_define_func.env);
    }
}

SKI_VALUE callNativeFunction(LocalEnvironment* env,char* func_name,Parameter* para)
{
    SKI_VALUE result;
    Function* iterator;

    int argc;
    SKI_VALUE* argv;
    argc = getArgc(para);
    argv = getArgv(env,argc,para);

    for(iterator = function_header->next;iterator != NULL;iterator = iterator->next)
    {
        if (strcmp(iterator->func_name,func_name) == 0)
        {
            SKI_VALUE (*func)() = iterator->native;
            result = (*func)(argc,argv);
            return result;
        }
    }
    ski_error("Function not found:%s",
    "Sorry,we don't prepare such a nice function:%s for you,write it yourself",
    executed_line_number,func_name);
}

void disposeFunction()
{
    Function* iterator;
    for(iterator = function_header;iterator != NULL;iterator = iterator->next)
    {
        free(iterator);
    }
}

void setReturnValue(SKI_VALUE val)
{
    return_value = val;
}

SKI_VALUE getReturnValue()
{
    return return_value;
}
