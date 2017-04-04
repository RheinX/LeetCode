//Description
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//	Given n will always be valid.
//	Try to do this in one pass.

//Solution
//use two pointer that they apart n
//move them and at last the next point to the hail,the previos pointer to the node we need to delete

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		////1.方法一
		//int length = 0;
		//ListNode* p = head;
		//while (p != NULL) {
		//	length++;
		//	p = p->next;
		//}

		//p = head;
		//if (length > n )
		//	for (int i = 0; i < length - n - 1; i++)
		//		p = p->next;
		//else
		//	return p->next;

		//p->next = p->next->next;

		//return head;

		//2.方法二
		ListNode *first = head, *second = head;
		int n1 = n;
		int length = 1;

		while (second->next != NULL) {
			if (n != 0) {
				second = second->next;
				--n;

			}


			else {
				second = second->next;
				first = first->next;

			}
			length++;
		}
		if (length == n1)
			return head->next;

		first->next = first->next->next;
		return head;
	}
};
