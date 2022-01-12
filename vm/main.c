#include <stdio.h>
#include <stdlib.h>

#include "stackvm.h"


int
main(void)
{
	StackVM *vm = init_vm();
	int size = 4;
     i32 prog[4] = {33,4,0x40000001, 0x40000000};
	run_program(vm,prog,size);
	run(vm);

}
