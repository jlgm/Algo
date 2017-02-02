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
#define M 1000000007

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

ll n;

int main() {

    scanf("%lld", &n);

    if (n == 1) {puts("0"); return 0;}
    if (n == 2) {puts("3"); return 0;}

    ll f = 3, prev = 3;
    fr(i,3,n+1) {
        f = (prev*3 + ((i&1)?(-3):(3)))%M;
        prev = f;
    }

    printf("%lld\n", f);

    return 0;
}
