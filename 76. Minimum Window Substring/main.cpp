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