# [Platinum III] Balanced Cow Subsets - 5879 

[문제 링크](https://www.acmicpc.net/problem/5879) 

### 성능 요약

메모리: 8296 KB, 시간: 20 ms

### 분류

비트마스킹, 중간에서 만나기

### 제출 일자

2024년 9월 8일 02:21:03

### 문제 설명

<p>Farmer John's owns N cows (2 <= N <= 20), where cow i produces M(i) units of milk each day (1 <= M(i) <= 100,000,000).  FJ wants to streamline the process of milking his cows every day, so he installs a brand new milking machine in his barn.  Unfortunately, the machine turns out to be far too sensitive: it only works properly if the cows on the left side of the barn have the exact same total milk output as the cows on the right side of the barn!</p><p>Let us call a subset of cows "balanced" if it can be partitioned into two groups having equal milk output.  Since only a balanced subset of cows can make the milking machine work, FJ wonders how many subsets of his N cows are balanced.  Please help him compute this quantity.</p>

### 입력 

 <ul><li>Line 1: The integer N.</li><li>Lines 2..1+N: Line i+1 contains M(i).</li></ul>

### 출력 

 <ul><li>Line 1: The number of balanced subsets of cows.</li></ul>

