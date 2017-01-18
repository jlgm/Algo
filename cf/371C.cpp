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

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

string s, tmp;
ll c[3], n[3], p[3], r, ans, cost;

bool can(ll k) {
    ll cost = 0;
    fr(i,0,3) cost += max((c[i]*k - n[i]),0LL) * p[i];

    return cost <= r;
}

int main() {

    cin >> s;
    int k = s.size();
    tmp = "BSC";

    fr(i,0,k) fr(j,0,3) c[j]+=(s[i]==tmp[j]);

    fr(i,0,3) cin >> n[i];
    fr(i,0,3) cin >> p[i];
    cin >> r;

    ll lo = 0, hi = 1e13, mid = lo;

    while(lo < hi) {
        mid = lo + (hi-lo)/2;
        if (!can(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << (hi-1) << endl;

    return 0;
}
