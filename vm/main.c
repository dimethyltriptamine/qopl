#include <stdio.h>
#include <stdlib.h>

#include "stackvm.h"

#define add 0x40000001
#define sub 0x40000002
#define mul 0x40000003
#define div 0x40000004
#define halt 0x40000000

int
main(void)
{
	StackVM *vm = init_vm();
	i32 prog[] = { 0, 3, add, 32, 5, 2, mul, halt };
	int size = sizeof(prog) / sizeof(i32);
	run_program(vm, prog, size);
	run(vm);
	return 0;
}
