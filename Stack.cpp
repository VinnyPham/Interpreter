// List.cpp 
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 50;

// Scope struct
struct Scope {
    string data[SIZE]; // Array to store data
    int count = 0; // Count of items in the scope

    void addVar(string var) {
        data[count] = var; // Add variable to the scope
        count++;
    }

    void printVar() {
        for (int i = 0; i < count; i++) {
            cout << data[i] << " "; // Print all variables in the scope
        }
        cout << endl;
    }
};

// Node struct
struct ScopeNode {
    Scope scope;
    ScopeNode* next;

    // Node constructor
    ScopeNode() {
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    ScopeNode* top;

public:
    Stack();
    ~Stack();
    void push();
    void pop();
    bool isEmpty();
    void addVar(string var);
    bool checkVar(string var);
    void printVar() {
        if (top) {
            top->scope.printVar(); // Print variables in the current scope
        } else {
            cout << "No variables in the current scope." << endl;
        }
    }
};

// Constructor
Stack::Stack() {
    top = nullptr;
}

// Destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop(); // Pop all nodes from the stack
    }
}

// Pushes a new node onto the stack
void Stack::push() {
    // Create a new node
    ScopeNode* newNode = new ScopeNode();

    // Add the new node to the top of the stack
    if (isEmpty()) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }

}                        

// Pops the top node from the stack
void Stack::pop() {
    if (top) {
        ScopeNode* temp = top;
        top = top->next;
        delete temp;
    }
}                         

// Checks if the stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}           

// Adds a variable to the current scope
void Stack::addVar(string var) {
    if (top) {
        top->scope.addVar(var); // Add variable to the current scope
    } 
}                        

// Checks if a variable exists in any scope
bool Stack::checkVar(string var) {
    ScopeNode* current = top;

    while (current) {
        for (int i = 0; i < current->scope.count; i++) {
            if (current->scope.data[i] == var) {
                return true; // Variable found in the current scope                
            }
        }
        current = current->next; // Move to the next node
    }
    return false; // Variable not found in any scope

}                  

#endif