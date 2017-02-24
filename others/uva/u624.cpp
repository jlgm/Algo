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

int n, m, a[25];

int main() {
	
	while(scanf("%d", &n) != EOF) {
		scanf("%d", &m); fr(i,0,m) scanf("%d", &a[i]);
		int resp = -1, resp1;
		fr(i,1,(1<<m)) {
			int sum = 0;
			fr(j,0,m) {
				if ((1<<j)&i) sum += a[j];
				if (sum > n) goto next;
			}
			if (sum >= resp) {
				resp1 = i;
				resp = sum;
			}
			next: ;
		}
		fr(i,0,m) if ((1<<i)&resp1) printf("%d ", a[i]);
		printf("sum:%d\n", resp);
	}
	return 0;
}







