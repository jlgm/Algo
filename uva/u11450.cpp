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

int m, c, size[25], table[25][25], dp[400][25];
bool found;

int bt(int sum, int idx) {
	if (sum > m) return -1;
	if (dp[sum][idx] != -1) return dp[sum][idx];
	if (idx >= c) {
		found = true;
		return sum;
	}
	int resp = sum;
	for (int i = 0; i < size[idx]; i++) {
		resp = max(resp, bt(sum+table[idx][i], idx+1));
	}
	return dp[sum][idx] = resp;
}

int main() {
	
	int t; scanf("%d", &t); while(t--) {
		ms(dp,-1); found = false;
		scanf("%d%d", &m, &c);
		fr(i,0,c) {
			scanf("%d", &size[i]);
			fr(j,0,size[i]) scanf("%d", &table[i][j]);
		}
		int resp = bt(0,0);
		if (found) printf("%d\n", resp);
		else puts("no solution");
		ms(table,0); ms(size,0);
	}
	
	return 0;
}







