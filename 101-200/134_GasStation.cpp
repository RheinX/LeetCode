//Description
//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).
//You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//The solution is guaranteed to be unique.

//Solution:
//Solution 1:
//just loop twice to start from every node

//Solution 2:
//there are two things we must konw to solve this problem
//1.If car starts at A and can not reach B.Any station between A and B
//can not reach B.(B is the first station that A can not reach.)
//2.If the total number of gas is bigger than the total number of cost.There must be a solution.
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//Solution 1
		/*if (gas.size() != cost.size())
			return -1;

		for (int times = 0; times < gas.size(); times++) {
			int total = 0;
			int i, count;
			for (i = times, count = 0; count < gas.size(); i++, count++) {
				total += gas[i];
				if (total < cost[i])
					break;

				total -= cost[i];

				if (i == gas.size() - 1)
					i = -1;
			}

			if (count == gas.size())
				return times;
		}

		return -1;*/

		//Solution 2:
		int start = 0, total = 0, tank = 0;
		for (int i = 0; i < gas.size();i++) {
			total = total + gas[i] - cost[i];
			if (total < 0) {
				start = i + 1;
				tank += total;
				total = 0;
			}
		}

		return (tank + total < 0) ? -1 : start;
	}
};