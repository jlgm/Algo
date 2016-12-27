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

string a, b;

int go() {
    int k = a.size(), l = b.size(), ans = 0;
    fr(i,0,k) {
        int ii = i, j = 0;
        while(a[ii] == b[j] && ii < k) ii++, j++;
        if (j == l) {
            ans++;
            i+=(l-1);
        }
    }
    return ans;
}

int main() {

    cin >> a >> b;
    cout << go() << endl;

    return 0;
}
