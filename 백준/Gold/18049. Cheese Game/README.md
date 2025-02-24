# [Gold I] Cheese Game - 18049 

[문제 링크](https://www.acmicpc.net/problem/18049) 

### 성능 요약

메모리: 6532 KB, 시간: 200 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 24일 10:26:58

### 문제 설명

<p>After taking part in the annual Two-player Games and Applied Cryptography Symposium, Alice and Bob want to relax by playing their favourite game. They have arranged <em>n</em> cheese slices in a row, numbered from 1 do <em>n</em>. As we all know, though cheese is tasty in general, some slices can be better than others – this is why the <em>i</em>-th slice is described by its deliciousness <em>o<sub>i</sub></em>.</p>

<p>Alice starts the game and the players alternate their moves. In a move, a player may eat any set of cheese slices that are still left on the board, providing that the set contains no two neighbouring slices (i.e. numbered <em>i</em> and <em>i</em>+1 for any 1 ≤ <em>i</em> ≤ <em>n</em>−1). We assume that the numbers of the slices do not change, so during the game no new neighbouring pairs appear.</p>

<p>Of course, both players aim to maximize the total delicioussness of their eaten pieces. Assuming that they both play optimally, what is the maximal score that Alice can achive?</p>

### 입력 

 <p>The first line of input contains the number of test cases <em>z</em> (1 ≤ <em>z</em> ≤ 20). The test cases follow, each one in the following format:</p>

<p>The first line of a test case contains the number of cheese slices <em>n</em> (1 ≤ <em>n</em> ≤ 100 000). The second line contains <em>n</em> integers <em>o</em><sub>1</sub>, <em>o</em><sub>2</sub>, . . . , <em>o<sub>n</sub></em> (1 ≤ <em>o<sub>i</sub></em> ≤ 1 000 000) – the values of the pieces’ delicioussness.</p>

### 출력 

 <p>For every test case, output a single integer – the total delicioussness of the slices eaten by Alice, assuming that both players play optimally.</p>

