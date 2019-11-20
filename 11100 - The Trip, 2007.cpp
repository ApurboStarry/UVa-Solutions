#include <bits/stdc++.h>

using namespace std;

int ara[10002];
bool isTaken[10002];

int main() {
    while(true) {
        int n;
        scanf("%d", &n);

        if(n == 0) break;

        memset(ara, 0, sizeof(ara));
        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
        }

        sort(ara, ara+n);
        memset(isTaken, false, sizeof(isTaken));

//    for(int i = 0; i < n; i++) {
//        printf("%d ", ara[i]);
//    }
//    printf("\n");

        int duplicates = 0;
        for(int i = 0; i < n-1; i++) {
            //printf("## %d\n", i);
            if(ara[i] == ara[i+1]) {
                int count = 0;
                while(true) {
                    if(ara[i+1] != ara[i]) {
                        count++;
                        break;
                    }
                    i++;
                    count++;
                }
                //printf("^^ %d\n", count);
                if(count > duplicates) duplicates = count;
            }
        }

        int size = duplicates > 0 ? duplicates : 1;
        vector<vector<int>> result(size);

        for(int i = 0; i < n; i++) {
            result[i%size].push_back(ara[i]);
        }

        cout << size << endl;
        for(int i = 0; i < size; i++) {
            cout << result[i][0];
            for(int j = 1; j < result[i].size(); j++) {
                cout << " " << result[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}
















