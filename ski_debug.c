#include "SkiffScript.h"
#include <stdio.h>

#define stddbg      stdout


void showIdentifier(Identifier* idef)
{
    if(idef->value.type == SKI_INTEGER)
    {
        fprintf(stddbg,"Identifier<%s>,type:<Integer>,value:<%d>\n",
        idef->id_name==NULL?"None" : idef->id_name,
        idef->value.value.int_value);
    }
    else if(idef->value.type == SKI_FLOAT)
    {
        fprintf(stddbg,"Identifier<%s>,type:<Real>,value:<%lf>\n",
        idef->id_name==NULL?"None" : idef->id_name,
        idef->value.value.real_value);
    }
    else if(idef->value.type == SKI_STR)
    {
         fprintf(stddbg,"Identifier<%s>,type:<String>,value:<%s>\n",
        idef->id_name==NULL?"None" : idef->id_name,
        idef->value.value.string_value.str);
    }
    else if (idef->value.type == SKI_BOOLEAN)
    {
        fprintf(stddbg,"Identifier<%s>,type:<Boolean>,value:<%s>\n",
        idef->id_name==NULL?"None" : idef->id_name,
        idef->value.value.boolean_value == TRUE?"TRUE":"FALSE");
    }
    else if (idef->value.type == SKI_BYTE)
    {
        fprintf(stddbg,"Identifier<%s>,type:<Byte>,value:<%u>\n",
        idef->id_name==NULL?"None" : idef->id_name,
        idef->value.value.byte_value);
    }
    else
    {
        fprintf(stddbg,"Identifier<%s>,type:<Unknow>,value:<%d>\n",
        idef->id_name==NULL?"None" : idef->id_name,
        idef->value.value.int_value);
    }
}

void showAllVariables()
{
    extern Variable* global_variable_header;
    extern Variable* global_variable_last;

    int i;

    Variable* iterator = global_variable_header;
    for(i = 0;i < variable_count;i++)
    {
        iterator = iterator->next;
        fprintf(stddbg,"Variable[%d]",i + 1);
        showIdentifier(iterator->identifier);
    }
}
