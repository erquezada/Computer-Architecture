	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 15, 0
	.globl	_multiply                       ; -- Begin function multiply
	.p2align	2
_multiply:                              ; @multiply
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp, #28]
	str	w1, [sp, #24]
	ldr	w8, [sp, #28]
	str	w8, [sp, #20]
	ldr	w8, [sp, #24]
	str	w8, [sp, #16]
	str	wzr, [sp, #12]
	str	wzr, [sp, #4]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	subs	w8, w8, #32
	cset	w8, lt
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	b	LBB0_6
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #20]
	and	w8, w8, #0x1
	str	w8, [sp, #8]
	ldr	w8, [sp, #8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w9, [sp, #16]
	ldr	w8, [sp, #12]
	add	w8, w8, w9
	str	w8, [sp, #12]
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #20]
	lsr	w8, w8, #1
	str	w8, [sp, #20]
	ldr	w8, [sp, #16]
	lsl	w8, w8, #1
	str	w8, [sp, #16]
	ldr	w8, [sp, #4]
	add	w8, w8, #1
	str	w8, [sp, #4]
	b	LBB0_1
LBB0_6:
	ldr	w0, [sp, #12]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_divide                         ; -- Begin function divide
	.p2align	2
_divide:                                ; @divide
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #40]
	str	x1, [sp, #32]
	str	w2, [sp, #28]
	str	w3, [sp, #24]
	str	wzr, [sp, #16]
	str	wzr, [sp, #12]
	mov	w8, #31
	str	w8, [sp, #20]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #20]
	subs	w8, w8, #0
	cset	w8, ge
	tbnz	w8, #0, LBB1_3
	b	LBB1_2
LBB1_2:
	b	LBB1_8
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	lsl	w8, w8, #1
	str	w8, [sp, #12]
	ldr	w8, [sp, #28]
	ldr	w9, [sp, #20]
	lsr	w8, w8, w9
	str	w8, [sp, #8]
	ldr	w8, [sp, #8]
	and	w8, w8, #0x1
	str	w8, [sp, #4]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #4]
	orr	w8, w8, w9
	str	w8, [sp, #12]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #24]
	subs	w8, w8, w9
	cset	w8, lo
	tbnz	w8, #0, LBB1_5
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_6
LBB1_5:                                 ;   in Loop: Header=BB1_1 Depth=1
	b	LBB1_7
LBB1_6:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #24]
	subs	w8, w8, w9
	str	w8, [sp, #12]
	ldr	w8, [sp, #16]
	ldr	w10, [sp, #20]
	mov	w9, #1
	lsl	w9, w9, w10
	orr	w8, w8, w9
	str	w8, [sp, #16]
	b	LBB1_7
LBB1_7:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #20]
	subs	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB1_1
LBB1_8:
	ldr	w8, [sp, #16]
	ldr	x9, [sp, #40]
	str	w8, [x9]
	ldr	w8, [sp, #12]
	ldr	x9, [sp, #32]
	str	w8, [x9]
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_convert                        ; -- Begin function convert
	.p2align	2
_convert:                               ; @convert
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	.cfi_def_cfa_offset 64
	str	x0, [sp, #56]
	str	w1, [sp, #52]
	ldr	w8, [sp, #52]
	str	w8, [sp, #48]
	ldr	w8, [sp, #48]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_2
	b	LBB2_1
LBB2_1:
	b	LBB2_11
LBB2_2:
	ldr	x8, [sp, #56]
	str	x8, [sp, #32]
	b	LBB2_3
LBB2_3:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #48]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB2_5
	b	LBB2_4
LBB2_4:
	b	LBB2_6
LBB2_5:                                 ;   in Loop: Header=BB2_3 Depth=1
	ldr	w8, [sp, #48]
	mov	w9, #10
	udiv	w10, w8, w9
	mul	w10, w10, w9
	subs	w8, w8, w10
	str	w8, [sp, #44]
	ldr	w8, [sp, #48]
	udiv	w8, w8, w9
	str	w8, [sp, #48]
	ldr	w8, [sp, #44]
	add	w8, w8, #48
	ldr	x9, [sp, #32]
	strb	w8, [x9]
	ldr	x8, [sp, #32]
	add	x8, x8, #1
	str	x8, [sp, #32]
	b	LBB2_3
LBB2_6:
	ldr	x8, [sp, #32]
	strb	wzr, [x8]
	ldr	x8, [sp, #32]
	subs	x8, x8, #1
	str	x8, [sp, #32]
	ldr	x8, [sp, #56]
	str	x8, [sp, #24]
	ldr	x8, [sp, #32]
	str	x8, [sp, #16]
	b	LBB2_7
LBB2_7:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #16]
	subs	x8, x8, x9
	cset	w8, lo
	tbnz	w8, #0, LBB2_9
	b	LBB2_8
LBB2_8:
	b	LBB2_10
LBB2_9:                                 ;   in Loop: Header=BB2_7 Depth=1
	ldr	x8, [sp, #24]
	ldrb	w8, [x8]
	strb	w8, [sp, #15]
	ldr	x8, [sp, #16]
	ldrb	w8, [x8]
	ldr	x9, [sp, #24]
	strb	w8, [x9]
	ldrb	w8, [sp, #15]
	ldr	x9, [sp, #16]
	strb	w8, [x9]
	ldr	x8, [sp, #24]
	add	x8, x8, #1
	str	x8, [sp, #24]
	ldr	x8, [sp, #16]
	subs	x8, x8, #1
	str	x8, [sp, #16]
	b	LBB2_7
LBB2_10:
	b	LBB2_12
LBB2_11:
	ldr	x8, [sp, #56]
	str	x8, [sp, #32]
	ldr	x9, [sp, #32]
	mov	w8, #48
	strb	w8, [x9]
	ldr	x8, [sp, #32]
	add	x8, x8, #1
	str	x8, [sp, #32]
	ldr	x8, [sp, #32]
	strb	wzr, [x8]
	b	LBB2_12
LBB2_12:
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #272
	.cfi_def_cfa_offset 272
	stp	x28, x27, [sp, #240]            ; 16-byte Folded Spill
	stp	x29, x30, [sp, #256]            ; 16-byte Folded Spill
	add	x29, sp, #256
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	.cfi_offset w27, -24
	.cfi_offset w28, -32
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-24]
	str	wzr, [sp, #108]
	sub	x0, x29, #60
	adrp	x1, l___const.main.a@PAGE
	add	x1, x1, l___const.main.a@PAGEOFF
	mov	x2, #36
	str	x2, [sp, #88]                   ; 8-byte Folded Spill
	bl	_memcpy
	ldr	x2, [sp, #88]                   ; 8-byte Folded Reload
	sub	x0, x29, #96
	adrp	x1, l___const.main.b@PAGE
	add	x1, x1, l___const.main.b@PAGEOFF
	bl	_memcpy
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	str	wzr, [sp, #104]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #104]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB3_4
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldrsw	x8, [sp, #104]
	sub	x9, x29, #60
	ldr	w10, [x9, x8, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [sp, #72]                   ; 8-byte Folded Spill
	ldrsw	x10, [sp, #104]
	sub	x8, x29, #96
	ldr	w11, [x8, x10, lsl #2]
                                        ; implicit-def: $x10
	mov	x10, x11
	str	x10, [sp, #80]                  ; 8-byte Folded Spill
	ldrsw	x10, [sp, #104]
	ldr	w0, [x9, x10, lsl #2]
	ldrsw	x9, [sp, #104]
	ldr	w1, [x8, x9, lsl #2]
	bl	_multiply
	ldr	x10, [sp, #72]                  ; 8-byte Folded Reload
	ldr	x8, [sp, #80]                   ; 8-byte Folded Reload
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
                                        ; implicit-def: $x8
	mov	x8, x0
	str	x8, [x9, #16]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	b	LBB3_3
LBB3_3:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	w8, [sp, #104]
	add	w8, w8, #1
	str	w8, [sp, #104]
	b	LBB3_1
LBB3_4:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	str	wzr, [sp, #104]
	b	LBB3_5
LBB3_5:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #104]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB3_8
	b	LBB3_6
LBB3_6:                                 ;   in Loop: Header=BB3_5 Depth=1
	ldrsw	x9, [sp, #104]
	sub	x8, x29, #60
	str	x8, [sp, #56]                   ; 8-byte Folded Spill
	ldr	w2, [x8, x9, lsl #2]
	ldrsw	x9, [sp, #104]
	sub	x8, x29, #96
	str	x8, [sp, #64]                   ; 8-byte Folded Spill
	ldr	w3, [x8, x9, lsl #2]
	add	x0, sp, #100
	add	x1, sp, #96
	bl	_divide
	ldr	x9, [sp, #56]                   ; 8-byte Folded Reload
	ldr	x8, [sp, #64]                   ; 8-byte Folded Reload
	ldrsw	x10, [sp, #104]
	ldr	w9, [x9, x10, lsl #2]
                                        ; implicit-def: $x12
	mov	x12, x9
	ldrsw	x9, [sp, #104]
	ldr	w8, [x8, x9, lsl #2]
                                        ; implicit-def: $x11
	mov	x11, x8
	ldr	w8, [sp, #100]
                                        ; implicit-def: $x10
	mov	x10, x8
	ldr	w9, [sp, #96]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x12, [x9]
	str	x11, [x9, #8]
	str	x10, [x9, #16]
	str	x8, [x9, #24]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	b	LBB3_7
LBB3_7:                                 ;   in Loop: Header=BB3_5 Depth=1
	ldr	w8, [sp, #104]
	add	w8, w8, #1
	str	w8, [sp, #104]
	b	LBB3_5
LBB3_8:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.6@PAGE
	add	x0, x0, l_.str.6@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	add	x0, sp, #112
	adrp	x1, l___const.main.nums@PAGE
	add	x1, x1, l___const.main.nums@PAGEOFF
	mov	x2, #36
	bl	_memcpy
	str	wzr, [sp, #104]
	b	LBB3_9
LBB3_9:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #104]
	subs	w8, w8, #9
	cset	w8, ge
	tbnz	w8, #0, LBB3_12
	b	LBB3_10
LBB3_10:                                ;   in Loop: Header=BB3_9 Depth=1
	ldrsw	x9, [sp, #104]
	add	x8, sp, #112
	str	x8, [sp, #40]                   ; 8-byte Folded Spill
	ldr	w1, [x8, x9, lsl #2]
	sub	x0, x29, #106
	str	x0, [sp, #48]                   ; 8-byte Folded Spill
	bl	_convert
	ldr	x9, [sp, #40]                   ; 8-byte Folded Reload
	ldr	x8, [sp, #48]                   ; 8-byte Folded Reload
	ldrsw	x10, [sp, #104]
	ldr	w9, [x9, x10, lsl #2]
                                        ; implicit-def: $x10
	mov	x10, x9
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	b	LBB3_11
LBB3_11:                                ;   in Loop: Header=BB3_9 Depth=1
	ldr	w8, [sp, #104]
	add	w8, w8, #1
	str	w8, [sp, #104]
	b	LBB3_9
LBB3_12:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	x9, [x29, #-24]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	cset	w8, eq
	tbnz	w8, #0, LBB3_14
	b	LBB3_13
LBB3_13:
	bl	___stack_chk_fail
LBB3_14:
	mov	w0, #0
	ldp	x29, x30, [sp, #256]            ; 16-byte Folded Reload
	ldp	x28, x27, [sp, #240]            ; 16-byte Folded Reload
	add	sp, sp, #272
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @__const.main.a
l___const.main.a:
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	5                               ; 0x5
	.long	7                               ; 0x7
	.long	9                               ; 0x9
	.long	11                              ; 0xb
	.long	25                              ; 0x19
	.long	100                             ; 0x64
	.long	200                             ; 0xc8

	.p2align	2, 0x0                          ; @__const.main.b
l___const.main.b:
	.long	4                               ; 0x4
	.long	3                               ; 0x3
	.long	3                               ; 0x3
	.long	2                               ; 0x2
	.long	9                               ; 0x9
	.long	12                              ; 0xc
	.long	4                               ; 0x4
	.long	1                               ; 0x1
	.long	0                               ; 0x0

	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Multiplication results using multiply():\n"

l_.str.1:                               ; @.str.1
	.asciz	"----------------------------------------------\n"

l_.str.2:                               ; @.str.2
	.asciz	"%d * %d = %d\n"

l_.str.3:                               ; @.str.3
	.asciz	"----------------------------------------------\n\n"

l_.str.4:                               ; @.str.4
	.asciz	"Division results using divide():\n"

l_.str.5:                               ; @.str.5
	.asciz	"%d / %d = %d, remainder = %d\n"

l_.str.6:                               ; @.str.6
	.asciz	"Conversion results using convert():\n"

	.section	__TEXT,__const
	.p2align	2, 0x0                          ; @__const.main.nums
l___const.main.nums:
	.long	0                               ; 0x0
	.long	4294967295                      ; 0xffffffff
	.long	1234                            ; 0x4d2
	.long	982                             ; 0x3d6
	.long	42                              ; 0x2a
	.long	17                              ; 0x11
	.long	624                             ; 0x270
	.long	978                             ; 0x3d2
	.long	16791                           ; 0x4197

	.section	__TEXT,__cstring,cstring_literals
l_.str.7:                               ; @.str.7
	.asciz	"convert(%u) = %s\n"

.subsections_via_symbols
