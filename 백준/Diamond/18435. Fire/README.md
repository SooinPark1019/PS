# [Diamond III] Fire - 18435 

[문제 링크](https://www.acmicpc.net/problem/18435) 

### 성능 요약

메모리: 42936 KB, 시간: 28 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 오프라인 쿼리, 세그먼트 트리, 스택, 스위핑

### 제출 일자

2025년 2월 11일 04:52:47

### 문제 설명

<p>There are N districts in JOI Village, numbered from 1 to N. These districts are located in a line. Now, a fire occurs in each district. At time 0, the strength of the fire in the i-th district (1 ≤ i ≤ N) is S<sub>i</sub> (S<sub>i</sub> > 0).</p>

<p>At time 0, the wind blows from the 1st district to the N-th district. For every pair of neighboring districts, if the fire in the upwind district is stronger than the fire in the downwind district at time t (0 ≤ t), the strength of the fire in the downwind district at time t +1 will be the strength of the fire in the upwind district at time t. Otherwise, the strength of the fire in the downwind district at time t +1 and time t are the same. Namely, if the strength of the fire in the i-th district (1 ≤ i ≤ N) at time t (0 ≤ t) is denoted by S<sub>i</sub>(t), we have S<sub>i</sub>(t) = max{S<sub>i−1</sub>(t − 1), S<sub>i</sub>(t − 1)} for every t (1 ≤ t). Here, for any t (0 ≤ t), we put S<sub>0</sub>(t) = 0. For any i (1 ≤ i ≤ N), we put S<sub>i</sub>(0) = S<sub>i</sub>.</p>

<p>You are a firefighter. You have Q plans to extinguish the fire. You are planning to do only one of the Q plans. In the j-th plan (1 ≤ j ≤ Q), you will use fire extinguishing agent for the k-th district for every k with L<sub>j</sub> ≤ k ≤ R<sub>j</sub>, and extinguish the fire in these districts. If the strength of the fire in a district is s, you need s liters of fire extinguishing agent to extinguish the fire in that district. Therefore, the amount of fire extinguishing agent needed for the j-th plan is S<sub>L<sub>j</sub></sub>(T<sub>j</sub>) + S<sub>L<sub>j+1</sub></sub>(T<sub>j</sub>) + · · · + S<sub>R<sub>j</sub></sub> (T<sub>j</sub>) liters. In order to examine the plan to be done, you want to know the amount of fire extinguishing agent needed for each plan.</p>

<p>Write a program which, given the strength of the fire at time 0 and information of fire extinguishing plans, calculates the amount of fire extinguishing agent needed for each plan.</p>

### 입력 

 <p>Read the following data from the standard input. Given values are all integers.</p>

<pre>N Q
S<sub>1</sub> . . . S<sub>N</sub>
T<sub>1</sub> L<sub>1</sub> R<sub>1</sub>
.
.
.
T<sub>Q</sub> L<sub>Q</sub> R<sub>Q</sub></pre>

### 출력 

 <p>Write Q lines to the standard output. In the j-th line (1 ≤ j ≤ Q), output the amount of fire extinguishing agent needed for the j-th plan.</p>

