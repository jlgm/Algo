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

int n, p;
string s, c1, c2;

int dist(char a, char b) {
    return min(abs(a-b), 26-(abs(a-b)));
}

int cost(string c, int cur) {
    int k = s.size();
    int li = 0, si = k, ans = 0, fnd = 0;

    fr(i,0,k) {
        if (s[i] != c[i]) {
            si = min(si, i);
            li = max(li, i);
            ans += dist(s[i], c[i]);
            fnd++;
        }
    }

    int f1 = abs(cur-si) + abs(si-li);
    int f2 = abs(cur-li) + abs(si-li);

    if (fnd >= 2) return ans + min(f1,f2);
    else if (fnd == 1) return ans + abs(cur-si);
    else return 0;
}

int main() {

    cin >> n >> p; p--;
    cin >> s;
    int k = s.size();

    fr(i,0,k/2)
        c1.pb(s[i]);
    if (k&1) c1.pb(s[k/2]);
    fr(i,0,k/2)
        c1.pb(c1[k/2-i-1]); //first candidate

    for(int i = k-1; i>=k/2; i--)
        c2.pb(s[i]);
    fr(i,0,k/2)
        c2.pb(c2[k/2-i-1]); //second candidate

    printf("%d\n", min(cost(c1, p), cost(c2, p)));
    return 0;
}
