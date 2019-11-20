#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int p[10002];

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        memset(p, 0, sizeof(p));
        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        int m;
        scanf("%d", &m);

        sort(p, p+n);

        int maxDifference = 1000005;
        int price1, price2;

        for(int i = 0; i < n; i++) {
            if(binary_search(p, p+n, m-p[i])) {
                if(p[i] == m-p[i]) {
                    if(count(p, p+n, p[i]) < 2)
                        continue;
                }
                if(abs(2*p[i]-m) < maxDifference) {
                    maxDifference = abs(2*p[i] - m);
                    price1 = min(p[i], m-p[i]);
                    price2 = max(p[i], m-p[i]);
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", price1, price2);
    }
}














