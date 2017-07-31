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

int n, k, a[2003];

int main() {

    scanf("%d%d", &n, &k);

    int cnt = 0;
    fr(i,0,n) {
        scanf("%d", &a[i]);
        if (a[i] + k <= 5) cnt++;
    }

    printf("%d\n", cnt/3);

    return 0;
}
