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

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

struct point{
    int x, y;
};

const int maxn = 100000;
int r[maxn], p[maxn], s[maxn];
int n, ans;
point pp[105];

int findset(int i) {return (p[i] == i)?(i):(p[i] = findset(p[i]));}
bool issame(int i, int j) {return findset(i) == findset(j);}
void create(int i) {p[i] = i; s[i] = 1; ans++;/*r[i] = 0;*/}

void setunion(int i, int j) {
    if (!issame(i,j)) {
        int x = findset(i); int y = findset(j);
        p[x] = p[y];
        ans--;
    }
}

void solve() {
    fr(i,0,n) fr(j,i+1,n) {
        if (pp[i].x == pp[j].x || pp[i].y == pp[j].y) setunion(i,j);
    }
}

int main() {

    scanf("%d", &n); int x,y;
    fr(i,0,n) scanf("%d%d", &x, &y), pp[i].x = x, pp[i].y = y;

    fr(i,0,n) create(i);

    solve();

    printf("%d\n", ans-1);

    return 0;
}
