# [Platinum I] Grass Cownoisseur - 10671 

[문제 링크](https://www.acmicpc.net/problem/10671) 

### 성능 요약

메모리: 25340 KB, 시간: 72 ms

### 분류

방향 비순환 그래프, 다이나믹 프로그래밍, 그래프 이론, 강한 연결 요소, 위상 정렬

### 제출 일자

2024년 12월 14일 01:54:09

### 문제 설명

<p>In an effort to better manage the grazing patterns of his cows, Farmer John has installed one-way cow paths all over his farm.  The farm consists of N fields, conveniently numbered 1..N, with each one-way cow path connecting a pair of fields.  For example, if a path connects from field X to field Y, then cows are allowed to travel from X to Y but not from Y to X.</p>

<p>Bessie the cow, as we all know, enjoys eating grass from as many fields as possible.  She always starts in field 1 at the beginning of the day and visits a sequence of fields, returning to field 1 at the end of the day.  She tries to maximize the number of distinct fields along her route, since she gets to eat the grass in each one (if she visits a field multiple times, she only eats the grass there once).</p>

<p>As one might imagine, Bessie is not particularly happy about the one-way restriction on FJ's paths, since this will likely reduce the number of distinct fields she can possibly visit along her daily route.  She wonders how much grass she will be able to eat if she breaks the rules and follows up to one path in the wrong direction. Please compute the maximum number of distinct fields she can visit along a route starting and ending at field 1, where she can follow up to one path along the route in the wrong direction.  Bessie can only travel backwards at most once in her journey.  In particular, she cannot even take the same path backwards twice. </p>

### 입력 

 <p>The first line of input contains N and M, giving the number of fields and the number of one-way paths (1 <= N, M <= 100,000).</p>

<p>The following M lines each describe a one-way cow path.  Each line contains two distinct field numbers X and Y, corresponding to a cow path from X to Y.  The same cow path will never appear more than once.</p>

### 출력 

 <p>A single line indicating the maximum number of distinct fields Bessie can visit along a route starting and ending at field 1, given that she can follow at most one path along this route in the wrong direction.</p>

