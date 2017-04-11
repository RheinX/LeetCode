//Description
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

//Solution :
//Solution 1
//set a variable *p,plus the vaule of elements befor *p in prices and behind by the function in 121
//sure,TLX

//Soluiton 2:
//this kind of solvtion i cannot understand..

//Solution 3:
//int maxProfit(vector<int> &prices) {
//	// f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
//	// f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
//	//          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
//	// f[0, ii] = 0; 0 times transation makes 0 profit
//	// f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
//	if (prices.size() <= 1) return 0;
//	else {
//		int K = 2; // number of max transation allowed
//		int maxProf = 0;
//		vector<vector<int>> f(K + 1, vector<int>(prices.size(), 0));
//		for (int kk = 1; kk <= K; kk++) {
//			int tmpMax = f[kk - 1][0] - prices[0];
//			for (int ii = 1; ii < prices.size(); ii++) {
//				f[kk][ii] = max(f[kk][ii - 1], prices[ii] + tmpMax);
//				tmpMax = max(tmpMax, f[kk - 1][ii] - prices[ii]);
//				maxProf = max(f[kk][ii], maxProf);
//			}
//		}
//		return maxProf;
//	}
//}
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//Solution 1
		int release1 = 0, release2 = 0;
		int hold1 = INT_MIN, hold2 = INT_MIN;

		for (int i:prices){
			release2 = max(release2, hold2 + i);     // The maximum if we've just sold 2nd stock so far.
			hold2 = max(hold2, release1 - i);  // The maximum if we've just buy  2nd stock so far.
			release1 =max(release1, hold1 + i);     // The maximum if we've just sold 1nd stock so far.
			hold1 = max(hold1, -i);          // The maximum if we've just buy  1st stock so far. 
		}

		return release2;
	}
};