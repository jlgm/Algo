#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define dg(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

string a, b;

vector<int> divs(int n) {
    vector<int> ret;
    int k = sqrt(n) + 1;
    fr(i,1,k) {
        if (n%i == 0) {
            ret.pb(i);
            ret.pb(n/i);
        }
    }
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}

bool checkA(string s, int k) {
    int size = s.size();
    fr(i,0,k) {
        fr(j,0,size) {
            if (s[j] != a[i*size+j]) return false;
        }
    }
    return true;
}

bool checkB(string s, int k) {
    int size = s.size();
    fr(i,0,k) {
        fr(j,0,size) {
            if (s[j] != b[i*size+j]) return false;
        }
    }
    return true;
}


int main() {

    cin >> a >> b;

    vector<int> da = divs(a.size());
    vector<int> db = divs(b.size());

    int ans = 0;

    fr(i,0,da.size()) {
        int k = a.size() / da[i];
        fr(j,0,db.size()) {
            int l = b.size() / db[j];
            if (l != k) continue;
            string tmp = a.substr(0,k);
            string tmp2 = b.substr(0,l);
            ans += (checkA(tmp, da[i]) && checkB(tmp2, db[j]) && (tmp==tmp2));
        }
    }

    cout << ans << endl;

    return 0;
}
