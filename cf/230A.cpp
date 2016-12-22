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

struct drag {
    int x, y;
};

int s, n;
drag d[1005];

bool cmp(drag a, drag b) {
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main() {

    scanf("%d%d", &s,&n);

    fr(i,0,n) scanf("%d%d", &d[i].x, &d[i].y);

    sort(d,d+n,cmp);

    fr(i,0,n) {
        if (s > d[i].x) s+=d[i].y;
        else {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}
