# [Platinum II] Ants - 3582 

[문제 링크](https://www.acmicpc.net/problem/3582) 

### 성능 요약

메모리: 3296 KB, 시간: 24 ms

### 분류

분할 정복, 최대 유량, 기하학, 선분 교차 판정, 최소 비용 최대 유량

### 제출 일자

2024년 9월 29일 03:50:11

### 문제 설명

<p>Young naturalist Bill studies ants in school. His ants feed on plant-louses that live on apple trees. Each ant colony needs its own apple tree to feed itself.</p>

<p>Bill has a map with coordinates of n ant colonies and n apple trees. He knows that ants travel from their colony to their feeding places and back using chemically tagged routes. The routes cannot intersect each other or ants will get confused and get to the wrong colony or tree, thus spurring a war between colonies.</p>

<p>Bill would like to connect each ant colony to a single apple tree so that all n routes are non-intersecting straight lines. In this problem such connection is always possible. Your task is to write a program that finds such connection.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/795db574-b8dc-4cf7-aac0-eecd3328212d/-/preview/" style="width: 172px; height: 168px;"></p>

<p>On this picture ant colonies are denoted by empty circles and apple trees are denoted by filled circles. One possible connection is denoted by lines.</p>

### 입력 

 <p>The first line of the input file contains a single integer number n (1 ≤ n ≤ 100) — the number of ant colonies and apple trees. It is followed by n lines describing n ant colonies, followed by n lines describing n apple trees. Each ant colony and apple tree is described by a pair of integer coordinates x and y (−10 000 ≤ x, y ≤ 10 000) on a Cartesian plane. All ant colonies and apple trees occupy distinct points on a plane. No three points are on the same line.</p>

### 출력 

 <p>Write to the output file n lines with one integer number on each line. The number written on i-th line denotes the number (from 1 to n) of the apple tree that is connected to the i-th ant colony.</p>

