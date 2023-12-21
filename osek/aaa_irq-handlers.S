.macro vic0_irq_handlers, num
.if \num
	vic0_irq_handlers "(\num-1)"

	push	{r0-r3, ip, lr}
	bl	spe_vic0_dispatch
.endif
.endm

.macro vic1_irq_handlers, num
.if \num
	vic1_irq_handlers "(\num-1)"

	push	{r0-r3, ip, lr}
	bl	spe_vic1_dispatch
.endif
.endm

	.section .text
	.global spe_vic0_vectors
	.global spe_vic0_vectors_end
	.global spe_vic1_vectors
	.global spe_vic1_vectors_end
spe_vic0_dispatch:
	adr	r0, (spe_vic0_vectors + 8)
	sub	r0, lr, r0
	lsr	r0, r0, #3
	bl	spe_vic0_irq_handler
	b	irq_end
spe_vic0_vectors:
	vic0_irq_handlers	32
spe_vic0_vectors_end:
spe_vic1_dispatch:
	adr	r0, (spe_vic1_vectors + 8)
	sub	r0, lr, r0
	lsr	r0, r0, #3
	bl	spe_vic1_irq_handler
	b	irq_end
spe_vic1_vectors:
	vic1_irq_handlers	32
spe_vic1_vectors_end: