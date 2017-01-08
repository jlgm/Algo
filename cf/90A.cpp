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

int a,b,c;

int main() {

    scanf("%d%d%d", &a, &b, &c);

    int ans = 0;
    while(a+b+c > 0) {
        if (ans%3==0) a-=2; a=max(a,0);
        if (ans%3==1) b-=2; b=max(b,0);
        if (ans%3==2) c-=2; c=max(c,0);
        ans++;
    }
    ans-=1;
    printf("%d\n", ans+30);

    return 0;
}
