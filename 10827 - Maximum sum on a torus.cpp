// https://saicheems.wordpress.com/2013/08/27/uva-10827-maximum-sum-on-a-torus/

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int sum[200][200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(sum, 0, sizeof(sum));

        for(int i = 0; i < 2*n; i++) {
            for(int j = 0; j < 2*n; j++) {
                if(i < n && j < n) {
                    scanf("%d", &sum[i][j]);
                    sum[i+n][j] = sum[i][j+n] = sum[i+n][j+n] = sum[i][j];
                }
                if(i>0) sum[i][j] += sum[i-1][j];
                if(j>0) sum[i][j] += sum[i][j-1];
                if(i>0 && j>0) sum[i][j] -= sum[i-1][j-1];
            }
        }

        int maxSum = INT_MIN;

        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) 
        for(int k = i; k < i+n; k++) for(int l = j; l < j+n; l++) {
            int check = sum[k][l];
            if(i>0) check -= sum[i-1][l];
            if(j>0) check -= sum[k][j-1];

            if(i>0 && j>0) check += sum[i-1][j-1];
            maxSum = max(maxSum, check);
        }

        printf("%d\n", maxSum);
    }
}
