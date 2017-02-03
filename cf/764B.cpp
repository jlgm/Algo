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

int n, a[200005];

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);

    fr(i,0,n/2) if (i%2==0) swap(a[i], a[n-i-1]);

    fr(i,0,n) printf("%s%d", i?" ":"", a[i]);

    return 0;
}
