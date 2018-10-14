@echo off
if exist "skis.exe" (del skis.exe)
gcc lex.yy.c ski_eval.c ski_variable.c y.tab.c ski_error.c ski_debug.c ski_function.c ski_nativefunc.c ski_string.c ski_interpreter.c ski_environment.c -o skis