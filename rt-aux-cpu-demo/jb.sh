export TOP=/home/kenaml/source/l4t-rt
export OUTDIR=/home/kenaml/source/l4rt_modify/l4t-rt/out
export CROSS_COMPILE=/home/kenaml/arm-none-eabi-gcc/bin/arm-none-eabi-
export FREERTOS_DIR=/home/kenaml/source/l4rt_modify/l4t-rt/FreeRTOSV8.1.2/FreeRTOS/Source
export FREERTOS_COMMON_DIR=/home/kenaml/source/l4rt_modify/l4t-rt/freertos-common
make clean
make TARGET=t19x
