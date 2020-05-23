/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

提示：

0 < grid.length <= 200
0 < grid[0].length <= 200
 */
#include "stdio.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>
#include <string.h>
using namespace std;
class Solution {
	
public:
    int maxValue(vector<vector<int> >& grid) {
		const int N = grid.size();
		const int M = grid[0].size();

		int dp[200][200] = {0};

		dp[0][0] = grid[0][0];

		//先算竖边
		for (int i = 1; i < N; i++)
		{
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}

		//再算横边
		for (int j = 1; j < M; j++)
		{
			dp[0][j] = grid[0][j] + dp[0][j - 1];
		}

		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				dp[i][j] =max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}

		return dp[N-1][M-1];
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int> > in;
	vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	in.push_back(a);

	a.clear();

	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	in.push_back(a);

	Solution d;
	printf("%d", d.maxValue(in));
	return 0;
}
