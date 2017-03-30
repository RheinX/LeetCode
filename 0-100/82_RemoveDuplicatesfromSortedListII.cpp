//Description
//Given a sorted linked list, delete all nodes that have duplicate numbers,
//leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3

//Answer
//we should set two pointer :previous and p
//*previous point to the previous point
//*p point to the current
//1.if the *p.val!=*p.next.val,let the *previous and *p point to the next element
//2.else:let *p move forward until *p.val!=*p.next.val
//at the time,the elements between *previous and *p.next is the nodes we should delete
//but we should return the head point,thus,wo set a point *answer which point to *previous initally
//and we also set a variable of bool to control the *answer

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
		if (NULL == head || NULL == head->next)
			return head;

		bool flag = true;
		ListNode *previous = new ListNode(-1);
		ListNode *p = head;
		ListNode *answer = previous;
		previous->next = p;

		while (NULL!=p&&NULL!=p->next){
			if (p->val != p->next->val) {
				p = p->next;
				previous = previous->next;
				flag = false;
			}
			else {
				while (NULL!=p->next&&p->val == p->next->val){
					p = p->next;
				}
				previous->next = p->next;
				if (flag) {
					answer = previous;
					flag = false;
				}
				p = p->next;
			}
		}

		return answer->next;
	}
};