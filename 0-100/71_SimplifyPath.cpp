//Description
//Given an absolute path for a file(Unix - style), simplify it.
//For example,
//path = "/home/", = > "/home"
//path = "/a/./b/../../c/", = > "/c"
//click to show corner cases.
//Corner Cases :
//•	Did you consider the case where path = "/../" ?
//In this case, you should return "/".
//•	Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo"
//
//注意：‘.’表示当前目录，’..’表示退回上级目录

//Answer:
//Answer 1
//循环字符，position = path.find(‘ / ’).next = path.find(‘ / ’, position + 1)，
//利用position和next取出夹在’ / ’之间的字符，若是‘..’则弹出vector底部数据，若不是’.’，则将字符及当前文件夹名压入容器。
//需要注意的是，当退出后循环后，可能还最后’ / ’后还有字符，需要判定。

//Answer 2:
//Getline函数类似与java中splite()函数。
//(1)	istream& getline(istream&  is, string& str, char delim);
//istream& getline(istream&& is, string& str, char delim);
//
//(2)	istream& getline(istream&  is, string& str);
//istream& getline(istream&& is, string& str);
//Get line from stream into string
//Extracts characters from is and stores them into str until the delimitation character delim is found(or the newline character, '\n', for (2)).
//
//The extraction also stops if the end of file is reached in is or if some other error occurs during the input operation.
//
//If the delimiter is found, it is extracted and discarded(i.e.it is not stored and the next input operation will begin after it).
//
//Note that any content in str before the call is replaced by the newly extracted sequence.
//
//Each extracted character is appended to the string as if its member push_back was called




#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		//方法一
	/*	vector<string> answer;
		int position = path.find('/');
		
		if (-1 == position)
			return path;
		else if (0 != position)
			answer.push_back(path.substr(0, position + 1));
		
		while (-1!=position){
			int next_position = path.find('/', position + 1);
			if(-1==next_position)
				break;

			string now = path.substr(position + 1, next_position - position - 1);
			if (".." == now&&!answer.empty())
				answer.pop_back();
			else if (!now.empty() && "." != now&&".."!=now)
				answer.push_back(now);

			position = next_position;
		}
		if (position < path.size()) {
			string now = path.substr(position + 1);
			if (".." == now&&!answer.empty())
				answer.pop_back();
			else if (!now.empty() && "." != now&&".." != now)
				answer.push_back(now);
		}

		if (answer.empty())
			return "/";

		string res;
		for (string v:answer){
			res += "/" + v;
		}

		return res;*/

		//方法二
		string fileName;
		char delim = '/';
		stringstream ss(path);
		vector<string> answer;

		while (getline(ss,fileName,delim)){
			if (fileName.empty() || "." == fileName)
				continue;
			else if (".." == fileName&&!answer.empty())
				answer.pop_back();
			else if(".." != fileName)
				answer.push_back(fileName);
		}

		if (answer.empty())
			return "/";

		string res;
		for (string v : answer) {
			res += "/" + v;
		}

		return res;
	}
};

int main() {
	Solution a;
	cout << a.simplifyPath("/.") << endl;
	system("pause");
	return 0;
}