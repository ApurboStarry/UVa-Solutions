#include <bits/stdc++.h>

using namespace std;

int M, C, price[25][25];
int memo[210][25];

int shop(int money, int g) {
    if(money < 0) return -100000;
    if(g == C) return M-money;
    if(memo[money][g] != -1) return memo[money][g];
    int ans = -1;
    for(int model = 1; model <= price[g][0]; model++) {
        ans  = max(ans, shop(money - price[g][model], g+1));
    }
    return memo[money][g] = ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &M, &C);
        memset(price, 0, sizeof(price));
        memset(memo, -1, sizeof(memo));

        for(int i = 0; i < C; i++) {
            scanf("%d", &price[i][0]);
            for(int j = 1; j <= price[i][0]; j++) {
                scanf("%d", &price[i][j]);
            }
        }
        int score = shop(M, 0);
        if(score < 0) printf("no solution\n");
        else printf("%d\n", score);
    }
}















