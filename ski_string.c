#include "SkiffScript.h"
#include <stdio.h>
#include <stdlib.h>

Identifier* currentString;

void openString()
{
    currentString = (Identifier*)malloc(sizeof(Identifier));
    currentString->value.type = SKI_STR;
    currentString->id_name = NULL;
    currentString->value.value.string_value.str = (char*)malloc(sizeof(char) * 32);
    currentString->value.value.string_value.length = 0;
    currentString->value.value.string_value.max_length = 32;
}

void addCharToString(char chr)
{
    if (currentString != NULL) {
        if (currentString->value.value.string_value.max_length < currentString->value.value.string_value.length + 2)
        {
            currentString->value.value.string_value.str = (char*)realloc(
                currentString->value.value.string_value.str,
                sizeof(char) * (currentString->value.value.string_value.max_length + 16)
            );
            currentString->value.value.string_value.max_length += 16;
        }
        currentString->value.value.string_value.str[currentString->value.value.string_value.length] = chr;
        currentString->value.value.string_value.length++;
    }
    return;
}

Identifier* disposeString()
{
    if (currentString != NULL)
    {
        currentString->value.value.string_value.str[currentString->value.value.string_value.length] = '\0';
    }
    return currentString;
}