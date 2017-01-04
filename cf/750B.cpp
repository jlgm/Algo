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

ll n, val;
string tmp;

int main() {

    ll b = 0; bool broke = false;
    cin >> n;

    fr(i,0,n) {
        cin >> val >> tmp;
        if (tmp == "South") b+=val;
        if (tmp == "North") b-=val;
        if (b < 0 || b > 20000)  broke = 1;
        if ((tmp == "West" || tmp == "East") && (b == 0 || b == 20000)) {
            broke = 1;
        }
    }

    if (b != 0 || broke) puts("NO");
    else puts("YES");

    return 0;
}
