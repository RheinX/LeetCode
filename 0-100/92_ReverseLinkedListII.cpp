//Description
//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//return 1->4->3->2->5->NULL.
//Note :
//	Given m, n satisfy the following condition :
//1 ¡Ü m ¡Ü n ¡Ü length of list.

//Solution 
//Solution 1:
//set *previous which point to the node which previous to mTh node and *later to the nTh node
//then just put the *previous->next to the next of later until *previous->next=*later
//notice:return head directly when m=n


#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (NULL == head || NULL == head->next)
			return head;

		ListNode* start = new ListNode(0);
		start->next = head;

		ListNode* previous = start;
		ListNode *later = previous;
		int i = 0;
		while (i<n){
			if (i < m-1)
				previous = previous->next;

			later = later->next;
			i++;
		}

		while (previous->next!=later){
			ListNode* p = previous->next;

			previous->next = p->next;
			p->next = later->next;
			later->next = p;
			p = previous->next;
		}

		return start->next;
	}
};