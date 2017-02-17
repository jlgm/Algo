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

#define B 3
#define M 1000000000000000003LL

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, p[600005];
unordered_map<ll, bool> hs;
char s[600005];

int main() {

    fr(i,0,600005) p[i] = (i ? (p[i-1]*B)%M : 1LL);

    scanf("%lld%lld\n", &n, &m);
    fr(i,0,n) {
        scanf("%s", s);
        ll h = 0; int k = strlen(s);
        fr(i,0,k) h = (h*B+s[i]-'a')%M;
        hs[h] = true;
    }

    fr(i,0,m) {
        scanf("%s", s);
        ll h = 0LL; int k = strlen(s);
        fr(i,0,k) {
            h = (h*B+(s[i]-'a'));
            h %= M;
        }
        fr(i,0,k) fr(j,0,3) {
            if (s[i]-'a' == j) continue;
            ll nh = h;
            nh -= ((s[i]-'a')*p[k-1-i]);
            nh += (j*p[k-1-i]);
            nh = (nh%M+M)%M;
            if (hs[nh]) {
                puts("YES");
                goto next;
            }
        }
        puts("NO");
        next: ;
    }

    return 0;
}
