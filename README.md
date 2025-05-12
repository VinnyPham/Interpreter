# **Interpreter**

## **Overview**
A custom interpreter program written in C++ for a simple programming language called BORG. This interpreter supports variable declarations, arithmetic operations, and basic control structures — all executed from parsed tokens and evaluated using a hash table with chaining for variable storage.

## **Features**
- Parses and executes code written in the BORG language
- Supports integer and float variables
- Basic arithmetic: +, -, *, /
- Variable declarations and assignments
- Hash table implementation with chaining for variable management
- Command-by-command execution with error handling
- Stack to hold the scope of variables 

## **Example Otput**
Enter commands: 
COM HERE IS OUR FIRST BORG PROGRAM
COM WHAT A ROBUST LANGUAGE IT IS
START
VAR BORAMIR = 25
VAR LEGOLAS = 101
PRINT BORAMIR
BORAMIR IS 25

BORAMIR ++
PRINT LEGOLAS
LEGOLAS IS 101

PRINT GANDALF
GANDALF IS UNDEFINED

PRINT BORAMIR * 2
BORAMIR * 2 IS 52

COM
COM NESTED BLOCK
COM
START
VAR GANDALF = 49
PRINT GANDALF
GANDALF IS 49

PRINT BORAMIR
BORAMIR IS 26

FINISH
PRINT GANDALF
GANDALF IS UNDEFINED

START
LEGOLAS = 1000
PRINT LEGOLAS
LEGOLAS IS 1000

FINISH
PRINT LEGOLAS
LEGOLAS IS 1000

LEGOLAS --
PRINT LEGOLAS
LEGOLAS IS 999

FINISH
