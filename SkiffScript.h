#ifndef     SKIFFSCRIPT_H_INCLUDED
#define     SKIFFSCRIPT_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

#define    byte        unsigned char
#define    word        unsigned short
#define    dword       unsigned int
#define    qword       unsigned long

#define     real        double

int line_number;

//
typedef enum{
    DUMMY,
    SKI_INTEGER,
    SKI_FLOAT,
    SKI_STR,
    SKI_BOOLEAN,
    SKI_BYTE,
    DUMMY_2
}SKI_TYPE;

typedef enum{
    FALSE = 0,
    TRUE = 1
}boolean;

typedef struct {
    char* str;
    size_t length;
    size_t max_length;
}SKI_STRING;

typedef struct _SKI_VALUE{
    SKI_TYPE type;
    union{
        dword       int_value;
        real        real_value;
        SKI_STRING string_value;
        boolean     boolean_value;
        byte        byte_value;
    }value;
}SKI_VALUE;


typedef struct _Identifier{
    char* id_name;
    boolean     isVariable;
    SKI_VALUE value;
}Identifier;

typedef struct _Variable {
    Identifier* identifier;
    struct _Variable* next;
}Variable;

typedef enum {
    NORMAL_FUNCTION,
    NATIVE_FUNCTION
}FUNC_TYPE;

#define ABS(N)      (N) > 0.0?(N):(-N)

//

#include "Ski_interprter.h"

typedef struct _Statement Statement;
typedef enum _EXP_TYPE EXP_TYPE;
typedef struct _LocalEnvironment LocalEnvironment;

typedef struct _Parameter {
    int para_count;
    Statement* stat;
    struct _Parameter* next;
}Parameter;

typedef struct _Function{
    char* func_name;
    FUNC_TYPE type;
    struct _SKI_VALUE (*native)();
    Parameter* para;
    struct{
        LocalEnvironment* env;
    }user_define_func;
    struct _Function* next;
}Function;

//ski_eval.c
#define     ADD_EXPR        0
#define     SUB_EXPR        1
#define     MUL_EXPR        2
#define     DIV_EXPR        3

void evalAddValue(Identifier* destination,Identifier* source0,Identifier* source1);
void evalSubValue(Identifier* destination,Identifier* source0,Identifier* source1);
void evalMulValue(Identifier* destination,Identifier* source0,Identifier* source1);
void evalDivValue(Identifier* destination,Identifier* source0,Identifier* source1);
SKI_VALUE evalBinaryExpression(LocalEnvironment* env,Statement* id0,EXP_TYPE expr,Statement* id1);
SKI_VALUE evalMinusExpression(LocalEnvironment* env,EXP_TYPE type,Statement* source);
void evalMinusValue(Identifier* destination,Identifier* source);
void evalNotValue(Identifier* destination,Identifier* source);

Identifier* getIdentifier(SKI_VALUE val);

SKI_VALUE evalIntValue(int int_val);
SKI_VALUE evalRealValue(real real_val);
SKI_VALUE evalStringValue(SKI_STRING str);
SKI_VALUE evalBooleanValue(boolean bol);
SKI_VALUE evalByteValue(byte byt);

SKI_VALUE evalAssignVaule(LocalEnvironment* env,Statement* left,Statement* right);
SKI_VALUE evalVariableValue(LocalEnvironment* env,const Statement* var);
SKI_VALUE evalFunctionCallValue(LocalEnvironment* env,char* func_name,Parameter* para);

SKI_VALUE* castToBoolean(SKI_VALUE* val);

//ski_variable.c
#define     GLOBAL_VARIABLE         NULL

int variable_count;

void showValue(char* var_name);
void addVariable(LocalEnvironment* env,Identifier* idef);
void AddLocalVariable(LocalEnvironment* env,Identifier* idef);
void disposeVariable();
SKI_VALUE valueVariable(LocalEnvironment* env,char* var_name,Identifier* value);
short checkVariable(LocalEnvironment* env,Identifier* idef);
Variable* findVariable(LocalEnvironment* env,char* var_name);
void initializeVariable();
Identifier* getVariable(LocalEnvironment* env,char* var_name);
void initializeLocalVar(LocalEnvironment* env);
void disposeLocalVar(LocalEnvironment* env);

//ski_error.c
void interpreteError(char const* errormsg);
void ski_error(const char* errmsg,const char* funnymsg,int line_number, ...);
void ski_exit(dword num);

//ski_debug.c

#define     DBG_INT(N)      printf("DBG_INT:%d\n",(N))
#define     DBG_HEX(N)      printf("DBG_HEX:%x\n",(N))
#define     DBG_REAL(N)     printf("DBG_REAL:%lf\n",(N))
#define     DBG_STR(N)      printf("DBG_STR:%s\n",(N))
#define     DBG_ASSERT(C,A) if((C)){printf("Assert true:%s\n",(A));}
void showIdentifier(Identifier* idef);
void showAllVariables();

//ski_function.c

int function_count;

void initializeFunction();
void regsiteNativeFunction(char* func_name,struct _SKI_VALUE (*func)() );//call by developer
LocalEnvironment* regsiteFunction(char* func_name,Parameter* para);//call by yacc
SKI_VALUE callNativeFunction(LocalEnvironment* env,char* func_name,Parameter* para);
SKI_VALUE callFunction(LocalEnvironment* env,Function* func,Parameter* para);
Function* findFunction(char* func_name);
void disposeFunction();

void setReturnValue(SKI_VALUE val);
SKI_VALUE getReturnValue();

//ski_nativefunc.c

void regsiteAllNativeFunctions();

//ski_string.c

void openString();
void addCharToString(char chr);
Identifier* disposeString();

//ski_environment.c
void initializeEnvironment();
void openLocalEnvironment(LocalEnvironment* env);
void closeLocalEnvironment();
LocalEnvironment* getCurrentEnvironment();

#endif
