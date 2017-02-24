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

vector<int> adj[1000001];
int n, m, tmp;

int main() {
	
	while(scanf("%d%d", &n, &m) != EOF) {
		fr(i,0,n) scanf("%d", &tmp), adj[tmp].pb(i);
		while(m--) {
			int k, v; scanf("%d%d", &k, &v);
			tmp = adj[v].size();
			printf("%d\n", k<=tmp?(adj[v][k-1]+1):0);
		}
		fr(i,0,1000001) adj[i].clear();
	}
	
	return 0;
}







