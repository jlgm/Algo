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

int a, b;

int main() {

    scanf("%d%d", &a, &b);
    int cnt = 0;
    while(a<=b) {
        a*=3;
        b*=2;
        cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
