/***************************************************************************************************
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
***************************************************************************************************/
#include <vector>

using std::vector;

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto const size = s.size();
        for(int i = 0; i < size/2; i++)
        {
            std::swap(s[i], s[size-i-1]);
        }
    }
};

// solution in C
void reverseString(char* s, int sSize) {
    for(int i = 0; i < sSize/2; i++)
    {
        char tempc = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = tempc;
    }
}
