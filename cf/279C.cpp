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

int n, m, a[100005], in[100005], dc[100005];

int main() {

    scanf("%d%d", &n, &m);
    fr(i,0,n) scanf("%d", &a[i]);
    fr(i,0,n) in[i] = dc[i] = i;
    fr(i,0,n) {
        int cur = i+1, prev = i;
        while(a[cur] >= a[prev] && cur < n) cur++, prev++;
        fr(j,i,cur-1) in[j] = cur-1;
        i+=(cur-i-1);
    }
    fr(i,0,n) {
        int cur = i+1, prev = i;
        while(a[cur] <= a[prev] && cur < n) cur++, prev++;
        fr(j,i,cur-1) dc[j] = cur-1;
        i+=(cur-i-1);
    }

    fr(i,0,m) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        printf("%s\n", (dc[in[x]] >= y) ? "Yes" : "No");
    }

    return 0;
}
