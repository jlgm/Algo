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
#define maxn 1000006

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

char s[maxn];
int f[maxn], n;
bool mark[maxn];

int main() {

    cin >> s;
    f[0] = 0;
    n = 1;
    for(int i = 1; s[i]; i++, n++) {
        int j = f[i-1];
        while(j && s[j] != s[i]) j = f[j-1];
        if (s[j] == s[i]) j++;
        f[i] = j;
        if (i) mark[f[i-1]] = 1;
    }

    for(int i = f[n-1]; i; i = f[i-1])
        if (mark[i]) {
            s[i] = '\0';
            printf("%s\n", s);
            return 0;
        }
    puts("Just a legend");
    return 0;
}
