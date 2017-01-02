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

int n;

void format(int c) {
    fr(i,0,(n-c)*2) printf(" ");
    fr(i,0,c) printf("%s%d", i?" ":"", i);
    for(int i = c; i >= 0; i--) printf("%s%d%s", c?" ":"", i, i?"":"\n");
}

int main() {

    scanf("%d", &n);

    fr(i,0,n) format(i);
    for(int i = n; i >= 0; i--) format(i);

    return 0;
}
