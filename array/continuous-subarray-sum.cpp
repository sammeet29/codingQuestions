/***************************************************************************************************
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.


Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false

#array #prefixSum
***************************************************************************************************/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
        {
            return false;
        }
        else if (k == 1)
        {
            return true;
        } 
        else if (nums.size() == 2)
        {
            int const subArraySum = nums[0] + nums[1];
            return ((subArraySum % k) == 0);
        }

        // else
        vector<int> cumalativeSumMod;
        int sum = 0;
        for(int n: nums)
        {
            sum += n;
            cumalativeSumMod.push_back(sum % k);
        }

        unordered_map<int, int> modIndexes;
        for (int i = 0; i < cumalativeSumMod.size(); i++)
        {
            if (i != 0 && cumalativeSumMod[i] == 0)
            {
                return true;
            }   
            auto it = modIndexes.find(cumalativeSumMod[i]);
            if (it == modIndexes.end() )
            {
                modIndexes[cumalativeSumMod[i]] = i; 
            } else {
                // see if 
                int startIndex = it->second;
                if ((i - startIndex) >= 2)
                {
                    return true;
                }
            }
        }

        return false;
          
    }
};
