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

ll n, a, b, c;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> a >> b >> c;

    ll ans = 0;

    if (b-c < a && n >= b) {
        ans += ((n-b)/(b-c)+1);
        n -= (ans*(b-c));
    }

    cout << ((ll)(n/a)+ans) << endl;

    return 0;
}
