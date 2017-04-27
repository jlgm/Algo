#include <cstdio>
#include <cstring>

using namespace std;

int n;

int main() {

	scanf("%d", &n);

	int aux = n, prev, cur;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < n; j++) {
			int ans = i + (j*(n+1));
			if (j == aux) {
				ans = prev + 1;
				cur = ans;
			}
			if (j > aux) {
				ans = cur + ((j-aux)*(n+1));
			}
			prev = ans;
			printf("%d ", ans);
		}
		puts("");
		aux--;
	}


	return 0;
}
