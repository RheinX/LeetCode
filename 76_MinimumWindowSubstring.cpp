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
//使用一个数组a记录t中字母出现的次数，通过出现的次数判断所有字母是否都出现。
//1.分别设置一个head和tail指针指向头和尾元素。
//2.循环s字符串。
//3.减去当前字母在a中对应数字的大小，原因在于当尾元素后移动时，可能遇到前面出现的字母，导致后面循环时出现错误。
//4.while (lack == 0)时，更新length，使得head向前移动直到a[s[head]] == 0



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