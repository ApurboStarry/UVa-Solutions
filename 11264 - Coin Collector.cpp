/*
 * https://algorithmist.com/wiki/UVa_11264
 */

#include <bits/stdc++.h>

using namespace std;

int coins[1002];

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        memset(coins, 0, sizeof(coins));
        for(int i = 0; i < n; i++) {
            scanf("%d", &coins[i]);
        }

        int sum = coins[0], ans = 1;

        for(int i = 1; i < n-1; i++) {
            if(sum+coins[i] < coins[i+1]) {
                sum += coins[i];
                ans++;
            }
        }
        if(n == 1) {
            printf("1\n");
        } else {
            printf("%d\n", ans+1);
        }
    }
}
















