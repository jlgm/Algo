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

string s;
int k;

int zeros() {
    int K = s.size(), ret = 0;
    fr(i,0,K) if (s[i]=='0') ret++;
    return ret;
}

int main() {

    cin >> s >> k;
    int z = zeros();
    if (z < k) {
        printf("%d\n", (int)s.size()-1);
        return 0;
    }

    int K = s.size(), tmp = 0, ans = 0;
    rf(i,K-1,0) {
        if (tmp == k) break;
        if (s[i]=='0') tmp++;
        else ans++;
    }

    printf("%d\n", ans);

    return 0;
}
