#ifndef STACK_VM_H
#define STACK_VM_H
#include <stdint.h>

typedef int32_t i32;

typedef struct StackVM {
	i32 pc; /* program counter  */
	i32 sp; /* stack pointer */
	i32 *memory; /* i32 allocated mem */
	i32 typ;
	i32 dat;
	i32 running;
	

}StackVM;

/* Who needs OOP anyways? */


/* As, thanfully, C doesn't have RAII, a init function is necessary,
 * so it inits the struct with all the necessary values and data.
 */

StackVM
*init_vm();

i32
get_type(i32 instruction);
i32
get_data(i32 instruction);

void
fetch(StackVM *vm);

void
decode(StackVM *vm);

void
execute(StackVM *vm);

void
do_primitive(StackVM *vm);

void
run(StackVM *vm);

void
run_program(StackVM *vm, i32 *prog, int size);


#endif
