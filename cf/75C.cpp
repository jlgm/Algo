#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll a, b, n, dp[40000];
vector<ll> da, db;

int main() {

    cin >> a >> b;

    int k = sqrt(a);
    fr(i,1,k+1) {
        if (a%i==0 && i*i!=a) da.pb(i), da.pb(a/i);
        else if (a%i==0 && i*i==a) da.pb(i);
    }

    k = sqrt(b);
    fr(i,1,k+1) {
        if (b%i==0 && i*i!=b) db.pb(i), db.pb(b/i);
        else if (b%i==0 && i*i==b) db.pb(i);
    }

    int cur = 0;

    fr(i,0,da.size()) fr(j,0,db.size())
        if (da[i]==db[j]) dp[cur++] = da[i];
    sort(dp,dp+cur); //dp has all common divisors, sorted

    int n; cin >> n; //queries
    fr(i,0,n) {
        ll x, y;
        cin >> x >> y;
        bool fnd = 0;
        for (int j = cur-1; j >= 0; j--) {
            if (dp[j] >= x && dp[j] <= y) {
                cout << dp[j] << endl;
                fnd = 1;
                break;
            }
        }
        if (!fnd) puts("-1");
    }

    //fr(i,0,cur) cout << dp[i] << " ";
    //puts("");

    return 0;
}
