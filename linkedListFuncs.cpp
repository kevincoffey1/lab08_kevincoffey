#include "linkedListFuncs.h"
#include <stddef.h>

using namespace std;

/**All functions MUST be implemented recursively - there will be a manual check
* No credit will be given for non-recursive solutions
*/

/*Given the head of a linked list, find and return the kth node of the linked list
 *Assume head is the first node
 *If k is larger than the size of the linked list, return NULL
 *
 * Example: n1 -> n2 -> n3 -> n4 -> n5, k = 3
 * Return &n3
 */
Node* findKthNode(Node *head, int k){
        if (head == NULL) 
		return NULL; 	
	else if (k > 1) 
		return findKthNode((*head).next,k-1); 
	else 
        	return head;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}

/*Given the head of a linked list, delete the first k nodes from the linked list
 *k will always be less than the length of the linked list
* 
* Return the head of the new linked list
*
* Example: n1 -> n2 -> n3 -> n4, k = 2
* Delete n1, n2 and return &n3
*/
Node* removeKFromFront(Node *head, int k) {
	Node* q,* p(head);  
        if (k > 0) {
		q = p; 
		p = (*head).next; 
		delete q; 
		return removeKFromFront(p, k- 1); 
	} else { 
		return p; 
	}
    
}

/*Given two linked lists, return a linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* sum(Node *head1, Node *head2) {
	Node* p = new Node;
	if(head1 == NULL && head2 == NULL) {
		return NULL; 
	} else if (head1 == NULL) { 
		*p = {0+(*head2).data,sum(NULL,(*head2).next)}; 
	} else if (head2 == NULL) {
		*p = {(*head1).data+0,sum((*head1).next,NULL)}; 
	}else {	
	*p= {(*head1).data+(*head2).data,sum((*head1).next,(*head2).next)};
		}
	
		
	return p; 
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}

/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL 
 * (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* splice(Node *head1, Node *head2) {
	if (head1 == NULL && head2 == NULL) 
		return NULL; 
	else if (head1 == NULL) 
		return head2; 
	else if (head2 == NULL) 
		return head1;
	else
		(*head1).next = splice(head2,(*head1).next); 
        	
        return head1;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}
