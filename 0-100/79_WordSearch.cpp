//Description
//Given a 2D board and a word, find if the word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cell, 
//where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//For example,
//Given board =
//[
//	['A', 'B', 'C', 'E'],
//	['S', 'F', 'C', 'S'],
//	['A', 'D', 'E', 'E']
//]
//word = "ABCCED", ->returns true,
//word = "SEE", ->returns true,
//word = "ABCB", ->returns false

//Answer:
//Answer 1:
//�ݹ鷨������һ��bool��������a����ʼֵΪtrue��
//���ȱ�����ά���飬������λ�õ���word��0���������a��Ӧλ�õ�Ԫ��Ϊfalse��
//֮���ж���һ��Ԫ�ص���������δ��ѡ�е�Ԫ���Ƿ���һ��Ԫ�ء�

//Answer 2:
//�ڵ�һ�ַ����Ͻ��иĽ���
//1).����Ҫʹ��a���顣ÿ���ҵ���ǰԪ�غ�ʹ��board[y][x] ^= 256��ֵ��Ϊ�Ƿ��ַ�(����ͬ��һ��������ɻָ�)��
//2).�����ж��ĴΣ�ʹ�û���������Ĵεݹ顣��֮ǰ�ж�x��yλ�õķ�Χ���ɡ�


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty())
			return true;
		
		if (word.empty())
			return false;

		int row = board.size();
		int column = board.front().size();
		vector<vector<bool>> flag(row, vector<bool>(column,true));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (board[i][j] == word[0]) {
					flag[i][j] = false;
					if (if_find(board, word, i, j, 1, row, column,flag))
						return true;
					else
						flag[i][j] = true;
				}
					
			}
		}

		return false;
	}
private:
	bool if_find(vector<vector<char>>& board, string word, int position_x, int position_y, int index,
					int row,int column, vector<vector<bool>> flag) {
		//position:the position of previous element in borad
		//index:the ith element in word
		if (index == word.size())
			return true;

		//���
		if (position_x < row - 1) {
			if (board[position_x + 1][position_y] == word[index]&&flag[position_x + 1][position_y]) {
				flag[position_x + 1][position_y] = false;
				if (if_find(board, word, position_x + 1, position_y, index + 1, row, column, flag)) {
					return true;
				}
				flag[position_x + 1][position_y] = true;
			}
		}

		//�Ҳ�
		if (position_x > 0) {
			if (board[position_x - 1][position_y] == word[index]&&flag[position_x - 1][position_y]) {
				flag[position_x - 1][position_y] = false;
				if (if_find(board, word, position_x - 1, position_y, index + 1, row, column, flag)) {
					return true;
				}
				flag[position_x - 1][position_y] = true;
			}
		}

		//�ϲ�
		if (position_y > 0) {
			if (board[position_x][position_y - 1] == word[index]&&flag[position_x][position_y - 1]) {
				flag[position_x][position_y - 1] = false;
				if (if_find(board, word, position_x, position_y - 1, index + 1, row, column, flag))
					return true;
				flag[position_x][position_y - 1] = true;
			}
		}

		if (position_y < column - 1) {
			if (board[position_x][position_y + 1] == word[index]&&flag[position_x][position_y + 1]) {
				flag[position_x][position_y + 1] = false;
				if(if_find(board, word, position_x, position_y + 1, index + 1, row, column,flag))
					return true;
				flag[position_x][position_y + 1] = true;
			}
		}

		return false;
	}
};

int main() {
	vector<vector<char>> test = { {'A','B','C','E'},
	{'S','F','C','S'},
		{'A','D','E','E'} };
	Solution a;
	cout << a.exist(test, "ABCCED") << endl;
	cout << a.exist(test, "SEE") << endl;
	cout << a.exist(test, "ABCB") << endl;

	system("pause");
	return 0;
}