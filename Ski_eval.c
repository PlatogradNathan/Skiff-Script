#include "SkiffScript.h"
#include "Ski_interprter.h"
#include <string.h>
#include <math.h>

//void evalAddValue(Identifier* destination,Identifier* source0,Identifier* source1);
//void evalSubValue(Identifier* destination,Identifier* source0,Identifier* source1);
//void evalMulValue(Identifier* destination,Identifier* source0,Identifier* source1);
//void evalDivValue(Identifier* destination,Identifier* source0,Identifier* source1);

extern int executed_line_number;

void evalAddValue(Identifier* destination,Identifier* source0,Identifier* source1)
{
    if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.int_value = source0->value.value.int_value + source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value + (double)(source1->value.value.int_value);
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.int_value) + source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value + source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_STR && source1->value.type == SKI_STR)
    {
        size_t size;
        destination->value.type = SKI_STR;
        size = (strlen(source0->value.value.string_value.str) + strlen(source1->value.value.string_value.str));
        destination->value.value.string_value.max_length = source0->value.value.string_value.max_length + 
            source1->value.value.string_value.max_length;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*size);
        strcpy(destination->value.value.string_value.str,source0->value.value.string_value.str);
        strcat(destination->value.value.string_value.str,source1->value.value.string_value.str);
        destination->value.value.string_value.length = size;
    }
    else if (source0->value.type == SKI_STR && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_STR;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*source0->value.value.string_value.length
         + 16);//16 is for the number added
        sprintf(destination->value.value.string_value.str,"%s%d",source0->value.value.string_value.str,source1->value.value.int_value);
        destination->value.value.string_value.length = strlen(destination->value.value.string_value.str);
        destination->value.value.string_value.max_length = destination->value.value.string_value.length + 16;
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_STR)
    {
        destination->value.type = SKI_STR;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*source1->value.value.string_value.length
         + 16);//16 is for the number added
        sprintf(destination->value.value.string_value.str,"%d%s",source0->value.value.int_value,source1->value.value.string_value.str);
        destination->value.value.string_value.length = strlen(destination->value.value.string_value.str);
        destination->value.value.string_value.max_length = destination->value.value.string_value.length + 16;
    }
    else if (source0->value.type == SKI_STR && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_STR;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*source0->value.value.string_value.length
         + 32);//32 is for the number added
        sprintf(destination->value.value.string_value.str,"%s%lf",source0->value.value.string_value.str,source1->value.value.real_value);
        destination->value.value.string_value.length = strlen(destination->value.value.string_value.str);
        destination->value.value.string_value.max_length = destination->value.value.string_value.length + 16;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_STR)
    {
        destination->value.type = SKI_STR;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*source1->value.value.string_value.length
         + 32);//32 is for the number added
        sprintf(destination->value.value.string_value.str,"%lf%s",source0->value.value.real_value,source1->value.value.string_value.str);
        destination->value.value.string_value.length = strlen(destination->value.value.string_value.str);
        destination->value.value.string_value.max_length = destination->value.value.string_value.length + 16;
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.int_value = source0->value.value.int_value + source1->value.value.byte_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_BYTE;
        destination->value.value.byte_value = source0->value.value.byte_value + source1->value.value.byte_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.int_value = source0->value.value.byte_value + source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.byte_value) + source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value + (double)(source1->value.value.byte_value);
    }
    else if (source0->value.type == SKI_STR && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_STR;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*source1->value.value.string_value.length
         + 32);//32 is for the number added
        sprintf(destination->value.value.string_value.str,"%s%u",source0->value.value.string_value.str,source1->value.value.byte_value);
        destination->value.value.string_value.length = strlen(destination->value.value.string_value.str);
        destination->value.value.string_value.max_length = destination->value.value.string_value.length + 16;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_STR)
    {
        destination->value.type = SKI_STR;
        destination->value.value.string_value.str = (char*)malloc(sizeof(char)*source1->value.value.string_value.length
         + 32);//32 is for the number added
        sprintf(destination->value.value.string_value.str,"%u%s",source0->value.value.byte_value,source1->value.value.string_value.str);
        destination->value.value.string_value.length = strlen(destination->value.value.string_value.str);
        destination->value.value.string_value.max_length = destination->value.value.string_value.length + 16;
    }
    else//wrong type such as boolean...
    {
        ski_error("Operator \'+\' is not allowed here",
        "I can imagine your project manager is about to go mad because of this wrong \'+\'"
        ,executed_line_number);
    }
    return;
}

void evalSubValue(Identifier* destination,Identifier* source0,Identifier* source1)
{
    if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.int_value = source0->value.value.int_value - source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value - (double)(source1->value.value.int_value);
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.int_value) - source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value - source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.byte_value) - source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value - (double)(source1->value.value.byte_value);
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_BYTE;
        destination->value.value.byte_value = source0->value.value.byte_value - source1->value.value.byte_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.real_value = source0->value.value.byte_value - source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.int_value - source1->value.value.byte_value;
    }
    else
    {
        ski_error("Operator \'*\' is not allowed here",
        "I can imagine your mathematics teacher is about to go mad because of this wrong \'*\'"
        ,executed_line_number);
    }
    return;
}

void evalMulValue(Identifier* destination,Identifier* source0,Identifier* source1)
{
    if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.int_value = source0->value.value.int_value * source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value * (double)(source1->value.value.int_value);
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.int_value) * source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value * source1->value.value.real_value;
    }
     else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.byte_value) * source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value * (double)(source1->value.value.byte_value);
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_BYTE;
        destination->value.value.byte_value = source0->value.value.byte_value * source1->value.value.byte_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.real_value = source0->value.value.byte_value * source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.int_value * source1->value.value.byte_value;
    }
    else
    {
        ski_error("Operator \'*\' is not allowed here",
        "I can imagine your mathematics teacher is about to go mad because of this wrong \'*\'"
        ,executed_line_number);
    }
    return;
}

void evalDivValue(Identifier* destination,Identifier* source0,Identifier* source1)
{
    if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.int_value = source0->value.value.int_value / source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value + (double)(source1->value.value.int_value);
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.int_value) / source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value / source1->value.value.real_value;
    }
     else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = (double)(source0->value.value.byte_value) / source1->value.value.real_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.real_value / (double)(source1->value.value.byte_value);
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_BYTE;
        destination->value.value.byte_value = source0->value.value.byte_value / source1->value.value.byte_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.real_value = source0->value.value.byte_value / source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.int_value / source1->value.value.byte_value;
    }
    else
    {
        ski_error("Operator \'/\' is not allowed here",
        "I can imagine your mathematics teacher is about to go mad because of this wrong \'/\'"
        ,executed_line_number);
    }
    return;
}

void evalModValue(Identifier* destination,Identifier* source0,Identifier* source1)
{
    if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.int_value = source0->value.value.int_value % source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = fmod(source0->value.value.real_value,
        (double)(source1->value.value.int_value)
        );
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = fmod((double)(source0->value.value.int_value),
        source1->value.value.real_value
        );
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = fmod(source0->value.value.real_value,
        source1->value.value.real_value
        );
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_FLOAT)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = fmod((double)(source0->value.value.byte_value) , source1->value.value.real_value);
    }
    else if (source0->value.type == SKI_FLOAT && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = fmod(source0->value.value.real_value , (double)(source1->value.value.byte_value));
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_BYTE;
        destination->value.value.byte_value = source0->value.value.byte_value % source1->value.value.byte_value;
    }
    else if (source0->value.type == SKI_BYTE && source1->value.type == SKI_INTEGER)
    {
        destination->value.type = SKI_INTEGER;
        destination->value.value.real_value = source0->value.value.byte_value % source1->value.value.int_value;
    }
    else if (source0->value.type == SKI_INTEGER && source1->value.type == SKI_BYTE)
    {
        destination->value.type = SKI_FLOAT;
        destination->value.value.real_value = source0->value.value.int_value % source1->value.value.byte_value;
    }
    else
    {
        ski_error("Operator \'%%\' is not allowed here",
        "I can imagine your mathematics teacher is about to go mad because of this wrong \'%%\'"
        ,executed_line_number);
    }
}

void evalGTValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    boolean* result = &destination->value.value.boolean_value;
    if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_INTEGER)
    {
        *result = s0->value.value.int_value > s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_FLOAT)
    {
        *result = (double)(s0->value.value.int_value) > s1->value.value.real_value;
    }
    else if (s0->value.type == SKI_FLOAT && s1->value.type == SKI_INTEGER)
    {
        *result = s0->value.value.real_value > (double)(s1->value.value.int_value);
    }
    else if (s0->value.type == SKI_FLOAT && s1->value.type == SKI_FLOAT)
    {
        *result = s0->value.value.real_value > s1->value.value.real_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_INTEGER)
    {
        *result = s0->value.value.byte_value > s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_BYTE)
    {
        *result = s0->value.value.byte_value > s1->value.value.byte_value;
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_BYTE)
    {
        *result = s0->value.value.int_value > s1->value.value.byte_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_FLOAT)
    {
        *result = (double)(s0->value.value.byte_value) > s1->value.value.real_value;
    }
    else if (s0->value.type == SKI_FLOAT && s1->value.type == SKI_BYTE)
    {
        *result = s0->value.value.real_value > (double)(s1->value.value.byte_value);
    }
    else
    {
        ski_error("Cannot compare these value",
        "What you just did is just like compare STL with beer",executed_line_number);
    }
}

void evalGEValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    boolean* result = &destination->value.value.boolean_value;
    if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_INTEGER)
    {
        *result = s0->value.value.int_value >= s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_FLOAT)
    {
        *result = (double)(s0->value.value.int_value) >= s1->value.value.real_value;
    }
    else if (s0->value.type == SKI_FLOAT && s1->value.type == SKI_INTEGER)
    {
        *result = s0->value.value.real_value >= (double)(s1->value.value.int_value);
    }
    else if (s0->value.type == SKI_FLOAT && s1->value.type == SKI_FLOAT)
    {
        *result = s0->value.value.real_value >= s1->value.value.real_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_INTEGER)
    {
        *result = s0->value.value.byte_value >= s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_BYTE)
    {
        *result = s0->value.value.byte_value >= s1->value.value.byte_value;
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_BYTE)
    {
        *result = s0->value.value.int_value >= s1->value.value.byte_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_FLOAT)
    {
        *result = (double)(s0->value.value.byte_value) >= s1->value.value.real_value;
    }
    else if (s0->value.type == SKI_FLOAT && s1->value.type == SKI_BYTE)
    {
        *result = s0->value.value.real_value >= (double)(s1->value.value.byte_value);
    }
    else
    {
        ski_error("Cannot compare these value",
        "What you just did is just like compare STL with beer",executed_line_number);
    }
}

void evalLTValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    evalGEValue(destination,s0,s1);
    if (destination->value.value.boolean_value == TRUE)
    {
        destination->value.value.boolean_value = FALSE;
    }
    else
    {
        destination->value.value.boolean_value = TRUE;
    }
}

void evalLEValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    evalGTValue(destination,s0,s1);
    if (destination->value.value.boolean_value == TRUE)
    {
        destination->value.value.boolean_value = FALSE;
    }
    else
    {
        destination->value.value.boolean_value = TRUE;
    }
}

void evalLogicalAndValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    boolean* result = &destination->value.value.boolean_value;
    if(s0->value.type == SKI_INTEGER && s1->value.type == SKI_INTEGER)
    {
        if (s0->value.value.int_value != 0 && s1->value.value.int_value != 0)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else if (s0->value.type == SKI_BOOLEAN && s1->value.type == SKI_BOOLEAN)
    {
        if (s0->value.value.boolean_value == TRUE && s1->value.value.boolean_value == TRUE)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else if (s0->value.type == SKI_BOOLEAN && s1->value.type == SKI_INTEGER)
    {
        if (s0->value.value.boolean_value == TRUE && s1->value.value.int_value != 0)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_BOOLEAN)
    {
        if (s0->value.value.int_value != 0 && s1->value.value.boolean_value == TRUE)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else
    {
        ski_error("Operator \'&\' is not allowed here","(debug this \'&\')&(This program may work)"
        ,executed_line_number);
    }
}

void evalLogicalOrValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    boolean* result = &destination->value.value.boolean_value;
    if(s0->value.type == SKI_INTEGER && s1->value.type == SKI_INTEGER)
    {
        if (s0->value.value.int_value != 0 || s1->value.value.int_value != 0)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else if (s0->value.type == SKI_BOOLEAN && s1->value.type == SKI_BOOLEAN)
    {
        if (s0->value.value.boolean_value == TRUE || s1->value.value.boolean_value == TRUE)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else if (s0->value.type == SKI_BOOLEAN && s1->value.type == SKI_INTEGER)
    {
        if (s0->value.value.boolean_value == TRUE || s1->value.value.int_value != 0)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_BOOLEAN)
    {
        if (s0->value.value.int_value != 0 || s1->value.value.boolean_value == TRUE)
        {
            *result = TRUE;
        }
        else
        {
            *result = FALSE;
        }
    }
    else
    {
        ski_error("Operator \'|\' is not allowed here","(debug this \'|\')|(give up this program)"
        ,executed_line_number);
    }
}

void evalAndValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_INTEGER)
    {
        destination->value.type == SKI_INTEGER;
        destination->value.value.int_value = s0->value.value.int_value & s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_BYTE)
    {
        destination->value.type == SKI_INTEGER;
        destination->value.value.int_value = s0->value.value.int_value & s1->value.value.byte_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_INTEGER)
    {
        destination->value.type == SKI_BYTE;
        destination->value.value.byte_value = s0->value.value.byte_value & s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_BYTE)
    {
        destination->value.type == SKI_BYTE;
        destination->value.value.byte_value = s0->value.value.byte_value & s1->value.value.byte_value;
    }
    else
    {
        ski_error("Operator \'&&\' is not allowed here","(debug this \'&&\')&&(This program may work)"
        ,executed_line_number);
    }
}

void evalOrValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_INTEGER)
    {
        destination->value.type == SKI_INTEGER;
        destination->value.value.int_value = s0->value.value.int_value | s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_INTEGER && s1->value.type == SKI_BYTE)
    {
        destination->value.type == SKI_INTEGER;
        destination->value.value.int_value = s0->value.value.int_value | s1->value.value.byte_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_INTEGER)
    {
        destination->value.type == SKI_BYTE;
        destination->value.value.byte_value = s0->value.value.byte_value | s1->value.value.int_value;
    }
    else if (s0->value.type == SKI_BYTE && s1->value.type == SKI_BYTE)
    {
        destination->value.type == SKI_BYTE;
        destination->value.value.byte_value = s0->value.value.byte_value | s1->value.value.byte_value;
    } 
    else
    {
        ski_error("Operator \'||\' is not allowed here","(debug this \'||\')||(give up this program)"
        ,executed_line_number);
    }
}

void evalEqValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    destination->value.type = SKI_BOOLEAN;
    boolean* result = &destination->value.value.boolean_value;
    *result = FALSE;
    if (s0->value.type == SKI_STR)
    {
        if (s1->value.type != SKI_STR)
        {
            *result = FALSE;
        }
        else
        {
            if(strcmp(s0->value.value.string_value.str,s1->value.value.string_value.str) == 0)
            {
                *result = TRUE;
            }
        }
    }
    else if (s0->value.type == SKI_BOOLEAN)
    {
        if (s1->value.type == SKI_BOOLEAN)
        {
            if (s0->value.value.boolean_value == s1->value.value.boolean_value)
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_INTEGER)
        {
            if ((s0->value.value.boolean_value == TRUE && s1->value.value.int_value != 0)||
            s0->value.value.boolean_value == FALSE && s1->value.value.int_value == 0)
            {
                *result = TRUE;
            }
        }
    }
    else if (s0->value.type == SKI_FLOAT)
    {
        if (s1->value.type == SKI_FLOAT)
        {
            if (s0->value.value.real_value == s1->value.value.real_value)
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_INTEGER)
        {
            if (s0->value.value.real_value == (double)(s1->value.value.int_value))
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_BYTE)
        {
            if (s0->value.value.real_value == (double)(s1->value.value.byte_value))
            {
                *result = TRUE;
            }
        }
    }
    else if (s0->value.type == SKI_INTEGER)
    {
        if (s1->value.type == SKI_FLOAT)
        {
            if ((double)s0->value.value.int_value == s1->value.value.real_value)
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_INTEGER)
        {
            if (s0->value.value.int_value == s1->value.value.int_value)
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_BYTE)
        {
            if (s0->value.value.int_value == s1->value.value.byte_value)
            {
                *result = TRUE;
            }
        }
    }
    else if (s0->value.type == SKI_BYTE)
    {
        if (s1->value.type == SKI_FLOAT)
        {
            if ((double)s0->value.value.byte_value == s1->value.value.real_value)
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_INTEGER)
        {
            if (s0->value.value.byte_value == s1->value.value.int_value)
            {
                *result = TRUE;
            }
        }
        else if (s1->value.type == SKI_BYTE)
        {
            if (s0->value.value.byte_value == s1->value.value.byte_value)
            {
                *result = TRUE;
            }
        }
    }
}

void evalNeValue(Identifier* destination,Identifier* s0,Identifier* s1)
{
    evalEqValue(destination,s0,s1);
    if(destination->value.value.boolean_value == TRUE)
    {
        destination->value.value.boolean_value = FALSE;
    }
    else
    {
        destination->value.value.boolean_value = TRUE;
    }
}

Identifier* getIdentifier(SKI_VALUE val)
{
    Identifier* idef;
    idef = (Identifier*)malloc(sizeof(Identifier));
    idef->id_name = NULL;
    idef->isVariable = FALSE;
    idef->value = val;
    return idef;
}

SKI_VALUE evalBinaryExpression(LocalEnvironment* env,Statement* id0,EXP_TYPE expr,Statement* id1)
{
    SKI_VALUE v;
    SKI_VALUE left,right;
    left = execute(env,id0);
    right = execute(env,id1);

    Identifier* result;
    result = (Identifier*)malloc(sizeof(Identifier));
    result->isVariable = FALSE;
    result->id_name = NULL;
    switch(expr)
    {
        case ADD_EXP:
            evalAddValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case SUB_EXP:
            evalSubValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case MUL_EXP:
            evalMulValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case DIV_EXP:
            evalDivValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case ASSIGN_EXP:
            v = evalAssignVaule(env,id0,id1);
            break;
        case MOD_EXP:
            evalModValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case GT_EXP:
            evalGTValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case GE_EXP:
            evalGEValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case LT_EXP:
            evalLTValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case LE_EXP:
            evalLEValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case LOGICAL_AND_EXP:
            evalLogicalAndValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case LOGICAL_OR_EXP:
            evalLogicalOrValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case AND_EXP:
            evalAndValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case EQ_EXP:
            evalEqValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        case NE_EXP:
            evalNeValue(result,getIdentifier(left),getIdentifier(right));
            v = result->value;
            break;
        default:
            break;
    }
    free(result);
    return v;
   // return result;
}

SKI_VALUE evalMinusExpression(LocalEnvironment* env,EXP_TYPE type,Statement* source)
{
    SKI_VALUE v;
    SKI_VALUE res;
    res = execute(env,source);

    Identifier* result;
    result = (Identifier*)malloc(sizeof(Identifier));
    result->id_name = NULL;
    result->isVariable = FALSE;

    switch(type)
    {
        case MINUS_EXP:
            evalMinusValue(result,getIdentifier(res));
            break;
        case NOT_EXP:
            evalNotValue(result,getIdentifier(res));
            break;
        default:
            break;
    }
    v = result->value;

    free(result);
    return v;
}

void evalMinusValue(Identifier* destination,Identifier* source)
{
    switch(source->value.type)
    {
        case SKI_INTEGER:
            destination->value.type = SKI_INTEGER;
            destination->value.value.int_value = -(source->value.value.int_value);
            break;
        case SKI_FLOAT:
            destination->value.type = SKI_FLOAT;
            destination->value.value.real_value = -(source->value.value.real_value);
            break;
        case SKI_BYTE:
            destination->value.type = SKI_BYTE;
            destination->value.value.byte_value = -(source->value.value.byte_value);
            break;
        default:
            break;
    }
}

void evalNotValue(Identifier* destination,Identifier* source)
{
    extern int executed_line_number;
    if (source->value.type == SKI_BOOLEAN)
    {
        destination->value.type = SKI_BOOLEAN;
        destination->value.value.boolean_value = source->value.value.boolean_value == TRUE? FALSE : TRUE;
    }
    else
    {
        ski_error("Operator:\'!\' is not allowed here","!(use operator \'!\' here)",executed_line_number);
    }
}

SKI_VALUE evalIntValue(int int_val)
{
    SKI_VALUE v;
    v.type = SKI_INTEGER;
    v.value.int_value = int_val;
    return v;
}

SKI_VALUE evalRealValue(real real_val)
{
    SKI_VALUE v;
    v.type = SKI_FLOAT;
    v.value.real_value = real_val;
    return v;
}

SKI_VALUE evalStringValue(SKI_STRING str)
{
    SKI_VALUE v;
    v.type = SKI_STR;
    v.value.string_value = str;
    return v;
}

SKI_VALUE evalBooleanValue(boolean bol)
{
    SKI_VALUE v;
    v.type = SKI_BOOLEAN;
    v.value.boolean_value = bol;
    return v;
}

SKI_VALUE evalByteValue(byte byt)
{
    SKI_VALUE v;
    v.type = SKI_BYTE;
    v.value.byte_value = byt;
    return v;
}

SKI_VALUE evalAssignVaule(LocalEnvironment* env,Statement* left,Statement* right)
{
    SKI_VALUE dest;
    dest = execute(env,right);
    valueVariable(env,left->value->id_name,getIdentifier(dest));
}

SKI_VALUE evalVariableValue(LocalEnvironment* env,const Statement* var)
{
    SKI_VALUE result;
    if (var->value->id_name == NULL)
    {
        return evalIntValue(0);
    }
    result = getVariable(env,var->value->id_name)->value;
    return result;
}

SKI_VALUE evalFunctionCallValue(LocalEnvironment* env,char* func_name,Parameter* para)
{
    SKI_VALUE val;
    val = callNativeFunction(env,func_name,para);
    return val;
}

SKI_VALUE* castToBoolean(SKI_VALUE* val)
{
    switch(val->type)
    {
        case SKI_BOOLEAN:
            return val;
        case SKI_INTEGER:
            val->type = SKI_BOOLEAN;
            if (val->value.int_value != 0)
            {
                val->value.boolean_value = TRUE;
            }
            else
            {
                val->value.boolean_value = FALSE;
            } 
            return val;
        case SKI_BYTE:
            val->type = SKI_BOOLEAN;
            if (val->value.byte_value != 0)
            {
                val->value.boolean_value = TRUE;
            }
            else
            {
                val->value.boolean_value = FALSE;
            } 
            return val;
        default:
            val->value.boolean_value = FALSE;
            break;
    }
}