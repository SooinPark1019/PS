# [Platinum I] Collecting Stamps 3 - 18433 

[문제 링크](https://www.acmicpc.net/problem/18433) 

### 성능 요약

메모리: 136636 KB, 시간: 188 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 4일 17:18:10

### 문제 설명

<p>Republic of IOI, where JOI-kun lives, is famous for a large lake. Today, a stamp rally event takes place around the lake.</p>

<p>There are N types of stamps situated around the lake. These stamps are numbered from 1 to N, in clockwise order. The perimeter of the lake is L, and the i-th stamp (1 ≤ i ≤ N) is located at X<sub>i</sub> meters clockwise from the starting point of the stamp rally.</p>

<p>Each participant stands at the starting point of the stamp rally. After the rally starts, each participant can move around the lake, both clockwise and counter-clockwise. Each participant can collect the i-th stamp (1 ≤ i ≤ N) only if they arrive at where the i-th stamp is located within T<sub>i</sub> seconds (inclusive) since the rally starts.</p>

<p>JOI-kun is a participant of the stamp rally. He takes 1 second to move 1 meter. You can ignore all the other times which he takes.</p>

<p>Write a program that, given the number of types of stamps, the perimeter of the lake, where each stamp is located, and the time until which JOI-kun can collect each stamp, calculates the maximum number of types of stamps he can collect in total.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N L
X<sub>1</sub> . . . X<sub>N</sub>
T<sub>1</sub> . . . T<sub>N</sub></pre>

### 출력 

 <p>Write the answer in one line to the standard output.</p>

