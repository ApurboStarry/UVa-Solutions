// this is just accumulated phi.

#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

long long phi[MAX];

int main() {
    phi[1] = 1;
    for(int i = 2; i < MAX; i++) {
        if(phi[i] == 0) {
            phi[i] = i-1;
            for(int j = 2*i; j < MAX; j+=i) {
                if(phi[j] == 0) {
                    phi[j] = j;
                }
                phi[j] -= phi[j]/i;
            }
        }
    }

    for(int i = 3; i < MAX; i++) {
        phi[i] = phi[i] + phi[i-1];
    }


    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;
        else if(n == 1) cout << 0 << endl;
        else cout << phi[n] << endl;
    }
}
