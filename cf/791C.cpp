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

int n, k;
string cmd, cur;
string ans[55];

string next(string a) {
    string tmp = "";
    if (a[1] < 'z') {
        tmp.pb(a[0]); tmp.pb(a[1]+1);
    }
    else {
        tmp.pb(a[0]+1); tmp.pb('a');
    }
    return tmp;
}

int main() {

    scanf("%d%d", &n, &k);
    cur = "Aa";
    rf(i,n-1,0) ans[i] = cur, cur = next(cur);
    fr(i,0,n-k+1) {
        cin >> cmd;
        if (cmd == "NO") {
            ans[n-i-k] = ans[n-i-1];
        }
    }
    rf(i,n-1,0) printf("%s%s", ans[i].c_str(), i?" ":"\n");

    return 0;
}
