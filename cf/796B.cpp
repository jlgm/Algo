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

int n, m, k;
bool hole[1000005];

int main() {

    scanf("%d%d%d", &n, &m, &k);

    int tmp;
    fr(i,0,m) scanf("%d", &tmp), hole[tmp] = true;

    int cur = 1;

    while(k--) {
        if (hole[cur]) {
            printf("%d\n", cur);
            return 0;
        }
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == cur) cur = y;
        else if (y == cur) cur = x;
    }

    printf("%d\n", cur);

    return 0;
}
