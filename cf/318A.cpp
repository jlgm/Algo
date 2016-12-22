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

ll n, k;

int main() {

    cin >> n >> k;

    if (n%2==0) {
        if (k <= n/2) cout << 2*k-1 << endl;
        else cout << 2*k - n << endl;
    }

    else {
        if (k <= n/2 + 1) cout << 2*k-1 << endl;
        else cout << 2*k - n - 1 << endl;
    }

    return 0;
}
