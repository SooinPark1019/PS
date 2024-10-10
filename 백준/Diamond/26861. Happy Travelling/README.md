# [Diamond V] Happy Travelling - 26861 

[문제 링크](https://www.acmicpc.net/problem/26861) 

### 성능 요약

메모리: 17936 KB, 시간: 956 ms

### 분류

자료 구조, 다이나믹 프로그래밍, 세그먼트 트리, 제곱근 분할법

### 제출 일자

2024년 10월 10일 16:03:03

### 문제 설명

<p>A holiday is coming and Sam plans to visit his parents. There are N cities numbered from 1 to N. Sam lives in a campus dormitory in city 1 while his parents live in city N.</p>

<p>Sam already did some research on the cities. He assigns an integer Hi to each city i representing the “happiness value” he will get if he visits city i, including city 1 and city N.</p>

<p>As for the transportation, he found out that for every city 1 ≤ i < N, there is a one-way bus that starts at city i and stops at each city from city i + 1 until city i + T<sub>i</sub>; in other words, the bus will stop at each of the next T<sub>i</sub> cities. It is guaranteed that i + T<sub>i</sub> ≤ N. When Sam is at city i < N, he will board a bus that starts at city i and alight at city j where j ∈ (i + 1, i + T<sub>i</sub>) while skipping all the stops between city i and city j (exclusive). Note that Sam cannot board a bus that does not start at city i if he is at city i.</p>

<p>Sam likes to be happy but he doesn’t like being on a bus for a long time (he gets bored easily). Specifically, if he boards a bus that starts at city i and alights at city j (where i < j), then his happiness value will be decreased by the following.</p>

<p style="text-align: center;">⌊(j − i) / K⌋ × D</p>

<p>Sam is busy preparing souvenirs for his parents and figuring out what to do when he gets there. So he needs your help computing the total maximum happiness value that he can get by carefully planning his journey from city 1 to city N.</p>

<p>For example, let N = 6, K = 2, D = 1, H<sub>1..6</sub> = {8, −7, −8, 9, 0, 2}, and T<sub>1..5</sub> = {5, 3, 3, 2, 1}. The maximum total happines value that can be obtained from this example is 18 as shown in the following plan.</p>

<ul>
	<li>Sam starts at city 1. He obtains a happiness value of H<sub>1</sub> = 8 at city 1.</li>
	<li>At city 1, Sam boards the bus that can stop at any city in [2, 6] and alights at city 4. His happiness value is decreased by ⌊(4−1)/2⌋ × 1 = 1 due to this bus trip. He obtains a happiness value of H<sub>4</sub> = 9 at city 4.</li>
	<li>At city 4, Sam boards the bus that can stop at any city in [5, 6] and alights at city 5. His happiness value is decreased by ⌊(5−4)/2⌋ × 1 = 0 due to this bus trip. He obtains a happiness value of H<sub>5</sub> = 0 at city 5.</li>
	<li>At city 5, Sam boards the bus that can stop at any city in [6, 6] and alights at city 6. His happiness value is decreased by ⌊(6−5)/2⌋ × 1 = 0 due to this bus trip. He obtains a happiness value of H<sub>6</sub> = 2 at city 6.</li>
</ul>

<p>In this plan, Sam boards a bus 3 times with the total happiness value of 8 + (−1 + 9) + (0 + 0) + (0 + 2) = 18. No other plan has a better total happiness value than this in this example.</p>

### 입력 

 <p>Input begins with a line containing three integers N K D (2 ≤ N ≤ 100 000; 1 ≤ K ≤ N; 0 ≤ D ≤ 10 000) representing the number of cities, and the parameter K and D as defined in the problem description, respectively. The second line contains N integers H<sub>i</sub> (−10 000 ≤ H<sub>i</sub> ≤ 10 000) representing the happiness value Sam will get if he visits city i. The third line contains N −1 integers T<sub>i</sub> (1 ≤ T<sub>i</sub>; i+T<sub>i</sub> ≤ N) for 1 ≤ i < N representing the number of next contiguous cities in which the bus that starts at city i will stop at.</p>

### 출력 

 <p>Output contains an integer in a line representing the maximum total happiness value that can be obtained.</p>

