/**
 *       Author :   Sakib62
 *       Created:   Sat__03.Dec.2022__16:27:32
 *       File   :   C_-_C.cpp
**/
//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << ">" << #x << ": " << x << "\n"; 
#define all(c) c.begin(), c.end()
#define revall(c) c.rbegin(), c.rend()
#define F first
#define S second

typedef unsigned long long ull;
typedef long long ll;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    //cin >> testCase;
    while(testCase--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        long long sum = 0;
//at least 1 block in each stack, top view doesn't change, need to consider side view.
//should work with stacks in descending order of blocks.
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];//total blocks present
        }
        if(n == 1) {
            cout << "0\n";//nothing can be removed
            continue;
        }
        sort(a, a + n);
        long long ans = 0;
        int track = a[n - 1];//from side view at least this amount should be present vertically
        for(int i = n - 1; i >= 1; i--) {
            if(a[i] > track) {
                if(track <= a[i - 1]) {//only 1 block from i'th stack will do, rest will be considered in a[i - 1]'th stack
                    ans++;
                    track--;
                }
                else {
                    ans += (track - a[i - 1]);//this amount of block needed from i'th stack
                    track = a[i - 1];
                }

            }
            else if(a[i] == track) {
                if(a[i] == a[i - 1]) {
                    ans++;
                    track--;
                }
                else {
                    ans += (a[i] - a[i - 1]);
                    track = a[i - 1];
                }
            }

            if(!track) {
                ans += i;//only 1 block(first row'th one) from each remaining stack; at least one block from each stack
                break;
            }
        }
        if(track) ans += track;//remaining track amount of block from first stack
        cout << sum - ans << "\n";
    }
}