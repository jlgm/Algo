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

int a, b, c;

int main() {

    scanf("%d%d%d", &a, &b, &c);

    int resp = 0;

    while(a >= 1 && b >= 2 && c >= 4) {
        resp += 7;
        a-=1; b-=2; c-=4;
    }

    printf("%d\n", resp);


    return 0;
}
