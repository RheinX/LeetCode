//Description
//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//Note:
//If there is no such window in S that covers all characters in T, return the empty string "".
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

//Answer:
//ʹ��һ������a��¼t����ĸ���ֵĴ�����ͨ�����ֵĴ����ж�������ĸ�Ƿ񶼳��֡�
//1.�ֱ�����һ��head��tailָ��ָ��ͷ��βԪ�ء�
//2.ѭ��s�ַ�����
//3.��ȥ��ǰ��ĸ��a�ж�Ӧ���ֵĴ�С��ԭ�����ڵ�βԪ�غ��ƶ�ʱ����������ǰ����ֵ���ĸ�����º���ѭ��ʱ���ִ���
//4.while (lack == 0)ʱ������length��ʹ��head��ǰ�ƶ�ֱ��a[s[head]] == 0



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int count[128] = { 0 };
		int lack = t.size();
		int first = 0;

		for (auto v : t) {
			count[v]++;
		}

		int head = 0, tail = 0, length = INT_MAX;

		while (tail<s.size()){
			if (count[s[tail++]]-->0)
				lack--;

			while (!lack){
				if (length > (tail - head)) {
					length = tail - head;
					first = head;
				}
				if (!count[s[head++]]++)
					lack++;
			}
		}

		return length == INT_MAX ? "" : s.substr(first, length);
	}
};

int main() {
	Solution a;
	cout << a.minWindow("bba", "ba") << endl;
	system("pause");
	return 0;
}