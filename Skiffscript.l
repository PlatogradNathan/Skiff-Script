/************************************
*Skiff Script
*Lex Section
*Written by Nathan Liu
*2018/9/4
*************************************/
%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "SkiffScript.h"
#include "Ski_interprter.h"

int yywrap ()
{
    return 1;
}
%}
%start COMMENT MULTILINE_COMMENT STRING
%%

<INITIAL>"+"         return ADD;
<INITIAL>"-"         return SUB;
<INITIAL>"*"         return MUL;
<INITIAL>"/"         return DIV;
<INITIAL>"=="        return EQ;
<INITIAL>"!="        return NE;
<INITIAL>">"         return GT;
<INITIAL>">="        return GE;
<INITIAL>"<"         return LT;
<INITIAL>"<="        return LE;
<INITIAL>"&&"        return LOGICAL_AND;
<INITIAL>"||"        return LOGICAL_OR;
<INITIAL>"&"         return AND;
<INITIAL>"|"         return OR;
<INITIAL>"!"         return NOT;
<INITIAL>"%"         return MOD;

<INITIAL>"="         return EQU;
<INITIAL>"\n"        {line_number++;}
<INITIAL>";"         return SR;
<INITIAL>":"         return SN0;
<INITIAL>"("         return LP;
<INITIAL>")"         return RP;
<INITIAL>"{"         return LC;
<INITIAL>"}"         return RC;
<INITIAL>","         return SN1;

<INITIAL>"var"      return VAR;
<INITIAL>"integer"  return INTEGER;
<INITIAL>"real"     return FLOAT;
<INITIAL>"string"   return STRING_TYPE;
<INITIAL>"boolean"  return BOOLEAN;
<INITIAL>"byte"     return BYTE;
<INITIAL>"else"     return ELSE;
<INITIAL>"elif"     return ELIF;
<INITIAL>"while"    return WHILE;
<INITIAL>"do"       return DO;
<INITIAL>"goto"     return GOTO;
<INITIAL>"break"    return BREAK;
<INITIAL>"continue" return CONTINUE;
<INITIAL>"return"   return RETURN;
<INITIAL>"for"      return FOR;
<INITIAL>"if"       return IF;
<INITIAL>"function" return FUNCTION;

<INITIAL>[0-9]+\.[0-9]+ {
    Statement* stat;
    Identifier* id_real;
    id_real = (Identifier*)malloc(sizeof(Identifier));
    id_real->isVariable = FALSE;
    id_real->id_name = NULL;
    id_real->value.type = SKI_FLOAT;
    sscanf(yytext,"%lf",&id_real->value.value.real_value);
    stat = allocStatement(REAL_EXP);
    stat->value = id_real;
    yylval.stat_value = stat;
    //yylval.id_value = id_real;
    return REAL_CONSTANT;
}
<INITIAL>"true" {
    Statement* stat;
    Identifier* id_bool;
    id_bool = (Identifier*)malloc(sizeof(Identifier));
    id_bool->isVariable = FALSE;
    id_bool->id_name = NULL;
    id_bool->value.type = SKI_BOOLEAN;
    id_bool->value.value.boolean_value = TRUE;
    stat = allocStatement(BOOLEAN_EXP);
    stat->value = id_bool;
    yylval.stat_value = stat;
    //yylval.id_value = id_bool;
    return BOOLEAN_CONSTANT;
}
<INITIAL>"false" {
    Statement* stat;
    Identifier* id_bool;
    id_bool = (Identifier*)malloc(sizeof(Identifier));
    id_bool->isVariable = FALSE;
    id_bool->id_name = NULL;
    id_bool->value.type = SKI_BOOLEAN;
    id_bool->value.value.boolean_value = FALSE;
    stat = allocStatement(BOOLEAN_EXP);
    stat->value = id_bool;
    yylval.stat_value = stat;
    //yylval.id_value = id_bool;
    return BOOLEAN_CONSTANT;
}
<INITIAL>([1-9][0-9]*)|"0" {
    Statement* stat;
    Identifier* id_int;
    id_int = (Identifier*)malloc(sizeof(Identifier));
    id_int->isVariable = FALSE;
    id_int->id_name = NULL;
    id_int->value.type = SKI_INTEGER;
    sscanf(yytext,"%d",&id_int->value.value.int_value);
    stat = allocStatement(INT_EXP);
    stat->value = id_int;
    yylval.stat_value = stat;
    //yylval.id_value = id_int;
    return INT_CONSTANT;
}
<INITIAL>[A-Za-z_][A-Za-z_0-9]* {
    Statement* stat;
    char* name;
    name = (char*)malloc(sizeof(char)*strlen(yytext));
    strcpy(name,yytext);
    Identifier* identifier;
    identifier = (Identifier*)malloc(sizeof(Identifier));
    identifier->id_name = name;
    stat = allocStatement(IDENTIFIER_EXP);
    stat->value = identifier;
    yylval.stat_value = stat;
    //yylval.id_value = identifier;
    return IDENTIFIER;
}
<INITIAL>"//"       BEGIN COMMENT;
<INITIAL>"/*"       BEGIN MULTILINE_COMMENT;

<INITIAL>[\t ]          ;

<INITIAL>\"         {
    openString();
    BEGIN STRING;
}      

<STRING>\"          {
    Statement* stat;
    char* str;
    Identifier* string;
    Identifier* idef = (Identifier*)malloc(sizeof(Identifier));
    idef->id_name = NULL;
    idef->value.type = SKI_STR;
    idef->isVariable = FALSE;
    string = disposeString();
    idef->value.value.string_value.str = (char*)malloc(sizeof(char) * string->value.value.string_value.max_length);
    strcpy(idef->value.value.string_value.str,string->value.value.string_value.str);
    stat = allocStatement(STR_EXP);
    stat->value = idef;
    yylval.stat_value = stat;
    BEGIN INITIAL;
    return STRING_CONSTANT;
}
<STRING>\n      {
    addCharToString('\n');
    line_number++;
}
<STRING>\\\"        addCharToString('"');
<STRING>\\n         addCharToString('\n');
<STRING>\\t         addCharToString('\t');
<STRING>\\a         addCharToString('\a');
<STRING>\\\\        addCharToString('\\');
<STRING>.           addCharToString(yytext[0]);

<MULTILINE_COMMENT>.        ;
<MULTILINE_COMMENT>\n       {line_number++;}
<MULTILINE_COMMENT>"*/"     BEGIN INITIAL;

<COMMENT>\n         {line_number++;BEGIN INITIAL;}
<COMMENT>.          ;
%%
