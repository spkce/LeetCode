/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

 
示例：

输入：[1,8,6,2,5,4,8,3,7]
输出：49

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
    int maxArea(vector<int>& height) {
        
		int l = 0;
		int r = height.size() - 1;

		int ret = 0;
		while (l < r)
		{
			if (height[l] < height[r])
			{
				ret = max((r - l ) * height[l], ret);
				l++;
			}
			else
			{
				ret = max((r - l ) * height[r], ret);
				r--;
			}
		};

		return ret;
    }
};


int main(int argc, char const *argv[])
{
	vector<int> in;
	in.push_back(1);
	in.push_back(8);
	in.push_back(6);
	in.push_back(2);
	in.push_back(5);
	in.push_back(4);
	in.push_back(8);
	in.push_back(3);
	in.push_back(7);
	Solution a;
	int ret = a.maxArea(in);
	printf("ret = %d \n", ret);
	return 0;
}
