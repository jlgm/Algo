//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string in;

    bool ispal(int x, int y) {
        for(int i = 0; i < y-x/2; i++) {
            if (in[x+i] != in[y-i]) return false;
            if (y-i <= x+i) break;
        }
        return true;
    }

    string longestPalindrome(string s) {
        in = s;
        int k = s.size();
        int idx = 0, ans = 0;
        for(int i = 0; i < k; i++)
            for(int j = i; j < k; j++) {
                if (j-i+1 > ans) {
                    if (ispal(i,j)) {
                        ans = j-i+1;
                        idx = i;
                    }
                }
            }
        string ret = "";
        for(int i = 0; i < ans; i++) ret.push_back(s[idx+i]);
        return ret;
    }
};
