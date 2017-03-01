#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> pii;

#define N 111111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int a[N], ans[N], answer = 0;
int cnt[A];

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void remove(int position) {
    if (a[position] > A) return;
    if(cnt[a[position]] == a[position]) answer--;
	cnt[a[position]]--;
	if(cnt[a[position]] == a[position]) answer++;
}

void add(int position) {
    if (a[position] > A) return;
    if(cnt[a[position]] == a[position]) answer--;
	cnt[a[position]]++;
	if(cnt[a[position]] == a[position]) answer++;
}

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = max(answer,0);
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}
