# [A - A](https://codeforces.com/problemset/problem/1117/B)
<details>
<summary><b><u>Summary</u></b></summary>

<p>There are n emotes, each assigned a value. Need to use some emotes total m times.<br>
Same emote can't be used more than k times in a row.<br>
Two emotes i & j(i!=j) such that (ai=aj) are considered different.<br>
Find maximum possible total value by using the emotes m times.</p>
</details>
<details>
<summary><b><u>Tutorial</u></b></summary>

Let's say X is the emote with maximum value & Y is the emote with 2nd maximum value.

We want to use X as much as possible. But it cannot be used more than k times in a row. So, in k+1'th move we will use Y. We will repeat this until m moves are complete.

If m is less than k, just use X m times. Else, use combo of X and Y contributing k+1 moves. If some moves remain after applying X, Y combo multiple times, use X for the remaining moves. Keep track of value added to the answer in each
</details>

[**Solution**](Solution/A_A.cpp)

<br>

# [C - C](https://codeforces.com/problemset/problem/1061/B)
<details>
<summary><b><u>Summary</u></b></summary>

There are some stacks containing some blocks, a top view camera and a side view camera.

Gravity won't affect the blocks, so if lower blocks are removed, upper blocks won't fall down.

Determine the maximum number of blocks that can be removed so that the top and side view remains same.
</details>
<details>
<summary><b><u>Tutorial</u></b></summary>

In each stack, at least one block remains. Top view won't change no matter what, need to consider side view. Need to work with the tallest stack first, then iterate in non-increasing order. 

Least total blocks that should be placed overall to obtain same side view is equal to tallest stack's block amount.

Question is, how many blocks from each stack needs to be placed to obtain same side view? Then the difference of this and total blocks in all stack will be the number of blocks than can be removed.

If i'th and i-1'th stack's have same number of blocks, then placing 1 block from i'th stack is sufficient as rest can be dealt with in i-1'th stack.

Else (i'th - i-1'th) blocks need to be placed from i'th stack. If all necessary blocks are placed and some stacks remaining, 1 blocks from those stack should be placed. If only 1 stack remains and multiple blocks need to be placed, then place all of them from remaining stack.
</details>

[**Solution**](Solution/C_C.cpp)

<br>

# [F - F](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4758)
<details>
<summary><b><u>Summary</u></b></summary>

Given program can compute vlaue of n up to 10^6. But for higher value of n, the code will not work for memory, time constraints.

Write a program which will give identical result for higher values of n. (up to 10^18)
</details>
<details>
<summary><b><u>Tutorial</u></b></summary>

By close observation, it can be noted that the given program counts set bit in binary of n.

We don't need to run a for loop to do that. It can be done in logn complexity.

We can use bitset, or manually keep dividing n by 2 until n > 0. Then count how many times remiander by 2 is 1.
</details>

[**Solution**](Solution/F_F.cpp)

<br>

# [G - G](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4759)
<details>
<summary><b><u>Summary</u></b></summary>

Coordinates of lower left and upper right corner of a rectangle is given. Also coordinates of a circle's center is given along with it's radius.

Given some inter-relation between various properties of the rectangle and circle, determine if provided coordinates matches those properties.
</details>
<details>
<summary><b><u>Tutorial</u></b></summary>

Calculate length, width etc from given coordinates and check if these fulfills all the properties.
</details>

[**Solution**](Solution/G_G.cpp)

<br>