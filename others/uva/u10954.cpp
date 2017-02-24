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

int n, tmp, resp;

int main() {
	
	while(scanf("%d", &n) != EOF && n) {
		priority_queue<int> heap;
		fr(i,0,n) scanf("%d", &tmp), heap.push(-tmp);
		resp=0;
		while(!heap.empty()) {
			int t1 = heap.top(); heap.pop();
			int t2 = heap.top(); heap.pop();
			heap.push(t1+t2);
			resp += (t1+t2);
			if (heap.size() == 1) break;
		}
		printf("%d\n", -resp);
	}
	
	return 0;
}







