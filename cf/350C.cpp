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

struct bomb {
    int id, x, y, dist;
};

int n;
bomb bs[100005];

bool cmp(bomb a, bomb b) {
    return a.dist < b.dist;
}

int main() {

    scanf("%d", &n);
    fr(i,0,n) {
        scanf("%d%d", &bs[i].x, &bs[i].y);
        bs[i].id = i;
        bs[i].dist = abs(bs[i].x)+abs(bs[i].y);
    }

    sort(bs, bs+n, cmp);
    int ans = 0;

    fr(i,0,n) {
        ans += (abs(bs[i].x) > 0)*2;
        ans += (abs(bs[i].y) > 0)*2;
        ans += 2;
    }

    printf("%d\n", ans);

    fr(i,0,n) {
        if ((abs(bs[i].x) > 0)) {
            if (bs[i].x > 0) {
                printf("1 %d R\n", (abs(bs[i].x)));
            }
            else {
                printf("1 %d L\n", (abs(bs[i].x)));
            }
        }
        if (abs(bs[i].y) > 0) {
            if (bs[i].y > 0) {
                printf("1 %d U\n", (abs(bs[i].y)));
            }
            else {
                printf("1 %d D\n", (abs(bs[i].y)));
            }
        }
        puts("2");
        if ((abs(bs[i].x) > 0)) {
            if (bs[i].x > 0) {
                printf("1 %d L\n", (abs(bs[i].x)));
            }
            else {
                printf("1 %d R\n", (abs(bs[i].x)));
            }
        }
        if (abs(bs[i].y) > 0) {
            if (bs[i].y > 0) {
                printf("1 %d D\n", (abs(bs[i].y)));
            }
            else {
                printf("1 %d U\n", (abs(bs[i].y)));
            }
        }
        puts("3");
    }

    return 0;
}
