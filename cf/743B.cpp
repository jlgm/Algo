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
ll pw[55];

int main() {

    pw[0] = 1;
    fr(i,1,51) pw[i] = pw[i-1]*2; //pw[i] = 2^i

    cin >> n >> k;

    for (int i = 0; i < n+1; i++) {
        if (pw[i] > k) k-=pw[i-1], i = 1;
        fr(j,0,51) {
            if (k == pw[j]) {
                cout << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
