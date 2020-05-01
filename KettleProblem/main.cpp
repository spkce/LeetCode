/*
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空

eg1:
输入: x = 3, y = 5, z = 4
输出: True

eg2:
输入: x = 2, y = 6, z = 5
输出: False
*/
#include "stdio.h"
#include <vector>
#include <stack>
#include <algorithm>
class Solution
{
	typedef std::pair<int, int> Pair;

  public:
	//BFS
	bool canMeasureWater1(int x, int y, int z);
	//贝祖定理
	bool canMeasureWater2(int x, int y, int z);
};

bool Solution::canMeasureWater1(int x, int y, int z)
{
	std::stack<Pair> stk;
	std::vector<Pair> vct;

	stk.push(Pair(0, 0));

	while (stk.size())
	{
		Pair param = stk.top();
		stk.pop();

		std::vector<Pair>::iterator it = find(vct.begin(), vct.end(), param);
		if (it != vct.end())
		{
			continue;
		}

		if (param.first == z || param.second == z || (param.first + param.second) == z)
		{
			return true;
		}

		//记录经历过的状态
		vct.push_back(param);

		//x满
		stk.push(Pair(x, param.second));
		//y满
		stk.push(Pair(param.first, y));
		//x空
		stk.push(Pair(0, param.second));
		//y空
		stk.push(Pair(param.first, 0));

		int rx, ry;
		//x -> y
		rx = param.first - std::min(param.first, (y - param.second));
		ry = param.second + std::min(param.first, (y - param.second));
		stk.push(Pair(rx, ry));
		//y -> x
		rx = param.first + std::min(param.second, (x - param.first));
		ry = param.second - std::min(param.second, (x - param.first));
		stk.push(Pair(rx, ry));
	}

	return false;
}

int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}

bool Solution::canMeasureWater2(int x, int y, int z)
{
	if ((x + y) < z)
	{
		return false;
	}

	if (x == 0 || y == 0)
	{
		return (z==0) || (x + y == z);
	}
	return z%gcd(x,y) == 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	Solution a;
	bool ret;
	ret = a.canMeasureWater1(3, 5, 4);
	printf("xyz(3,5,4) = %d \n", ret);
	ret = a.canMeasureWater1(2, 6, 5);
	printf("xyz(2,6,5) = %d \n", ret);

	ret = a.canMeasureWater2(3, 5, 4);
	printf("xyz(3,5,4) = %d \n", ret);
	ret = a.canMeasureWater2(2, 6, 5);
	printf("xyz(2,6,5) = %d \n", ret);
	return 0;
}
