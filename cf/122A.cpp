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

int lk[] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main() {

    scanf("%d", &n);

    fr(i,0,14) if (n%lk[i]==0) {
        puts("YES");
        return 0;
    }

    puts("NO");
    return 0;
}
