volatile unsigned int * const UART0DR = (unsigned int *)0xc280000;//tx2 is 0x3100000
volatile unsigned int * const ULSR = (unsigned int *)0xc280014;//offset 14
#define UTHR 0x00 /* UART Transmit Holding Register */
#define ULSR_THRE (1 << 5) /* Transmit Holding Register Empty */
#include "Os_Cpu_Types.h"
extern TaskType OSTCBCur;

void print_char(const char *s) {
    while(*s != '\0') { /* Loop until end of string */
		while ((*ULSR & ULSR_THRE) == 0);
        *UART0DR = (unsigned int)(*s); /* Transmit char */
        s++; /* Next char */
    }
}

void print_reg(unsigned int temp)
{
	char str[10];
	str[0]='0';
	str[1]='x';

	int count;
	for (count = 9; count >=2; count--)
	{
		unsigned int num = temp % 16;
		char number;
		if(num<10)
		{
			number = num + '0';
		}
		else
		{
			number =(num-10)+'a';
		}
		str[count] = (char)number;
		temp = temp / 16;
	}
	for (count = 0; count <= 9; count++)
	{
		while ((*ULSR & ULSR_THRE) == 0);
		*UART0DR = (unsigned int)(str[count]);
	}
	print_char("\r\n");
}
void print_normal_reg()
{
	unsigned long lr,sp;
	__asm__(
	"mov %[lr], r14\n\t"
	: [lr] "=r" (lr)
	:
	);
	__asm__(
	"mov %[sp], r15\n\t"
	: [sp] "=r" (sp)
	:
	);
	print_reg(lr);
	print_reg(sp);
}
void print_all()
{
	unsigned int all;
	__asm__(
	"mov %[reg], r0\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r0: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r1\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r1: ");
	print_reg(all);

	__asm__(
	"mov %[reg], r2\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r2: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r3\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r3: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r4\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r4: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r5\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r5: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r6\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r6: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r7\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r7: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r8\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r8: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r9\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r9: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r10\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r10: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r11\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r11: ");
	print_reg(all);

	__asm__(
	"mov %[reg], r12\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r12: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r13\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r13: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r14\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r14: ");
	print_reg(all);
	__asm__(
	"mov %[reg], r15\n\t"
	: [reg] "=r" (all)
	:
	);
	print_char("r15: ");
	print_reg(all);
}


void print_stk(unsigned int *ptos) {
	unsigned int temp = *ptos;
	print_char("spsr: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r0: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r1: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r2: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r3: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r4: ");
	print_reg(temp);
	
	temp = *(++ptos);
	print_char("r5: ");
	print_reg(temp);
	
	temp = *(++ptos);
	print_char("r6: ");
	print_reg(temp);
	
	temp = *(++ptos);
	print_char("r7: ");
	print_reg(temp);
	
	temp = *(++ptos);
	print_char("r8: ");
	print_reg(temp);
	
	temp = *(++ptos);
	print_char("r9: ");
	print_reg(temp);
	
	temp = *(++ptos);
	print_char("r10: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r11: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("r12: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("sp: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("lr: ");
	print_reg(temp);

	temp = *(++ptos);
	print_char("ret addr: ");
	print_reg(temp);
	return;
}

void print_cur(){
	print_stk(OSTCBCur->OSTCBStkCur);
	print_all();
	return ;
}