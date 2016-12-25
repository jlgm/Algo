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

ll n;
ll a[30];

map<ll,int> f;

bool cmp(ll a, ll b) {
    return f[a] > f[b];
}

bool can() {
    fr(i,0,n) fr(j,i+1,n) {
        if (a[i] == a[j] && a[i]) return false;
    }
    return true;
}

int main() {

    cin >> n; ll sum = 0;
    fr(i,0,n) {
        cin >> a[i];
        sum+=a[i];
        f[a[i]]++;
    }

    while(!can() && sum) {
        sort(a,a+n, cmp);
        f[a[0]]--;
        a[0]--; f[a[0]]++;
        sum--;
        f[0LL]=0;
    }

    cout << sum << endl;

    return 0;
}
