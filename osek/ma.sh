# !/bin/bash
CFLAGS="-mcpu=cortex-r5 -mthumb-interwork \
-mfloat-abi=softfp -mfpu=vfpv3-d16 \
-std=c99 \
-I ./include/"

/home/kenaml/arm-none-eabi-gcc/bin/arm-none-eabi-gcc -o test.elf boot.S aaa_irq-handlers.S armv7-exceptions.S armv7-exception.c aaa_irq.c aaa_clock.c aaa_hsp.c \
                                                        cache-cortex-r5.c aaa_debug_init.c aaa_queue.c aaa_semphr.c aaa_vic.c aaa_print.c main.c App_Cfg.c IntHandle.c \
                                                        MY_Task.c NonPlat_Lib.c Os_Alarm.c Os_Core.c Os_Counter.c OS_Cpu_A.s Os_Cpu_C.c Os_Evt.c Os_Hook.c Os_Main.c Os_Res.c \
                                                        Os_Task.c Osek.c \
                                                        -Tspe.ld.in -nostartfiles \
                                                        $CFLAGS

/home/kenaml/arm-none-eabi-gcc/bin/arm-none-eabi-objcopy -O binary test.elf spe.bin