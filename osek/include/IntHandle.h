#ifndef INTHANDLE_H_
#define INTHANDLE_H_

#include "Os.h"
    extern uint8 IntNesting;
    /* Enable processor recognition of interrupts */    /* Set MSR[EE]=1  */
    #if(OS_INTERUUPTION_NESTING == STD_ON)
        #define SUSPEND_INTERRUPTES() asm(" DINT");   //asm(" MVC CSR, B0");asm(" AND -2, B0, B0"); asm(" MVC B0, CSR")
        #define RESUME_INTERRUPTES()  asm(" RINT");   //asm(" MVC CSR, B0");asm(" OR 1, B0, B0"); asm(" MVC B0, CSR")
    #else
        #define RESUME_INTERRUPTES()  asm(" NOP")
        #define SUSPEND_INTERRUPTES() asm(" NOP")
    #endif
     
    #if(OS_INTERRUPT_MODULE == STD_ON)
        #define IntEnter() ++IntNesting //RESUME_INTERRUPTES()    //Support interrupt nesting
        void    OSIntExit(void);
        #define IntExit()  OSIntExit()    //SUSPEND_INTERRUPTES(); OSIntExit()

        #define portDISABLE_INTERRUPTS()	__asm__( " cpsid i" )
        #define portENABLE_INTERRUPTS()		__asm__( " cpsie i" )
        #define taskENTER_CRITICAL() \
                portDISABLE_INTERRUPTS(); \
                ++ IntNesting;
        #define taskEXIT_CRITICAL() \
                if( IntNesting > 0 ) \
                { \
		            IntNesting -- ; \
                    if( IntNesting == 0 ) \
                    { \
                        portENABLE_INTERRUPTS(); \
                    } \
                }
    #else
        #define IntExit()  SUSPEND_INTERRUPTES()
        #define IntEnter() RESUME_INTERRUPTES()
    #endif



#endif /*INTHANDLER_H_*/
