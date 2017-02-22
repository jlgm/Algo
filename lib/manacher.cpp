#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

string in;

vector<int> manacher(const string& s) {
    string s2 = "#";
    for(unsigned int i = 0; i < s.size(); i++)
        s2 += s[i], s2 += '#';

    int c = 1, sz = (int)s2.size(), j;
    vector<int> ans(sz);
    while(c < sz) {
        while(c > ans[c] && c+ans[c]+1 < sz && s2[c-ans[c]-1] == s2[c+ans[c]+1])
            ans[c]++;

        j = 1;
        while(c+j < sz && j < ans[c]-ans[c-j])
            ans[c+j] = ans[c-j], j++;
        if(c+j < sz)
            ans[c+j] = ans[c]-j;
        c += j;
    }

    return ans;
}

int main() {

    while(cin>>in) {
        vector<int> ans = manacher(in);
        int k = ans.size();
        fr(i,0,k) {
            printf("%d\n", ans[i]); //max(ans[i]) will be the size of the longest palindrome
        }
    }

    return 0;
}
