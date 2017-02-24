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

int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1}, cnt[13], n;
double N;

int main() {

    scanf("%lf", &N);
    n = N*100;

    int cur = 0;
    while(n) {
        while(n >= coins[cur] && cur < 12) {
            n-=coins[cur];
            cnt[cur]++;
        }
        cur++;
    }
    puts("NOTAS:");
    fr(i,0,6) printf("%d nota(s) de R$ %.2lf\n", cnt[i], (double)coins[i]/100.0);
    puts("MOEDAS:");
    fr(i,6,12) printf("%d moeda(s) de R$ %.2lf\n", cnt[i], (double)coins[i]/100.0);
    
    return 0;
}
