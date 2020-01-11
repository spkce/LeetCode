/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] == target - nums[i])
				{
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					return temp;
				}
			}
		}
		
		throw ;
	}
};

int main(int argc, char const *argv[])
{
	int target = 9;
	int temp[] = {2, 7, 11, 15};
	vector<int> vInput(temp, temp + sizeof(temp)/sizeof(int));
	Solution solution;
	vector<int> vOutput = solution.twoSum(vInput, target);
	
	for (int i = 0; i < vOutput.size(); i++)
	{
		cout<<vOutput[i]<<endl;
	}
	return 0;
}
