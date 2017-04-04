//Description
//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//	Output : "bab"
//
//	Note : "aba" is also a valid answer.
//	Example :
//
//	Input : "cbbd"
//
//	Output : "bb

//Solution 1:
//set a two-dimensional array of bool ,flag[i][j] means that the string from i to j is palindrome
//thus if flag[i][j] is palindrome only if flag[i-1][j-1] is palindrome 

//Solution 2:
//view word as the center ,and move back and right
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		//����һ����ʱ
		/*string answer;
		for (int i = 0; i < s.size(); i++) {
		for (int j = 1; j <= s.size()-i; j++) {
		if (this->IfPalindrome(s.substr(i, j)))
		answer = answer.size()>j ? answer : s.substr(i, j);
		}
		}
		return answer;*/

		////����������ʱ
		//string rev = this->resver(s);
		//string answer;
		//for (int i = 0; i < s.size(); i++) {
		//	for (int j = 1; j <= s.size() - i; j++) {
		//		string substring = s.substr(i, j);

		//		if(substring==rev.substr(s.size()-i-j,j))
		//			answer = answer.size()>j ? answer : s.substr(i, j);
		//	}
		//}
		//return answer;

		////������
		//bool **p = new bool *[s.size()];
		//for (int i = 0; i < s.size(); i++) {
		//	p[i] = new bool[s.size()];
		//	p[i][i] = false;
		//}
		//
		//int max = 1, start = 0, end = 0;
		//for (int offset = 1; offset < s.size(); offset++) {
		//	for (int i = 0; i < s.size() - offset; i++) {
		//			//�ַ�������Ϊ����
		//			if (offset % 2 == 0) {
		//				if (!p[i + 1][i + offset - 1]) {
		//					if ((s[i] == s[i + offset])) {
		//						p[i][i + offset] = false;
		//						if (max < offset + 1) {
		//							max = offset + 1;
		//							start = i;
		//							end = offset;
		//						}
		//					}
		//				}
		//			}
		//			else {
		//				if (offset == 1) {
		//					if ((s[i] == s[i + offset])) {
		//						p[i][i + offset] = false;
		//						if (max < offset + 1) {
		//							max = offset + 1;
		//							start = i;
		//							end = offset;
		//						}
		//					}
		//				}
		//				else {
		//					if ((s[i] == s[i + offset])&&(!p[i + 1][i + offset - 1])) {
		//						p[i][i + offset] = false;
		//						if (max < offset + 1) {
		//							max = offset + 1;
		//							start = i;
		//							end = offset;
		//						}
		//					}
		//				}
		//			}
		//		
		//	}
		//		
		//}
		//delete[]p;
		///*cout << start << " " << end << endl;*/
		//return s.substr(start, end+1);

		//������

		int *oneSelf = new int[s.size()], *twoSelf = new int[s.size()];
		for (int i = 0; i < s.size(); i++) {
			oneSelf[i] = 0;
			twoSelf[i] = 0;
		}
		int max = 0, center = 0, type = 0;;

		for (int i = 1; i < s.size(); i++) {
			for (int offset = 1; offset < min(i + 1, s.size() - i); offset++) {
				//���Լ�Ϊ����
				if (s[i - offset] == s[i + offset])
					oneSelf[i] = offset;
				else
					oneSelf[i] = -1;

				//����ΧΪ����
				if (offset == 1) {
					if ((s[i - 1] == s[i]))
						twoSelf[i] = offset;
					else
						twoSelf[i] = -1;
				}
				else {

					if (s[i - offset] == s[i + offset - 1])
						twoSelf[i] = offset;
					else
						twoSelf[i] = -1;

				}
				if (oneSelf[i] == -1 && twoSelf[i] == -1)
					break;

			}

		}
		for (int i = 0; i < s.size(); i++) {
			if (oneSelf[i] > max) {
				center = i;
				max = oneSelf[i];
				type = 1;
			}
			else if (twoSelf[i] > max) {
				center = i;
				max = twoSelf[i];
				type = 2;
			}
		}

		string answer;
		if (type == 1)
			answer = s.substr(center - max, 1 + max * 2);
		else if (type == 2)
			answer = s.substr(center - max, 1 + max * 2 - 1);
		else
			answer = s[0];
		return answer;

	}

	//����һ�����׷������ж�s�Ƿ�Ϊ�����ַ���
	bool IfPalindrome(string s) {
		for (int i = 0; i < s.size(); i++)
			if (s[i] != s[s.size() - 1 - i])
				return false;

		return true;
	}

	//�����������׷���������s�ĵ����ַ�
	string resver(string s) {
		string rev = s;
		for (int i = 0; i < s.size(); i++)
			rev[i] = s[s.size() - i - 1];

		return rev;
	}

	int min(int a, int b) {
		return a < b ? a : b;
	}
};