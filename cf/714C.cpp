#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

int t;
map<ll, int> h, g;

ll transform(ll val) {
    string t = "";

    while(val) {
        ll tmp = val%10;
        val/=10;
        if (tmp%2) t.pb('1');
        else t.pb('0');
    }
    reverse(t.begin(), t.end());

    ll ret = 0;
    sscanf(t.c_str(), "%lld", &ret);

    return ret;
}

int main() {

    scanf("%d\n", &t);
    while(t--) {
        char c;
        ll val;
        scanf("%c %lld\n", &c, &val);
        if (c == '+') {
            h[val]++;
            g[transform(val)]++;
        }
        if (c == '-') {
            h[val]--;
            g[transform(val)]--;
        }
        if (c == '?') {
            printf("%d\n", g[val]);
        }
    }

    return 0;
}
