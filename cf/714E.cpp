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

int n, t;
priority_queue<int> q;

int main() {

    scanf("%d%d", &n, &t);
    q.push(t);

    ll ans = 0LL;

    fr(i,1,n) {
        scanf("%d", &t); t-=i;
        q.push(t);
        if (q.top() > t) {
            ans += q.top() - t;
            q.pop();
            q.push(t);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
