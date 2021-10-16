#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

#include <cctype>

using namespace std;


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		int left = 0;
		int right = nums.size();
		if (target <= nums[0]) {
			return 0;
		}

		if (target > nums[right - 1]) {
			return nums.size();
		}

		while (left < right) {
			int mid = left + ((right - left) >> 1);
			if (nums[mid] > target) {
				right = mid;
			} else if (nums[mid] < target) {
				left = mid + 1;
			} else {
				return mid;
			}
		}
		return right;
    }
};



class Solution69 {
public:
    int mySqrt(int x) 
	{
		if (x < 0) {
			-1;
		}
		int result = x / 2;
		int left = 0;
		int right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			result = mid * mid;
			if (result == x) {
				return mid;
			} else if (result > x) {
				right = mid - 1;
			} else if (result < x) {
				left = mid + 1;
			}
		}

		if (left * left <= x) {
			return left;
		}
    }
};

	

class Solution1614 {
public:
    int maxDepth(string s) 
	{

         int depth = 0;
		 stack<char> str;
		 for (int i = 0; i < s.size(); i++) {
			 if (s[i] == '(') {
				 str.push(s[i]);
				 int tmp = str.size();
				 depth = max(depth, tmp);
			 } else if (s[i] == ')') {
                 str.pop();
			 }
		 }
		 return depth;
    }
};



int mian()
{
	int x=1;
	int i;
	for(i=0;i<10;i++)
	{
		cout<<x<<endl;
	}
	return 0;
}