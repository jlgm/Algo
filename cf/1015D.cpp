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

int n, k, s;

int main() {

    scanf("%d%d%d", &n, &k, &s);
    if (k*9 < s) {
        puts("NO");
        return 0;
    }
    int a = s/9;
    int b = s%9;
    int next = 10;

    for(int i = 0; i < a; i++) {
        printf("%d ", next);
        next = ((next == 10) ? 1 : 10);
    }

    if (b == 0) {
        printf("%s\n", next == 10? "1 2" : "1 2");
    }
    else printf("%d\n", (next == 10)? b : 10-b);

    return 0;
}
