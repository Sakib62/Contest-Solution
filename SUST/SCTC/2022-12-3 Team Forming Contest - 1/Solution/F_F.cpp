/**
 *       Author :   Sakib62
 *       Created:   Sat__03.Dec.2022__15:31:09
 *       File   :   F_-_F.cpp
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

// ll fun(ll n) {
//     if(n == 0) return 0;
//     return fun(n / 2) + n % 2;
// }

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    cin >> testCase;
    while(testCase--) {
        long long n, cnt = 0;
        cin >> n; // need to count set bit in the binary of n

//Approach 1    //fun(n);
//Approach 2   //bitset < 64 > bt(n); cout << bt.count() << "\n";
//Approach 3  //cout << __builtin_popcountll(n) << "\n";
//Approach 4 //for (ll i = 0; i < 64; i++) cnt += ( (n & ( 1ll << i ) ) ? 1 : 0 );
        if(n & 1) cnt++;
        while(n > 0) {
            n /= 2;
            if(n & 1) cnt++;
        }
        cout << cnt << "\n";
    }
}