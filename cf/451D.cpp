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

string s;
ll cnt[2][2];

int main() {

    cin >> s;
    int k = s.size();
    pair<ll,ll> ans;

    fr(i,1,k+1) {
        int c = s[i-1]-'a';
        ans.X += cnt[c][!(i%2)];
        ans.Y += cnt[c][i%2]+1;
        cnt[c][i%2]++;
    }

    printf("%lld %lld\n", ans.X, ans.Y);

    return 0;
}
