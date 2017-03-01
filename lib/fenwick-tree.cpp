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

int n, a[100005], f[100005];

void update(int id, int v) {
    while(id <= n) f[id] += v, id += (id & -id);
}

int sum(int id) {
    int ret = 0;
    while(id > 0) ret += f[id], id -= (id & -id);
    return ret;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);

    int ans = 0;
    rf(i,n-1,0) {
        ans += sum(a[i]-1); //counts how many inversions array a has
        update(a[i], 1);
    }

    printf("%d\n", ans);

    return 0;
}
