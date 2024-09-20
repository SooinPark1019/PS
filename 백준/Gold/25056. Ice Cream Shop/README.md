# [Gold II] Ice Cream Shop - 25056 

[문제 링크](https://www.acmicpc.net/problem/25056) 

### 성능 요약

메모리: 8296 KB, 시간: 60 ms

### 분류

이분 탐색, 수학, 누적 합, 스위핑, 두 포인터

### 제출 일자

2024년 9월 20일 17:18:02

### 문제 설명

<p>On a beach there are $n$ huts in a perfect line, hut $1$ being at the left and hut $i + 1$ being $100$ meters to the right of hut $i$, for all $1 ≤ i ≤ n - 1$. In hut $i$ there are $p_i$ people.</p>

<p>There are $m$ ice cream sellers, also aligned in a perfect line with all the huts. The $i$-th ice cream seller has their shop $x_i$ meters to the right of the first hut. All ice cream shops are at distinct locations, but they may be at the same location as a hut.</p>

<p>You want to open a new ice cream shop and you wonder what the best location for your shop is. You can place your ice cream shop anywhere on the beach (not necessarily at an integer distance from the first hut) as long as it is aligned with the huts and the other ice cream shops, even if there is already another ice cream shop or a hut at that location. You know that people would come to your shop only if it is strictly closer to their hut than any other ice cream shop.</p>

<p>If every person living in the huts wants to buy exactly one ice cream, what is the maximum number of ice creams that you can sell if you place the shop optimally?</p>

### 입력 

 <p>The first line contains two integers $n$ and $m$ ($2 ≤ n ≤ 200\,000$, $1 ≤ m ≤ 200\,000$) — the number of huts and the number of ice cream sellers.</p>

<p>The second line contains $n$ integers $p_1$, $p_2$, $\dots$, $p_n$ ($1 ≤ p_i ≤ 10^9$) — the number of people in each hut.</p>

<p>The third line contains $m$ integers $x_1$, $x_2$, $\dots$, $x_m$ ($0 ≤ x_i ≤ 10^9$, $x_i \ne x_j$ for $i \ne j$) — the location of each ice cream shop.</p>

### 출력 

 <p>Print the maximum number of ice creams that can be sold by choosing optimally the location of the new shop.</p>

