//https://leetcode.com/problems/palindrome-number/#/description
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int aux = 0, tmp = x;
        while(tmp) {
            aux *= 10;
            aux += (tmp%10);
            tmp /= 10;
        }
        return aux == x;
    }
};
