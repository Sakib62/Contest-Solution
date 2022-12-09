# [A - Two Gangsters](https://acm.timus.ru/problem.aspx?space=1&num=1409)
<details>
<summary><b>Summary</b></summary>

<p>There are at max 10 cans. Harry starts shooting them from left to right & Larry shoots right to left. At one point, they both shoot the same can and stop shooting.
<br><br>
How many cans did each of them not shoot?</p>
</details>
<details>
<summary><b>Tutorial</b></summary>

<p>Both of them shot the last can. Apart from that, none shot the cans of that other person shot. Harry started from left and stopped when shot a can at the same time with Larry. Harry didn't shot rest of the cans that Larry shot.<br><br>
So, both of them didn't shot 1 less than other shot.</p>
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << b - 1 << " " << a - 1 << "\n";
    return 0;
}
```
</details>

# [B - 1, 10, 100, 1000...](https://acm.timus.ru/problem.aspx?space=1&num=1209)
<details>
<summary><b>Summary</b></summary>

<p>An infinite sequence of digits constructed by concatenating ascending powers of 10. Here is the beginning of the sequence: 110100100010000… 
<br><br>
Find out what digit is located at the given position of the sequence.</p>
</details>
<details>
<summary><b>Tutorial</b></summary>

<p>If we look at powers of 10, each time number of zero increases.<br>1, 10, 100, 1000, 10000,...Positions of 1 are: 1, 2, 4, 7, 11, 16...<br>Difference between position of 1 increases by 1.<br><br>
So in this sequence, we can pre calculate the position of 1's and store it in a container.Then at given position, just check whether it exist in the container. If it does, then given position contains 1, else it contains 0.</p>
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    cin >> testCase;
    vector<long long>store; //or set
    long long tmp=1, cnt=1;
    while(tmp<1e10) {
        store.push_back(tmp);
        tmp+=cnt; //adding difference
        cnt++; //increasing difference
    }
    while(testCase--) {
        long long n;
        cin >> n;
        //find() in vector may give tle
        if(binary_search(store.begin(), store.end(), n)) cout<<"1"; //for set: if(store.find(n)!=store.end()) cout<<"1";
        else cout<<"0";
        if(testCase) cout<<" "; //better practise
    }
    //cout<<store.size()<<"\n";
    //cout<<store[store.size()-1];
}
```
</details>

# [C - Labyrinth](https://acm.timus.ru/problem.aspx?space=1&num=1033)
<details>
<summary><b>Summary</b></summary>

<p>Labyrinth or a maze is given. Top left corner is entrance and bottom right corner is exit. It is expressed as a 2d matrix, each cell denoting a 3x3 room, which has 3 meter high wall. Some cells are defined as dot, some as diesis(#) meaning those room are blocked. Visitors can't enter in those room, so only their outside wall are visible. Now the task is to paint the wall that are visible. If some dot cells are surrounded by diesis cell, those dot cell cannot be accessed. Just need to paint those wall that the visitors can walk to and see. It is like a closed sqaure shaped house, you enter and may not exit! Traverse all the path that you can. Just the visible portion needs to be covered with painted walls.
Calculate total area that needs to be painted.</p>
</details>
<details>
<summary><b>Tutorial</b></summary>

<p>When we enter a cell, need to check if top, bottom, right & left cells(if exist, if not we assume those as inaccessible) are accessible. If not, then add counter by 1. For exit and entrance at least 2 cells are accessible. For entrance, top & left and for exit, bottom & right cells. These 4 cells don't need to covered.<br><br>
This is simple bfs/dfs problem. For each cell we check their adjacent cells. If those are accessible, add it to the queue and check their adjacent cells too and repeat. Else increment counter, as the path is blocked and need to paint the wall.<br><br>
Just multiple counter by 9, as walls are 3 meter high and 3 meter wide.</p>
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
// Problem: 1033. Labyrinth
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1033
// Time Limit: 1000 ms Memory Limit: 64 MB
// Parsed at: 2022-11-18 13:02:30

/*
    Bismillahir Rahmanir Rahim
    Author: Sakib62
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
    //#endif
    ios::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        vector< vector<char> >grid(n+2, vector<char>(n+2, '#'));

        vector< vector<bool> > visited(n+2, vector<bool> (n+2, false));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> grid[i][j];
            }
        }
        // for(auto &i: grid) {
        //     for(auto &j: i) cout << j;
        //     cout << "\n";
        // }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        queue<pair<int, int> >index;
        index.push({1, 1});
        index.push({n, n});
        visited[1][1] = true;
        visited[n][n] = true;

        while(!index.empty()) {
            int i = index.front().first;
            int j = index.front().second;
            
            index.pop();
            //(i-1, j), (i+1, j), (i, j-1), (i, j+1)
            for(int p = 0; p < 4; p++) {
                int curX = i+dx[p], curY = j+dy[p];
                if(grid[curX][curY] == '#') ans++;
                else {
                    if(visited[curX][curY]==false) {
                        index.push({curX, curY});
                        visited[curX][curY] = true;
                    }
                }
            }
            //cout << ans << " ";
        }
        ans-=4;
        cout << ans * 3 * 3 <<"\n"; //wall height 3, wall width 3
    }
}
```
</details>

# [D - Brave Balloonists](https://acm.timus.ru/problem.aspx?space=1&num=1049)
<details>
<summary><b>Summary</b></summary>

<p>Given 10 numbers, determine product(P) of them, count total divisor(X) of the product(P). Print the last digit of X</p>
</details>
<details>
<summary><b>Tutorial</b></summary>

<p>We need to prime factorize every 10 numbers, thus we get the frequency of prime numbers that are factors of at least one of the 10 numbers.<br>If a prime's frequency is X, we can take this prime X+1 times, that is we can take X times & not take it at all. X+1 is the number of option for a single prime factor.<br>Thus,by multiplying available options for all prime factors, we get total divisor for the product of 10 numbers. Then, just print modulo of it.<br><br>
Note that if all 10 numbers are 1, the answer is 1. Though it must be handled if we initialize ans with 1.</p>
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int freq[10001];

void primeFactorize(int x) {
    while(x%2==0) {
        x/=2;
        freq[2]++;
    }
    for(int i=3;i<=x;i+=2) {
        while(x%i==0) {
            x/=i;
            freq[i]++;
        }
    }
}

int main() {
    int x;
    for(int i=1;i<=10;i++) {
        cin>>x;
        primeFactorize(x);
    }
    int ans=1;
    for(int i=2;i<=10000;i++) {
        ans*=(freq[i]+1);
    }
    cout<<ans%10;
}
```
</details>

# [E - Oh Your Royal Greediness!](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2876)
<details>
<summary><b>Summary</b></summary>

<p>Starting time & Ending time is given. One enforcer must be present in this interval. At a time, one enforcer can be at one interval. After finishing that interval, the enforcer can be at another interval.<br><br>
Given list of intervals, at least how many enforcers are required?</p>
</details>
<details>
<summary><b>Tutorial 1</b></summary>

<p>When an interval begins, we must assign an enforcer to that interval. When the interval finishes, the enforcer can resign.<br><br>
Thus, we keep track of how many enforcers are present at a given time. Maximum of these value is the answer.</p>
</details>
<details>
<summary><b>Solution 1</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int Case=1;
    while(1) {
        int n;
        cin >> n;
        if(n==-1) break;
        int start, end;
        vector<pair<int, int>> vp;
        for(int i=1; i<=n; i++) {
            cin >> start >> end;
            vp.push_back({start, 0}); //with 0 & 1 keeping track of start & end time.
            vp.push_back({end, 1});
        }
        sort(vp.begin(), vp.end()); //thus we can simulate the process from the beginning & check when an enforcer is assigned & at which time another leaves. 
        // to differentiate between start & end time, 0 & 1 is used.
        int ans=0, cnt=0;//cnt to keep track at a given time how many enforcer has been assigned.
        //ans to take max of them.
        for(int i=0; i<vp.size(); i++) {
            if(vp[i].second==0) cnt++; //enforcer assigned.
            else cnt--; //enforcer left //as vp is sorted, these events are handled sequentially.
            ans=max(ans, cnt);
        }
        cout<<"Case "<<Case<<": ";
        cout<<ans<<"\n";
        Case++;
    }
}
```
</details>
<details>
<summary><b>Tutorial 2</b></summary>

<p>We can individually store start & end time and sort them both. Then, for each ending time, check how many enforcers are already assigned. This can be done by checking how many start time is smaller or how many interval started before current interval ended. After going through each interval's ending time, we get the maximum number of enforcers we need at a certain time.</p>
</details>
<details>
<summary><b>Solution 2</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int Case=1;
    while(1) {
        int n;
        cin >> n;
        if(n==-1) break;
        int ans=0, cnt=0, st[n], en[n];
        for(int i=0; i<n; i++) {
            cin>>st[i]>>en[i];
        }
        sort(st, st+n);
        sort(en, en+n);
        for(int i=0;i<n;i++) {//to maintain end time
            cnt=0;
            for(int j=i;j<n;j++) {//to compare start time
                if(en[i]>=st[j]) cnt++; //before ending the ith interval, another enforcer is needed.
                else break;//rest start time are also greater, meaning j'th start time is after i'th ending time. 
            }
            ans=max(ans, cnt);
        }
        cout<<"Case "<<Case++<<": "<<ans<<"\n";
    }
}
```
</details>
