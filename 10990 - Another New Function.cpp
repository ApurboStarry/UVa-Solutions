// Euler's Totient Function


#include <bits/stdc++.h>
const int MX = 2e6+1;

using namespace std;

long long phi[MX];
long long depthOfPhi[MX];
long long sodf[MX];

int main()
{
    phi[1] = 1;
    depthOfPhi[1] = 0;
    depthOfPhi[2] = 1;
    sodf[1] = 1;
    for(int i = 2; i < MX; i++) {
        if(phi[i] == 0) {
            phi[i] = i-1;
            for(int j = 2*i; j < MX; j+=i) {
                if(phi[j] == 0) {
                    phi[j] = j;
                }
                phi[j] = phi[j] - phi[j]/i;
            }
        }
    }

    for(int i = 3; i < MX; i++) {
        depthOfPhi[i] = depthOfPhi[phi[i]] + 1;
    }

    for(int i = 2; i < MX; i++) {
        sodf[i] = sodf[i-1] + depthOfPhi[i];
    }

//    for(int i = 1; i < 22; i++) {
//        cout << phi[i] << " ";
//    }
//    cout << endl;
//
//    for(int i = 1; i < 22; i++) {
//        cout << depthOfPhi[i] << " ";
//    }
//    cout << endl;
//
//    for(int i = 1; i < 22; i++) {
//        cout << sodf[i] << " ";
//    }
//    cout << endl;

    int t, m, n;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        cout << sodf[n] - sodf[m-1] << endl;
    }
}

