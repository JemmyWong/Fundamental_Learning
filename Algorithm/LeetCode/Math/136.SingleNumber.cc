/* Easy
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tips:
The same numbers XOR together will be 0

Reference:
https://www.lijinma.com/blog/2014/05/29/amazing-xor/
https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

Bit-Wise Operation:
Set union A | B
Set intersection A & B
Set subtraction A & ~B
Set negation ALL_BITS ^ A or ~A
Set bit A |= 1 << bit
Clear bit A &= ~(1 << bit)
Test bit (A & 1 << bit) != 0
Extract last bit A&-A or A&~(A-1) or x^(x&(x-1))
Remove last bit A&(A-1)
Get all 1-bits ~0

Relatives:
136. Single Number
137. Single Number II
260. Single Number III
268. Missing Number
287. Find the Duplicate Number
389. Find the Difference
645. Set Mismatch */

#include<iostream>
#include<vector>
#include<numeric>    // accumulate
#include<functional> // bit_xor
#include<assert.h>

using namespace std;

// 14ms, beat 85.23%
int singleNumber(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}

// 15ms, 66.37%
int singleNumber_1(vector<int>& nums) {
    int len = nums.size();
    int ret = 0;
    for (int i = 0; i < len; ++i)
        ret = ret ^ nums[i];

    return ret;
}

/******************** there are two single nums ******************************/
// get the location of the first 1 in the lower bits of num
int getFirstOneBit(int num) {
    return  num & ~(num - 1);
}

void singleNumberTwo(vector<int> nums) {
    int aXORb = 0;
    int a = 0;
    int b = 0;
    int firstOneBit = 0;
    int len = nums.size();

    for (int i = 0; i < len; ++i) {
        aXORb ^= nums[i];
    }
    assert(aXORb != 0);
    firstOneBit = getFirstOneBit(aXORb);
    for (int i = 0; i < len; ++i) {
        if (nums[i] & firstOneBit) {
            a ^= nums[i];
        }
    }
    b = aXORb & a;
    cout << a << " : " << b << endl;
}

/******************** there are three single nums *****************************/

int singleNumberThree(vector<int> nums) {

}

int main() {
    // vector<int> vec = {1, 2, 6, 2, 1};
    // cout << singleNumber(vec) << endl;
    cout << (1 | 2) << endl;
}