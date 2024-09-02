# [Platinum II] Redundant Paths - 26985 

[문제 링크](https://www.acmicpc.net/problem/26985) 

### 성능 요약

메모리: 2652 KB, 시간: 0 ms

### 분류

단절점과 단절선, 자료 구조, 분리 집합, 그래프 이론

### 제출 일자

2024년 9월 3일 00:26:43

### 문제 설명

<p>In order to get from one of the F (1 ≤ F ≤ 5,000) grazing fields (which are numbered 1..F) to another field, Bessie and the rest of the herd are forced to cross near the Tree of Rotten Apples. The cows are now tired of often being forced to take a particular path and want to build some new paths so that they will always have a choice of at least two separate routes between any pair of fields. They currently have at least one route between each pair of fields and want to have at least two. Of course, they can only travel on Official Paths when they move from one field to another.</p>

<p>Given a description of the current set of R (F-1 ≤ R ≤ 10,000) paths that each connect exactly two different fields, determine the minimum number of new paths (each of which connects exactly two fields) that must be built so that there are at least two separate routes between any pair of fields. Routes are considered separate if they use none of the same paths, even if they visit the same intermediate field along the way.</p>

<p>There might already be more than one paths between the same pair of fields, and you may also build a new path that connects the same fields as some other path.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: F and R</li>
	<li>Lines 2..R+1: Each line contains two space-separated integers which are the fields at the endpoints of some path.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of new paths that must be built.</li>
</ul>

