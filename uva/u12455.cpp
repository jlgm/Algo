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

int n, p, a[25];

int main() {
	
	int t; scanf("%d", &t); while(t--) {
		scanf("%d%d", &n, &p);
		fr(i,0,p) scanf("%d", &a[i]);
		
		for(int i = 0; i <= (1 << p); i++) {
			int sum = 0;
			fr(j,0,p) if (i&(1 << j)) sum += a[j];
			if (sum == n) {
				puts("YES");
				goto next;
			}
		}
		puts("NO");
		next: ;
	}
	return 0;
}







