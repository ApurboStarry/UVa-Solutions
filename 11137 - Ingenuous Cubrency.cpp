#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ull dp[10000];

int main() {
    int coins[21];
    for(int i = 0; i < 21; i++) {
        coins[i] = (i+1)*(i+1)*(i+1);
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 21; i++) {
        for(int j = coins[i]; j < 10000; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    int inp;
    while(scanf("%d", &inp) != EOF) {
        printf("%lld\n", dp[inp]);
    }
}


















