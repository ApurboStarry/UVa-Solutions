// https://saicheems.wordpress.com/2014/01/03/uva-147-dollars/

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int N = 11, V;
ll coinValue[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000}, memo[15][30000];

ll ways(int type, ll value) {
    if (value == 0)              return 1;
    if (value < 0 || type == N)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main() {
    memset(memo, -1, sizeof memo); // we only need to initialize this once

    double inp;
    while(true) {
        scanf("%lf", &inp);
        if(inp == 0.00) break;
        ll temp = (int) round(inp * 100);
        //cout << inp * 100 << " " << temp << endl;
        printf("%6.2f%17lld\n", inp, ways(0, temp));
    }
}


















