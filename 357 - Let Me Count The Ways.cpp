#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int coins[] = {1, 5, 10, 25, 50}, N = 5;
ll memo[6][30005];

ll ways(int type, int value) {
    if(value == 0) return 1;
    if(value < 0 || type == N) return 0;
    if(memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type+1, value) + ways(type, value - coins[type]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int v;
    while(scanf("%d", &v) != EOF) {
        ll res = ways(0, v);
        if(res > 1) {
            printf("There are %lld ways to produce %d cents change.\n", res, v);
        } else {
            printf("There is only 1 way to produce %d cents change.\n", v);
        }
    }

}


















