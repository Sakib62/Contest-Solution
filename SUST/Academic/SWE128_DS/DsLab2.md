# [A - Two Gangsters](https://acm.timus.ru/problem.aspx?space=1&num=1409)
<details>
<summary>Summary</summary>

<blockquote>
There are at max 10 cans. Harry starts shooting them from left to right & Larry shoots right to left. At one point, they both shoot the same can and stop shooting.
<br><br>
How many cans did each of them not shoot?</blockquote>
</details>
<details>
<summary>Tutorial</summary>

<blockquote>
Both of them shot the last can. Apart from that, none shot the cans of that other person shot. Harry started from left and stopped when shot a can at the same time with Larry. Harry didn't shot rest of the cans that Larry shot.<br><br>
So, both of them didn't shot 1 less than other shot.
</blockquote>
</details>
<details>
<summary>Solution</summary>

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
<summary>Summary</summary>

<blockquote>
An infinite sequence of digits constructed by concatenating ascending powers of 10. Here is the beginning of the sequence: 110100100010000… 
<br><br>
Find out what digit is located at the given position of the sequence.
</blockquote>
</details>
<details>
<summary>Tutorial</summary>

<blockquote>
If we look at powers of 10, each time number of zero increases.<br>1, 10, 100, 1000, 10000,...Positions of 1 are: 1, 2, 4, 7, 11, 16...<br>Difference between position of 1 increases by 1.<br><br>
So in this sequence, we can pre calculate the position of 1's and store it in a container.Then at given position, just check whether it exist in the container. If it does, then given position contains 1, else it contains 0.
</blockquote>
</details>
<details>
<summary>Solution</summary>

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
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>
<details>
<summary>Solution</summary>

```cpp
```
</details>

# [D - Brave Balloonists](https://acm.timus.ru/problem.aspx?space=1&num=1049)
<details>
<summary>Summary</summary>

<blockquote>
Given 10 numbers, determine product(P) of them, count total divisor(X) of the product(P). Print the last digit of X.
</blockquote>
</details>
<details>
<summary>Tutorial</summary>

<blockquote>
We need to prime factorize every 10 numbers, thus we get the frequency of prime numbers that are factors of at least one of the 10 numbers.<br>If a prime's frequency is X, we can take this prime X+1 times, that is we can take X times & not take it at all. X+1 is the number of option for a single prime factor.<br>Thus,by multiplying available options for all prime factors, we get total divisor for the product of 10 numbers. Then, just print modulo of it.
<br>
<br>
Note that if all 10 numbers are 1, the answer is 1. Though it must be handled if we initialize ans with 1.
</blockquote>
</details>
<details>
<summary>Solution</summary>

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

# [E - Oh Your Royal Greediness!](https://vjudge.net/problem/UVA-11776/origin)
<details>
<summary>Summary</summary>

<blockquote>
Starting time & Ending time is given. One enforcer must be present in this interval. At a time, one enforcer can be at one interval. After finishing that interval, the enforcer can be at another interval.<br><br>
Given list of intervals, at least how many enforcers are required?
</blockquote>
</details>
<details>
<summary>Tutorial 1</summary>

<blockquote>
When an interval begins, we must assign an enforcer to that interval. When the interval finishes, the enforcer can resign.<br><br>
Thus, we keep track of how many enforcers are present at a given time. Maximum of these value is the answer.
</blockquote>
</details>
<details>
<summary>Solution 1</summary>

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
<summary>Tutorial 2</summary>

<blockquote>
We can individually store start & end time and sort them both. Then, for each ending time, check how many enforcers are already assigned. This can be done by checking how many start time is smaller or how many interval started before current interval ended. After going through each interval's ending time, we get the maximum number of enforcers we need at a certain time.
</blockquote>
</details>
<details>
<summary>Solution 2</summary>

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
