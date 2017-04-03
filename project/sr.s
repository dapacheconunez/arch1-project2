	.arch msp430g2553
	.p2align 1,0
	.text

	.global or_sr
or_sr:  nop
	bis r12, r2
	nop
	ret

