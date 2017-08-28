#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

string a;

bool iseven(char c) {
    return c == '2' || c == '4' || c=='6' || c == '8' || c == '0';
}

int main() {

    cin >> a;
    int l = -1;

    for(int i = 0; i < a.size()-1; i++) {
        if (iseven(a[i])) {
            l = i;
            if (a[i] < a[a.size()-1]) 
                break;
        }
    }

    if (l != -1) {
        swap(a[l], a[a.size()-1]);
        puts(a.c_str());
    }
    else puts("-1");

    return 0;
}
