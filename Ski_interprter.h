#ifndef SKI_INTERPRETER_INCLUDED
#define SKI_INTERPRETER_INCLUDED

#include "SkiffScript.h"
#include <setjmp.h>

typedef struct _Parameter Parameter;
typedef struct _LocalEnvironment LocalEnvironment;
typedef struct _Function Function;

typedef enum _EXP_TYPE{
    INT_EXP,
    REAL_EXP,
    STR_EXP,
    IDENTIFIER_EXP,
    BOOLEAN_EXP,
    BYTE_EXP,
    ADD_EXP,
    SUB_EXP,
    MUL_EXP,
    DIV_EXP,
    MOD_EXP,
    EQ_EXP,
    NE_EXP,
    GT_EXP,
    GE_EXP,
    LT_EXP,
    LE_EXP,
    LOGICAL_AND_EXP,
    LOGICAL_OR_EXP,
    AND_EXP,
    OR_EXP,
    NOT_EXP,
    ASSIGN_EXP,
    FUNC_CALL_EXP,
    IF_STAT,
    WHILE_STAT,
    FOR_STAT,
    MINUS_EXP,
    BREAK_STAT,
    CONTINUE_STAT,
    RETURN_STAT,
    VAR_EXP
}EXP_TYPE;

typedef enum {
    LOCAL_IF,
    LOCAL_WHILE,
    LOCAL_ELSE,
    LOCAL_FUNCTION,
    LOCAL_FOR
}LOCAL_TYPE;

typedef struct _Statement Statement;

typedef struct{
    Statement* left;
    Statement* right;
}BinaryExpression;

typedef struct {
    Statement* stat;
}MinusExpression;

typedef struct {
    FUNC_TYPE type;
    Parameter* para;
    Function* func;
    char* func_name;
}FunctionCallExpression;

typedef struct {
    Identifier* var;
    LocalEnvironment* env;
}VariableExpression;

typedef struct _Block {
    Statement* statements;
    Statement* statement_last;
}Block;

typedef struct _LocalEnvironment {
    Variable* variable_last;
    Variable* local_variable;
    Block* block;
    struct _LocalEnvironment* outer;
    void* super;
    LOCAL_TYPE local_type;
    jmp_buf jmp_location;
}LocalEnvironment;

typedef enum {
    JMP_SET = 0,//first time call setjmp()
    JMP_BREAK = 1,//longjmp called
    JMP_CONTINUE = 2,
    JMP_RETURN = 3
}JMP_TYPE;

typedef struct _IfStatement {
    Statement* condition;
    LocalEnvironment* env;
    LocalEnvironment* elseenv;
    struct _Statement* elif;
}IfStatement;

typedef enum {
    NORMAL_WHILE,
    DO_WHILE
}WHILE_TYPE;

typedef struct _WhileStatement {
    Statement* condition;
    LocalEnvironment* env;
    WHILE_TYPE type;
}WhileStatement;

typedef struct _ForStatement {
    Statement* condition;
    LocalEnvironment* env;
    Statement* initCondition;
    Statement* action;
}ForStatement;

typedef struct _ReturnStatement {
    Statement* return_value;
}ReturnStatement;

typedef struct _Statement{
    struct _Statement* next;
    EXP_TYPE type;
    int line_number;

    Identifier* value;//for number,variable,not expression

    union{
        BinaryExpression* binary;
        FunctionCallExpression* func_call;
        IfStatement* if_stat;
        MinusExpression* minus;
        WhileStatement* while_stat;
        ForStatement* for_stat;
        VariableExpression* variable;
        ReturnStatement* return_stat;
    }u;
}Statement;

typedef struct {
    Variable* globalVariable;
    Statement* statements;
    int current_line_number;
}Interpreter;

void initializeInterpreter();
Statement* allocStatement(EXP_TYPE type);
void appendStatement(Block* block,Statement* stat);
void removeStatement(LocalEnvironment* env);
void removeStatementAndCheck(LocalEnvironment* env,Statement* target);
Statement* createBinaryExpression(LocalEnvironment* env,EXP_TYPE type,Statement* left,Statement* right);
Statement* createFunctionCallExpression(LocalEnvironment* env,char* func_name,Parameter* para);
Statement* createVariableExpression(LocalEnvironment* env,Identifier* idef);
void executeStatments(LocalEnvironment* env);
SKI_VALUE execute(LocalEnvironment* env,const Statement* stat);
void executeWhileStatement(LocalEnvironment* env,WhileStatement* stat);
void disposeInterpreter();

Statement* createIfStatement(LocalEnvironment* env,Statement* condition);
LocalEnvironment* createElseLocalEnvironment(LocalEnvironment* env);
Statement* createElseIfStatement(LocalEnvironment* env,Statement* condition);
Statement* createMinusExpression(LocalEnvironment* env,EXP_TYPE type,Statement* stat);
Statement* createWhileStatement(LocalEnvironment* env,Statement* condition,WHILE_TYPE type);
Statement* createBreakStatement(LocalEnvironment* env);
Statement* createContinueStatement(LocalEnvironment* env);
Statement* createForStatement(LocalEnvironment* env,Statement* initCondition,Statement* condition,
                                Statement* action);
Statement* createReturnStatement(LocalEnvironment* env,Statement* return_value);

void executeForStatement(LocalEnvironment* env,ForStatement* stat);

#endif