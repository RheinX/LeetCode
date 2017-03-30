//Description
//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
//(each operation is counted as 1 step.)
//You have the following 3 operations permitted on a word :
//a) Insert a character
//b) Delete a character
//c) Replace a character

//Answer:
//This is a classic problem of Dynamic Programming.
//We define the state dp[i][j] to be the minimum number of operations to convert word1[0..i - 1] to word2[0..j - 1].
//The state equations have two cases : the boundary case and the general case.
//Note that in the above notations, both i and j take values starting from 1.
//For the boundary case, that is, to convert a string to an empty string, 
//it is easy to see that the mininum number of operations to convert word1[0..i - 1] to "" requires at least i operations(deletions).
//In fact, the boundary case is simply :
//1.	dp[i][0] = i;
//2.	dp[0][j] = j.
//Now let's move on to the general case, that is, convert a non-empty word1[0..i - 1] to another non-empty word2[0..j - 1]. 
//Well, let's try to break this problem down into smaller problems(sub - problems).Suppose we have already known how to convert word1[0..i - 2] to word2[0..j - 2], 
//which is dp[i - 1][j - 1].Now let's consider word[i - 1] and word2[j - 1]. If they are euqal, then no more operation is needed and dp[i][j] = dp[i - 1][j - 1]. 
//Well, what if they are not equal?
//If they are not equal, we need to consider three cases :
//1.	Replace word1[i - 1] by word2[j - 1](dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
//2.	Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1](dp[i][j] = dp[i - 1][j] + 1 (for deletion));
//3.	Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1](dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
//Make sure you understand the subtle differences between the equations for deletion and insertion.
//For deletion, we are actually converting word1[0..i - 2] to word2[0..j - 1], which costs dp[i - 1][j], and then deleting the word1[i - 1],
//which costs 1. The case is similar for insertion.
//Putting these together, we now have :
//1.	dp[i][0] = i;
//2.	dp[0][j] = j;
//3.	dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
//4.	dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
//The above state equations can be turned into the following code directly.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int length_1 = word1.size(), length_2 = word2.size();

		vector<vector<int>> dp(length_1 + 1, vector<int>(length_2 + 1, 0));

		for (int i = 1; i < length_1 + 1; i++) {
			dp[i][0] = i;
		}
		for (int j = 1; j < length_2 + 1; j++) {
			dp[0][j] = j;
		}

		for (int i = 1; i < length_1 + 1; i++) {
			for (int j = 1; j < length_2 + 1; j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}

		return dp[length_1][length_2];
	}
};