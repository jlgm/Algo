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

int n, d[1000005], sum, cnt[10];
bool possible, mark[1000005];

bool cmp(int a, int b) { return a > b; }

int main() {

    sum = 0;
    scanf("%d", &n);
    fr(i,0,n) {
        scanf("%d", &d[i]);
        sum+=d[i];
        possible|=(d[i]==0);
        cnt[d[i]]++;
    }

    if (!possible) { puts("-1"); return 0; }
    if (sum == 0) { puts("0"); return 0; }
    if (sum % 3 == 0) { sort(d,d+n,cmp); fr(i,0,n) printf("%d", d[i]); return 0; }

    sort(d, d+n);

    while(sum%3 != 0) {
        int mod = sum%3;
        if (mod == 1) {
            bool fnd = false;
            fr(i,0,n) {
                if (cnt[d[i]]==0) continue;
                if (d[i]%3==1) {
                    sum-=d[i];
                    cnt[d[i]]--;
                    fnd = true;
                    break;
                }
            }
            if (!fnd) {
                int tmp = 0;
                fr(i,0,n) {
                    if (cnt[d[i]]==0) continue;
                    if (d[i]%3==2) {
                        sum-=d[i];
                        cnt[d[i]]--;
                        tmp++;
                        if (tmp == 2) break;
                    }
                }
            }
        }
        else {
            bool fnd = false;
            fr(i,0,n) {
                if (cnt[d[i]]==0) continue;
                if (d[i]%3==2) {
                    sum-=d[i];
                    cnt[d[i]]--;
                    fnd = true;
                    break;
                }
            }
            if (!fnd) {
                int tmp = 0;
                fr(i,0,n) {
                    if (cnt[d[i]]==0) continue;
                    if (d[i]%3==1) {
                        sum-=d[i];
                        cnt[d[i]]--;
                        tmp++;
                        if (tmp == 2) break;
                    }
                }
            }
        }
    }

    bool ln = 0;
    for(int i = 9; i >= 1; i--) fr(j,0,cnt[i]) printf("%d", i), ln=1;
    if (ln) fr(i,0,cnt[0]) printf("0");
    else puts("0");

    return 0;
}
