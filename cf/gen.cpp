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

//use this code to generate personalized inputs

int h[100005], a[100005];

int main() {

    puts("999");
    int k = 0;
    fr(i,1,1000) {
        printf("%d ", i+k);
        if (i&1) k+=2;
        else k++;
    }

    return 0;
}
