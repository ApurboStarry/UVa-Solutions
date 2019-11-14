/*
 * Any valid value of y lies between k+1 and 2k, inclusive.
 * We can loop over all possible values for y,
 * and each time check whether the corresponding x is an integer.
 *
 */

#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<pair<int, int>> pairs;
int k;

int main() {
    while(scanf("%d", &k) == 1) {
        pairs.clear();
        for(int i = k+1; i <= 2*k; i++) {
            if((i*k) % (i-k) == 0) {
                pairs.emplace_back((i*k)/(i-k), i);
            }
        }
        printf("%d\n", pairs.size());
        for(int i = 0; i < pairs.size(); i++) {
            printf("1/%d = 1/%d + 1/%d\n", k, pairs[i].first, pairs[i].second);
        }
    }
}














