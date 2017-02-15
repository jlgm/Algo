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

int n, m, grid[505][505], sx, sy, tx, ty;
int dx[] = {1, 0,-1, 0};
int dy[] = {0, 1, 0,-1};
bool mark[505][505];

void dfs(int x, int y) {
    if (mark[x][y]) return;
    mark[x][y] = true;

    fr(i,0,4) {
        int v = x+dx[i];
        int w = y+dy[i];
        if (grid[v][w]) dfs(v,w);
        if (v == tx && w == ty) mark[v][w] = true; //t is reachable
    }
}

int main() {

    scanf("%d%d\n", &n, &m);
    fr(i,1,n+1) fr(j,1,m+1) {
        char c; scanf("%c", &c);
        grid[i][j] = (c == '.');
        if (j == m) scanf("\n");
    }

    scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
    dfs(sx,sy);

    if (!mark[tx][ty]) {
        puts("NO");
        return 0;
    }

    if (!grid[tx][ty] && (sx!=tx || sy!=ty)) {
        puts("YES");
        return 0;
    }

    if (grid[tx][ty]) {
        grid[sx][sy] = 1;
        int cnt = 0;
        fr(i,0,4) {
            int v = tx+dx[i];
            int w = ty+dy[i];
            cnt += grid[v][w];
        }
        printf("%s\n", (cnt>=2)?"YES":"NO");
        return 0;
    }

    if (sx==tx && sy==ty) {
        fr(i,0,4) {
            int v = tx+dx[i];
            int w = ty+dy[i];
            if (grid[v][w]) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");
    return 0;
}
