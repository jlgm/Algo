#include <bits/stdc++.h>
using namespace std;

int a[30], k;
string in;

int main() {

    cin >> in;
    scanf("%d", &k);
    int ans = 0, l = 0;
    for(int i = 0; i < 26; i++) 
        scanf("%d", &a[i]), l = max(l, a[i]);
    
    for(int i = 0; i < in.size(); i++)
        ans += (i+1)*a[in[i]-'a'];
    for(int i = 1; i <= k; i++)
        ans += (i+in.size())*l;
    
    printf("%d\n", ans);

    return 0;
}
