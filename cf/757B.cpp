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

int n, a[100005], cnt[100005];
bool primes[100005];
vector<int> p;

int main() {

    ms(primes,1);
    primes[1] = 0;
    primes[2] = 1;

    for (int i = 2; i <= 100002; i++) {
        if (!primes[i]) continue;
        for (int j = i+i; j <= 100002; j+=i) {
            primes[j] = false;
        }
    }

    scanf("%d", &n);
    fr(i,0,n) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    fr(i,2,100001) if (primes[i]) p.pb(i);

    if (n == 1) {
        puts("1");
        return 0;
    }

    int k = p.size(), ans = 1;
    fr(i,0,k) {
        int tmp = 0;
        for(int j = p[i]; j <= 100000; j+=p[i]) {
            tmp += cnt[j];
        }
        ans = max(ans,tmp);
    }

    printf("%d\n", ans);

    return 0;
}
