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
vector<string> grid, pattern;

bool match(int x, int y) {
    if (x+m > n) return false;
    if (y+m > n) return false;
    fr(i,0,m) fr(j,0,m) {
        if (pattern[i][j] != grid[x+i][j+y]) return false;
    }
    return true;
}

int count() {
    int ret = 0;
    fr(i,0,n) fr(j,0,n) if (match(i,j)) ret++;
    return ret;
}

void rotate() {
    vector<string> tmp;
    fr(i,0,m) tmp.pb("");
    fr(i,0,m) {
        string aux = pattern[m-i-1];
        fr(j,0,m) tmp[j].pb(aux[j]);
    }
    pattern = tmp;
}

int main() {

    std::ios::sync_with_stdio(false);

    while((cin >> n >> m) && (n||m)) {
        string tmp;
        fr(i,0,n) {
            cin >> tmp;
            grid.pb(tmp);
        }
        fr(i,0,m) {
            cin >> tmp;
            pattern.pb(tmp);
        }
        cout << count() << " ";
        rotate();
        cout << count() << " ";
        rotate();
        cout << count() << " ";
        rotate();
        cout << count() << endl;
        grid.clear(); pattern.clear();
    }

    return 0;
}
