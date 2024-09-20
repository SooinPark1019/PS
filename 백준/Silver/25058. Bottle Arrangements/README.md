# [Silver III] Bottle Arrangements - 25058 

[문제 링크](https://www.acmicpc.net/problem/25058) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 9월 20일 17:20:27

### 문제 설명

<p>Gabriella has been instructed to organize a renowned wine tasting event which will be attended by $m$ critics. On display, there will be $n$ different varieties of wine, each of which can either be a red wine or a white wine.</p>

<p>The wines will come in $n$ bottles arranged in a line on the table, and, for convenience, each critic will sip from a contiguous interval of bottles: that is, he/she will taste exactly the bottles at position $a$, $a + 1$, $\dots$, $b$ for some $1 ≤ a ≤ b ≤ n$. The interval depends on the critic, who will select it on the spot according to their preferences. In fact, the $i$-th critic ($1 ≤ i ≤ m$) has requested that he/she wants to taste exactly $r_i$ red wines and $w_i$ white wines.</p>

<p>Gabriella has yet to choose how many bottles of red wine and white wine there will be, and in what order they will appear. Help her find an arrangement (that is, a sequence of $n$ bottles of either red or white wine) that satisfies the requests of all the critics, or state that no such arrangement exists.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 100$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>The first line of each test case contains two integers $n$ and $m$ ($1 ≤ n ≤ 100$, $1 ≤ m ≤ 100$) — the number of bottles of wine and the number of critics.</p>

<p>Each of the next $m$ lines contains two integers $r_i$ and $w_i$ ($0 ≤ r_i , w_i ≤ 100$, $r_i + w_i ≥ 1$) — the number of red and white wines that the $i$-th critic wants to taste.</p>

### 출력 

 <p>For each test case, if at least one solution exists, print a string of length $n$ made up of the characters <code>R</code> and <code>W</code>, where the $j$-th character ($1 ≤ j ≤ n$) denotes the type of the wine in the $j$-th bottle of the arrangement (<code>R</code> for <em>red</em> and <code>W</code> for <em>white</em>).</p>

<p>If there are multiple solutions, print any. If no solution exists, print the string <code>IMPOSSIBLE</code>.</p>

