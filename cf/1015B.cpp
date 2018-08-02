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

int n;
string s, t;

int main() {

    cin >> n;
    cin >> s >> t;

    string tmp_s = s;
    string tmp_t = t;

    sort(tmp_s.begin(), tmp_s.end());
    sort(tmp_t.begin(), tmp_t.end());

    if (tmp_s != tmp_t) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int pos = n-1;
            for(int j = i+1; j < n; j++) {
                if (s[j] == t[i]) {
                    pos = j;
                    break;
                }
            }
            for(int j = pos; j > i; j--) {
                swap(s[j], s[j-1]);
                ans.pb(j-1);
            }
        }
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%s%d", i?" ":"", ans[i]+1);

    return 0;
}
