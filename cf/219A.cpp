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

int k, cnt[26];
string s;

int main() {

    scanf("%d", &k);
    cin >> s;

    int size = s.size();
    fr(i,0,size) cnt[s[i]-'a']++;

    fr(i,0,26) if (cnt[i]%k != 0 && cnt[i] != 0) {
        puts("-1");
        return 0;
    }

    fr(j,0,k) {
        fr(i,0,26) if (cnt[i]) {
            int amt = cnt[i]/k;
            fr(l,0,amt) printf("%c", i+'a');
        }
    }
    puts("");

    return 0;
}
