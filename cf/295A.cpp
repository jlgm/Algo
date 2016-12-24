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

struct op {
    int X,Y,D;
};

ll n, m, k;
ll a[100005], f[100005], sum[100005];
pii q[100005];
op o[100005];

int main() {

    cin >> n >> m >> k;
    fr(i,0,n) cin >> a[i];
    fr(i,0,m) {
        cin >> o[i].X >> o[i].Y >> o[i].D;
        o[i].X--; o[i].Y--;
    }
    fr(i,0,k) {
        cin >> q[i].X >> q[i].Y;
        q[i].X--; q[i].Y--;
        f[q[i].X]++; f[q[i].Y+1]--;
    }

    fr(i,0,m) {
        if (i) f[i]+=f[i-1];
        sum[o[i].X] += (f[i]*o[i].D);
        sum[o[i].Y+1] -= (f[i]*o[i].D);
    }

    fr(i,0,n) {
        if (i) sum[i] += sum[i-1];
        a[i] += sum[i];
    }

    fr(i,0,n) cout << (i?" ":"") << a[i];
    puts("");

    return 0;
}
