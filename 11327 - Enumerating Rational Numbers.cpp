//Euler's totient function

/* Hint: https://codeforces.com/blog/entry/3754

First notice: Max denominator is 2*10^5 (from test case).
Second notice: Each denominator have exatcly phi(denominator) fractions.

After this notices you can precalculate euler functions for first 2*10^5 numbers. 
For determine denominator you can precalc prefix sum of euler functions and 
easily find denominator with binary search in this array.

After this we need to determine numerator. If denominator is num, 
it's exatcly (k - sum[num - 1]) coprime number with prime. 
It's step you can simply do with iterate from 1 to num and calc gcd.

*/


#include <bits/stdc++.h>
const int MX = 2e5+1;

using namespace std;

long long phi[MX];
long long accumulated[MX];

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int getNumerator(int a, int n) {
    if(a == 1) return 1;
    else {
        int count = 1;
        for(int i = 2; i < n; i++) {
            if(gcd(i, n) == 1) count++;
            if(count == a) return i;
        }
    }
    return 0;
}

int main()
{
    phi[1] = 1;
    accumulated[0] = 1;
    accumulated[1] = 2;
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

    for(int i = 2; i < MX; i++) {
        accumulated[i] = accumulated[i-1] + phi[i];
    }

//    for(int i = 0; i < 12; i++) {
//        cout << accumulated[i] << " ";
//    }


    while(true) {
        long long numerator, denominator;

        long long n;
        cin >> n;

        if(n == 0) break;

        if(n == 1) {
            cout << "0/1" << endl;
        }
        else {
            denominator = lower_bound(accumulated, accumulated + MX, n) - accumulated;
            //cout << denominator << endl;
            numerator = getNumerator(n - accumulated[denominator-1], denominator);
            //cout << numerator << endl;
            cout << numerator << "/" << denominator << endl;
        }
    }
}

