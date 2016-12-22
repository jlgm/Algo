#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <list>
#include <map>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define pb push_back
#define mp make_pair
#define F first 
#define S second 

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const double PI = acos(-1.0);

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

int a, b, c;

int main() {
	
	int t; scanf("%d", &t); fr(caso, 1, t+1) {
		scanf("%d%d%d", &a, &b, &c);
		int mn = min(a,min(b,c));
		int mx = max(a,max(b,c));
		if (a != mn && a != mx) printf("Case %d: %d\n", caso, a);
		else if (b != mn && b != mx) printf("Case %d: %d\n", caso, b);
		else if (c != mn && c != mx) printf("Case %d: %d\n", caso, c);
	}
	
	return 0;
}







