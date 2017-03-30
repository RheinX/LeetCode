//description
//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

//Answer
//Answer 1:
//just judge whether the val of current point equals the next 

//Answer 2:
//use the recursion

#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		//Solution 1
	/*	if (NULL == head || NULL == head->next)
			return head;

		ListNode *p = head;

		while (NULL!=p->next){
			if (p->val != p->next->val)
				p = p->next;
			else
				p->next = p->next->next;
		}

		return head;*/

		//Solution 2
		if (NULL == head || NULL == head->next)
			return head;

		head->next = deleteDuplicates(head->next);
		return head->val == head->next->val ? head->next : head;
	}
};