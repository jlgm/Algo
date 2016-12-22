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

string s, t;
int val, k;

double cnt(int i, int pts ) {

    if (i == k) return pts == val;
    if (t[i]=='+') return cnt(i+1, pts+1);
    if (t[i]=='-') return cnt(i+1, pts-1);

    return 0.5*(cnt(i+1, pts+1)+cnt(i+1,pts-1));
}

int main() {

    cin >> s >> t;

    val  = 0;
    k = s.size();

    fr(i,0,k) {
        if (s[i] == '+') val++;
        else val--;
    }

    printf("%.12lf\n", cnt(0,0));

    return 0;
}
