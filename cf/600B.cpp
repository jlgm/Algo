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

int n, m, a[200005];//, b[200005];

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,n) scanf("%d", &a[i]);
    sort(a,a+n);
    fr(i,0,m) {
        int b; scanf("%d", &b);
        printf("%s%d", i?" ":"", (int)(upper_bound(a,a+n,b) - a));
    }

    return 0;
}
