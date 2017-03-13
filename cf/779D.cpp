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

char a[200005], b[200005];
int p[200005], n, k;
bool mark[200005];

bool check(int val) {
    ms(mark,0);
    fr(i,0,val) mark[p[i]]=1;
    int cur = 0, cnt = 0;
    fr(i,0,k) {
        char c = b[i];
        bool fnd = 0;
        fr(j,cur,n) {
            if (mark[j]) continue;
            if (c == a[j]) {
                cur = j+1;
                cnt++;
                fnd = 1;
                break;
            }
        }
        if (!fnd) return false;
    }
    return cnt == k;
}

int main() {

    scanf("%s", a);
    scanf("%s", b);
    n = strlen(a);
    k = strlen(b);

    fr(i,0,n) scanf("%d", &p[i]), p[i]--;

    int lo = 0, hi = n, mid;
    fr(i,0,50) {
        mid = lo + (hi-lo)/2;
        if (!check(mid)) hi = mid;
        else lo = mid+1;
    }

    printf("%d\n", lo-1);

    return 0;
}
