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

double a, b, c, d;

int main() {

    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    double pa = max(3*a/10, a-(a*c/250));
    double pb = max(3*b/10, b-(b*d/250));

    if (pa==pb) {
        puts("Tie");
        return 0;
    }

    printf("%s\n", (pa>pb)?"Misha":"Vasya");

    return 0;
}
