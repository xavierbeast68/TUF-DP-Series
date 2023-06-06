//* https://leetcode.com/problems/climbing-stairs/
//* https://youtu.be/mLfjzJsN8us
//* https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
//* https://www.youtube.com/watch?v=Y0lT9Fck7qI&ab_channel=NeetCode

class Solution {
public:
    int climbStairs(int n) {

        // Fibonacci Sequence
        int a = 0, b = 1;
        for(int i = 0; i < n; i ++){
            int temp = a + b;
            a = b;
            b = temp;
        }

        return b;
    }
};