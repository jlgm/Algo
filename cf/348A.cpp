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

ll n, a[100005], sum;

bool cmp(ll x, ll y) {
    return x > y;
}

bool can(ll x) {
    return ((n-1)*x - a[0]) >= (sum-a[0]);
}

int main() {

    cin >> n; sum = 0;
    fr(i,0,n) cin >> a[i], sum+=a[i];

    sort(a,a+n,cmp);

    ll lo = a[0], hi = sum, mid = lo;

    while(lo < hi) {
        mid = lo + (hi-lo)/2;
        if (can(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << lo << endl;

    return 0;
}
