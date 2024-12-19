# [Platinum III] The Twin Tower - 5392 

[문제 링크](https://www.acmicpc.net/problem/5392) 

### 성능 요약

메모리: 102120 KB, 시간: 116 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 런타임 전의 전처리

### 제출 일자

2024년 12월 19일 12:35:53

### 문제 설명

<p>In recent years so many twins enrolled at Leiden University, that housing them has become a big problem. In an effort to accomodate everyone, the university has made plans to build a skyscraper of N floors high, with 9 rooms on each floor, laid out in a 3 × 3 square. According to these plans, everyone should be able to get a room next to or directly above or below their twin brother or sister. To be even more precise: the two rooms of a twin should either be at opposite sides of a common wall, or the floor of one room should be the ceiling of the other. For the sake of privacy, students never share a room.</p>

<p>Today the university has tasked some poor soul (you!) to count all possible pairings of rooms that leave no room unpaired, modulo 10, 007.</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with an integer N, satisfying 0 ≤ N ≤ 5, 000.</li>
</ul>

### 출력 

 <p>For every test case in the input, the output should contain a single number, on a single line: the number of possible configurations modulo 10, 007.</p>

