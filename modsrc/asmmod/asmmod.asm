bits 64
; default rel


extern		create_identifier

extern		create_block
extern		create_block_settings
extern		register_block

extern		create_item
extern		create_block_item
extern		create_item_settings
extern		item_settings_max_count
extern		register_item

extern		log_info


global		init:function


section		.rodata
mod_id			db		"asmmod", 0
block_name		db		"asm_block", 0
item_name		db		"asm_item", 0
test_message	db		"Hello from ASM!", 0


section		.text
init:
	push	rbp
	mov		rbp,	rsp




	lea		rax,	[rel test_message]
	mov		rdi,	rax
	call	log_info				wrt		..plt



	; Create Block
	call	create_block_settings	wrt		..plt
	

	mov		rdi,	rax
	call	create_block			wrt		..plt
	mov		rbx,	rax


	lea		rax,	[rel mod_id]
	mov		rdi,	rax
	lea		rax,	[rel block_name]
	mov		rsi,	rax
	call	create_identifier		wrt		..plt


	mov		rdi,	rax
	mov		rsi,	rbx
	call	register_block			wrt		..plt



	; Create Block Item
	call	create_item_settings	wrt		..plt
	

	mov		rdi,	rbx
	mov		rsi,	rax
	call	create_block_item		wrt		..plt
	mov		rbx,	rax


	lea		rax,	[rel mod_id]
	mov		rdi,	rax
	lea		rax,	[rel block_name]
	mov		rsi,	rax
	call	create_identifier		wrt		..plt


	mov		rdi,	rax
	mov		rsi,	rbx
	call	register_item			wrt		..plt



	; Create Item
	call	create_item_settings	wrt		..plt

	mov		rdi,	rax
	mov		rsi,	42
	call	item_settings_max_count	wrt		..plt
	

	mov		rdi,	rax
	call	create_item				wrt		..plt
	mov		rbx,	rax


	lea		rax,	[rel mod_id]
	mov		rdi,	rax
	lea		rax,	[rel item_name]
	mov		rsi,	rax
	call	create_identifier		wrt		..plt


	mov		rdi,	rax
	mov		rsi,	rbx
	call	register_item			wrt		..plt




	lea		rax,	[rel mod_id]
	pop		rbp
	ret