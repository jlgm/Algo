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

int t, n;
bool a[181];

int main() {

    scanf("%d", &t);

    fr(i,3,1000) {
        if ((i-2)*180%i==0) a[(i-2)*180/i] = true;//, printf("%d\n",(i-2)*180/i);
    }

    while(t--) {
        scanf("%d", &n);
        printf("%s\n", a[n]?"YES":"NO");
    }

    return 0;
}
