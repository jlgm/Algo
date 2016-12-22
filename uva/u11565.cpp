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

int a, b, c, z1, z2, z3;

int main() {
	
	int t; scanf("%d", &t); while(t--) {
	
		scanf("%d%d%d", &a, &b, &c);
		
		int r = min(a,b); r = min(r,c);
		
		for (int i = -101; i < 101; i++)
			for (int j = -101; j < 101; j++) {
				z1 = a - (i+j);
				(i&&j)?(z2 = b/(i*j)):(z2=-1);
				z3 = (int) sqrt(c - (i*i + j*j));
				if (z1 == z2 && z2 == z3 && i != j && j != z1 && i != z1) {
					if (z1 < i) swap(z1,i);
					else if (z1 < j) swap(z1,j);
					
					printf("%d %d %d\n", i, j, z1);
					goto next;
				}
			}
		puts("No solution.");
		next : ;
	}
	
	return 0;
}







