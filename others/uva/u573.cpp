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

int h, u, d, f;

int main() {
	
	while(scanf("%d%d%d%d", &h, &u, &d, &f) != EOF && (h&&u&&d&&f)) {
		int cur = 1, dist = 0;
		h*=100000, u*=100000, d*=100000;
		
		f = (u/100) * f;
		
		bool fst = true;
		while(1) {
			if (!fst) u -= f, u = max(u, 0);
			dist += u;
			if (dist > h) {printf("success on day %d\n", cur);break;}
			dist -= d;
			if (dist < 0) {printf("failure on day %d\n", cur);break;}
			cur++;
			fst = false;
		}
		
	}
	
	return 0;
}







