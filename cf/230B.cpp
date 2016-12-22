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

int n;
bool primes[1000005];
ll s;

int main() {

    ms(primes,1);
    primes[0] = 0;
    primes[1] = 0;
    primes[2] = 1;

    for (int i = 2; i <= 1000000; i++) {
        if (!primes[i]) continue;
        for (int j = i+i; j <= 1000000; j+=i) {
            primes[j] = false;
        }
    }

    scanf("%d", &n);
    fr(i,0,n) {
        cin >> s;
        ll sq = (ll)sqrtl(s);
        if (sq*sq != s) {
            puts("NO");
            continue;
        }
        printf("%s\n", primes[sq]?"YES":"NO");
    }

    return 0;
}
