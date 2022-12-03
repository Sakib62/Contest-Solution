/**
 *       Author :   Sakib62
 *       Created:   Sat__03.Dec.2022__15:06:10
 *       File   :   A_-_A.cpp
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
        int n, m, k;
        cin >> n >> m >> k;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int y = a[n - 1];
        int z = a[n - 2];
        if(k >= m) {//Use emote with highest happiness m times
            cout << 1ll * y * m << "\n";
            continue;
        }
        //Combo of k times highest value emote, then 1 time second highest value emote.
        // tmp is the value of this combo, lol is the repeatation of this combo, po is the remaining moves that would be filled by the highest value emote.
        long long tmp = 1ll * k * y + z, lol = m / (k + 1), po = m % (k + 1), ans;
        ans = tmp * lol + po * y;
        cout << ans << "\n";
    }
}