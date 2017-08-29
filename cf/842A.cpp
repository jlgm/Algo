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

int l, r, x, y, k;

int main() {

    scanf("%d%d%d%d%d", &l, &r, &x, &y, &k);

    for(int i = l; i <= r; i++) {
        if ((i%k)!=0) continue;
        int tmp = i/k;
        if (tmp >= x && tmp <= y) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}
