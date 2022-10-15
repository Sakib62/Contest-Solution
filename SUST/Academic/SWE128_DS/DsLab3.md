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


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>
<details>
<summary><b>Solution</b></summary>

```cpp
```
</details>

# [D - Complex Operations](https://toph.co/p/complex-operations)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>
<details>
<summary><b>Solution</b></summary>


</details>

# [E - Pascal's Triangle](https://toph.co/p/pascals-triangle)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>
<details>
<summary><b>Solution</b></summary>


</details>

# [F - Fibonacci Numbers](https://toph.co/p/fibonacci-numbers)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>
<details>
<summary><b>Solution</b></summary>


</details>