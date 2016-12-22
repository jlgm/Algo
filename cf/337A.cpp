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

int n, m;
int a[55];

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,m) scanf("%d", &a[i]);

    sort(a,a+m);
    int ans = 500000000;

    fr(i,0,(m-n)+1) {
        ans = min(ans, a[i+n-1]-a[i]);
    }

    printf("%d\n", ans);

    return 0;
}
