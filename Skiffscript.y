/************************************
*Skiff Script
*Lex Section
*Written by Nathan Liu
*2018/9/4
*************************************/
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SkiffScript.h"
#include "Ski_interprter.h"

#define _DEBUG_

int importFile(const char* filename);

char* ski_file_name;

%}

%union{
    int int_value;
    double double_value;
    struct _Identifier* id_value;
    struct _Parameter* para_value;
    struct _Statement* stat_value
}

%token ADD SUB MUL DIV AND OR MOD
%token EQ NE GT GE LT LE LOGICAL_AND LOGICAL_OR NOT
%token SN0 SR EQU LP RP SN1 LC RC
%token VAR INTEGER FLOAT STRING_TYPE BYTE IF BOOLEAN ELSE ELIF DO WHILE GOTO BREAK CONTINUE RETURN FOR FUNCTION
%token<stat_value> IDENTIFIER
%token<stat_value> REAL_CONSTANT INT_CONSTANT STRING_CONSTANT BOOLEAN_CONSTANT
%type<stat_value>expression assign_expression logical_expression and_or_expression equ_expression compare_expression  add_expression term primary
%type<para_value> paralist
%type<stat_value> line
%%
line_list
    : line
    | line_list line
    ;
line
    :expression SR
    |FUNCTION IDENTIFIER LP paralist RP LC
    {
        LocalEnvironment* env;
        env = regsiteFunction($2->value->id_name,$4);
        openLocalEnvironment(env);
    }
    |IF LP expression RP LC
    {
        $$ = createIfStatement(getCurrentEnvironment(),$3);
        openLocalEnvironment($$->u.if_stat->env);
        $$->line_number = line_number;
    }
    |WHILE LP expression RP LC
    {
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        $$ = createWhileStatement(getCurrentEnvironment(),$3,NORMAL_WHILE);
        openLocalEnvironment($$->u.while_stat->env);
        $$->line_number = line_number;
    }
    |RC ELSE LC
    {
        if(getCurrentEnvironment() != NULL)
        {
            IfStatement* current_if;
            current_if = (IfStatement*)(getCurrentEnvironment()->super);
            current_if->elseenv =createElseLocalEnvironment(getCurrentEnvironment());
            closeLocalEnvironment();
            openLocalEnvironment(current_if->elseenv);
            $$ = current_if;
            $$->line_number = line_number;
        }
        else
        {
            ski_error("else missing if","What's the meaning of a single else?",line_number);
        }
    }
    |RC ELIF LP expression RP LC
    {
        removeStatementAndCheck(getCurrentEnvironment(),$4);
        if (getCurrentEnvironment() != NULL && getCurrentEnvironment()->local_type == LOCAL_IF)
        {
            IfStatement* current_if;
            current_if = (IfStatement*)(getCurrentEnvironment()->super);
            closeLocalEnvironment();
            current_if->elif = createElseIfStatement(getCurrentEnvironment(),$4);
            $$ = current_if->elif;
            openLocalEnvironment(current_if->elif->u.if_stat->env);
            $$->line_number = line_number;
        }
        else
        {
            ski_error("elif missing if","You cannot use elif the same as if",line_number);
        }
    }
    |RC
    {
        closeLocalEnvironment();
    }
    |DO LC
    {
        $$ = createWhileStatement(getCurrentEnvironment(),NULL,DO_WHILE);
        openLocalEnvironment($$->u.while_stat->env);
        $$->line_number = line_number;
    }
    |RC WHILE LP expression RP
    {
        WhileStatement* current_while;
        removeStatementAndCheck(getCurrentEnvironment(),$4);
        current_while = (WhileStatement*)(getCurrentEnvironment()->super);
        current_while->condition = $4;
        closeLocalEnvironment();
        $$->line_number = line_number;
    }
    |FOR LP expression SR expression SR expression RP LC
    {
        //for (a; b; c;)
        //removeStatementAndCheck(getCurrentEnvironment(),$3);
        //removeStatementAndCheck(getCurrentEnvironment(),$5);
        //removeStatementAndCheck(getCurrentEnvironment(),$7);
        removeStatementAndCheck(getCurrentEnvironment(),$7);
        removeStatementAndCheck(getCurrentEnvironment(),$5);
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        $$ = createForStatement(getCurrentEnvironment(),$3,$5,$7);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP SR expression SR expression RP LC
    {
        //for( ; b; c )
        removeStatementAndCheck(getCurrentEnvironment(),$4);
        removeStatementAndCheck(getCurrentEnvironment(),$6);
        $$ = createForStatement(getCurrentEnvironment(),NULL,$4,$6);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP SR SR expression RP LC
    {
        //for (; ; c)
        removeStatementAndCheck(getCurrentEnvironment(),$5);
        $$ = createForStatement(getCurrentEnvironment(),NULL,NULL,$5);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP SR expression RP LC
    {
        //for (; b; )
        removeStatementAndCheck(getCurrentEnvironment(),$4);
        $$ = createForStatement(getCurrentEnvironment(),NULL,$4,NULL);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP SR SR RP LC
    {
        //for (; ;  )
        $$ = createForStatement(getCurrentEnvironment(),NULL,NULL,NULL);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP expression SR RP LC
    {
        //for(a; ;)
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        $$ = createForStatement(getCurrentEnvironment(),$3,NULL,NULL);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP expression SR SR expression RP LC
    {
        //for (a; ; c)
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        removeStatementAndCheck(getCurrentEnvironment(),$6);
        $$ = createForStatement(getCurrentEnvironment(),$3,NULL,$6);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FOR LP expression SR expression SR RP LC
    {
        //for (a; b;)
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        removeStatementAndCheck(getCurrentEnvironment(),$5);
        $$ = createForStatement(getCurrentEnvironment(),$3,$5,NULL);
        openLocalEnvironment($$->u.for_stat->env);
        $$->line_number = line_number;
    }
    |FUNCTION IDENTIFIER LP RP LC
    {
        LocalEnvironment* env;
        env = regsiteFunction($2->value->id_name,NULL);
        openLocalEnvironment(env);
    }
    ;
paralist
    :expression
    {
        removeStatementAndCheck(getCurrentEnvironment(),$1);
        $$ = (Parameter*)malloc(sizeof(Parameter));
        $$->stat = $1;
        $$->para_count = 1;
        $$->next = NULL;
    }
    |paralist SN1 expression
    {
        Parameter* iterator;
        iterator = $1;
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        for(int i = 1;i < $1->para_count;i++)
        {
            iterator = iterator->next;
        }
        iterator->next = (Parameter*)malloc(sizeof(Parameter));
        iterator->next->stat = $3;
        iterator->next->next = NULL;
        $1->para_count++;
        $$ = $1;
    }
    ;
expression
    :assign_expression
    |VAR IDENTIFIER SN0 INTEGER
    {
        $2->value->value.type = SKI_INTEGER;
        $$ = createVariableExpression(getCurrentEnvironment(),$2->value);
        $$->line_number = line_number;
    }
    |VAR IDENTIFIER SN0 FLOAT
    {
        $2->value->value.type = SKI_FLOAT;
        $$ = createVariableExpression(getCurrentEnvironment(),$2->value);
        $$->line_number = line_number;
    }
    |VAR IDENTIFIER SN0 STRING_TYPE
    {
        $2->value->value.type = SKI_STR;
        $$ = createVariableExpression(getCurrentEnvironment(),$2->value);
        $$->line_number = line_number;
    }
    |VAR IDENTIFIER SN0 BYTE
    {
        $2->value->value.type = SKI_BYTE;
        $$ = createVariableExpression(getCurrentEnvironment(),$2->value);
        $$->line_number = line_number;
    }
    |VAR IDENTIFIER SN0 BOOLEAN
    {
        $2->value->value.type = SKI_BOOLEAN;
        $$ = createVariableExpression(getCurrentEnvironment(),$2->value);
        $$->line_number = line_number;
    }
    |VAR IDENTIFIER
    {
        $$ = createVariableExpression(getCurrentEnvironment(),$2->value);
        $$->line_number = line_number;
    }
    |BREAK
    {
        $$ = createBreakStatement(getCurrentEnvironment());
        $$->line_number = line_number;
    }
    |CONTINUE
    {
        $$ = createContinueStatement(getCurrentEnvironment());
        $$->line_number = line_number;
    }
    |RETURN expression
    {
        $$ = createReturnStatement(getCurrentEnvironment(),$2);
        $$->line_number = line_number;
    }
    |RETURN
    {
        $$ = createReturnStatement(getCurrentEnvironment(),NULL);
        $$->line_number = line_number;
    }
    ;
assign_expression
    :logical_expression
    |IDENTIFIER EQU logical_expression
    {
        removeStatementAndCheck(getCurrentEnvironment(),$3);
        $$ = createBinaryExpression(getCurrentEnvironment(),ASSIGN_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
logical_expression
    :and_or_expression
    |logical_expression LOGICAL_AND and_or_expression
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),LOGICAL_AND_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |logical_expression LOGICAL_OR and_or_expression
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),LOGICAL_OR_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
and_or_expression
    :equ_expression
    |and_or_expression AND equ_expression
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),AND_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |and_or_expression OR equ_expression
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),OR_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
equ_expression
    :compare_expression
    |equ_expression EQ compare_expression
    {
        // '=='
        $$ = createBinaryExpression(getCurrentEnvironment(),EQ_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |equ_expression NE compare_expression
    {
        // '!='
        $$ = createBinaryExpression(getCurrentEnvironment(),NE_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
compare_expression
    :add_expression
    |compare_expression GT add_expression
    {
        // '>'
        $$ = createBinaryExpression(getCurrentEnvironment(),GT_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |compare_expression GE add_expression
    {
        // '>='
        $$ = createBinaryExpression(getCurrentEnvironment(),GE_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |compare_expression LT add_expression
    {
        // '<'
        $$ = createBinaryExpression(getCurrentEnvironment(),LT_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |compare_expression LE add_expression
    {
        // '<='
        $$ = createBinaryExpression(getCurrentEnvironment(),LE_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
add_expression
    :term
    |add_expression ADD term
    {
       $$ = createBinaryExpression(getCurrentEnvironment(),ADD_EXP,$1,$3);
       $$->line_number = line_number;
    }
    |add_expression SUB term
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),SUB_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
term
    :primary
    |term MUL primary
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),MUL_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |term DIV primary
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),DIV_EXP,$1,$3);
        $$->line_number = line_number;
    }
    |term MOD primary
    {
        $$ = createBinaryExpression(getCurrentEnvironment(),MOD_EXP,$1,$3);
        $$->line_number = line_number;
    }
    ;
primary
    :REAL_CONSTANT
    |INT_CONSTANT
    |STRING_CONSTANT
    |BOOLEAN_CONSTANT
    |IDENTIFIER
    |LP expression RP
    {
        $$ = $2;
        $$->line_number = line_number;
    }
    |SUB primary
    {
        $$ = createMinusExpression(getCurrentEnvironment(),MINUS_EXP,$2);
        $$->line_number = line_number;
    }
    |NOT primary
    {
        $$ = createMinusExpression(getCurrentEnvironment(),NOT_EXP,$2);
        $$->line_number = line_number;
    }
    |IDENTIFIER LP RP
    {
        $$ = createFunctionCallExpression(getCurrentEnvironment(),$1->value->id_name,NULL);
        $$->line_number = line_number;
    }
    |IDENTIFIER LP paralist RP
    {
        $$ = createFunctionCallExpression(getCurrentEnvironment(),$1->value->id_name,$3);
        $$->line_number = line_number;
    }
    ;
%%

extern word isFunnyMsgOpen;

int yyerror(char const *str)
{
    extern char* yytext;
    ski_error("Wrong grammar near \"%s\"","May be there's a low-level mistake near %s",line_number,yytext);
    return 0;
}

int importFile(const char* filename)
{
    extern FILE* yyin;
    extern int yyparse();
    extern Interpreter* interpreter;

    yyin = fopen(filename,"rb");
    if (yyparse())
    {
        exit(1);
    }
}

void readArgs(int argc,char** argv)
{
    int i;
    char* para;
    for (i = 2;i < argc;i++)
    {
        para = argv[i];
        if (strcmp(para,"-f") == 0 || strcmp(para,"/f") == 0) {
            isFunnyMsgOpen = 1;
        } else if (strcmp(para,"-?") == 0 || strcmp(para,"/?") == 0 || strcmp(para,"-help") ==0 || 
        strcmp(para,"/help") == 0) {
            puts("*****************************");
            puts("*  Skiff script help info   *");
            puts("*skis <filename> -f...      *");
            puts("*-f:show funny error message*");
            puts("*-?:show this help info     *");
            puts("*****************************");
        } else {
            printf("Unknow parameter:%s\n\a",para);
            exit(0);
        }
    }
}

int main(int argc,char** argv)
{
    extern int yyparse();
    extern FILE* yyin;
    extern Interpreter* interpreter;

    if (argc > 1)
    {
       ski_file_name = argv[1];
       if (strcmp(argv[1],"-?") == 0 || strcmp(argv[1],"/?") == 0 || strcmp(argv[1],"-help") ==0 || 
        strcmp(argv[1],"/help") == 0) {
            puts("*****************************");
            puts("*  Skiff script help info   *");
            puts("*skis <filename> -f...      *");
            puts("*-f:show funny error message*");
            puts("*-?:show this help info     *");
            puts("*****************************");
            exit(0);
        }
        isFunnyMsgOpen = 0;
       if (argc >= 2) {
            readArgs(argc,argv);
        }
       initializeVariable();
        initializeFunction();
        initializeInterpreter();
        initializeEnvironment();
        regsiteAllNativeFunctions();
       importFile(argv[1]);
        executeStatments(NULL);
        disposeVariable();
        disposeFunction();
        disposeInterpreter();
        fclose(yyin);
    }
}
