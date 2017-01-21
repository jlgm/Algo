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

ll n, stk[200005], sum;
ll adds[200005];

int main() {

    scanf("%lld", &n);

    int cur = 1;
    stk[cur++] = 0; sum = 0;

    fr(i,0,n) {
        int t; scanf("%d", &t);
        if (t == 1) {
            ll val, pos;
            scanf("%lld%lld",&pos, &val);
            adds[pos] += val;
            sum += (val*pos);
        }
        if (t == 2) {
            ll val;
            scanf("%lld", &val);
            sum += val;
            stk[cur++] = val;
        }
        if (t == 3) {
            cur--;
            ll val = stk[cur];
            ll add = adds[cur];
            sum -= val+add;
            adds[cur-1] += add;
            adds[cur] = 0;
        }
        printf("%.6lf\n", (double)sum / ((double)cur-1.0));
    }

    return 0;
}
