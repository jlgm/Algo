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

int n, a[4000];
map<int, bool> mark;

int main() {
	
	while(scanf("%d", &n) != EOF) {
		fr(i,0,n) scanf("%d", &a[i]);
		
		fr(i,0,n-1) mark[a[i]] = false;
		fr(i,0,n-1) mark[(int)(abs(a[i]-a[i+1]))] = true;
		
		fr(i,0,n-1) if (!(mark[i+1])) { puts("Not jolly"); goto next; }
		
		printf("%s\n", n?("Jolly"):("Not jolly"));
		
		next: ;
		
		mark.clear();
		
	}
	
	return 0;
}







