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

string s, pok;
int cnt[1000];

int main() {

    cin >> s;
    int k = s.size();

    fr(i,0,k) {
        cnt[s[i]]++;
    }

    pok = "Bulbasaur";
    cnt['u']/=2; cnt['a']/=2;

    k = pok.size(); int ans = s.size();
    fr(i,0,k) ans = min(ans, cnt[pok[i]]);

    printf("%d\n", ans);

    return 0;
}
