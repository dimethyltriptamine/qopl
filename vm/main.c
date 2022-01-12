#include <stdio.h>
#include <stdlib.h>

#include "stackvm.h"


int
main(void)
{
	StackVM *vm = init_vm();
     i32 prog[7] = {0,3,0x40000004, 5,5,0x40000001, 0x40000000};
	run_program(vm,prog,7);
	run(vm);
	return 0;
}
