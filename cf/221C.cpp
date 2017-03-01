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

int n, a[100005], b[100005];

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]), b[i]=a[i];

    sort(b,b+n);
    int ans = 0;
    fr(i,0,n) {
        if (a[i] != b[i]) ans++;
    }

    if (ans <= 2) puts("YES");
    else puts("NO");

    return 0;
}
