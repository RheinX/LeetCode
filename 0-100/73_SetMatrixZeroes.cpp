//Description
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//click to show follow up.
//Follow up :
//Did you use extra space ?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution ?
//
//注意：此题的意思是若原有的数组位置上的元素为0，则更改。更改后为0不用更改。

//Answer:
//Answer 1
//额外创建一个数组a，若是a【i】【j】为0，则使原矩阵的i行j列置为0.

//Answer 2
//设置一个一维数组，长度为m + n，分别代表i和j。若是(I, j)出现0，则令数组对应位置的值改为false。
//最后依旧是true的i，j。使用笛卡尔乘积得到的坐标即为不变的数。
//需要注意的是，此处使用的map进行存储，当map的key是结构体时，需要重载 < 符号，函数体如下:
//inline bool operator < (const struct pot &c) const {
//	return x < c.x || (x == c.x && y < c.y);
//}
//
//Ps:时间复杂度我感觉高了不少。。第一种方法以空间换取时间

//Answer 3
//将每行的首位和每列的首位设置为状态值，若是此行或者此列有值为0，
//则令matrix[i][0]和matrix[0][j] = 0，但是i和j都为0会相互影响，因此另外设置一个值判断列，而j从1开始。


#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	struct pot {
		int x, y;
		pot(int _x, int _y) :x(_x), y(_y) {};

		inline bool operator < (const struct pot &c) const{ 
			return x < c.x || (x == c.x && y<c.y);
		}
	};
	void setZeroes(vector<vector<int>>& matrix) {
		//方法一
		/*int row = matrix.size();
		int column = matrix.front().size();

		vector<vector<int>> answer = matrix;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!answer[i][j])
					this->fill_table(matrix, i, j);
			}
		}*/

		//方法二
		
	/*	int row = matrix.size();
		int column = matrix.front().size();

		vector<bool> flag(row + column, true);
		
		map<pot,int> my_map;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!matrix[i][j]) {
					flag[i] = false;
					flag[row + j ] = false;
				}
					
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = row; j < row + column; j++) {
				if (flag[i] && flag[j]) {
					my_map.insert(pair<pot, int>(pot(i, j-row), matrix[i][j-row]));
				}
			}
		}
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (flag[i]&&flag[row+j]) {
					matrix[i][j] = my_map.find(pot(i, j))->second;
				}
				else
					matrix[i][j] = 0;

			}
		}*/

		//方法三
		int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < cols; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		}

		for (int i = rows - 1; i >= 0; i--) {
			for (int j = cols - 1; j >= 1; j--)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			if (col0 == 0) matrix[i][0] = 0;
		}


	}
	

private:
	void fill_table(vector<vector<int>>& matrix, int i, int j) {
		for (int m = 0; m < matrix.front().size(); m++)
			matrix[i][m] = 0;

		for (int m = 0; m < matrix.size(); m++)
			matrix[m][j] = 0;
	}
};

int main() {
	vector<vector<int>>  matrix = { {1,2,3,4},{5,0,5,0},{8,9,2,0},{5,7,2,1} };
	Solution a;
	a.setZeroes(matrix);

	for (auto v:matrix){
		for (auto value:v){
			cout << value << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}