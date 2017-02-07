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

int n, a[100005];

int main() {

    scanf("%d", &n);
    fr(i,0,n) scanf("%d", &a[i]);

    sort(a, a+n);

    fr(i,1,n-1) if (a[i-1]+a[i] > a[i+1]) {
        puts("YES");
        return 0;
    }

    puts("NO");
    return 0;
}
