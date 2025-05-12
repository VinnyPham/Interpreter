/* 
===============================================================
How to use the program:
1. Compile the code using a C++ compiler.
2. Run the program.
3. Enter commands in the format:
   - START
   - VAR <variable_name> = <value>
   - PRINT <variable_name>
   - <variable_name> = <value>
   - <variable_name> ++
   - <variable_name> --
   - FINISH
===============================================================
Programmer: Vinny Pham
Date: 05/12/2025
===============================================================

*/ 
#include <iostream>
#include <string>
#include <sstream>
#include "HashTable.cpp"
using namespace std;

void interpret(string input, HashTable& variable);

//====main======================================================
//
//==============================================================
int main() {
    HashTable variable; // Create a hash table for variables
    string input; // Input string

    cout << "Enter commands: \n";
    while (getline(cin, input)) { 
        if (!input.empty()) {
            interpret(input, variable); // Interpret the input
        }
    }

    return 0;
}                     // end of main()
//==============================================================


//====interpret=================================================
// This function interprets the input commands and performs the corresponding operations on the hash table.
//
// Parameters:
// - input: The input command string.
// - variable: The hash table object to perform operations on.
//==============================================================
void interpret(string input, HashTable& variable) {
    int value;
    string operation;
    string var;
    string command;
    stringstream stream(input); 
    stream >> command; // Read the first word from the input

    if (command == "START") {
        variable.enterScope();
    } else if (command == "FINISH") {
        variable.exitScope();
    } else if (command == "VAR") {
        stream >> var;
        variable.declareVar(var); 
        stream >> operation;
        if (operation == "=") {
            stream >> value; // Read the value to assign
            variable.assignVar(var, value); // Assign the value to the variable
        }
    } else if (command == "PRINT") {
        stream >> var;
        if (stream >> operation) {
            int num = 0;
            stream >> value;
            if (operation == "+") {
                num = variable.applyOperator('+', var, value); // Add the variable to the current variable
                cout << var << " + " << value << " IS " << num << endl << endl;
            } else if (operation == "-") {
                num = variable.applyOperator('-', var, value); // Subtract the variable from the current variable
                cout << var << " - " << value << " IS " << num << endl << endl;
            } else if (operation == "*") {
                num = variable.applyOperator('*', var, value); // Multiply the variable by the current variable
                cout << var << " * " << value << " IS " << num << endl << endl;
            } else if (operation == "/") {
                num = variable.applyOperator('/', var, value); // Divide the variable by the current variable
                cout << var << " / " << value << " IS " << num << endl << endl;
            } else if (operation == "%") {
                num = variable.applyOperator('%', var, value); // Modulus the variable by the current variable
                cout << var << " % " << value << " IS " << num << endl << endl;
            } else if (operation == "^") {
                num = variable.applyOperator('^', var, value); // Exponentiate the variable by the current variable
                cout << var << " ^ " << value << " IS " << num << endl << endl;
            }
        } else {
            string print = variable.printVar(var); // Print the variable
            cout << print << endl; // Output the variable value
        } 
    } else if (variable.checkScope(command)) {
        stream >> operation; // Read the operation

        if (operation == "=") {
            stream >> value; // Read the value to assign
            variable.assignVar(command, value); // Assign the value to the variable
        } else if (operation == "++") {
            variable.increamentVar(command, 1); // Add the variable to the current variable
        } else if (operation == "--") {
            variable.increamentVar(command, -1); // Subtract the variable from the current variable
        }
    }
}                 // end of interpret()
//==============================================================


/*
Output:
Test Run 1:
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
*/