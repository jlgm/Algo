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

int dig[10] = {0,1,2,3,4,5,6,7,8,9}, n;
vector<pii> resp[100];

int main() {
	
	bool first = true;
	
	do {
		int a = dig[0]*10000 + dig[1]*1000 + dig[2]*100 + dig[3]*10 + dig[4];
		int b = dig[5]*10000 + dig[6]*1000 + dig[7]*100 + dig[8]*10 + dig[9];
		int tmp = a/b;
		
		if (tmp*b == a) {
			resp[tmp].pb(pii(a,b));
		}
		
	} while(next_permutation(dig, dig+10));
			
	while(scanf("%d", &n) != EOF && n) {
		
		if (!first) puts(""); first = false;
		
		int k = resp[n].size();
		
		if (k) {
			fr(i,0,k) printf("%05d / %05d = %d\n", resp[n][i].F, resp[n][i].S, n);
		}
		else printf("There are no solutions for %d.\n", n);
	}
	
	return 0;
}







