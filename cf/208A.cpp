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

string s;

int main() {

    cin >> s;

    string ans = "";

    int k = s.size();
    int i, f = true;

    for (i = 0; i < k-2; i++) {
        if (s.substr(i,3) == "WUB") {
            i+=2;
            if (!f) ans += ' ', f = true;
        }
        else ans += s[i], f = false;
    }

    if (i < k) fr(j,i,k) ans+=s[j];

    printf("%s\n", ans.c_str());

    return 0;
}
