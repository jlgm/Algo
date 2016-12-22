#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define pb push_back
#define mp make_pair
#define F X
#define S Y

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n;
string s;
bool canR, canG, canB, mark[205][205][205];

void go(int r, int g, int b) {

    if (mark[r][g][b]) return;
    if (r == 0 && g == 0 && b > 0) {canB = 1; return;} //b++
    if (r == 0 && b == 0 && g > 0) {canG = 1; return;} //g++
    if (b == 0 && g == 0 && r > 0) {canR = 1; return;} //r++

    if (r && g) go(r-1, g-1, b+1);
    if (r && b) go(r-1, g+1, b-1);
    if (g && b) go(r+1, g-1, b-1);

    if (r >= 2) go(r-1, g, b);
    if (g >= 2) go(r, g-1, b);
    if (b >= 2) go(r, g, b-1);

    mark[r][g][b] = 1;
}

int main() {

    int r, g, b;
    r = g = b = 0;

    scanf("%d", &n);
    cin >> s;

    fr(i,0,n) {
        if (s[i] == 'R') r++;
        if (s[i] == 'G') g++;
        if (s[i] == 'B') b++;
    }

    go(r,g,b);

    //printf("%d %d %d\n", r, g, b);

    cout << (canB?"B":"") << (canG?"G":"") << (canR?"R":"") << endl;

    return 0;
}
