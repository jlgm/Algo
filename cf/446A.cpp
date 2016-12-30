#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << " ";
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, a[100005], l[100005], r[100005];

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);
    int ans = 1;

    l[0] = 1;
    fr(i,1,n)
        l[i] = (a[i]>a[i-1])?(l[i-1]+1):1, ans = max(ans, l[i-1]+1);

    r[n-1] = 1;
    for (int i = n-2; i>=0; i--)
        r[i] = (a[i] < a[i+1])?(r[i+1]+1):1, ans = max(ans, r[i+1]+1);

    fr(i,1,n-1)
        if (l[i-1]+1+r[i+1] > ans && a[i-1]+1 < a[i+1]) ans = l[i-1]+1+r[i+1];

    printf("%d\n", ans);

    return 0;
}
