// https://turing13.wordpress.com/2015/04/18/uva-11517-exact-change/
// https://tausiq.wordpress.com/2010/07/25/uva-11517-exact-change/

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define INFINITE 1000000

int table[20000], coins[105];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int price, n;
        scanf("%d", &price);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &coins[i]);
        }

        memset(table, INFINITE, sizeof(table));
        table[0] = 0;

        for(int i = 0; i < n; i++) {
            for(int j = price; j >= 0; j--) {
                table[j+coins[i]] = min(table[j]+1, table[j+coins[i]]);
            }
        }

        for(int i = price; i < 20000; i++) {
            if(table[i] < INFINITE) {
                printf("%d %d\n", i, table[i]);
                break;
            }
        }
    }
}


















