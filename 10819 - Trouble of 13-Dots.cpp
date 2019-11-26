// https://algorithmist.com/wiki/UVa_10819

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int price[100], favour[100], dp[103][10003];
int n, m;

int knapsack(int index, int cost) {
    if(cost > m && m <= 1800) return INT_MIN;
    if(cost > m+200) return INT_MIN;
    if(index == n) {
        if(cost > m && cost <= 2000) return INT_MIN;
        return 0;
    }
    if(dp[index][cost] != -1) return dp[index][cost];
    return dp[index][cost] = max(knapsack(index+1, cost), favour[index] + knapsack(index+1, cost + price[index]));
}

int main() {
    while(scanf("%d %d", &m, &n) != EOF) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &price[i], &favour[i]);
        }
        printf("%d\n", knapsack(0, 0));
    }
}
