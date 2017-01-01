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
#define E 200

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n, mapa[1000];
string s;

int main() {

    ll t; scanf("%lld\n", &t);

    while(t--) {
        scanf("%lld\n", &n);
        fr(i,0,n) {
            char c; ll val;
            cin >> c >> val;
            mapa[c+E] = val;
        }
        scanf("%lld\n", &n);
        int ans = 0;
        fr(i,0,n) {
            getline(cin, s);
            int k = s.size();
            fr(j,0,k) ans += mapa[s[j]+E];
        }
        printf("%d.%02d$\n", ans/100, ans%100);
        ms(mapa,0);
    }

    return 0;
}
