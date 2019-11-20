#include <bits/stdc++.h>

using namespace std;

int coins[1002];

int main() {
    int t;
    scanf("%d", &t);
    for(int caseInd = 1; caseInd <= t; caseInd++) {
        int n;
        scanf("%d", &n);
        char ara[n];
        for(int i = 0; i < n; i++) {
            //scanf("%c", &ara[i]);
            cin >> ara[i];
        }

        int left[n];
        int right[n];

        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));

        for(int i = 0; i < n; i++) {
            if(i-1 < 0) {
                left[i] = 0;
            } else {
                left[i] = i-1;
            }
            if(i+1 > n-1) {
                right[i] = n-1;
            } else {
                right[i] = i+1;
            }
        }

//        for(int i = 0; i < n; i++) {
//            printf("%d: %d %d\n", i, left[i], right[i]);
//        }

        int currentPos = 0, currentIndex = 0, count = 0;
        for(int i = 0; i < n; i++) {
            //printf("CurrentPos: %d i: %d\n", currentPos, i);
            if(ara[i] != '#') {
                int maxRight = i;
                currentPos = i;
                for(int j = i+1; ; j++) {
                    if(left[j] > currentPos) break;
                    if(right[j] > right[maxRight]) maxRight = j;
                }
                //printf("## %d\n", maxRight);
                count++;
                i = right[maxRight];
            }
        }
        printf("Case %d: %d\n", caseInd, count);
    }


}
















