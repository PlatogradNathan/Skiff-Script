#include "SkiffScript.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Variable* global_variable_last;
Variable* global_variable_header;

extern int executed_line_number;

void initializeVariable()
{
    variable_count = 0;
    line_number = 1;
    global_variable_header = (Variable*)malloc(sizeof(Variable));
    global_variable_last = global_variable_header;
}

void initializeLocalVar(LocalEnvironment* env)
{
    env->local_variable = (Variable*)malloc(sizeof(Variable));
    env->local_variable->next = NULL;
    env->variable_last = env->local_variable;
}

void disposeLocalVar(LocalEnvironment* env)
{
    Variable* iterator;
    Variable* preIterator;
    iterator = env->local_variable;
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

extern int yyerror(char const* str);

void AddLocalVariable(LocalEnvironment* env,Identifier* idef)
{
    idef->isVariable = TRUE;
    env->variable_last->next = (Variable*)malloc(sizeof(Variable));
    env->variable_last->next->identifier = idef;
    env->variable_last = env->variable_last->next;
    env->variable_last->next = NULL;
}

void addVariable(LocalEnvironment* env,Identifier* idef)
{
    boolean isAddable;
    isAddable = checkVariable(env,idef);
    if (isAddable == FALSE)
    {
        return;
    }
    idef->isVariable = TRUE;
    if (env != GLOBAL_VARIABLE)
    {
        AddLocalVariable(env,idef);
        return;
    }
    variable_count++;
    global_variable_last->next  = (Variable*)malloc(sizeof(Variable));
    global_variable_last->next->identifier = idef;
    global_variable_last = global_variable_last->next;
}

short checkVariable(LocalEnvironment* env,Identifier* idef)
{
    int i;
    Variable* var;
    var = findVariable(env,idef->id_name);
    if (var == NULL)
        return TRUE;
    return FALSE;
}

Variable* findVariable(LocalEnvironment* env,char* var_name)
{
    Variable* iterator;
    LocalEnvironment* local;
    int i;
    local = env;
    while(local != NULL)
    {
        for(iterator = local->local_variable->next;iterator;iterator = iterator->next)
        {
            if (strcmp(var_name,iterator->identifier->id_name) == 0)
            {
                return iterator;
            }
        }
        local = local->outer;
    }
//global:
    iterator = global_variable_header->next;
    for(i = 0;i < variable_count;i++)
    {
        if (strcmp(var_name,iterator->identifier->id_name) == 0)
        {
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
}

SKI_VALUE valueVariable(LocalEnvironment* env,char* var_name,Identifier* value)
{
    Variable* iterator;
    SKI_VALUE v;
    int i;
    iterator = global_variable_header;
    iterator = findVariable(env,var_name);
    if (iterator != NULL)
    {
        iterator->identifier->value.type = value->value.type;
        iterator->identifier->value = value->value;
        v = iterator->identifier->value;
        return v;
    }
    else
    {
        ski_error("Variable not found:%s",
        "You're too lazy to create a variable called %s",executed_line_number,var_name);
    }
}

Identifier* getVariable(LocalEnvironment* env,char* var_name)
{
    Variable* iterator;
    int i;
    iterator = global_variable_header;
    iterator = findVariable(env,var_name);
    if (iterator != NULL)
    {
        return iterator->identifier;
    }
    else
    {
        return NULL;
    }
}

void disposeVariable()
{
    Variable* iterator,*previterator;
    iterator = global_variable_header;
    while(1)
    {
        previterator = iterator;
        iterator = iterator->next;
        if (previterator == global_variable_last)
        {
            break;
        }
        free(previterator);
    }
}
