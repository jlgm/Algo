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

int n, k, a[105];
bool mark[105];

int main() {

    scanf("%d%d", &n, &k);
    int st = 0, N = n;
    fr(i,0,k) {
        scanf("%d", &a[i]);
        int d = a[i]%n, cnt = 0;
        while(cnt < d) {
            if (!mark[st++]) cnt++;
            if (st == N) st=0;
        }
        while(mark[st]) st++;
        if (st == N) st = 0;
        while(mark[st]) st++;
        mark[st]=1;
        printf("%d%s", st+1, i==(k-1) ? "\n":" ");
        while(mark[st]) st++;
        if (st == N) st = 0;
        while(mark[st]) st++;
        n--;
    }

    return 0;
}
