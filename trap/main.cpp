/*

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
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
    int trap(vector<int>& height)
	{
    int result = 0;
	int max = 0;
	for (int i = 0; i < height.size(); i++)
	{
		max = std::max(max, height[i]);
	}

	for (int i = 0; i < max; i++)
	{
		int risedown = -1;
		int riseup =-1;
		for (int j = 1; j < height.size()-1; j++)
		{
			if(height[j]<= i && height[j-1]>i)
			{
				risedown = j;
			}

			if(height[j]<= i && height[j+1]>i)
			{
				riseup = j;
			}

			if (risedown <= riseup && riseup != -1 && risedown != -1)
			{
				result += riseup - risedown + 1;
				risedown = -1;
				riseup =-1;
			}
		}
	}
	return result;
    }
};



int main(int argc, char const *argv[])
{
	/* code */

	vector<int> a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(0);
	a.push_back(2);
	a.push_back(1);
	a.push_back(0);
	a.push_back(1);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(2);
	a.push_back(1);

	Solution d;
	printf("%d", d.trap(a));
	return 0;
}