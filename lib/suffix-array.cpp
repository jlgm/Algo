#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

#define MAX 100001
#define MAXP 1001

int dp[MAX][2], n, h, g, skip, suffix[MAX];
char s[MAX], pattern[MAXP];

int cmp(int i, int j) {
    return (dp[(i += skip) <= n? i : n][h]) < (dp[(j += skip) <= n? j:n][h]);
}

void suffixArray(int len = 1<<30) {
    n = strlen(s);
    for (int i = 0; i <= n; i++)
        suffix[i] = i, dp[i][0] = s[i];
    skip = h = 0, sort(suffix, suffix+n+1,cmp);
    for (skip = 1; skip; skip<<=1) {
        g = -1;
        for (int i = 0, j = 0; i <= n; ) {
            if (j == n+1 || dp[suffix[i]][h] != dp[suffix[j]][h]) {
                sort(suffix+i, suffix+j, cmp);
                dp[suffix[i]][h^1] = ++g;
                while(++i < j) {
                    if (cmp(suffix[i-1],suffix[i])) g++;
                    dp[suffix[i]][h^1] = g;
                }
            }
            else j++;
        }
		h = h^1;
        if (h && g >= n) break;
        else if (skip >= len) break;
    }
}

int lcp(int i, int j) {
    if (i == j) return n-i;
    int len = 0;
    for (int k = h; k >= 0; k--) {
        if (dp[i][k] == dp[j][k]) {
            len += (1<<k);
            i += (1<<k);
            j += (1<<k);
        }
    }
    return len;
}

int comp(int suf) {
    int k = strlen(pattern);
    for (int i = suf; i < n; i++) {
        if (i-suf == k) break;
        if (pattern[i-suf] > s[i]) return -1;
        else if (pattern[i-suf] < s[i]) return 1;
    }
    if (k > n-suf) return -1;
    return 0;
}

bool match() {
    if (strlen(s) == 1) return strlen(pattern) == strlen(s) && pattern[0] == s[0];

    int lo = 0, hi = n, med;
    while (lo<=hi) { //binary search
        med = lo + (hi-lo)/2;
        int result = comp(suffix[med]);
        if (result == 0) {
            return true;
        }
        else if (result < 0) {
            lo = med+1;
        }
        else hi = med-1;
    }
    return false;
}

int main() {
    int N; scanf("%d", &N);
    while(N-- && scanf("%s", s) != EOF) {
        suffixArray(1001);
        int k; scanf("%d", &k);
        while(k--) {
            scanf("%s", pattern);
            printf("%s\n", match()?"y":"n");
        }
        memset(dp, 0, sizeof(dp));
        memset(suffix, 0, sizeof(suffix));
    }

    return 0;
}
