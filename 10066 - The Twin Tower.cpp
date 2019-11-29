#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

int tower1[105], tower2[105], dp[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2, towerNumber = 1;
    while(true) {
        scanf("%d %d", &n1, &n2);
        if(n1+n2 == 0) break;

        for(int i = 0; i < n1; i++) {
            scanf("%d", &tower1[i]);
        }

        for(int i = 0; i < n2; i++) {
            scanf("%d", &tower2[i]);
        }

        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(tower1[i-1] == tower2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else {
                    dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
                }
            }
        }
        printf("Twin Towers #%d\n", towerNumber);
        printf("Number of Tiles : %d\n\n", dp[n1][n2]);

        towerNumber++;
    }
}


















