//Description
//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

//Answer :
//Answer 1:
//first we should move to the node whose val is >=x,let it called *p
//if *p->next->val<x,it means *p->next should be changged,and then wo loop the list from the head 
//and insert it into the suitable position
//sure ,it is better to set a pointer whose next is pointer to head

//Answer 2:
//as the meaning of this problem,wo do not put the element into the ture position(sort by size)
//we just need to put the node whose elment <x by original order
//so ,we set two list ,one store the node whose element <x ,and another is contrary
//what we should notice is that *p2->next=null and connect *p1 and *p2
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		//Answer 1
		//if (NULL == head || NULL == head->next)
		//	return head;

		//ListNode *previous = new ListNode(-1);
		//previous->next = head;
		//ListNode *p = head;

		////locate to the position where its val is x
		//while (NULL!=p->next&&x>p->val){
		//	p = p->next;
		//}

		//while (NULL!=p->next){
		//	if (p->next->val < x) {
		//		ListNode* now = p->next;
		//		p->next = p->next->next;

		//		ListNode* position = previous;
		//		while (NULL != position->next&&position->next->val < x) {
		//			position = position->next;
		//		}

		//		now->next = position->next;
		//		position->next = now;
		//	}
		//	else
		//		p = p->next;
		//}

		//return previous->next;

		//Answer 2:
		if (NULL == head || NULL == head->next)
			return head;

		ListNode node1(0), node2(0);
		ListNode *p1 = &node1, *p2 = &node2;
		while (NULL!=head){
			if (head->val < x)
				p1 = p1->next = head;
			else
				p2 = p2->next = head;
			head = head->next;
		}

		p2->next = NULL;
		p1->next = node2.next;

		return node1.next;

	}
};