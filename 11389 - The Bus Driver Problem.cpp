#include <bits/stdc++.h>

using namespace std;

int coins[1002];

int main() {
    int n, r, d;
    while(true) {
        scanf("%d %d %d", &n, &d, &r);

        if(n == 0 && r == 0 && d == 0) break;

        int morning[n], afternoon[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &morning[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &afternoon[i]);
        }

        sort(morning, morning+n);
        sort(afternoon, afternoon+n, greater<int>());

//        for(int i = 0; i < n; i++) {
//            printf("%d ", morning[i]);
//        }
//        printf("\n");
//
//        for(int i = 0; i < n; i++) {
//            printf("%d ", afternoon[i]);
//        }
//        printf("\n");

        int sum = 0;
        for(int i = 0; i < n; i++) {
            int temp = (morning[i]+afternoon[i] - d);
            if(temp > 0) {
                //printf("%d ", temp);
                sum += temp;
            }
        }
        //printf("\n");
        printf("%d\n", sum*r);
    }
}
















