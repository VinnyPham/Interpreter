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
Enter commands:<br>
COM HERE IS OUR FIRST BORG PROGRAM<br>
COM WHAT A ROBUST LANGUAGE IT IS<br>
START<br>
VAR BORAMIR = 25<br>
VAR LEGOLAS = 101<br>
PRINT BORAMIR<br>
BORAMIR IS 25<br>

BORAMIR ++<br>
PRINT LEGOLAS<br>
LEGOLAS IS 101<br>

PRINT GANDALF<br>
GANDALF IS UNDEFINED<br>

PRINT BORAMIR * 2<br>
BORAMIR * 2 IS 52<br>

COM<br>
COM NESTED BLOCK<br>
COM<br>
START<br>
VAR GANDALF = 49<br>
PRINT GANDALF<br>
GANDALF IS 49<br>

PRINT BORAMIR<br>
BORAMIR IS 26<br>

FINISH<br>
PRINT GANDALF<br>
GANDALF IS UNDEFINED<br>

START<br>
LEGOLAS = 1000<br>
PRINT LEGOLAS<br>
LEGOLAS IS 1000<br>

FINISH<br>
PRINT LEGOLAS<br>
LEGOLAS IS 1000<br>

LEGOLAS --<br>
PRINT LEGOLAS<br>
LEGOLAS IS 999<br>

FINISH<br>
