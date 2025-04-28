# [Platinum V] Free Edges - 18452 

[문제 링크](https://www.acmicpc.net/problem/18452) 

### 성능 요약

메모리: 7664 KB, 시간: 40 ms

### 분류

애드 혹, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 4월 28일 19:55:18

### 문제 설명

<p>You have an undirected graph. Initially, all edges are white. You can choose some edges and paint them black.</p>

<p>After that, while there is a vertex such that exactly one white edge comes out of it, this white edge also becomes black.</p>

<p>Your goal is to choose the minimum possible number of edges to paint black such that, after the process is finished, all edges will be black.</p>

### 입력 

 <p>The first line of the input contains two integers n and m: the number of vertices and the number of edges in your graph (1 ≤ n, m ≤ 10<sup>5</sup>).</p>

<p>The next m lines contain description of the edges of the graph. Each of these lines contains two integers a<sub>i</sub> and b<sub>i</sub>, describing an edge between vertices a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n, a<sub>i</sub> ≠ b<sub>i</sub>).</p>

<p>It is guaranteed that there are no multiple edges.</p>

### 출력 

 <p>Print one integer: the minimum possible number of edges you need to paint black such that, after the end of the described process, all edges will be black.</p>

