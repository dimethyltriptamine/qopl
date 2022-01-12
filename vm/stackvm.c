#include <stdio.h>
#include <stdlib.h>
#include "stackvm.h"

/* INSTRUCTION FORMAT 
 * Header: 2 bits
 * Data: 30 bits
 *
 * Header format:
 * 0 -> positive int
 * 1 -> primitive instruction
 * 2 -> negative int
 * 3 -> undefined
 */

StackVM
*init_vm()
{
	i32 *memory = malloc(1000000);
	StackVM *vm = malloc(sizeof(StackVM));
	
	vm->pc  = 100;
	vm->sp  = 0;
	vm->typ = 0;
	vm->dat = 0;
	vm->running = 1;
	vm->memory = memory;

	return vm;
}

i32
get_type(i32 instruction)
{
	i32 type = 0xC0000000;
	type = (type & instruction) >> 30;
	return type;

}

i32
get_data(i32 instruction)
{
	i32 data = 0x3FFFFFF;
	data = data & instruction;
	return data;
}

void
fetch(StackVM *vm)
{
	vm->pc++;
}

void
decode(StackVM *vm)
{
	vm->typ = get_type(vm->memory[vm->pc]);
	vm->dat = get_data(vm->memory[vm->pc]);

}

void
execute(StackVM *vm)
{
	/* Positive or negative int */
	if(vm->typ == 0 || vm->typ == 2) {
		vm->sp++;
		vm->memory[vm->sp] = vm->dat;
	} else {
		do_primitive(vm);
	}
}

void
do_primitive(StackVM *vm)
{
	switch(vm->dat) {
	case 0: /* halt */
		printf("halted\n");
		vm->running = 0;
		break;
	case 1: /* add */
		printf("Adding %i %i\n",vm->memory[vm->sp - 1],
			  vm->memory[vm->sp]
			);
		vm->memory[vm->sp - 1] = vm->memory[vm->sp - 1] + vm->memory[vm->sp];
		vm->sp--;
		break;
	case 2: /* substract */
		printf("Substracting %i %i\n",vm->memory[vm->sp - 1],
			  vm->memory[vm->sp]
			);
		vm->memory[vm->sp - 1] = vm->memory[vm->sp - 1] - vm->memory[vm->sp];
		vm->sp--;
		break;

	case 3: /* multiply */
		printf("Multiplying %i %i\n",vm->memory[vm->sp - 1],
			  vm->memory[vm->sp]
			);
		vm->memory[vm->sp - 1] = vm->memory[vm->sp - 1] * vm->memory[vm->sp];
		vm->sp--;
		break;
	case 4: /* divide */
		printf("Dividing %i %i\n",vm->memory[vm->sp - 1],
			  vm->memory[vm->sp]
			);
		vm->memory[vm->sp - 1] = vm->memory[vm->sp - 1] * vm->memory[vm->sp];
		vm->sp--;
		break;

	}

}

void
run(StackVM *vm)
{
	vm->pc -= 1;
	while(vm->running) {
		fetch(vm);
		decode(vm);
		execute(vm);
		printf("ToS: %i\n", vm->memory[vm->sp]);
	}

}

void
run_program(StackVM *vm, i32 *prog, int size)
{
	for(i32 i = 0; i < size; i++) 
		vm->memory[vm->pc + i] = prog[i];

}
