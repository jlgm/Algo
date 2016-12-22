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

int dx[] = {1, 1, 1, 0, 0,-1,-1,-1};
int dy[] = {1, 0,-1, 1,-1, 1, 0,-1};

char grid[105][105];
int row, col;

int count(int r, int c) {
	if (r < 0 || r > row || c < 0 || c > col) return 0;
	if (grid[r][c] != 'W') return 0;
	int ret = 1;
	grid[r][c] = '.';
	for (int i = 0; i < 8; i++) {
		ret += count(r+dx[i], c+dy[i]);
	}
	return ret;
}

int main() {
	
	bool fst = true;
	string s;
	
	int t; scanf("%d\n\n", &t); 
	
	while(t--) {
		int k = 0; row = 0;
		
		while(getline(cin, s)) {
			if (!(s[0] == 'L' || s[0] == 'W')) break;
			fr(i,0,s.size()) grid[row][i] = s[i];
			col = s.size();
			row++;
		}
		
		do {
			if (!(isdigit(s[0]))) break;
			int a, b;
			sscanf(s.c_str(), "%d%d", &a,&b);
			printf("%d\n", count(a-1,b-1));
			fr(i,0,row) {
				fr(j,0,col) if (grid[i][j] == '.') grid[i][j] = 'W';//printf("%c", grid[i][j]);
				// puts("");
			}
		} while(getline(cin, s));
		
		fst = false;
		// printf("t: %d", t);
		if (t) puts("");
	}
	
	
	return 0;
}







