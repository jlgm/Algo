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

#define MAXN 10005 //size of string

string text, pattern;
int f[MAXN];

bool match() {

    int n = text.size();
    int m = pattern.size();

    f[0] = f[1] = 0;

    for(int i = 2; i <= m; i++) {
        int j = f[i-1];
        for(;;) {
            if (pattern[j] == pattern[i-1]) {
                f[i] = j+1; break;
            }
            if (j == 0) {
                f[i] = 0; break;
            }
            j = f[j];
        }
    }
    //f[i] has the size of longest proper suffix of preffix (0,i)

    int i = 0, j = 0;
    for(;;) {
        if (j == n) break; //end of text, no match
        if (text[j] == pattern[i]) {
            i++, j++;
            if (i == m) {
                //match found at position i
                return true;
            }
        }
        else if (i > 0) i = f[i];
        else j++;
    }

    //no match found if it reaches here
    return false;
}

int main() {

    cin >> text;

    while(cin >> pattern) {
        printf("%s\n", match()?"YES":"NO");
    }

    return 0;
}
