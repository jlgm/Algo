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

int n, m, z;

int gcd(int a, int b) {
    if (b) return gcd(b, a%b);
    return a;
}

int lcm(int a, int b) {
    return a*b / gcd(a,b);
}

int main() {

    scanf("%d%d%d", &n, &m, &z);

    int ans = z/lcm(n,m);
    printf("%d\n", ans);

    return 0;
}
