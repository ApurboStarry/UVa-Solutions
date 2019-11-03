// Euler's Totient Function

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

void phi(ll n) {
    ll result = n;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n = n / i;
            }
            result -= result / i;
        }
    }
    if(n > 1) {
        result -= result / n;
    }
    cout << result << endl;
}

int main()
{
    ll n;
    while(true) {
        cin >> n;
        if(n == 0) break;
        if(n == 1) cout << 0 << endl;
        else phi(n);
    }
}

