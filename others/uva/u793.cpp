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

/* disjoint-set - created by jlgm */

const int maxn = 100000;
int r[maxn], p[maxn], s[maxn];

int findset(int i) {return (p[i] == i)?(i):(p[i] = findset(p[i]));}
bool issame(int i, int j) {return findset(i) == findset(j);}
int getsize(int i) {return (p[i] == i)?(s[i]):(s[findset(i)]);}
void create(int i) {p[i] = i; s[i] = 1;/*r[i] = 0; //not using this, check \/ */}

void setunion(int i, int j) {
    if (!issame(i,j)) {
        int x = findset(i); int y = findset(j);
        s[p[y]] += getsize(x);
        p[x] = p[y]; //no ranking heuristic for now. might implement that later
    }
}

int main() {

    bool fst = true;
    int t; scanf("%d", &t); while(t--) {
        ms(p,0); ms(r,0);
        int n; scanf("%d\n", &n); fr(i,1,n+1) create(i);
        string s;
        int ans1 = 0, ans2 = 0;
        while(getline(cin, s) && s.size() > 1) {
            char c; int a, b;
            sscanf(s.c_str(), "%c%d%d", &c, &a, &b);
            if (c == 'c') setunion(a, b);
            if (c == 'q') {
                bool same = issame(a,b);
                ans1 += same; ans2 += !same;
            }
        }
        printf("%s%d,%d\n", fst?"":"\n", ans1, ans2);
        fst = false;
    }

    return 0;
}
