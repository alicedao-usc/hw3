#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    // if(argc < 2) {
    //     cout << "Please provide an input file" << endl;
    //     return 1;
    // }

    // // -----------------------------------------------
    // // Feel free to update any code below this point
    // // -----------------------------------------------
    // Node* head = readList(argv[1]);
    // cout << "Original list: ";
    // print(head);

    Node* one = new Node(5, nullptr);
    Node* two = new Node(8, nullptr);
    Node* three = new Node(2, nullptr);
    Node* four = new Node(3, nullptr);
    one->next = two;
    two->next = three;
    three->next = four;
    Node* smaller = new Node(0, nullptr);
    Node* larger = new Node(0, nullptr);
    llpivot(one, smaller, larger, 5);
    cout << "Smaller contents: " << endl;
    
    while(smaller != nullptr){
      cout << smaller->val << " ";
      smaller = smaller->next;
    }

    cout << "Larger contents: " << endl;
    while(larger != nullptr){
      cout << larger->val << " ";
      larger = larger->next;
    }
    // Node* heads = llfilter(one, 1);
    // while(heads != nullptr){
    //   cout << heads->val << " ";
    //   heads = heads->next;
    // }
    // cout << endl;

    
    return 0;

}
