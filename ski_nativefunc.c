#include "Skiffscript.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*********************************************
 * The standard formats of native C Functions*
 * SKI_VALUE function_name(int argc,SKI_VALUE* argv);
 * SKI_VALUE : returned value of this func
 * argc : the number of the parameter(s)
 * argv: each parameter
 * ******************************************/

//io section

SKI_VALUE ski_puts(int argc,SKI_VALUE* argv)
{
    puts(argv->value.string_value.str);
    return evalIntValue(0);
}

SKI_VALUE ski_input(int argc,SKI_VALUE* argv)
{
    SKI_VALUE v;
    v.type = SKI_STR;
    v.value.string_value.str = (char*)malloc(32);
    v.value.string_value.max_length == 32;
    if (argc > 0)
    {
        printf(argv->value.string_value.str);
        scanf("%s",v.value.string_value.str);
    }
    v.value.string_value.length = strlen(v.value.string_value.str);
    return v;
}

SKI_VALUE ski_input_int(int argc,SKI_VALUE* argv)
{
    SKI_VALUE v;
    v.type = SKI_INTEGER;
    if (argc > 0)
    {
        printf(argv->value.string_value.str);
        scanf("%d",&v.value.int_value);
    }
    return v;
}

SKI_VALUE ski_input_real(int argc,SKI_VALUE* argv)
{
    SKI_VALUE v;
    v.type = SKI_FLOAT;
    if (argc > 0)
    {
        printf(argv->value.string_value.str);
        scanf("%lf",&v.value.real_value);
    }
    return v;
}

SKI_VALUE ski_print(int argc,SKI_VALUE* argv)
{
    printf(argv->value.string_value.str);
    return evalIntValue(0);
}

//math section

SKI_VALUE ski_sin(int argc,SKI_VALUE* argv)
{
    return evalRealValue(sin(argv->value.real_value));
}

SKI_VALUE ski_cos(int argc,SKI_VALUE* argv)
{
    return evalRealValue(cos(argv->value.real_value));
}

SKI_VALUE ski_tan(int argc,SKI_VALUE* argv)
{
    return evalRealValue(tan(argv->value.real_value));
}

SKI_VALUE ski_sqrt(int argc,SKI_VALUE* argv)
{
    return evalRealValue(sqrt(argv->value.real_value));
}

void regsiteAllNativeFunctions()
{
    regsiteNativeFunction("puts",ski_puts);
    regsiteNativeFunction("inputInt",ski_input_int);
    regsiteNativeFunction("input",ski_input);
    regsiteNativeFunction("inputReal",ski_input_real);
    regsiteNativeFunction("print",ski_print);
    //
    regsiteNativeFunction("sin",ski_sin);
    regsiteNativeFunction("cos",ski_cos);
    regsiteNativeFunction("tan",ski_tan);
    regsiteNativeFunction("sqrt",ski_sqrt);
}