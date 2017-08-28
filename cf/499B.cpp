#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;//, c[3003];
map<string,string> atob, btoa;

int main() {

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        atob[a] = b;
        btoa[b] = a;
    }
    for(int i = 0; i < n; i++) {
        cin >> a;
        if (atob.find(a) != atob.end()) b = atob[a];
        else b = btoa[a];
        
        if (a.size() == b.size()) printf("%s%s", i?" ":"", a.c_str());
        else printf("%s%s", i?" ":"", a.size() < b.size() ? a.c_str() : b.c_str());
    }

    return 0;
}
