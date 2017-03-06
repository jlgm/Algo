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

int n, p;
bool mark[100005];

int main() {

    int ans = 0, cur = 0;
    scanf("%d", &n);
    fr(i,0,(2*n)) {
        scanf("%d", &p);
        if (mark[p]) cur--;
        else cur++;
        mark[p] = true;
        ans = max(ans,cur);
    }

    printf("%d\n", ans);

    return 0;
}
