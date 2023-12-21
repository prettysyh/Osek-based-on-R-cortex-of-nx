#ifndef SEMPHR
#define SEMPHR

#include "Os.h"
#include "aaa_queue.h"

#define GET_SEM_WAIT_NUM(SEM) ((SEM)->count-1)
#define WAIT_JUDGE(SEM) (((SEM)->count-1) > 0)

typedef struct Sem{
    int count;
    queue WaitIndex;
}Sem,*SemHandle;


void InitSem(SemHandle s);
bool TakeSem(SemHandle s);
bool GiveSem(SemHandle s);




#endif