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

pii pts[100005];
int n, r, d, ri[100005];

long double dist(pii p, pii q) {
    return sqrtl((p.X - q.X)*(p.X - q.X) + (p.Y - q.Y)*(p.Y - q.Y));
}

//verifies if point i is on crost
bool issol(int i) {
    long double D = dist(pts[i], mp(0,0));
    if (D < (long double)(r-d) || D > (long double)(r)) {
        return false;
    }

    return (D-(long double)(r-d)) >= (long double)ri[i] && (long double)(D+ri[i]) <= (long double)r;
}

int main() {

    scanf("%d%d", &r, &d);
    scanf("%d", &n);
    
    int ans = 0;
    fr(i,0,n) {
        scanf("%d%d%d", &pts[i].X, &pts[i].Y, &ri[i]);
        if (issol(i)) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
