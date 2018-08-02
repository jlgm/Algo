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
string g[111];
bool mark[111][111];

struct repl {
    int a, b, c;
};

bool can(int x, int y, int i) {
    if (x-i < 0 || y-i < 0 || x+1 >= n || y+i >= m) return false;
    else return true;
}

int star(int x, int y) {
    if (x == 0 || y == 0 || x == n-1 || y == m-1) return -1;
    if (g[x][y] != '*') return -1;
    if (g[x-1][y] == '*' && g[x+1][y] == '*' && g[x][y-1] == '*' && g[x][y+1] == '*') return 1;
    return -1;
}

int visit(int x, int y) {
    mark[x][y] = mark[x-1][y] = mark[x+1][y] = mark[x][y-1] = mark[x][y+1] = true;
    int i = 1;
    while(can(x,y,i) && g[x-i][y] == '*' && g[x+i][y] == '*' && g[x][y-i] == '*' && g[x][y+i] == '*') {
        mark[x-i][y] = mark[x+i][y] = mark[x][y-i] = mark[x][y+i] = true;
        i++;
    }
    return i-1;
}

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,n) cin >> g[i];

    vector<repl> ans;
    fr(i,0,n) fr(j,0,m) {
        int k = star(i,j);
        if (k>0) {
            int l = visit(i,j);
            repl tmp;
            tmp.a = i;
            tmp.b = j;
            tmp.c = l;
            ans.pb(tmp);
        }
    }

    fr(i,0,n) fr(j,0,m) if (g[i][j] == '*' && !mark[i][j]) {
        puts("-1");
        return 0;
    }

    printf("%d\n", ans.size());
    fr(i,0,ans.size()) {
        printf("%d %d %d\n", ans[i].a+1, ans[i].b+1, ans[i].c);
    }

    return 0;
}
