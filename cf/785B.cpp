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

int n, m;

int main() {

    int ans1 = 1000000005, ans2 = 0;
    int ans3 = 1000000005, ans4 = 0;

    scanf("%d", &n);
    fr(i,0,n) {
        int x, y;
        scanf("%d%d", &x, &y);
        ans1 = min(ans1, y);
        ans2 = max(ans2, x);
    }
    scanf("%d", &m);
    fr(i,0,m) {
        int x, y;
        scanf("%d%d", &x, &y);
        ans3 = min(ans3, y);
        ans4 = max(ans4, x);
    }

    printf("%d\n", max(0, max(ans4-ans1, ans2-ans3)));

    return 0;
}
