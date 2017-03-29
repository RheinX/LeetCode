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
		////方法一
		//if (0 == k||NULL==head||NULL==head->next)
		//	return head;

		//ListNode* p = new ListNode(0), *next_p = head;
		//p->next = head;

		//for (int i = 0; i < k - 1; i++)
		//	next_p = next_p->next;

		//while (NULL!=next_p->next){
		//	p = p->next;
		//	next_p = next_p->next;
		//}

		//ListNode* answer = p->next;

		//p->next = NULL;
		//next_p->next = head;

		//return answer;

		//方法二
		if (NULL == head || NULL == head->next)
			return head;

		int length = 1;
		ListNode* p = head;
		
		while (p->next){
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

	while (answer->next){
		cout << answer->val << " ";
		answer = answer->next;
	}
	system("pause");
	return 0;
}