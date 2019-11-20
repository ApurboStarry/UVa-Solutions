#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int a[20005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b;
    scanf("%d", &b);
    for(int caseInd = 1; caseInd <= b; caseInd++) {
        int s;
        scanf("%d", &s);

        memset(a, 0, sizeof(a));

        for(int i = 1; i <= s-1; i++) {
            scanf("%d", &a[i]);
        }

        int check = 0, end = 0, start = 0, max = 0, sum = 0;
        for(int i = 1; i <= s-1; i++) {
            sum += a[i];
            if(max < sum || (max == sum && i-check > end-start)) {
                max = sum;
                start = check;
                end = i;
            }
            if(sum < 0) {
                sum = 0;
                check = i;
            }
        }

        if(max > 0) {
            printf("The nicest part of route %d is between stops %d and %d\n", caseInd, start + 1, end + 1);
        } else {
            printf("Route %d has no nice parts\n", caseInd);
        }
    }
}














