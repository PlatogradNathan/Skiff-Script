#include "Ski_interprter.h"
#include <setjmp.h>

Interpreter* interpreter;
Statement* statement_last;

extern Variable* global_variable_header;

int executed_line_number;

void initializeInterpreter()
{
    interpreter = (Interpreter*)malloc(sizeof(Interpreter));
    interpreter->globalVariable = global_variable_header;
    interpreter->statements = (Statement*)malloc(sizeof(Statement));
    statement_last = interpreter->statements;
    interpreter->statements->next = NULL;
    interpreter->current_line_number = 0;
}

Statement* allocStatement(EXP_TYPE type)
{
    Statement* stat;
    stat = (Statement*)malloc(sizeof(Statement));
    stat->type = type;
    stat->line_number = interpreter->current_line_number;
    return stat;
}



void appendStatement(Block* block,Statement* stat)
{
    if (block == NULL)//global statements
    {
        statement_last->next = stat;
        statement_last = statement_last->next;
        statement_last->next = NULL;   
    }
    else
    {
        block->statement_last->next = stat;
        block->statement_last = block->statement_last->next;
        block->statement_last->next = NULL;
    }
    
}

void removeStatement(LocalEnvironment* env)
{
    Statement *iterator;
    if(env == NULL)
    {
        for(iterator = interpreter->statements;iterator->next->next;iterator = iterator->next) ;
        iterator->next = NULL;
        statement_last = iterator;
    }
    else
    {
        for(iterator = env->block->statements;iterator->next->next;iterator = iterator->next) ;
        iterator->next = NULL;
        env->block->statement_last = iterator;
    }
}

void removeStatementAndCheck(LocalEnvironment* env,Statement* target)
{
     if(!(target->type == INT_EXP || target->type == REAL_EXP || target->type == BYTE_EXP || target->type == STR_EXP
        ||target->type == BOOLEAN_EXP || target->type == IDENTIFIER_EXP)) {
            removeStatement(env);
        }
}

Statement* createVariableExpression(LocalEnvironment* env,Identifier* idef)
{
    VariableExpression* expression;
    Statement* result;

    expression = (VariableExpression*)malloc(sizeof(VariableExpression));
    expression->env = env;
    expression->var = idef;
    result = (Statement*)malloc(sizeof(Statement)); 
    result->u.variable = expression;
    result->type = VAR_EXP;
    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
    return result;
}

Statement* createBinaryExpression(LocalEnvironment* env,EXP_TYPE type,Statement* left,Statement* right)
{
    BinaryExpression* expression;
    Statement* result;

    expression = (BinaryExpression*)malloc(sizeof(BinaryExpression));
    expression->left = left;
    expression->right = right;
    result = (Statement*)malloc(sizeof(Statement)); 
    result->u.binary = expression;
    result->type = type;
    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
    return result;
}

Statement* createMinusExpression(LocalEnvironment* env,EXP_TYPE type,Statement* stat)
{
    MinusExpression* expression;
    Statement* result;
    
    expression = (MinusExpression*)malloc(sizeof(MinusExpression));
    expression->stat = stat;

    result = allocStatement(type);
    result->u.minus = expression;

    if (env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
}

Statement* createFunctionCallExpression(LocalEnvironment* env,char* func_name,Parameter* para)
{
    FunctionCallExpression* expression;
    //Function* func;
    Statement* result;
    expression = (FunctionCallExpression*)malloc(sizeof(FunctionCallExpression));

   /* func = findFunction(func_name);
    if (func == NULL)
    {
        DBG_STR("Func is null!");
        //report error and exit
    }*/

   // expression->func = func;
    expression->func_name = func_name;
   // expression->type = func->type;

    expression->para = para;

    result = (Statement*)malloc(sizeof(Statement)); 
    result->value = (Identifier*)malloc(sizeof(Identifier));
    result->value->id_name = func_name;
    result->value->isVariable = FALSE;
    result->u.func_call = expression;
    result->type = FUNC_CALL_EXP;

    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
    return result;
}

Statement* createIfStatement(LocalEnvironment* env,Statement* condition)
{
    IfStatement* stat;
    Statement* result;
    result = allocStatement(IF_STAT);
    stat = (IfStatement*)malloc(sizeof(IfStatement));
    stat->condition = condition;
    stat->env = (LocalEnvironment*)malloc(sizeof(LocalEnvironment));
    stat->env->block = (Block*)malloc(sizeof(Block));
    stat->env->block->statements = (Statement*)malloc(sizeof(Statement));
    stat->env->block->statement_last = stat->env->block->statements;
    stat->env->block->statement_last->next = NULL;
    stat->env->super = (IfStatement*)stat;
    stat->elseenv = NULL;
    stat->env->local_type = LOCAL_IF;
    stat->elif = NULL;
    initializeLocalVar(stat->env);
    result->u.if_stat = stat;

    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
    return result;
}

Statement* createWhileStatement(LocalEnvironment* env,Statement* condition,WHILE_TYPE type)
{
    Statement* result;
    WhileStatement* stat;

    stat = (WhileStatement*)malloc(sizeof(WhileStatement));
    stat->type = type;
    stat->env = (LocalEnvironment*)malloc(sizeof(LocalEnvironment));
    stat->env->block = (Block*)malloc(sizeof(Block));
    stat->env->block->statements = (Statement*)malloc(sizeof(Statement));
    stat->env->block->statement_last = stat->env->block->statements;
    stat->env->block->statement_last->next = NULL;
    stat->env->super = (WhileStatement*)stat;
    stat->env->local_type = LOCAL_WHILE;
    stat->condition = condition;
    initializeLocalVar(stat->env);

    result = allocStatement(WHILE_STAT);
    result->u.while_stat = stat;

    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
    return result;
}

Statement* createForStatement(LocalEnvironment* env,Statement* initCondition,Statement* condition,
Statement* action)
{
    Statement* result;
    ForStatement* stat;

    stat = (ForStatement*)malloc(sizeof(ForStatement));
    stat->env = (LocalEnvironment*)malloc(sizeof(LocalEnvironment));
    stat->env->block = (Block*)malloc(sizeof(Block));
    stat->env->block->statements = (Statement*)malloc(sizeof(Statement));
    stat->env->block->statement_last = stat->env->block->statements;
    stat->env->block->statement_last->next = NULL;
    stat->env->super = (ForStatement*)stat;
    stat->env->local_type = LOCAL_FOR;
    stat->condition = condition;
    stat->initCondition = initCondition;
    stat->action = action;
    initializeLocalVar(stat->env);

    result = allocStatement(FOR_STAT);
    result->u.for_stat = stat;

    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        appendStatement(NULL,result);
    }
    return result;
}

Statement* createBreakStatement(LocalEnvironment* env)
{
    Statement* stat;
    stat = allocStatement(BREAK_STAT);
    if(env != NULL)
    {
        appendStatement(env->block,stat);
    }
    else
    {
        appendStatement(NULL,stat);
    }
    return stat;
}

Statement* createContinueStatement(LocalEnvironment* env)
{
    Statement* stat;
    stat = allocStatement(CONTINUE_STAT);

    if(env != NULL)
    {
        appendStatement(env->block,stat);
    }
    else
    {
        appendStatement(NULL,stat);
    }
    return stat;
}

Statement* createElseIfStatement(LocalEnvironment* env,Statement* condition)
{
    IfStatement* stat;
    Statement* result;
    result = allocStatement(IF_STAT);
    stat = (IfStatement*)malloc(sizeof(IfStatement));
    stat->condition = condition;
    stat->env = (LocalEnvironment*)malloc(sizeof(LocalEnvironment));
    stat->env->block = (Block*)malloc(sizeof(Block));
    stat->env->block->statements = (Statement*)malloc(sizeof(Statement));
    stat->env->block->statement_last = stat->env->block->statements;
    stat->env->block->statement_last->next = NULL;
    stat->env->super = (IfStatement*)stat;
    stat->elseenv = NULL;
    stat->env->local_type = LOCAL_IF;
    stat->elif = NULL;
    initializeLocalVar(stat->env);
    result->u.if_stat = stat;
    return result;
}

Statement* createReturnStatement(LocalEnvironment* env,Statement* return_value)
{
    extern int line_number;
    ReturnStatement* stat;
    Statement* result;

    result = allocStatement(RETURN_STAT);
    stat = (ReturnStatement*)malloc(sizeof(ReturnStatement));
    stat->return_value = (Statement*)malloc(sizeof(Statement));

    stat->return_value = return_value;
    result->u.return_stat = stat;

    if(env != NULL)
    {
        appendStatement(env->block,result);
    }
    else
    {
        ski_error("Return without function","Where do you want to return?",line_number);
    }
    return result;
}

LocalEnvironment* createElseLocalEnvironment(LocalEnvironment* env)
{
    LocalEnvironment* elseenv;
    extern int line_number;
    if (env->local_type == LOCAL_IF)
    {
        elseenv = (LocalEnvironment*)malloc(sizeof(LocalEnvironment));
        elseenv->super = env->super;
        elseenv->local_type = LOCAL_ELSE;
        elseenv->block = (Block*)malloc(sizeof(Block));
        elseenv->block->statements = (Statement*)malloc(sizeof(Statement));
        elseenv->block->statement_last = elseenv->block->statements;
        elseenv->block->statement_last->next = NULL;
        initializeLocalVar(elseenv);
    }
    else
    {
        ski_error("Else missing if","Maybe you hate \"if\",but you must write it to match your \"else\"",
        line_number);
    }
    return elseenv;
}

void executeStatments(LocalEnvironment* env)
{
    Statement* iterator;
    if (env == NULL)
    {
        for (iterator = interpreter->statements->next;iterator;iterator = iterator->next)
        {
            execute(env,iterator);
        }
    }
    else
    {
        for(iterator = env->block->statements->next;iterator;iterator = iterator->next)
        {
            execute(env,iterator);
        }
    }
}

void executeWhileStatement(LocalEnvironment* env,WhileStatement* stat)
{
    int jmp_result;
    jmp_result = setjmp(stat->env->jmp_location);
    if(jmp_result == JMP_BREAK)
    {
        goto end;
    }
    else if(jmp_result == JMP_CONTINUE)
    {
        goto new_loop;
    }
    if (stat->type == DO_WHILE)
    {
        executeStatments(stat->env);
    }
    SKI_VALUE cond;
    cond = execute(env,stat->condition);
    while(castToBoolean(&cond)->value.boolean_value == TRUE)
    {
new_loop:
        executeStatments(stat->env);
        cond = execute(env,stat->condition);
    }
end:
    return;
}

void executeForStatement(LocalEnvironment* env,ForStatement* stat) {
    int jmp_result;
    SKI_VALUE cond;
    jmp_result = setjmp(stat->env->jmp_location);

    if(jmp_result == JMP_BREAK)
    {
        goto end;
    }
    else if (jmp_result == JMP_CONTINUE)
    {
        goto new_loop;
    }
    execute(env,stat->initCondition);
    if (stat->condition != NULL)
    {
        cond = execute(env,stat->condition);
        castToBoolean(&cond);
    }
    else
    {
        cond.type = SKI_BOOLEAN;
        cond.value.boolean_value = TRUE;
    }
   for(;;) {
new_loop:
       if (stat->condition != NULL) {
            cond = execute(env,stat->condition);
            if (castToBoolean(&cond)->value.boolean_value == FALSE) 
            {
                break;
            }
       }
        executeStatments(stat->env);
        execute(env,stat->action);
   }
end:
    return;
}

SKI_VALUE executeFunctionCallExpression(LocalEnvironment* env,FunctionCallExpression* exp)
{
    SKI_VALUE v;
    exp->func = findFunction(exp->func_name);
    if (exp->func == NULL)
    {
        ski_error("Function not found:%s",
        "Sorry,we don't prepare such a nice function:%s for you,write it yourself",
        executed_line_number,exp->func->func_name);
    }
    exp->type = exp->func->type;
    if (exp->type == NATIVE_FUNCTION)
    {
        v = callNativeFunction(env,exp->func->func_name,exp->para);
        return v;
    }
    else
    {
        int jmp_result;
        jmp_result = setjmp(exp->func->user_define_func.env->jmp_location);
        if (jmp_result == JMP_RETURN)
        {
            v  = getReturnValue();
            return v;
        }
        callFunction(env,exp->func,exp->para);
    }
}

SKI_VALUE execute(LocalEnvironment* env,const Statement* stat)
{
    SKI_VALUE v;
    if(stat == NULL)
    {
        return evalIntValue(0);
    }
    executed_line_number = stat->line_number;
    switch (stat->type)
    {
        case INT_EXP:
        {
            //DBG_STR("INT_EXP");
            v = evalIntValue(stat->value->value.value.int_value);
            //DBG_STR("INT END");
            break;
        }
        case REAL_EXP:
        {
           //DBG_STR("REAL_EXP");
            v = evalRealValue(stat->value->value.value.real_value);
          //  DBG_STR("REAL END");
            break;
        }
        case STR_EXP:
        {
         //   DBG_STR("STR_EXP");
            v = evalStringValue(stat->value->value.value.string_value);
         //   DBG_STR("STR END");
            break;
        }
        case BOOLEAN_EXP:
        {
          //  DBG_STR("BOL_EXP");
            v = evalBooleanValue(stat->value->value.value.boolean_value);
          //  DBG_STR("BOL_END");
            break;
        }
        case BYTE_EXP:
        {
          //  DBG_STR("BYT_EXP");
            v = evalByteValue(stat->value->value.value.byte_value);
          //  DBG_STR("BYT_END");
            break;
        }
        case IDENTIFIER_EXP:
        {
          //  DBG_STR("IDEF_EXP");
            v = evalVariableValue(env,stat);
         //  DBG_STR("IDEF END");
            break;
        }
        case VAR_EXP:
        {
          //  DBG_STR("VAR_EXP");
            addVariable(stat->u.variable->env,stat->u.variable->var);
         //   DBG_STR("VAR_END");
            break;
        }
        case ADD_EXP:
        case SUB_EXP:
        case MUL_EXP:
        case DIV_EXP:
        case GT_EXP:
        case GE_EXP:
        case LT_EXP:
        case LE_EXP:
        case EQ_EXP:
        case NE_EXP:
        case AND_EXP:
        case OR_EXP:
        case LOGICAL_AND_EXP:
        case LOGICAL_OR_EXP:
        {
        //    DBG_STR("BIN_EXP");
            v = evalBinaryExpression(env,stat->u.binary->left,stat->type,stat->u.binary->right);
         //   DBG_STR("BIN END");
            break;
        }
        case MINUS_EXP:
        case NOT_EXP:
        {
            v = evalMinusExpression(env,stat->type,stat->u.minus->stat);
            break;
        }
        case ASSIGN_EXP:
        {
        //    DBG_STR("ASSIGN_EXP");
            v = evalAssignVaule(env,stat->u.binary->left,stat->u.binary->right);
         //   DBG_STR("ASSIGN END");
            break;
        }
        case FUNC_CALL_EXP:
        {
         //   DBG_STR("FNCCALL_EXP");
            //DBG_STR("FNCCALL END");
            v = executeFunctionCallExpression(env,stat->u.func_call);
        //    DBG_STR("FNCCALL END");
            break;
        }
        case IF_STAT:
        {
        //    DBG_STR("IF_STAT");
            v = execute(env,stat->u.if_stat->condition);
            if (castToBoolean(&v)->value.boolean_value == TRUE)
            {
                executeStatments(stat->u.if_stat->env);
            }
            else {
                if (stat->u.if_stat->elseenv != NULL)
                {
                    executeStatments(stat->u.if_stat->elseenv);
                    v = evalIntValue(0);
                }
                else if (stat->u.if_stat->elif != NULL)
                {
                    v = execute(stat->u.if_stat->env->outer,stat->u.if_stat->elif);
                }
            }
        //    DBG_STR("IF END");
            break;
        }
        case WHILE_STAT:
        {
            executeWhileStatement(env,stat->u.while_stat);
            break;
        }
        case BREAK_STAT:
        {
            LocalEnvironment* iterator;
            for(iterator = env;iterator;iterator = iterator->outer)
            {
                if (iterator->local_type == LOCAL_WHILE || iterator->local_type == LOCAL_FOR)
                {
                    WhileStatement* local_while;
                    local_while = (WhileStatement*)(iterator->super);
                    longjmp(local_while->env->jmp_location,JMP_BREAK);
                }
            }
            ski_error("Break missing for or while","Sorry,I'll break you because of this unmatched \"break\"",
            stat->line_number);
            break;
        }
        case CONTINUE_STAT:
        {
            LocalEnvironment* iterator;
            for(iterator = env;iterator;iterator = iterator->outer)
            {
                if (iterator->local_type == LOCAL_WHILE || iterator->local_type == LOCAL_FOR)
                {
                    WhileStatement* local_while;
                    local_while = (WhileStatement*)(iterator->super);
                    longjmp(local_while->env->jmp_location,JMP_CONTINUE);
                }
            }
            ski_error("Continue without for or break",
            "Sorry your program cannot continue running because of this unmatched \"continue\"",
            stat->line_number);
        }
        case FOR_STAT:
        {
           // DBG_STR("FOR_STAT");
            executeForStatement(env,stat->u.for_stat);
            //DBG_STR("FOR_END");
            break;
        }
        case RETURN_STAT:
        {
            LocalEnvironment* iterator;
            for(iterator = env;iterator;iterator = env->outer)
            {
                if (iterator->local_type == LOCAL_FUNCTION)
                {
                    v = execute(env,stat->u.return_stat->return_value);
                    setReturnValue(v);
                    longjmp(iterator->jmp_location,JMP_RETURN);
                }
            }
            ski_error("Return without function",
            "You've to return to your boring debug-work because of this unmatched \"return\"",
            stat->line_number);
        }
        default:
        {
            DBG_STR("Failed!");
            DBG_INT(stat->type);
        }

    }
    return v;

}

void disposeInterpreter()
{
    Statement* iterator;
    Statement* preIterator;
    iterator = interpreter->statements;
    while(1)
    {
        preIterator = iterator;
        iterator = iterator->next;
        if(!iterator)
        {
            free(preIterator);
            break;
        }
        free(preIterator);
    }
}