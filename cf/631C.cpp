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

int n, m, mx, a[200005], inc[200005], t[200005], r[200005], up[200005];

int main() {

    scanf("%d%d", &n, &m);
    fr(i,1,n+1) scanf("%d", &a[i]), inc[i]=a[i];
    fr(i,1,m+1) {
        scanf("%d%d", &t[i], &r[i]);
        up[r[i]] = i;
        mx = max(mx,r[i]);
    }

    sort(inc+1,inc+mx+1);

    int tmp = 0, iinc = 1, idec = mx;
    rf(i,n,1) {
        tmp = max(tmp,up[i]);
        if (tmp == 0) continue;
        if (t[tmp] == 1) a[i] = inc[idec--];
        else a[i] = inc[iinc++];
    }

    fr(i,1,n+1) printf("%s%d", i!=1?" ":"", a[i]);
    puts("");

    return 0;
}
