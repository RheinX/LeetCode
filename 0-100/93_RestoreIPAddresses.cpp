//Description
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//For example :
//Given "25525511135",
//return["255.255.11.135", "255.255.111.35"]. (Order does not matter)

//Solution
//Solution 1:
//use the BFS
//we can loop three times and every time add a character,the character of this time called *ch
//if *ch meet this requirement:the responable value of int <=255 and the rest number of *s meet the requirment
//we can push it into string
//notice:when we meet the element of 0,we should do extra judgement
//include:when appear in the first position ,there is no other elements behind it

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> answer;
		if (!this->judge_length(0, -1, s))
			return answer;

		string now = "";
		this->add_answer(answer, s, now, 0, 1);
		return answer;
	
	}

private:
	bool judge_length(const int &count, const int &index,const string &source) {
		int minCount = 4 - count;
		int maxCount = 3 * (4 - count);

		if (source.size() - index - 1 < minCount)
			return false;

		if (source.size() - index - 1 > maxCount)
			return false;

		return true;
	}

	void add_answer(vector<string> &answer, const string& source, string now, int index, int count) {
		if (count > 3) {
			if ('0' == source[index]&&index!=source.size()-1)
				return;
			string rest = source.substr(index);
			if (this->string_to_int(rest)<=255){
				now += rest;
				answer.push_back(now);
			}
			return;
		}
		if ('0' == source[index]) {
			string contempoary = now;
			now.append(source.substr(index,1) + '.');
			this->add_answer(answer, source, now, index + 1, count + 1);
			now = contempoary;
		}
		else {
			int total = 0;
			for (int i = 0; i < 3; i++) {
				total = total * 10 + source[index + i] - '0';
				bool test = this->judge_length(count, index + i, source);
				if (index + i + 1 < source.size() && total <= 255 && this->judge_length(count, index + i, source)) {
					string contempoary = now;
					now.append(source.substr(index, i + 1) + '.');
					this->add_answer(answer, source, now, index + i + 1, count + 1);
					now = contempoary;
				}
			}
		}
		
	}
	int string_to_int(const string& s) {
		stringstream a;
		a << s;
		int v;
		a >> v;
		return v;
	}
	
};

int main() {
	Solution a;
	vector<string> answer = a.restoreIpAddresses("010010");
	for (auto v : answer) {
		cout << v << endl;
	}
	
	system("pause");
	return 0;
}