/* Easy
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:
Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.

Relatives:
136. Single Number
137. Single Number II
260. Single Number III
268. Missing Number
287. Find the Duplicate Number
389. Find the Difference
645. Set Mismatch */

#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char chr = 0;

        for (int i = 0; i < s.size(); ++i)
            chr ^= s[i] ^ t[i];
        chr ^= t.back();

        return chr;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ascii[128] = {0};

        for (int beg = 0, end = s.size()-1; beg <= end; ++beg, --end) {
            ++ascii[s[beg]];
            ++ascii[s[end]];
        }
        if (s.size() % 2) {
            --ascii[s[s.size()/2]];
        }

        for (int beg = 0, end = t.size()-1; beg <= end; ++beg, --end) {
            --ascii[t[beg]];
            --ascii[t[end]];
        }
        if (t.size() % 2) {
            ++ascii[t[t.size()/2]];
        }

        for (int i = 0; i < 128; ++i) {
            if (ascii[i])
                return i;
        }

        return ' ';
    }
};