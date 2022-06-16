# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## The monty program

- Usage: monty file
	- where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
	- where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
	- where is the line number where the instruction appears.
	- Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
	- it executed properly every line of the file
	- it finds an error in the file
	- an error occured
- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)




### 0x19. C - Stacks, Queues - LIFO, FIFO

#### General

##### What do LIFO and FIFO mean?

- FIFO (“First In, First Out”) `: means “first in, first out”. For example, this system is ideal for the storage of perishable producers, which in addition to their placement by ranges or families, must be placed in such a way that the first to come out are the closest to their expiration date. There are also the LILO ("Last In, Last Out").

- LIFO (“Last In, First Out”) `: means “last in, first out”. For example, this is the perfect system for non-perishable products that do not have an expiration date. There are also the FILO ("First In, Last Out").

##### What is a stack, and when to use it?

- Stack is a structure where we store data and use it in 2 ways FILO (First-in Last-out) and LIFO (Last-in First-out) where a stack is first accumulated and the data is removed from the last input. Use a battery when you want to take things out in the reverse order you put them in.

##### What is a queue, and when to use it?
- Queue is a data structure and we use it in 2 ways FIFO (First-in First-out) and LILO (Last-in Last-out) where first it is accumulating in the queue and the data is removed from the first input. Use a tail when you want to take things out in the order you put them in.

##### What are the common implementations of stacks and queues?
> More information: https://es.slideshare.net/nieves1988/estructura-datos-pilas-y-colas - automatic![Stack and Queue]

**STACKS**: Arithmetic Expressions, Operations (Power, Multiplication, Divide, Addition, Subtraction, Infix Notation, Prefix Notation, Postfix Notation), Recursive Functions, Program Sequence Control (A subprogram runs completely before returning to the point where it was called).

**QUEUES**: There are 4 types of Queues:

	- **Simple Tail**: Linear structure where the elements leave in the same order in which they arrive.

	- **Circular Tail**: Logical Representation of a Simple Queue in an Array

	- **Priority Queue**: Linear structure in which the elements are inserted in any position of the queue and are removed only from the front.

	- **Double Tail**: Linear structure in which elements can be added or removed at either end of the tail.

*Queue Implementation: Arrangement, Linked Lists.*

##### What are the most common use cases of stacks and queues?
**STACKS**: Arithmetic Expressions, Operations, Recursive Functions, Program Sequence Control.
**QUEUES**: Arrangement, Linked Lists.

##### What is the proper way to use global variables?

Global variables should be used when multiple functions need to access the data or write to an object. For example, if you had to pass data or a reference to multiple functions such as a single log file, a connection pool, or a hardware reference that needs to be accessed across the application. This prevents very long function declarations and large allocations of duplicated data.

You should typically not use global variables unless absolutely necessary because global variables are only cleaned up when explicitly told to do so or your program ends. If you are running a multi-threaded application, multiple functions can write to the variable at the same time. If you have a bug, tracking that bug down can be more difficult because you don't know which function is changing the variable. You also run into the problem of naming conflicts unless you use a naming convention that explicitly gives global variables a unique name.


