// https://turing13.wordpress.com/2016/03/11/uva-10616-divisible-group-sums/

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int ara[250];
int dp[210][15][25];
int m, n, q, d;

ll value(int index, int count, int sum) {
    if(count == m) {
        if(sum == 0) return 1;
        return 0;
    }
    if(index >= n) return 0;
    if(dp[index][count][sum] != -1) return dp[index][count][sum];
    int temp = (sum + ara[index])%d;
    if(temp < 0) temp += d;

    ll xx = value(index+1, count+1, temp);
    ll yy = value(index+1, count, (sum)%d);

    return dp[index][count][sum] = xx+yy;
}

int main() {
    int caseInd = 1;
    while(true) {
        scanf("%d %d", &n, &q);
        if(n == 0 && q == 0) break;

        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
        }

        printf("SET %d:\n", caseInd);
        caseInd++;

        for(int i = 0; i < q; i++) {
            scanf("%d %d", &d, &m);
            memset(dp, -1, sizeof(dp));
            printf("QUERY %d: %lld\n", i+1, value(0, 0, 0));
        }
    }
}
