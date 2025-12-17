# infix_to_postfix
PROJECT_OVERVIEW
This project implements Infix to Postfix expression conversion using the C programming language.
The conversion is done with the help of a stack data structure, following standard operator precedence and associativity rules.
>>What is Infix and Postfix?
Infix Expression
Operators are written between operands
Example: A + B
Postfix Expression 
Operators are written after operands
Example: AB+
Postfix expressions are easier for computers to evaluate because they do not require parentheses.

>>Features
Supports operators: + , - , * , / , ^
Handles parentheses ( and )
Uses stack implementation
Follows correct operator precedence
Simple and beginner-friendly code

>>Algorithm Used
Initialize an empty stack.
Scan the infix expression from left to right.
If the symbol is an operand, add it to the postfix expression.
If the symbol is (, push it onto the stack.
If the symbol is ), pop operators from the stack until ( is found.
If the symbol is an operator:
Pop operators from the stack with higher or equal precedence
Push the current operator onto the stack
After scanning the expression, pop all remaining operators from the stack.

>>Technologies Used
Programming Language: C
Concept: Stack, Expression Conversion

Compiler: GCC

📂 File Structure
.
├── infix_to_postfix.c
└── README.md

>>How to Run
Compile the program:
gcc infix_to_postfix.c -o infix
Run the executable:
./infix
