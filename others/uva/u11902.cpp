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


int graph[102][102], mark[102], n;
bool sol[102];

void dfs(int v, int f) {
	if (mark[v]) return;
	if (v == f) return;
	mark[v] = true;
	fr(i,0,n) if (graph[v][i]) dfs(i, f);
}

int main() {
	int t; scanf("%d", &t); fr(caso,1,t+1) {
		ms(graph,0);
		scanf("%d", &n);
		fr(i,0,n) fr(j,0,n) scanf("%d", &graph[i][j]);
		ms(sol,0); ms(mark,0);
		printf("Case %d:\n", caso);
		printf("+"); fr(i,0,2*n-1) printf("-"); printf("+\n");
		dfs(0, n);
		fr(i,0,n) if (mark[i]) sol[i]=true;
		fr(i,0,n){
			ms(mark, 0); dfs(0,i);
			fr(j,0,n) {
				if (!sol[i] || !sol[j]) { printf("|N"); continue; }
				if (!mark[j]) printf("|Y");
				else printf("|N");
			}
			puts("|");
			printf("+"); fr(i,0,2*n-1) printf("-"); printf("+\n");
		}
	}
	return 0;
}

