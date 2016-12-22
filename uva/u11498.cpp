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

int x, y;

int main() {
	
	int k; while(scanf("%d", &k) != EOF && k) {
		scanf("%d%d", &x, &y);
		while(k--) {
			int a, b; scanf("%d%d", &a,&b);
			if (a == x || b == y) puts("divisa");
			else {
				if (a < x && b > y) puts("NO");
				else if (a > x && b > y) puts("NE");
				else if (a < x && b < y) puts("SO");
				else if (a > x && b < y) puts("SE");
			}
		}
	}
	
	return 0;
}







