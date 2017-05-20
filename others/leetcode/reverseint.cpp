#include <bits/stdc++.h>
using namespace std;

//--start of algorithm--
int my_reverse(int x) {
    int ans = 0;
    while(x) {
        ans *= 10;
        ans += x%10;
        x/=10;
    }
    return ans * (x<0 ? -1 : 1);
}

int reverse(int x) {
    int ans = my_reverse(x);
    while(x%10==0 && x) x/=10;
    if (my_reverse(ans) != x) return 0;
    return ans;
}
//--end of algorithm--

//--start of testing--
int main() {

    printf("%d\n", reverse(1234567899));
    printf("%d\n", reverse(0));

    return 0;
}
//--end of testing--
