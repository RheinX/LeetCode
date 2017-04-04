//Description
//Given a roman numeral, convert it to an integer.
//Input is guaranteed to be within the range from 1 to 3999.

//Solution "
//Solution 1:
//first we store the number and its responding character into a map
//then,we loop the string.judge the size of the current character and next
//if current character is smaller than the next,minus the curent in total ,otherwise,add it

//Solution 2:
//we judge there are exist the suition where the bigger character in the right side
//let the total minus the double difference
//loop the whole string ,add the value the character responding
#include <iostream>
#include<string>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		char s_base[7] = { 'I','V','X','L','C','D','M' };
		int value[] = { 1,5,10,50,100,500,1000 };
		map<char, int> base;

		for (int i = 0; i < 7; i++)
			base.insert(pair<char, int>(s_base[i], i));

		int total = 0;

		for (int i = 0; i < s.size() - 1; i++) {
			int last = base.find(s[i + 1])->second;
			int now = base.find(s[i])->second;

			if (last > now)
				total = total - value[now];
			else
				total += value[now];

		}
		total += value[base.find(s[s.size() - 1])->second];
		return total;
	}
};

