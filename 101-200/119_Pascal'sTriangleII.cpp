//Description
//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return[1, 3, 3, 1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space ?

//Solution:
//Solution 1:
//we can use the function of previous probelem
//only change the parameter 

//Solution 2:
//we can do an improbement that only use the constant space
//we use a vector to simulator
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 0)
			return vector<int>{};

		/*auto answer = this->generate(rowIndex + 1);
		return answer.back();*/

		vector<int> answer(rowIndex + 1, 0);
		answer[0] = 1;
		for (int i = 1; i < rowIndex + 1;i++) {
			for (int j = i; j > 0; j--)
				answer[j] += answer[j - 1];
		}

		return answer;
	}
private:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> answer;
		if (numRows < 1)
			return answer;

		vector<int> a;
		a.push_back(1);
		answer.push_back(a);

		if (1 == numRows)
			return answer;

		for (int i = 1; i < numRows; i++) {
			vector<int> now(i + 1, 0);
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