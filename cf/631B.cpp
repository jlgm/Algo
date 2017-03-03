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

struct op {
    int id, t, a;
};

int n, m, k, grid[5005][5005];
op ops[100005];

bool R[5005], C[5005];

int main() {

    scanf("%d%d%d", &n, &m, &k);
    fr(i,0,k) {
        int id, t, a;
        scanf("%d%d%d", &id, &t, &a); t--;
        ops[i].id = id;
        ops[i].t = t;
        ops[i].a = a;
    }

    rf(i,k-1,0) {
        int id, t, a;
        id = ops[i].id, t = ops[i].t, a = ops[i].a;
        if (id == 1) {
            if (R[t]) continue;
            fr(i,0,m) {
                if (C[i]) continue;
                grid[t][i] = a;
            }
            R[t] = 1;
        }
        else {
            if (C[t]) continue;
            fr(i,0,n) {
                if (R[i]) continue;
                grid[i][t] = a;
            }
            C[t] = 1;
        }
    }

    fr(i,0,n) {
        fr(j,0,m) {
            printf("%s%d", j?" ":"", grid[i][j]);
        }
        puts("");
    }

    return 0;
}
