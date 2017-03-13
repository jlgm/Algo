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

int n;
int a[6], b[6];

int main() {

    scanf("%d", &n);
    fr(i,0,n) {
        int x; scanf("%d", &x);
        a[x]++;
    }
    fr(i,0,n) {
        int x; scanf("%d", &x);
        b[x]++;
    }

    int ans = 0;
    fr(i,1,6) {
        if (a[i] != b[i]) {
            if ((a[i] + b[i])&1) {
                puts("-1");
                return 0;
            }
            if (a[i] > b[i]) swap(a[i],b[i]);
            ans += abs(a[i]-(a[i]+b[i])/2);
        }
    }

    printf("%d\n", ans/2);

    return 0;
}
