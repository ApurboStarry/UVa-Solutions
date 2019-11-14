// just calculate phi of the given number. that's it.

#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

long long phi[MAX];

int main()
{
    phi[1] = 1;
    for(int i = 2; i < MAX; i++) {
        if(phi[i] == 0) {
            phi[i] = i - 1;
            for(int j = 2 * i; j < MAX; j+=i) {
                if(phi[j] == 0) {
                    phi[j] = j;
                }
                phi[j] -= phi[j] / i;
            }
        }
    }

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << phi[n] << endl;
    }
}

