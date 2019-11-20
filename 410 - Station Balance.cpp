#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int s[10];

int main() {
    int C, S, setNo = 1;

    while(scanf("%d %d", &C, &S) != EOF) {
        memset(s, 0, sizeof(s));

        double average = 0;
        for(int i = 0; i < S; i++) {
            scanf("%d", &s[i]);
            average += s[i];
        }
        average /= (double)C;
        sort(s, s+2*C);

//        for(int i = 0; i < 2*C; i++) {
//            printf("%d ", s[i]);
//        }
//        printf("\n");

        double imbalance = 0;

        printf("Set #%d\n", setNo);
        for(int i = 0; i < C; i++) {
            if(s[i] == 0 && s[2*C-i-1] == 0) {
                printf(" %d: \n", i);
                imbalance += average;
            } else if(s[i] == 0) {
                printf(" %d: %d\n", i, s[2*C-i-1]);
                imbalance += abs(s[2*C-i-1] - average);
            } else {
                printf(" %d: %d %d\n", i, s[i], s[2*C-i-1]);
                imbalance += abs(s[2*C-i-1]+s[i] - average);
            }
        }
        printf("IMBALANCE = %0.5lf\n\n", imbalance);
        setNo++;
    }
}














