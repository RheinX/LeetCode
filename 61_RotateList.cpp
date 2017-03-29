//descruption:
//Given a list, rotate the list to the right by k places, where k is non - negative.
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

//Solution
//此题的k会超出链表长度，因此首先循环链表到尾部，得到链表长度和尾指针tail，tail->next = head, 
//将其变成循环链表。利用k %= length，处理k大于length的情况，之后循环链表即可。


#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		//方法二
		if (NULL == head || NULL == head->next)
			return head;

		int length = 1;
		ListNode* p = head;

		while (p->next) {
			p = p->next;
			length++;
		}
		p->next = head;

		if (k%length) {
			for (int i = 0; i < length - k; i++) {
				p = p->next;
			}
		}

		ListNode* answer = p->next;
		p->next = NULL;

		return answer;

	}
};

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	l1->next = l2;

	Solution a;
	ListNode *answer = a.rotateRight(l1, 2);

	while (answer->next) {
		cout << answer->val << " ";
		answer = answer->next;
	}
	system("pause");
	return 0;
}