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

int n, k;

int main() {

    scanf("%d%d", &n, &k);

    int cur = 0, ans = 0;

    while(cur+k < 240 && ans < n) {
        ans+=1;
        cur+=(5*ans);
    }

    printf("%d\n", ans - ((cur+k)>240));

    return 0;
}
