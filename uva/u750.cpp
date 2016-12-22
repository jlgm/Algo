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

int row[8], a, b, t, cont;

bool possible(int r, int c) {
	fr(i,0,c) if (row[i] == r || (abs(row[i]-r) == abs(i-c))) return false;
	return true;
}

void bt(int c) {
	
	if (c == 8 && row[b] == a) {
		printf("%2d      ", cont++);
		for (int i = 0; i < 8; i++) printf("%s%d", i?" ":"", row[i]+1);
		puts("");
		return;
	}
	
	for (int r = 0; r < 8; r++)
		if (possible(r,c)) { row[c] = r; bt(c+1); }
}

int main() {
	
	scanf("%d", &t); while(t--) {
		cont = 1;
		scanf("%d%d", &a, &b);
		a--; b--;
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
		bt(0);
		printf("%s", t?"\n":"");
	}
	
	return 0;
}







