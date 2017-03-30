//Description
//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//For example,
//If n = 4 and k = 2, a solution is :


//Answer:
//BFS

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> answer;
		vector<int> now;
		bp(answer, k, now, n,0);

		return answer;
	}
private:
	void bp(vector<vector<int>>& answer, int lack, vector<int> now,int n,int p) {
		if (!lack) {
			answer.push_back(now);
			return;
		}

		for (int i = p; i < n ; i++) {
			now.push_back(i + 1);
			bp(answer, lack - 1, now, n,i + 1);
			now.pop_back();
		}
	}
};

int main() {
	Solution a;
	vector<vector<int>> answer = a.combine(4, 5);
	for (auto v:answer){
		for (auto value:v){
			cout << value << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}