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

struct music {
    int a, b;
};

int n, m;
music ms[111111];

bool cmp(music x, music y) {
    return (x.a-x.b) < (y.a-y.b);
}

int main() {

    scanf("%d%d", &n, &m);
    ll tot_a = 0, tot_b = 0;
    fr(i,0,n) {
        scanf("%d%d", &ms[i].a, &ms[i].b);
        tot_a += ms[i].a;
        tot_b += ms[i].b;
    }

    if (tot_b > m) {
        puts("-1");
        return 0;
    }

    if (tot_a <= m) {
        puts("0");
        return 0;
    }

    sort(ms, ms+n, cmp);
    int ans = n, cur = 0;
    while(tot_b <= m) {
        ans--;
        tot_b -= ms[cur].b;
        tot_b += ms[cur].a;
        cur++;
    }

    printf("%d\n", ans+1);
        
    return 0;
}
