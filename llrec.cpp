#include "llrec.h"
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head==NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }
    // if (head->next==NULL) { // the last item in LL
    //     if (head->val < pivot) {
    //         smaller = head;
    //         larger = NULL;
    //         head = NULL;
    //     }
    //     else {
    //         larger = head;
    //         smaller = NULL;
    //         head = NULL;
    //     }
    //     return;
    // }
    // get to the end of the list first
    llpivot(head->next, smaller, larger, pivot);
    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    }
    else {
        head->next = larger;
        larger = head;
    }
    head = NULL;

    // backwards
    // // base case / empty list
    // if (head==nullptr)
    //     return;
    // Node* temp = head->next;
    // if (head->val < pivot) {
    //     // add to smaller ll
    //     head->next = smaller; // the thing currently at smaller
    //     smaller = head;
    // }
    // else {
    //     // add to larger ll
    //     head->next = larger; // the thing currently at smaller
    //     larger = head;
    // }

    // // move on to next node
    // llpivot(temp, smaller, larger, pivot);
}