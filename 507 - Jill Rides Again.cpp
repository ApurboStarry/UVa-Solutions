#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

int niceness[20010];
int result[20010], startIndices[20010], endIndices[20010];
int resultIndex = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b;
    scanf("%d",&b);
    for(int route = 1; route <= b; route++) {
        int s;
        scanf("%d", &s);
        for(int i = 0; i < s-1; i++) {
            scanf("%d", &niceness[i]);
        }

        int ans = -1, sum = 0, start = 0, end = 0;
        int finalAns = -1, finalStart = 0, finalEnd = 0;
        for(int i = 0; i < s-1; i++) {
            sum += niceness[i];
            if(sum >= ans) {
                ans = sum;
                //cout << i << ": " << i-start << " " << end - start << endl;
                if(i-start > end - start) {
                    end = i;
                }
                if(finalAns < ans || (finalEnd - finalStart < end - start)) {
                    finalAns = ans;
                    finalStart = start;
                    finalEnd = end;
                }
                //cout << i << ": end: " << end << " start: " << start << " ans: " << ans << endl;
            }
            if(sum < 0) {
                sum = 0;
                start = i+1;
                end = i+1;
            }
        }

        ans == -1 ? printf("Route %d has no nice parts\n", route) : printf("The nicest part of route %d is between stops %d and %d\n", route, finalStart+1, finalEnd+2);
        //printf("%d\n", ans);
        //printf("%d %d\n", start+1, end+2);
        //printf("Final Ans: %d\n", ans);
        //printf("Finally: %d %d", finalStart+1, finalEnd+2);
    }

}


















