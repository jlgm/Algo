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
#define INF 1e7

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, tot;
vector<int> a[3];

bool cmp(int x, int y) { return x > y; }

int best(int k) {

    int ret = tot;
    int it1 = 0, it2 = 0; 
    int one = a[1].size(), two = a[2].size();

    if (k&1) {
        if (one == 0) return ret;
        ret-=a[1][0];
        k--;
        it1++; //
    }
    while(k) {
        int foo = (it1 < one-1) ? a[1][it1]+a[1][it1+1] : 0;
        int bar = (it2 < two) ? a[2][it2] : 0;
        if (foo > bar) ret-=foo, it1+=2;
        else ret-=bar, it2++;
        k-=2;
    }
    return ret;
}

int main() {

    scanf("%d", &n);
    tot = 0;

    fr(i,0,n) {
        int foo, bar;
        scanf("%d%d", &foo, &bar);
        a[foo].pb(bar);
        tot+=bar;
    }

    sort(a[1].begin(), a[1].end(), cmp);
    sort(a[2].begin(), a[2].end(), cmp);

    int cand = 0, sum = tot;

    while(cand < sum) {
        cand += 1;
        sum = best(cand);
    }

    printf("%d\n", cand);

    return 0;
}
