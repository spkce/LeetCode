/*
329. 矩阵中的最长递增路径
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
输出: 4 
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
输出: 4 
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
*/

#include "stdio.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>
#include <map>
#include <string.h>

using namespace std;

class Solution 
{
	int** m_pNote;
	int m_maxRow;
	int m_maxCol;
public:
    int longestIncreasingPath(vector<vector<int> >& matrix)
	{
		m_maxRow = matrix.size();
		if (m_maxRow == 0)
		{
			return 0;
		}
		m_maxCol = matrix[0].size();

		m_pNote = new int*[m_maxRow];
		for (int i = 0; i < m_maxRow; i++)
		{
			m_pNote[i] = new int[m_maxCol];
		}
		int ret = 0;
		for (int row = 0; row < m_maxRow; row++)
		{
			for (int col = 0; col < m_maxCol; col++)
			{
				clearMap();
				ret = max(dfs(matrix, row, col), ret);
			}
		}
		//printf("%d\n", dfs(matrix, 2, 1));
		//for (int i = 0; i < m_maxRow; i++)
		//{
		//	for (int j = 0; j < m_maxCol; j++)
		//	{
		//		printf("%d ", m_pNote[i][j]);
		//	}
		//	printf("\n");
		//}

		for (int i = 0; i < m_maxRow; i++)
		{
			delete[] m_pNote[i];
		}
		delete[] m_pNote;
		return ret;
    }
private:
	void clearMap()
	{
		for (int i = 0; i < m_maxRow; i++)
		{
			for (int j = 0; j < m_maxCol; j++)
			{
				m_pNote[i][j] = 0;
			}
		}
	}
	int dfs(vector<vector<int> >& matrix, int row, int col)
	{
		if (m_pNote[row][col] != 0)
		{
			return m_pNote[row][col];
		}

		//printf("(%d %d)\n", col, row);
		
		m_pNote[row][col] = 1;

		int level = 0;

		if (row + 1 < m_maxRow && matrix[row+1][col] > matrix[row][col] )
		{
			m_pNote[row][col] = max(dfs(matrix, row + 1, col) + 1, m_pNote[row][col]);
		}
		
		if (row -1 >= 0 && matrix[row-1][col] > matrix[row][col])
		{
			m_pNote[row][col] = max(dfs(matrix, row - 1, col) + 1, m_pNote[row][col]);
		}

		if (col + 1 < m_maxCol && matrix[row][col+1] > matrix[row][col])
		{
			m_pNote[row][col] = max(dfs(matrix, row, col + 1) + 1, m_pNote[row][col]);
		}

		if (col -1 >= 0 && matrix[row][col-1] > matrix[row][col])
		{
			m_pNote[row][col] = max(dfs(matrix, row, col - 1) + 1, m_pNote[row][col]);
		}

		return m_pNote[row][col];
	}
};

main(int argc, char const *argv[])
{
	vector<vector<int> > matrix;
	vector<int> raw;
	raw.push_back(7);
	raw.push_back(8);
	raw.push_back(9);
	matrix.push_back(raw);
	raw.clear();

	raw.push_back(9);
	raw.push_back(7);
	raw.push_back(6);
	matrix.push_back(raw);
	raw.clear();

	raw.push_back(7);
	raw.push_back(2);
	raw.push_back(3);
	matrix.push_back(raw);
	raw.clear();

	Solution a;
	int ret = a.longestIncreasingPath(matrix);
	printf("%d\n", ret);


	return 0;
}