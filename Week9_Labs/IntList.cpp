#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
   This function does NOT output a newline or space at the end.
*/
ostream & operator<<(ostream &out, const IntList &list) {
   return operator<<(out, list.head);
}

/* Returns true if the integer passed in is contained within the IntList.
   Otherwise returns false.
*/
bool IntList::exists(int inputVal) const {
   return exists(head, inputVal);
}

/* Helper function that returns true if the integer passed in is contained within
   the IntNodes starting from the IntNode whose address is passed in.
   Otherwise returns false.
*/
bool IntList::exists(IntNode *val, int input) const {
   if (val != nullptr) {
      if (val->value == input) {
         return true;
      }

      else {
         exists(val->next, input);
      }
   }

   return false;

}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream &out, IntNode *val) {
   if (val != nullptr) {
      out << val->value << " ";
      operator<<(out, val->next);
   }

   return out;
}