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

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, k, sum[1000005];
string s;

int main() {

    cin >> k >> s;

    int n = s.size();

    fr(i,1,n+1) sum[i] = sum[i-1]+(s[i-1]=='1');
    // fr(i,0,n) db(sum[i])

    ll ans = 0;
    fr(i,1,n+1) {
        int tmp = sum[i-1] + k;
        if (sum[n] < tmp) break;
        int a = lower_bound(sum+i, sum+n+1, tmp)-sum;
        int b = upper_bound(sum+i, sum+n+1, tmp)-sum;
        // cout << tmp << " " << a << " " << b << endl;
        ans += (b-a);
    }

    cout << ans << endl;

    return 0;
}
