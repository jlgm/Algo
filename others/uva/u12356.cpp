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

int s, b;
int L[100005], R[100005];

int main() {

    while(scanf("%d%d", &s, &b) && (s||b)) {

        fr(i,1,s+1) L[i] = i-1, R[i] = i+1;
        L[1] = -1, R[s] = -1;

        while(b--) {
            int x, y;
            scanf("%d%d", &x, &y);

            L[R[y]] = L[x];
            R[L[x]] = R[y];

            if (L[x]==-1) printf("* ");
            else printf("%d ", L[x]);

            if (R[y]==-1) printf("*\n");
            else printf("%d\n", R[y]);

        }
        puts("-");
        // ms(R,0); ms(L,0);
    }

    return 0;
}
