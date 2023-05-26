# Monty project

The Monty project is a group project offered by ALX Software Engineering program. It involves creating an interpreter for Monty ByteCodes files using the C programming language. The Monty language is a scripting language that relies on a unique stack and provides specific instructions to manipulate it.

# Project Overview

The Monty interpreter reads Monty ByteCodes files, which typically have the .m extension. Each line in the bytecode file represents an opcode and its optional argument. The interpreter executes the bytecodes line by line, manipulating the stack based on the specified instructions.

To compile the Monty interpreter, use the following command:
 <pre>
<code>
 gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
</code>
</pre>

To run the Monty interpreter, provide the path to the Monty bytecode file as the argument:
 <pre>
<code>
./monty &lt;path-to-bytecode-file&gt;
</code>
</pre>

# Usage and Supported Opcodes
The Monty interpreter supports the following opcodes.\
 push <value>:  Pushes an integer value to the stack.\
pall:  Prints all values on the stack.\
pint:  Prints the value at the top of the stack.\
pop:  Removes the top element from the stack.\
swap:  Swaps the top two elements of the stack.\
add:  Adds the top two elements of the stack.\
sub:  Subtracts the top element of the stack from the second top element.\
div:  Divides the second top element of the stack by the top element.\
mul:  Multiplies the top two elements of the stack.\
mod:  Computes the modulus of the second top element divided by the top element.
  
  # Error Handling
  
The Monty interpreter includes error handling mechanisms. If an error occurs during the execution, such as an invalid instruction, stack underflow, or memory allocation failure, the interpreter will print an error message to stderr and exit with the status code EXIT_FAILURE

 # Contribution
This project is a group effort developed by ALX Software Engineering students [3k3n3](https://https://github.com/3k3n3) and [Gold Israel](https://github.com/TechieGold23).\
 Contributions are welcome via pull requests. If you find any issues or have suggestions for improvement, please create an issue in the project repository.

# Credits
The Monty project is a part of the ALX Software Engineering program. It is based on the Monty language and the project requirements provided by ALX.


