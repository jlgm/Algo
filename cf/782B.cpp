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
#define eps 1e-7

typedef long long ll;
typedef pair<int, int> pii;

struct f {
    double x, v;
};

int n;
f fs[60006];

bool cmp(f v, f w) {
    if (v.x == w.x) return v.v > w.v;
    return v.x < w.x;
}

bool can(double t) {
    double R = fs[0].x + t*fs[0].v;
    double L = fs[0].x - t*fs[0].v;

    fr(i,1,n) {
        double r = fs[i].x + t*fs[i].v;
        double l = fs[i].x - t*fs[i].v;
        R = min(R,r);
        L = max(L,l);
    }
    return R > L;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%lf", &fs[i].x);
    fr(i,0,n) scanf("%lf", &fs[i].v);

    double lo = 0.0, hi = 1000000007, mid = lo;

    while(hi-lo>eps) {
        mid = lo + (hi-lo)/2.0;
        if (can(mid)) hi = mid;
        else lo = mid+0.0000001;
    }

    printf("%.6lf\n", mid);

    return 0;
}
