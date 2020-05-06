#include "stdio.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <bitset>
#include <map>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> mMap;
		int result = 0;
		int length = 0;
		
		int start = 0;
		for (int end = 0; end < s.size(); end++)
		{
			if (mMap.find(s[end]) != mMap.end() && mMap[s[end]] >= start)
			{
				start = mMap[s[end]] + 1;
				length = end - start;
			}
			
			length++;
			mMap[s[end]] = end;
		

			if (result < length)
			{
				result = length;
			}
		}
		return result;
    }
};

int main(int argc, char const *argv[])
{
	string in = "aab";
	Solution a;
	int ret = a.lengthOfLongestSubstring(in);
	printf("ret = %d \n", ret);
	return 0;
}