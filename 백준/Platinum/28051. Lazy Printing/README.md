# [Platinum II] Lazy Printing - 28051 

[문제 링크](https://www.acmicpc.net/problem/28051) 

### 성능 요약

메모리: 5480 KB, 시간: 56 ms

### 분류

이분 탐색, 그리디 알고리즘, 해싱, KMP, 라빈–카프, 문자열

### 제출 일자

2025년 6월 3일 17:52:11

### 문제 설명

<p>Vinícius has an interesting typing machine. The machine accepts instructions consisting of a non-empty string $s$ and a positive integer $n$. For each such instruction, the machine prints $n$ characters: the $i$-th ($0$-based) printed character equals $s_r$, where $r$ is the remainder after dividing $i$ by the length of $s$ and $s_r$ denotes the $r$-th ($0$-based) character of $s$. For instance, with the sequence of instructions:</p>

<ol>
	<li>$s =$ “<code>ab</code>”, $n = 4$</li>
	<li>$s =$ “<code>cd</code>”, $n = 3$</li>
	<li>$s =$ “<code>xx</code>”, $n = 2$</li>
</ol>

<p>the machine will print “<code>ababcdcxx</code>”.</p>

<p>Vinícius is lazy, so he only gives strings of length at most $D$ to the machine in each instruction. Since he is very lazy, he also wants to use as few instructions as possible. Given a string $T$ and the integer $D$, help Vinícius find the minimum number of instructions he needs in order to print $T$ using the machine.</p>

### 입력 

 <p>The input consists of a single line that contains a string $T$ of lowercase letters followed by the integer $D$ ($1 ≤ D ≤ |T| ≤ 2 \times 10^5$), as described in the statement.</p>

### 출력 

 <p>Output a single line with an integer indicating the minimum number of instructions Vinícius needs.</p>

