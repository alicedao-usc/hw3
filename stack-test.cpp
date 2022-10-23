#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <string> 
#include <stdexcept>
#include "stack.h"
using namespace std;

int main() 
{ 
    try 
        { 
        Stack<int>      intStack;   // stack of ints 
        Stack<string>   stringStack;    // stack of strings 

        // manipulate int stack 
        intStack.push( 7 ); 
        cout << "After pushing int stack once the top is " << intStack.top() <<endl; 
				intStack.push( 13); 
        cout << "After pushing int stack twice the top is " << intStack.top() <<endl; 
				intStack.push( 6 ); 
        cout << "After pushing int stack thrice the top is " << intStack.top() <<endl; 
				intStack.pop(); 
        cout << "After popping int stack once the top is " << intStack.top() <<endl; 
				intStack.pop(); 
        cout << "After popping int stack twice the top is " << intStack.top() <<endl; 
				intStack.pop(); 

        // manipulate string stack 
        stringStack.push( "hello" ); 
				cout << "After pushing once, the top of the stack is " << stringStack.top() << std::endl; 
        stringStack.push( "world" ); 
        cout << "After pushing twice, the top of the stack is " << stringStack.top() << std::endl; 
        stringStack.pop(); 
        cout << "After popping once, the top of the stack is " << stringStack.top() << std::endl; 
        stringStack.pop(); 
        cout << "The size of the stack is now: " << stringStack.size() << std::endl;
        cout << stringStack.top() << std::endl; 

        cout << "The size of the stack is now: " << stringStack.size() << std::endl;

        return 0;

    } 
    catch ( exception const& ex ) 
    { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1; 

    } 

} 