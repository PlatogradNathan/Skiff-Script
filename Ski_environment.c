#include "SkiffScript.h"
#include "Ski_interprter.h"
#include <stdio.h>

LocalEnvironment* currentEnv;
LocalEnvironment* preEnv;

void initializeEnvironment()
{
    preEnv = NULL;
    currentEnv = NULL;
}

void openLocalEnvironment(LocalEnvironment* env)
{
    env->outer = currentEnv;
    currentEnv = env;
}

void closeLocalEnvironment()
{
    if(currentEnv != NULL)
    {
        currentEnv = currentEnv->outer;
    }
}

LocalEnvironment* getCurrentEnvironment()
{
    return currentEnv;
}