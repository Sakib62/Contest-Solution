/**
 *       Author :   Sakib62
 *       Created:   Sat__03.Dec.2022__15:49:02
 *       File   :   G_-_G.cpp
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

// Length : Width = 10 : 6
// Length : Radius = 10 : 2
// CenterY = LowerLeftY + Width / 2
// CenterX = LowerLeftX + (4.5 * Length) / 10

//Its centre will be placed on the intersecting point of the perpendicular drawn from the ninetwentieth(9/20) part of the length of the flag
//and the horizontal line drawn through the middle of its width.

    cin >> testCase;
    while(testCase--) {
        int x0, y0, x1, y1, cx, cy, r;
        cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;
        int len = x1 - x0;
        int wid = y1 - y0;
        bool ok = true;
        if((10 * wid) / len != 6) ok = false;
        if((10 * r) / len != 2) ok = false;
        if( (100 * (cx - x0)) / len != 45) ok = false;
        if( 2 * (cy - y0) != wid) ok = false;

        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }
}