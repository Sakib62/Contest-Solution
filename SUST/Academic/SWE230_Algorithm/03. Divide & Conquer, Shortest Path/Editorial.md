# [A - Extended Traffic](https://lightoj.com/problem/extended-traffic)
<details>
<summary><b>Summary</b></summary>

Find shortest distance from source to various destination.

</details>
<details>
<summary><b>Tutorial</b></summary>

<p>Using Bellman Ford, calculate shortest distance from source to all other nodes. Then answer in O(1) for each query.

When relaxing edge, check if the entrance node of the edge is reachable from source. Otherwise that edge can't be relaxed. Thus multiple component case will also be handled.

In case of negative cycle, shortest distance keeps decreasing. According to the problem statement, if the distane is below 3, just print `?`. Same for unreachable destination.
</p>
</details>

[**Solution**](Solution/A_ExtendedTraffic.cpp)

<br>

# [B - Instant View of Big Bang](https://lightoj.com/problem/instant-view-of-big-bang)
<details>
<summary><b>Summary</b></summary>

<p>Given a directed weighted graph, need to find if negative cycle exist. If it exists, which are the nodes that are part of this cycle? Also find the nodes from which negative cycle is reachable.</p>

**The problem asks for the nodes which are either:**

1. part of a negative cycle
2. or a node from which you can start and reach a negative cycle
</details>
<details>
<summary><b>Tutorial</b></summary>

[This blog explains it smoothly!](https://prisonbreakingbad.wordpress.com/2016/04/20/lightoj-1108-instant-view-of-big-bang/)


</details>

[**Solution**](Solution/B_InstantViewofBigBang.cpp)

<br>

# [C - Travel Company](https://lightoj.com/problem/travel-company)
<details>
<summary><b>Summary</b></summary>

In a given directed graph, each edge has income and expense. Find whether a cycle exists, where ratio of total income of all edge and total expense of all edge is greater than P. 
</details>
<details>
<summary><b>Tutorial</b></summary>

First, we need to build the graph. For each edge, income & expense is given. We need to combine this two parameters into one which will denote the weight of the edge.

For a single road, it is good if<br>
`income / expense > P`<br>
`income > expense * P`<br>

So, **weight of the road** = `expense * P - income` is negative which is desired.

If there is a cycle with total weight negative, it means that the cycle has more good road. So, overall income, expense ratio will be greater than P. 

All we need to do is to check if there is a negative cycle. If found, answer is "YES". Else "NO".

</details>

[**Solution**](Solution/C_TravelCompany.cpp)

<br>

# [D - Monkey Banana Problem](https://lightoj.com/problem/monkey-banana-problem)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [E - Rooks](https://lightoj.com/problem/rooks)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [F - Hex-a-bonacci](https://lightoj.com/problem/hex-a-bonacci)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [G - Brush (III)](https://lightoj.com/problem/brush-3)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [H - Brush (V)](https://lightoj.com/problem/brush-5)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [I - Commandos](https://lightoj.com/problem/commandos)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [J - A Wedding Party](https://lightoj.com/problem/a-wedding-party)
<details>
<summary><b>Summary</b></summary>


</details>
<details>
<summary><b>Tutorial</b></summary>


</details>

[**Solution**](Solution)

<br>

# [K - Toll Management](https://lightoj.com/problem/toll-management)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [L - Sending Packets](https://lightoj.com/problem/sending-packets)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [M - Travelling Graph](https://codeforces.com/problemset/problem/21/D)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [N - The Geodetic Set Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3639)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [O - Postal Worker Rings Once](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=53)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [P - USHER](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3674)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [Q - Airline Comparison](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=810)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [R - Roads in Berland](https://codeforces.com/problemset/problem/25/C)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [S - String Problem](https://codeforces.com/problemset/problem/33/B)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [T - Arbitrage](https://www.spoj.com/problems/ARBITRAG/en/)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)

<br>

# [U - Jogging Trails](https://lightoj.com/problem/jogging-trails)
<details>
<summary>Summary</summary>


</details>
<details>
<summary>Tutorial</summary>


</details>

[**Solution**](Solution)