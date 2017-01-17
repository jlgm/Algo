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

string s;
int p[200005];

string fix(string in) {
    int k = in.size();
    string ret = "";
    fr(i,0,k) {
        char cur = in[i];
        ret.pb(cur);
        int cnt = 1;
        while(i+1 < k && in[i+1]==cur) {
            if (cnt < 2) ret.pb(in[i]);
            cnt++;
            i++;
        }
    }
    return ret;
}

int main() {

    cin >> s;
    s = fix(s);

    int k = s.size();
    fr(i,0,k-1) p[i] = s[i]==s[i+1];

    int i;
    for(i = 0; i < k ; i++) {
        if (p[i]==0) printf("%c", s[i]);
        if (p[i]==1) {
            printf("%c%c", s[i],s[i]);
            if (i+2 < k && p[i+2]==1) printf("%c", s[i+2]), i+=2;
            i+=1;
        }
    }
    puts("");

    return 0;
}
