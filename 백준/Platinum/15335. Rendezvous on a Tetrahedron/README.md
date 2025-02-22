# [Platinum IV] Rendezvous on a Tetrahedron - 15335 

[문제 링크](https://www.acmicpc.net/problem/15335) 

### 성능 요약

메모리: 2076 KB, 시간: 0 ms

### 분류

애드 혹, 많은 조건 분기, 기하학

### 제출 일자

2025년 2월 22일 09:53:50

### 문제 설명

<p>One day, you found two worms P and Q crawling on the surface of a regular tetrahedron with four vertices A, B, C, and D. Both worms started from the vertex A, went straight ahead, and stopped crawling after a while.</p>

<p>When a worm reached one of the edges of the tetrahedron, it moved on to the adjacent face and kept going without changing the angle to the crossed edge (Figure G.1).</p>

<p>Write a program which tells whether or not P and Q were on the same face of the tetrahedron when they stopped crawling.</p>

<p>You may assume that each of the worms is a point without length, area, or volume.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15335/1.png" style="height:279px; width:276px"></p>

<p style="text-align:center">Figure G.1. Crossing an edge</p>

<p>Incidentally, lengths of the two trails the worms left on the tetrahedron were exact integral multiples of the unit length. Here, the unit length is the edge length of the tetrahedron. Each trail is more than 0.001 unit distant from any vertices, except for its start point and its neighborhood. This means that worms have crossed at least one edge. Both worms stopped at positions more than 0.001 unit distant from any of the edges.</p>

<p>The initial crawling direction of a worm is specified by two items: the edge XY which is the first edge the worm encountered after its start, and the angle d between the edge AX and the direction of the worm, in degrees.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15335/2.png" style="height:317px; width:327px"></p>

<p style="text-align:center">Figure G.2. Trails of the worms corresponding to Sample Input 1</p>

<p>Figure G.2 shows the case of Sample Input 1. In this case, P went over the edge CD and stopped on the face opposite to the vertex A, while Q went over the edge DB and also stopped on the same face.</p>

### 입력 

 <p>The input consists of a single test case, formatted as follows.</p>

<pre>X<sub>P</sub>Y<sub>P</sub> d<sub>P</sub> l<sub>P</sub>
X<sub>Q</sub>Y<sub>Q</sub> d<sub>Q</sub> l<sub>Q</sub></pre>

<p>X<sub>W</sub> Y<sub>W</sub> (W = P, Q) is the first edge the worm W crossed after its start. X<sub>W</sub> Y<sub>W</sub> is one of BC, CD or DB.</p>

<p>An integer d<sub>W</sub> (1 ≤ d<sub>W</sub> ≤ 59) is the angle in degrees between edge AX<sub>W</sub> and the initial direction of the worm W on the face △AX<sub>W</sub>Y<sub>W</sub>.</p>

<p>An integer l<sub>W</sub> (1 ≤ l<sub>W</sub> ≤ 20) is the length of the trail of worm W left on the surface, in unit lengths.</p>

### 출력 

 <p>Output <code>YES</code> when and only when the two worms stopped on the same face of the tetrahedron. Otherwise, output <code>NO</code>.</p>

