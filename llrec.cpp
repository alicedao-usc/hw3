#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  if (head == NULL)
  {
    return;
  }

  if ( head -> val <= pivot){
    smaller -> next = head;
    Node *temp = head -> next;
    head -> next = NULL;
    return llpivot(temp, smaller -> next,larger, pivot);
  }

  if (head-> val > pivot){
    larger -> next = head;
    Node *temp = head -> next;
    head -> next = NULL;
    return llpivot(temp, smaller, larger ->next, pivot);


  }



}

