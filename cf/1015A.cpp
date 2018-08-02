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

int n, m;
bool mark[1000];

int main() {

    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        for(int j = x; j <= y; j++)
            mark[j] = true;
    }
    vector<int> ans;
    for(int i = 1; i <= m; i++)
        if (!mark[i]) ans.pb(i);
    
    printf("%d", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%s%d", i?" ":"\n", ans[i]);
    

    return 0;
}
