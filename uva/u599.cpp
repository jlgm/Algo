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

vector<int> adj[30];
bool exists[30], mark[30];

int dfs(int v) {
	if (mark[v]) return -1;
	mark[v] = true;
	int ret = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		dfs(adj[v][i]);
		ret++;
	}
	return ret;
}

int main() {
	
	int t; scanf("%d\n", &t); while(t--) {
		char a,b, buf[1000];
		
		while (scanf("%s\n", buf) != EOF && buf[0] != '*') {
			sscanf(buf, "(%c,%c)", &a, &b);
			adj[a-'A'].pb(b-'A');
			adj[b-'A'].pb	(a-'A');
		}
		
		string s;
		getline(cin, s); 
		
		ms(exists,0);
		
		fr(i,0,s.size()) if (s[i] >= 'A' && s[i] <= 'Z') exists[s[i]-'A'] = true;
		
		ms(mark,0); int resp1 = 0, resp2 = 0;
		
		fr(i,0,30) if (exists[i]) {
			if (mark[i]) continue;
			int tmp = dfs(i);
			if (tmp == 1) resp1++;
			else resp2++;
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n", resp2, resp1);
		
		fr(i,0,30) adj[i].clear();
		
	}
	
	return 0;
}







