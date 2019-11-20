#include <bits/stdc++.h>

using namespace std;

int bachelor[10002];
int spinster[10002];

int main() {
    int b, s, caseInd = 1;
    while(true) {
        scanf("%d %d", &b, &s);

        if(b == 0 && s == 0) break;

        memset(bachelor, 0, sizeof(bachelor));
        memset(spinster, 0, sizeof(spinster));

        for(int i = 0; i < b; i++) {
            scanf("%d", &bachelor[i]);
        }

        for(int i = 0; i < s; i++) {
            scanf("%d", &spinster[i]);
        }

        if(b > s) {
            sort(bachelor, bachelor+b);
            printf("Case %d: %d %d\n", caseInd, b-s, bachelor[0]);
        } else {
            printf("Case %d: 0\n", caseInd);
        }
        caseInd++;
    }
}















