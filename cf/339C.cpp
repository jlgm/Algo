#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define EP 20

typedef long long ll;
typedef pair<int, int> pii;

string s;
int n, dp[30][11][1001];
bool mark[15];
vector<int> resp;

bool possible(int sum, int l, int v) {
    int &ret = dp[sum][l][v];
    if (ret != -1) return ret;
    if (v==n) return ret = 1;
    if (sum < 0) return ret = 0;
    ret = 0;
    fr(i,1,11) {
        if (i == l) continue;
        if (i <= sum) continue;
        if (mark[i]) {
            bool ans = possible((int)abs(i-sum), i, v+1);
            ret = (ret || ans);
            if (ans) {
                resp.pb(i);
                break;
            }
        }
    }
    return ret;
}

int main() {

    cin >> s;
    scanf("%d", &n);

    fr(i,0,10) mark[i+1] = (s[i]=='1');
    ms(dp,-1);

    printf("%s\n", possible(0,0,0)?"YES":"NO");
    int k = resp.size();
    fr(i,0,k) {
        printf("%s%d", i?" ":"", resp[k-i-1]);
    }
    return 0;
}
