#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, a[100005], b[100005], c[100005];

bool issol(int f, int l) {
    int idx = 0;
    while(c[idx] != a[f]) idx++;
    for(; f <= l; f++) {
        if (c[idx++] != a[f]) return false;
    }
    return true;
}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]), b[i] = c[i] = a[i];;
    
    sort(b,b+n);
    sort(c,c+n,greater<int>());

    int f = -1, l = -1;
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (f == -1) f = i;
            l = i;
        }
    }

    if (f == -1) {
        puts("yes\n1 1");
        return 0;
    }

    //printf("%d %d\n",f,l);
    if (issol(f, l)) {
        printf("yes\n%d %d\n", f+1, l+1);
    }
    else puts("no");

    //printf("%d %d\n", b[0], c[0]);
    return 0;
}