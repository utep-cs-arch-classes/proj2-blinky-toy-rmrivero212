	.arch msp430g2553
	.p2align 1,0
	.text

	.global function_assembly

function_assembly:
	call #state_advance
