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

ll a, b;

int bits(ll number) {
    int ret = 0;
    while(number) {
        ret += 1;
        number>>=1LL;
    }
    return ret;
}

int main() {

    cin >> a >> b;

    if (a==b) {
        puts("0");
        return 0;
    }

    ll aa = a, bb = b, amt = bits(b);
    amt--;

    while(amt>=0) {
        bool t1 = (aa&(1LL<<amt));
        bool t2 = (bb&(1LL<<amt));
        if (t1 != t2) { amt--; continue; }
        if (t1 == 0 && (aa|(1LL<<(amt))) <= bb) (aa|=(1LL<<(amt)));
        else if (t2 == 1 && (bb&~(1LL<<(amt))) >= aa) (bb&=~(1LL<<(amt)));
        amt--;
    }
    cout << (aa^bb) << endl;

    return 0;
}
