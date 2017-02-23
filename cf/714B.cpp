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

int n, a[100005], cnt;
map<int, bool> h;

int main() {

    scanf("%d", &n);
    cnt = 0;

    fr(i,0,n) {
        scanf("%d", &a[i]);
        if (h[a[i]] == false) cnt++;
        h[a[i]] = true;
    }

    if (cnt <= 2) {puts("YES"); return 0;}
    if (cnt > 3) {puts("NO"); return 0;}

    sort(a,a+n);
    int f = a[0], mid;
    fr(i,1,n) {
        if (a[i] != f) {
            mid = a[i];
            break;
        }
    }

    int k = abs(a[0]-mid);

    fr(i,0,n) {
        if (a[i] == mid) continue;
        if (a[i]-k != mid && a[i]+k != mid) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}
