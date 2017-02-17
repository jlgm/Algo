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

#define MOD 997 //(prime number)
#define B 256 //size of alphabet

string text, pattern;

inline int int_mod(int a, int b)  {return (a%b+b)%b;}

bool match() {

    int n = text.size();
    int m = pattern.size();

    if (n < m) return false;

    int p = 1;
    fr(i,0,m-1) p = int_mod(p*B, MOD);

    int hp = 0, ht = 0;
    fr(i,0,m) {
        hp = int_mod(hp*B + (pattern[i]), MOD); //hash for pattern
        ht = int_mod(ht*B + (text[i]), MOD); //hash for text
    }

    fr(i,0,n-m+1) {
        if (ht == hp) {
            //high chance of being a match
            //check characters to be 100% sure because it might be a false positive
            //another option is to create double hash (using another MOD) and check if both hashes match
            return true;
        }
        if (i < n-m) {
            ht = int_mod((B*(ht - text[i]*p) + text[i+m]), MOD);
        }
    }

    //no match found
    return false;
}

int main() {

    cin >> text;

    while(cin >> pattern) {
        printf("%s\n", match()?"YES":"NO");
    }

    return 0;
}
