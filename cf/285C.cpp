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

ll n, a[300005], cur;
int mark[300005];

int next() {
    while(mark[cur] && cur <= n) {
        cur++;
    }
    mark[cur]=true;
    return cur;
}

int main() {

    cin >> n;
    fr(i,0,n) {
        cin >> a[i];
        if (a[i] >= 1 && a[i] <= n) mark[a[i]]++;
    }

    sort(a,a+n);

    cur = 1; ll ans = 0;

    fr(i,0,n) {
        if (a[i] >= 1 && a[i] <= n) {
            if (mark[a[i]] == 1) continue;
            else {
                int tgt = next();
                ans += (int)abs(a[i]-tgt);
                mark[a[i]]--;
                continue;
            }
        }
        int tgt = next();
        ans += (int)abs(a[i]-tgt);
    }

    cout << ans << endl;

    return 0;
}
