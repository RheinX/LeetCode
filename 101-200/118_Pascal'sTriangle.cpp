//Description
//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//	[1],
//	[1, 1],
//	[1, 2, 1],
//	[1, 3, 3, 1],
//	[1, 4, 6, 4, 1]
//]

//Soluion
//we first store the data of numRow=1
//answer[i][j]=answer[i-1][j-1]+answer[i-1][j]
//sure,we should notice the range
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> answer;
		if (numRows<1)
			return answer;

		vector<int> a;
		a.push_back(1);
		answer.push_back(a);
		
		if (1 == numRows)
			return answer;

		for (int i = 1; i < numRows; i++) {
			vector<int> now(i + 1,0);
			for (int j = 0; j <= i; j++) {
				int left = (j == 0) ? 0 : answer.back()[j - 1];
				int right = (j == i) ? 0 : answer.back()[j];
				int value = left + right;
				now[j] = value;
			}
			answer.push_back(now);
		}

		return answer;
	}
};

int main() {
	Solution a;
	auto answer = a.generate(5);
	for (auto v:answer){
		for (auto value:v) {
			cout << value << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}