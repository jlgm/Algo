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

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int n, k, g, b;

char next(char c) {
    if (c == 'B') return 'G';
    else return 'B';
}

int main() {
    scanf("%d%d%d%d", &n, &k, &g, &b);

    string ans = "";

    int load = 0;

    char last = 'C';

    fr(i,0,n) {
        //db(ans); db(g); db(b);
        if (g == b) {
            for (int j = i; j < n; j++) {
                ans.pb(next(last));
                last = next(last);
            }
            break;
        }

        if (load < k) {
            if (g > b) {
                ans.pb('G'), g--;
                if (last == 'G') load++;
                else load = 1;
                last = 'G';
            }
            else if (b > g) {
                ans.pb('B'), b--;
                if (last == 'B') load++;
                else load = 1;
                last = 'B';
            }
        }

        else {
            if (last == 'B' && g == 0) break;
            else if (last == 'G' && b == 0) break;

            if (last == 'B') {
                ans.pb('G'), g--;
                load = 1;
                last = 'G';
            }
            else {
                ans.pb('B'), b--;
                load = 1;
                last = 'B';
            }
        }
    }

    if (ans.size() != n) printf("NO\n");
    else cout << ans << endl;

    return 0;
}
