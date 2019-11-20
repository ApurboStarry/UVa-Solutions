/*
 * https://saicheems.wordpress.com/2013/07/16/uva-12192-grapevine/
 */

#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int plot[502][502];

int main() {
    int n, m, q, l, u;
    while(true) {
        scanf("%d %d", &n, &m);

        if(n == 0 && m == 0) break;

        for(int i = 0; i < 502; i++) {
            memset(plot[i], 0, sizeof(plot[i]));
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &plot[i][j]);
            }
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            scanf("%d %d", &l, &u);
            int currentMaxSide = 0;
            for(int j = 0; j < n; j++) {
                int minIndex = lower_bound(plot[j], plot[j]+m, l) - plot[j];
                for(int k = currentMaxSide; k < n; k++) {
                    if(j+k >= n || minIndex+k >= m || plot[j+k][minIndex+k] > u) break;
                    if(k+1 > currentMaxSide)    currentMaxSide = k+1;
                }
            }
            printf("%d\n", currentMaxSide);
        }
        printf("-\n");
    }
}














