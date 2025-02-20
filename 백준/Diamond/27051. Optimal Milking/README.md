# [Diamond V] Optimal Milking - 27051 

[문제 링크](https://www.acmicpc.net/problem/27051) 

### 성능 요약

메모리: 3092 KB, 시간: 28 ms

### 분류

분류 없음

### 제출 일자

2025년 2월 20일 10:03:57

### 문제 설명

<p>FJ has moved his K (1 ≤ K ≤ 30) milking machines out into the cow pastures among the C (1 ≤ C ≤ 200) cows. A set of paths of various lengths runs among the cows and the milking machines. The milking machine locations are named by ID numbers 1..K; the cow locations are named by ID numbers K+1..K+C.</p>

<p>Each milking point can "process" at most M (1 ≤ M ≤ 15) cows each day.</p>

<p>Write a program to find an assignment for each cow to some milking machine so that the distance the furthest-walking cow travels is minimized (and, of course, the milking machines are not overutilized). At least one legal assignment is possible for all input data sets. Cows can traverse several paths on the way to their milking machine.</p>

### 입력 

 <ul>
	<li>Line 1: A single line with three space-separated integers: K, C, and M.</li>
	<li>Lines 2.. ...: Each of these K+C lines of K+C space-separated integers describes the distances between pairs of various entities. The input forms a symmetric matrix. Line 2 tells the distances from milking machine 1 to each of the other entities; line 3 tells the distances from machine 2 to each of the other entities, and so on. Distances of entities directly connected by a path are positive integers no larger than 200. Entities not directly connected by a path have a distance of 0. The distance from an entity to itself (i.e., all numbers on the diagonal) is also given as 0. To keep the input lines of reasonable length, when K+C > 15, a row is broken into successive lines of 15 numbers and a potentially shorter line to finish up a row. Each new row begins on its own line.</li>
</ul>

### 출력 

 <p>A single line with a single integer that is the minimum possible total distance for the furthest walking cow.</p>

