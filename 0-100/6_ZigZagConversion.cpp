//Description
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

//Solution
//Solution 1:
//just find the rule of this

//Solution 2:
//use a varilble to control the up and down
//add the word to different string one by one

#include<iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || s.size() <= numRows)
			return s;

		////方法一
		//int offset = 2 * numRows - 2;
		//int numColumn = s.size() / offset;
		//string answers;

		//for (int i = 0; i < numRows; i++) {
		//	for (int j = 0; j < numColumn; j++) {
		//		answers += s[offset*j + i];
		//		//对于非第一行及最后一行
		//		if (i != 0 && i != numRows - 1) {
		//			answers += s[offset*j + offset - i];
		//		}
		//	}
		//	//若还有剩余
		//	int last = numColumn;

		//	if ((offset*last + i)<s.size()&&i!=numRows-1) {
		//		answers += s[offset*last + i];
		//	}
		//	if((offset*last + offset - i)<s.size()){
		//		answers += s[offset*last + offset - i];
		//	}
		//}
		//return answers;

		//方法二
		const int stLength = s.size();
		string *str = new string[stLength];
		int step = 0, turn = 0;
		for (int i = 0; i < stLength; i++) {
			if (step == 0)
				turn = 1;
			else if (step == numRows - 1)
				turn = -1;

			str[step].push_back(s[i]);
			step += turn;
		}
		string answer;
		for (int i = 0; i < numRows; i++)
			answer += str[i];

		return answer;
	}
};