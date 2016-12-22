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

#define eps 1e-9

const double PI = acos(-1.0);

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

string s, lixo;
int d, n, cont;

struct Type {
	int km, v;
	string type;
} t[50];

bool simulate(double x) {
	
	int f = t[0].v;
	int prev = 0;
	int isleaking = 0;
	double origX = x;
	
	fr(i,1,cont) {
		x -= (double)f*(double)(t[i].km-prev)/100.0;
		if (t[i].type == "fuel") f = t[i].v;
		if (isleaking) x-= isleaking*(double)((double)t[i].km-(double)prev);
		if (x < 0) return false;
		if (t[i].type == "leak") isleaking++;
		if (t[i].type == "mec") isleaking = 0;
		prev = t[i].km;
		if (t[i].type == "gas") x = origX;
	}
	return x >= 0.0;
}

int main() {
	cont = 0;
	
	while(cin >> d >> s) {
		if (s == "Fuel") {
			cin >> lixo >> n; if (n == 0) return 0;
			t[cont].type = "fuel";
			t[cont].km = d;
			t[cont].v = n;
			cont++;
		}
		
		else if (s == "Goal") {
			t[cont].type = "goal";
			t[cont].km = d;
			cont++;
			
			double lo = 0.0, hi = 10000.0, mid = 0.0;//, ans = 0.0;
			while(abs(lo-hi) > eps) {
				mid = (lo+hi)/2.0;
				if (simulate(mid)) hi = mid;
				else lo = mid;
			}
			
			printf("%.3lf\n", mid);
			
			cont = 0;
		}
		
		else if (s == "Leak") {
			t[cont].type = "leak";
			t[cont].km = d;
			cont++;
		}
		
		else if (s == "Gas") {
			cin >> lixo;
			t[cont].type = "gas";
			t[cont].km = d;
			cont++;
		}
		
		else if (s == "Mechanic") {
			t[cont].type = "mec";
			t[cont].km = d;
			cont++;
		}
	}
	
	return 0;
}







