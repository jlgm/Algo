#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k, a[1005];
bool mark[1005];

int main() {

    scanf("%d%d%d", &n, &m, &k);
    fr(i,0,n) {
        scanf("%d", &a[i]);
        if (a[i] <= k && a[i]) mark[i] = true;
    }

    int ans = n;
    fr(i,0,n) if (mark[i]) ans = min(ans, abs(m-i-1));

    printf("%d\n", ans*10);

    return 0;
}
