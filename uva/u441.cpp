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

int k, a[15];

int main() {
	
	bool fst = true;
	
	while(scanf("%d", &k) && k) {
		fr(i,0,k) scanf("%d", &a[i]);
		
		if (!fst) puts("");
	
		fr(i,0,k-5)
			fr(j,i+1,k-4) 
				fr(l,j+1,k-3)
					fr(m,l+1,k-2)
						fr(n,m+1,k-1)
							fr(s,n+1,k)
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[l], a[m], a[n], a[s]);
		
		fst = false;
	}
	
	return 0;
}







