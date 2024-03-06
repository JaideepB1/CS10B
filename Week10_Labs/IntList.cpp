#include "IntList.h"

/* Starting from the back of the list this function "bubbles up" values smaller than the value that comes before it
   such that the smallest value in the list will end up at the front of the list.
   The function returns true if any value bubbled up. It returns false if no value was moved by the function. 
   Works by calling a recursive function (defined below).
*/
bool IntList::bubbleUp() {
   if (bubbleUp(head)) {
      return true;
   }

   else {
      return false;
   }
}

/* Recursive helper functions that will (1) go to the back of the list and then 
   (2) recursively bubble up smaller values (values smaller than the value preceding it in the list).
   If any value in the list is swapped, the function should return true, otherwise return false.
*/
bool IntList::bubbleUp(IntNode* curr) {
   if (curr->next == nullptr) {
      return false;
   }

   bool swapVal = bubbleUp(curr->next);

   if (curr->next->value <= curr->value) {
      swap(curr->next->value, curr->value);
      return true;
   }

   return swapVal;
}
