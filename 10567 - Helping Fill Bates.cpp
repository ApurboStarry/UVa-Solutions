/*
 * https://saicheems.wordpress.com/2013/07/10/uva-10567-helping-fill-bates/
 */

#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<vector<int>> vvi;
string s, ss;

int main() {
    vvi.resize(256);
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        vvi[s[i]].push_back(i);
    }

    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        cin >> ss;

        int ind = -1, a = 0;
        bool flag = true;
        for(int j = 0; j < ss.length(); j++) {
            vector<int>::iterator low = upper_bound(vvi[ss[j]].begin(), vvi[ss[j]].end(), ind);
            ind = low - vvi[ss[j]].begin();
            if(low == vvi[ss[j]].end()) flag = false;
            ind = vvi[ss[j]][ind];
            if(j == 0)  a = ind;
            //printf("$$ %d\n", ind);
        }
        if(flag)    printf("Matched %d %d\n", a, ind);
        else    printf("Not matched\n");
    }
}














