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
    int k = (n-c)*2;
    fr(i,0,k) printf(" ");
    fr(i,0,c) printf("%s%d", i?" ":"", i);
    printf("%s%d", c?" ":"", c);
    for(int i = c-1; i >= 0; i--) printf("%s%d", " ", i);
    puts("");
}

int main() {

    scanf("%d", &n);

    fr(i,0,n) format(i);
    format(n);
    for(int i = n-1; i >= 0; i--) format(i);

    return 0;
}
