# [A - GCD Plus LCM](https://toph.co/p/gcd-plus-lcm)
<details>
<summary><b>Summary</b></summary>

Given two number a & b, check if gcd(a,b) + lcm(a,b) = a+b.<br>Note, 0 < a, b <= 1e18
</details>
<details>
<summary><b>Greedy Tutorial</b></summary>

Calculate gcd through Euclid algorithm or builtin `__gcd(a, b)` function. <br>
We know, a*b = gcd(a,b) * lcm(a,b)
<br>So, lcm(a,b) = (a*b) / gcd(a,b)
<br>But a*b will overflow long long range.<br><br>
So, the trick is to first divide by gcd(a,b), then multiply.
<br>lcm(a,b) = (a/gcd(a,b)) * b<br>
Then just check whether given condition is true or not.
</details>
<details>
<summary><b>Greedy Solution</b></summary>

```cpp
#include <bits/stdc++.h>>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		long long a, b, c, d;
		cin >> a >> b;
		c = __gcd(a, b);
		d = (a/c)*b;
		if(c+d == a+b) cout<<"true\n";
		else cout<<"false\n";
	}
	return 0;
}

```
</details>
<details>
<summary><b>Optimized Tutorial</b></summary>

We need to check if gcd(a,b) + lcm(a,b) = a + b
<br>
We can convert gcd to lcm and vice versa since gcd(a,b) * lcm(a,b) = a*b
<br>So, Left side of the equation can be written as:<br>
gcd(a,b) + (a*b)/gcd(a,b)<br><br>
If gcd is a, then after dividing with gcd we get b, so we get a+b.<br>
Or, if gcd is b, after dividing with gcd we get a, so we get a+b in this case also.<br>Hence to satisfy the equation, gcd(a,b) needs to be either a or b.
<br><br>
We can check through gcd or just check whether one number divides another.
</details>
<details>
<summary><b>Optimized Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        long long a, b;
        cin >> a >> b;
        if(__gcd(a,b)==a || __gcd(a,b)==b) cout<<"true\n";
        else cout<<"false\n";
    }
}
```
</details>

# [B - Big Factorials](https://toph.co/p/big-factorials)
<details>
<summary><b>Summary</b></summary>

Given an integer N, print the last 4 digits of N! (N factorial).<br>
1<=N<=999
</details>
<details>
<summary><b>Tutorial</b></summary>

Factorial(n) is the product of consecutive numbers from 1 to n. To get a trailing 0, a pair of 2 & 5 is needed. But 2 comes more times than 5 does. So, need to count how many 5 is present. <br>From fact(1) to fact(4), there are no zero, hence no trailing 0.<br>From fact(5) to fact(9), there are one 5, contributed by number 5 itself.
<br>Similarly from fact(20) onwards, there are four 5, thus four trailing zeros.<br><br>
Since, we are to print trailing 4 digit of factorial(n), from 20 onwards, for factorial of every number, trailing 4 digit will be 0.
<br><br>
We don't need to print factorial of 1 to 19 via if condition.
As we only need trailing 4 digit, we can mod factorial by 10000. Thus, factorial value will remain under 10000. If final mod value is 0, just print 0000.
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans=1;
    cin >> n;
    for(int i=2; i<=n; i++) {
        ans*=i;//factorial
        ans%=10000;//last 4 digits. //Value of next iteration won't be affected since multipling with the trailing digits produce trailing digits of product.
    }
    if(ans==0) cout<<"0000";
    else cout<<ans;
}
```
</details>

# [C - Left Prime](https://toph.co/p/left-prime)
<details>
<summary><b>Summary</b></summary>

Given a number N, output count of numbers < N that are prime.
</details>
<details>
<summary><b>Tutorial</b></summary>

Pre-compute primes up to 10^7.
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

#define range 10000001
int isComposite[range/32+1];//int (32bits), not bool
vector < int > primes;

bool check(int n, int pos) {
	return (bool)(n & (1<<pos));
}

int setBit(int n, int pos) {
	return n |= (1 << pos);
}

void sieve(int n) {
    for(int i = 3; i * i <= range; i += 2) {
        if(check(isComposite[i/32], i%32) == 0) {
            for(int j = i * i; j <= range; j += i + i) {
                isComposite[j/32] = setBit(isComposite[j/32], j%32);
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= range; i += 2) {
        if(check(isComposite[i/32], i%32) == 0) primes.push_back(i); 
    }
}

int main() {
    sieve(range);
    
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << lower_bound(primes.begin(), primes.end(), n) - primes.begin() << "\n";
    }
    return 0;
}
```
</details>

# [D - Complex Operations](https://toph.co/p/complex-operations)
<details>
<summary><b>Summary</b></summary>

In an array of length N:
- Type 1: Subtract X from all elements
- Type 2: Print K'th smallest number among the numbers of the array whose values are between L and R (both inclusive).<br>If there is not enough numbers in between L and R, then print -1.

Given Q queries, print answer for Type 2 operations.

1 <= N, Q, K <= 10^5<br>
1 <= X, L, R <= 10^18
</details>
<details>
<summary><b>Tutorial</b></summary>

- Sort the array to apply binary search.
- For Type 1 operations, just track total amount by which all elements will be subtracted.
- For Type 2 operations, Count how many numbers are less than L (StartIndex) in modified array & how many elements are less than R+1 (EndIndex) in modified array.
- (EndIndex - StartIndex) is the length of the range.
- If k is greater than range, no answer, print -1
- Else print (StartIndex + k - 1)-th element minus total amount that has been subtracted.
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
// Problem: Complex Operations
// Contest: Toph
// URL: https://toph.co/p/complex-operations
// Time Limit: 1000 ms Memory Limit: 512 MB
// Parsed at: 2022-12-10 01:00:55

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
        int n, q;
        cin >> n >> q;
        long long a[n];
        for(int i = 0; i < n; i++) {
        	cin >> a[i];
        }
        sort(a, a + n);//need to apply binary search
        long long totalSub = 0;	
    	while(q--) {
    		int type;
    		cin >> type;
    		if(type == 1) {
    			long long sub;//can be upto 10^18
    			cin >> sub;
    			totalSub += sub;//as all elements will be modified, just keep track of total amount modified
    		}
    		else {
    			long long l, r, k;
    			cin >> l >> r >> k;
    			int startInd = lower_bound(a, a + n, l + totalSub) - a;//how many numbers are before l in modified array
    			int endInd = upper_bound(a, a + n, r + totalSub) - a;//how many numbers are before r+1 in modified array
    			if(endInd - startInd >= k) {//total elements in range inclusive
    				cout << a[startInd + k - 1] - totalSub << "\n";//startInd is 1st in range, so to find k-th add k-1. All elements have been subtracted by totalSub amount
    			}
    			else cout << "-1\n";//range size is less than k
    			
    			// int neededInd = startInd + k - 1;
				// if(neededInd > n-1 || a[neededInd] > r + totalSub) cout << "-1\n";
				// else cout << a[neededInd] - totalSub << "\n";
    		}
    	}
    }
}
```
</details>

# [E - Pascal's Triangle](https://toph.co/p/pascals-triangle)
<details>
<summary><b>Summary</b></summary>

Given an integer N, print the sum of the Nth row of the Pascal's triangle.

In mathematics, Pascal's triangle is a triangular array of the binomial coefficients.

The numbers on the edges of the triangle are always 1.<br>Each of the remaining numbers are the sum of the two numbers that appear immediately above it.
</details>
<details>
<summary><b>Tutorial</b></summary>

Summation of number of each row is a power of two.

Sum of N-th row is: 2^(n-1)
</details>
<details>
<summary><b>Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Binary Exponentiation
ll power(ll x, ll y) {
    ll ans = 1;
    while(y > 0) {
        if(y&1) ans *= x;
        y = y >> 1;
        x *= x;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << power(2, n-1) << "\n";
}
```
</details>

# [F - Fibonacci Numbers](https://toph.co/p/fibonacci-numbers)
<details>
<summary><b>Summary</b></summary>

Given an integer N, print N-th Fibonacci number.

The series is: 1, 1, 2, 3, 5, 8, ..
</details>
<details>
<summary><b>Tutorial</b></summary>

Iterative solution with 3 variable or with array.

If recursive, use memoization. Though max value of N is 50, still better to follow optimized approach.
</details>
<details>
<summary><b>Iterative Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	//Given fibonacci series: 1 1 2 3 5
	int ans = 1, tmp1 = 1, tmp2 = 1;
	if(n > 2) {
		for(int i = 3; i <= n; i++) {
			ans = tmp1 + tmp2;
			tmp1 = tmp2;
			tmp2 = ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
```
</details>

<details>
<summary><b>Recursive Solution</b></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int ans[51];

int fib(int n) {
	if(n <= 2) return ans[n] = 1;//base case
	if(ans[n]) return ans[n];//if already value calculated
	return ans[n] = fib(n-1) + fib(n-2);//recursive way
}

int main() {
	int n;
	cin >> n;
	cout << fib(n) << "\n";
	return 0;
}
```
</details>