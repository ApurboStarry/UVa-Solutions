#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int l[10002], h[10002];
int p[1000];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(l, 0, sizeof(l));
        memset(h, 0, sizeof(h));
        memset(p, 0, sizeof(p));
        int d;
        cin >> d;
        string m[d];
        for(int i = 0; i < d; i++) {
            cin >> m[i] >> l[i] >> h[i];
        }

        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++) {
            scanf("%d", &p[i]);
        }

        bool flag = false;
        int maker;

        for(int i = 0; i < q; i++) {
            flag = false;
            for(int j = 0; j < d; j++) {
                if(p[i] >= l[j] && p[i] <= h[j]) {
                    if(!flag) {
                        flag = true;
                        maker = j;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) cout << m[maker] << endl;
            else cout << "UNDETERMINED" << endl;
        }
        if(t)   printf("\n");
    }
}














