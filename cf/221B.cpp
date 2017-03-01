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

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long ll;
typedef pair<int, int> pii;

int x;
vector<int> dvs;

bool ok(int a, int b) {
    string s1 = tostr(a);
    string s2 = tostr(b);
    fr(i,0,s1.size()) {
        fr(j,0,s2.size()) {
            if (s1[i] == s2[j]) return true;
        }
    }
    return false;
}

int main() {

    scanf("%d", &x);

    int sq = sqrt(x);
    for (int i = 1; i <= sq; i++) {
        if (x%i==0) {
            dvs.pb(i);
            if (x/i != i) dvs.pb(x/i);
        }
    }

    int ans = 0;
    fr(i,0,dvs.size()) {
        if (ok(x,dvs[i])) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
