// Graph.cpp - Implementation file
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "Stack.cpp"
using namespace std;

// Node struct for linked list
struct Node {
    string key; 
    int value;
    Node* next; 
    Node(string k, int v) : key(k), value(v), next(nullptr) {} // Constructor
};

// HashTable struct
struct HashTable {
    Stack scope; // Stack for storing values
    Node* table[SIZE]; 

    HashTable();
    ~HashTable();
    int hash(string key); 
    void enterScope();
    void exitScope();
    void declareVar(string key);
    void assignVar(string key, int value);
    string printVar(string key);
    void increamentVar(string key, int value);
    int applyOperator(char operation, string key, int value);
    bool checkScope(string key) {
        return scope.checkVar(key); // Check if variable exists in the current scope
    }

};

// HashTable constructor
HashTable::HashTable() {
    // Initialize all elements to -1 (empty)
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr; 
    }
}

// HashTable destructor
HashTable::~HashTable() {}

// Hash function to map value to index
int HashTable::hash(string key) {
    int sum = 0;
    for (int i = 0; i < key.size(); ++i)
        sum += (i + 1) * key[i];
    return sum % SIZE;
}

// Enter a new scope
void HashTable::enterScope() {
    scope.push(); // Push a new scope onto the stack
}

// Exit the current scope
void HashTable::exitScope() {
    if (!scope.isEmpty()) {
        scope.pop(); // Pop the current scope from the stack
    } else {
        cout << "No scope to exit." << endl; // Error message if no scope to exit
    } 
}

// Declare a new variable
void HashTable::declareVar(string key) {
    scope.addVar(key); // Push the variable onto the stack

    int index = hash(key); // Get the index for the key
    Node* newNode = new Node(key, 0); // Create a new node

    // Insert the new node into the linked list at the index
    if (table[index] == nullptr) {
        table[index] = newNode; // If empty, insert directly
    } else {
        Node* current = table[index];
        while (current->next != nullptr) {
            current = current->next; // Traverse to the end of the list
        }
        current->next = newNode; // Insert at the end of the list
    }
}

// Assign a value to a variable
void HashTable::assignVar(string key, int value) {
    int index = hash(key); // Get the index for the key
    Node* current = table[index]; // Get the linked list at the index

    // Traverse the linked list to find the variable
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value; // Assign the value to the variable
            return;
        }
        current = current->next; // Move to the next node
    }
    cout << "Variable not found." << endl; // Error message if variable not found
}

// Print the value of a variable
string HashTable::printVar(string key) {
    // Check if variable exists in the current scope
    if (!checkScope(key)) {
        return key + " IS UNDEFINED\n"; // Variable is undefined
    }

    int index = hash(key); // Get the index for the key
    Node* current = table[index]; // Get the linked list at the index

    // Traverse the linked list to find the variable
    while (current != nullptr) {
        if (current->key == key) {
            return key + " IS " + to_string(current->value) + "\n";
        }
        current = current->next; // Move to the next node
    }
    return key + " IS UNDEFINED\n"; // Variable is undefined
}

// Traverse the linked list and perform an operation
int HashTable::applyOperator(char operation, string key, int value) {
    // Check if variable exists in the current scope
    if (!checkScope(key)) {
        return -1;
    }

    int num = 0;
    int index = hash(key); // Get the index for the key
    Node* current = table[index]; // Get the linked list at the index

    // Traverse the linked list to find the variable
    while (current != nullptr) {
        if (current->key == key) {
            switch (operation) {
                case '+':
                    num = current->value + value; // Increment the value
                    break;
                case '-':
                    num = current->value - value; // Decrement the value
                    break;
                case '*':
                    num = current->value * value; // Multiply the value by 2
                    break;
                case '/':
                    num = current->value / value; // Divide the value by 2
                    break;
                case '%':
                    num = current->value % value; // Modulus operation
                    break;
                case '^':
                    num = current->value ^ value; // Bitwise XOR operation
                    break;
                default:
                    cout << "Invalid operation." << endl; // Error message for invalid operation
            }
            return num;
        }
        current = current->next; // Move to the next node
    }
    cout << "Variable not found." << endl; // Error message if variable not found
    return -1;
}


// Increment or decrement the value of a variable
void HashTable::increamentVar(string key, int value) {
    int index = hash(key); // Get the index for the key
    Node* current = table[index]; // Get the linked list at the index

    // Traverse the linked list to find the variable
    while (current != nullptr) {
        if (current->key == key) {
            current->value += value; // Increment or decrement the value
            return;
        }
        current = current->next; // Move to the next node
    }
    cout << "Variable not found." << endl; // Error message if variable not found
}



#endif