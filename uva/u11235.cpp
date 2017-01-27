#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define M 100005

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, m, in[100005], H[300005], F[300005], a[100005], s[4*100005];

void build(int id, int l, int r) {
    if (l==r) { s[id] = l; return; }

    int mid = (l+r)/2;
    build((id<<1), l, mid);
    build((id<<1) + 1, mid+1, r);
    int p1 = s[(id<<1)], p2 = s[(id<<1)+1];

    s[id] = (a[p1] >= a[p2]) ? p1 : p2;
}

int rmq(int p, int l, int r, int i, int j) {
    if (i > r || j < l) return -1;
    if (l >= i && r <= j) return s[p];

    int p1 = rmq((p<<1), l, ((l+r)/2), i, j);
    int p2 = rmq(((p<<1)+1), ((l+r)/2+1), r, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;

    return (a[p1] >= a[p2]) ? p1 : p2;
}

int qq(int i, int j) { return rmq(1,0,n-1,i,j); }

int main() {

    while(scanf("%d%d", &n, &m) && n) {
        ms(F,-1);
        fr(i,0,n) {
            scanf("%d", &in[i]), H[in[i]+M]++;
            if (F[in[i]+M] == -1) F[in[i]+M] = i;
        }

        fr(i,0,n) a[i] = H[in[i]+M];
        build(1,0,n-1);

        fr(i,0,m) {
            int x, y;
            scanf("%d%d", &x, &y); x--, y--;
            if (in[x] == in[y]) {
                printf("%d\n", y-x+1);
                continue;
            }
            int it1 = 0;
            while(in[x+it1] == in[x] && x+it1 < y) it1++;
            int it2 = 0;
            while(in[y-it2] == in[y] && y-it2 > x) it2++;
            int ans = max(it1, it2);
            ans = max(ans, a[qq(x+it1, y-it2)]);
            printf("%d\n", ans);
        }
        ms(in,0);
        ms(H,0);
        ms(s,0);
        ms(a,0);
    }

    return 0;
}
