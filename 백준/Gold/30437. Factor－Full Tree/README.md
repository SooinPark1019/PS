# [Gold II] Factor-Full Tree - 30437 

[문제 링크](https://www.acmicpc.net/problem/30437) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

해 구성하기, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘, 수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 10월 18일 01:59:26

### 문제 설명

<p>Aivar is very good at number theory. In fact, it is the only thing he is good at, but this doesn't stop him from achieving great things. However, if Aivar wants to solve any problem in life, he first needs to convert it to number theory.</p>

<p>For example, consider a rooted tree with $N$ vertices. In order to deal with such structures, Aivar first constructs a <em>divisor labelling</em> of the tree. A divisor labelling is a way to label each vertex $v$ with a positive integer $x_v$ so that $v$ is an ancestor of $u$ if and only if $x_v$ divides $x_u$.</p>

<p>After constructing such a labelling, Aivar can simply forget about the tree and just think about the list of numbers $x_1, x_2, \dots, x_N$.</p>

<p>You are given a rooted tree with $N$ vertices, and your task is to find a divisor labelling. The vertices are numbered from $1$ to $N$, and $1$ is the root.</p>

### 입력 

 <p>The first line contains an integer $N$ ($1 \leq N \leq 60$).</p>

<p>The following $N-1$ lines each contain two integers $u$ and $v$ ($1 \leq u, v \leq N$, $u \neq v$), meaning that an edge goes between vertices $u$ and $v$. These edges will form a tree.</p>

### 출력 

 <p>Print one line with $N$ integers, the numbers $x_1, x_2, \dots x_N$. These numbers must satisfy $1 \leq x_i \leq 10^{18}$. It can be shown that under these constraints, an answer always exists.</p>

