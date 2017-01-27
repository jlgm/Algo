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

ll n, a[100005];

bool isconst() {
    ll prev = a[0];
    fr(i,1,n) if (a[i] != prev) return false;
    return true;
}

bool isprog() {
    fr(i,1,n-1) if (a[i]-a[i-1] != a[i+1]-a[i]) return false;
    return true;
}

int main() {

    scanf("%lld", &n);
    fr(i,0,n) scanf("%lld", a+i);

    if (n == 1) { puts("-1"); return 0; }
    sort(a,a+n);

    if (isconst()) {
        puts("1");
        printf("%lld\n", a[0]);
        return 0;
    }

    if (isprog()) {
        ll q = a[1] - a[0];
        vector<ll> ans;
        ans.pb(a[0]-q);
        if (n==2)
            if (ceil((double)(a[0]+a[1])/2) == floor((double)(a[0]+a[1]) / 2))
                ans.pb((a[0]+a[1]) / 2);
        ans.pb(a[n-1]+q);
        int k = ans.size();
        printf("%d\n", k);
        fr(i,0,k) printf("%s%lld", i ? " ":"", ans[i]);
        puts("");
    }

    else {
        ll q = a[1] - a[0];
        fr(i,1,n) q = min(q, a[i]-a[i-1]);
        fr(i,1,n) {
            if (a[i]-a[i-1] != q) {
                ll ans = a[i-1]+q;
                a[n++] = ans;
                sort(a,a+n);
                if (isprog()) puts("1"), printf("%lld\n", ans);
                else puts("0");
                break;
            }
        }
    }

    return 0;
}
