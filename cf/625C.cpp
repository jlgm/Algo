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

int n, k, ans[505][505];

int main() {

    scanf("%d%d", &n, &k);

    int a = n*n, b = 1;
    int resp = 0;
    k = n-k;

    fr(i,0,n) {
        fr(j,0,n) {
            if (j <= k) {
                ans[i][j] = a--;
                if (j==k) resp+=ans[i][j];
            }
            else ans[i][n-j+k] = b++;
        }
    }

    printf("%d\n", resp);
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--)
            printf("%s%d", (j==(n-1))?"":" ", ans[i][j]);
        puts("");
    }

    return 0;
}
