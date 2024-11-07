# [Diamond IV] Two Buildings - 20180 

[문제 링크](https://www.acmicpc.net/problem/20180) 

### 성능 요약

메모리: 34920 KB, 시간: 128 ms

### 분류

분할 정복, 분할 정복을 사용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2024년 11월 8일 03:21:52

### 문제 설명

<p>There are <em>n</em> buildings along a horizontal street. The buildings are next to each other along the street, and the <em>i</em>-th building from left to right has width 1 and height <em>h<sub>i</sub></em>. Among the <em>n</em> buildings, we are to find two buildings, say the <em>i</em>-th building and <em>j</em>-th building with <em>i</em> < <em>j</em>, such that (<em>h<sub>i</sub></em> + <em>h<sub>j</sub></em>) × (<em>j</em> − <em>i</em>) is maximized.</p>

<p>For example, the right figure shows 5 buildings, with heights 1, 3, 2, 5, 4, from left to right. If we choose the first 2 buildings, then we get (1 + 3) × (2 − 1) = 4. If we choose the first and fifth buildings, then we (1 + 4) × (5 − 1) = 20. The maximum value is achieved by the second and fifth buildings with heights 3 and 4, respectively: (3 + 4) × (5 − 2) = 21.</p>

<p>Write a program that, given a sequence of building heights, prints max<sub>1≤<em>i</em><<em>𝑗</em>≤<em>n</em></sub>(<em>h<sub>i</sub></em> + <em>h<sub>j</sub></em>) × (<em>j</em> − <em>i</em>).</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (2 ≤ <em>n</em> ≤ 1,000,000), where <em>n</em> is the number of buildings. The buildings are numbered 1 to <em>n</em> from left to right. The second line contains the heights of <em>n</em> buildings separated by a space such that the <em>i</em>-th number is the height <em>h<sub>i</sub></em> of the <em>i</em>-th building (1 ≤ <em>h<sub>i</sub></em> ≤ 1,000,000).</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain max<sub>1≤<em>i</em><<em>𝑗</em>≤<em>n</em></sub>(<em>h<sub>i</sub></em> + <em>h<sub>j</sub></em>) × (<em>j</em> − <em>i</em>).</p>

