//Description
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//click to show follow up.
//Follow up :
//Did you use extra space ?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution ?
//
//ע�⣺�������˼����ԭ�е�����λ���ϵ�Ԫ��Ϊ0������ġ����ĺ�Ϊ0���ø��ġ�

//Answer:
//Answer 1
//���ⴴ��һ������a������a��i����j��Ϊ0����ʹԭ�����i��j����Ϊ0.

//Answer 2
//����һ��һά���飬����Ϊm + n���ֱ����i��j������(I, j)����0�����������Ӧλ�õ�ֵ��Ϊfalse��
//���������true��i��j��ʹ�õѿ����˻��õ������꼴Ϊ���������
//��Ҫע����ǣ��˴�ʹ�õ�map���д洢����map��key�ǽṹ��ʱ����Ҫ���� < ���ţ�����������:
//inline bool operator < (const struct pot &c) const {
//	return x < c.x || (x == c.x && y < c.y);
//}
//
//Ps:ʱ�临�Ӷ��Ҹо����˲��١�����һ�ַ����Կռ任ȡʱ��

//Answer 3
//��ÿ�е���λ��ÿ�е���λ����Ϊ״ֵ̬�����Ǵ��л��ߴ�����ֵΪ0��
//����matrix[i][0]��matrix[0][j] = 0������i��j��Ϊ0���໥Ӱ�죬�����������һ��ֵ�ж��У���j��1��ʼ��


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
		//����һ
		/*int row = matrix.size();
		int column = matrix.front().size();

		vector<vector<int>> answer = matrix;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!answer[i][j])
					this->fill_table(matrix, i, j);
			}
		}*/

		//������
		
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

		//������
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