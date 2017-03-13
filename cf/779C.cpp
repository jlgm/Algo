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

struct prod {
    int x, y;
};

bool cmp(prod a, prod b) {
    if (abs(a.x-a.y) == abs(b.x-b.y)) return a.x < b.x;
    return abs(a.x-a.y) < abs(b.x-b.y);
}

int n, k;
prod p[200005];

int main() {

    scanf("%d%d", &n, &k);
    fr(i,0,n) scanf("%d", &p[i].x);
    fr(i,0,n) scanf("%d", &p[i].y);

    sort(p,p+n,cmp);

    int tmp = 0;
    fr(i,0,n) {
        if (p[i].x <= p[i].y) k--;
    }

    int ans = 0;
    if (k <= 0) {
        fr(i,0,n) ans += min(p[i].x, p[i].y);
        printf("%d\n", ans);
        return 0;
    }

    fr(i,0,n) {
        if (k > 0) {
            if (p[i].x > p[i].y) k--;
            ans += p[i].x;
        }
        else ans += min(p[i].x, p[i].y);
    }

    printf("%d\n", ans);

    return 0;
}
