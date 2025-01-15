# [Gold I] Dice Grid - 26866 

[문제 링크](https://www.acmicpc.net/problem/26866) 

### 성능 요약

메모리: 9040 KB, 시간: 16 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 구현

### 제출 일자

2025년 1월 16일 01:13:41

### 문제 설명

<p>Debora is playing a video game. In one of the levels, she is given a cube and a flat colorful $n \times n$ grid. The cell in row $i$ and column $j$ of the grid is denoted by $(i, j)$ and has color $c_{i, j}$. Debora can see the whole grid, including the color of each cell.</p>

<p>The cube face size matches the grid cell size. Whenever we say that the cube is located at cell $(i, j)$, it means that its <em>bottom</em> face coincides with the grid cell $(i, j)$. Opposite to the bottom face is the <em>top</em> face. The face that is "looking" at cell $(i + 1, j)$ is called the <em>front</em> face. The <em>back</em> face is "looking" at cell $(i - 1, j)$, the <em>right</em> face is "looking" at cell $(i, j + 1)$, and the <em>left</em> face is "looking" at cell $(i, j - 1)$.</p>

<p>Initially, the cube is located at cell $(1, 1)$. The goal of the game is to roll the cube to cell $(n, n)$.</p>

<p>From any cell $(i, j)$, Debora can only move the cube down --- to cell $(i + 1, j)$, or right --- to cell $(i, j + 1)$. The way to move the cube down is to rotate it around the edge connecting its bottom and front faces. For instance, after the rotation, the front face becomes the new bottom face. Similarly, the way to move the cube to the right is to rotate it around the edge connecting its bottom and right faces.</p>

<p>The faces of the cube are not colored yet. Debora has to paint each face in any color she wants. At every moment of the game, including the moments when the cube is located at $(1, 1)$ and $(n, n)$, the cube's bottom face color has to match the color of the grid cell where the cube is located.</p>

<p>The goal is to paint the cube in such a way that Debora will be able to move the cube from cell $(1, 1)$ to cell $(n, n)$ satisfying the conditions above. Find any possible cube coloring.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 625$). The description of the test cases follows.</p>

<p>The first line of each test case contains a single integer $n$ --- the number of rows and columns in the grid ($2 \le n \le 50$).</p>

<p>The $i$-th of the following $n$ lines contains $n$ integers $c_{i, 1}, c_{i, 2}, \ldots, c_{i, n}$ ($0 \le c_{i, j} < 2^{24}$). The RGB color of cell $(i, j)$ is $c_{i, j}$.</p>

<p>It is guaranteed that the sum of $n^2$ over all test cases does not exceed $2500$.</p>

### 출력 

 <p>For each test case, if no coloring exists, print a single word "<code>No</code>" on a separate line.</p>

<p>Otherwise, in the first line, print a single word "<code>Yes</code>".</p>

<p>In the second line, print six integers $a_b$, $a_l$, $a_k$, $a_f$, $a_r$, and $a_t$ --- the colors of the bottom, left, back, front, right, and top faces of the cube, respectively, in its initial position at cell $(1, 1)$ ($0 \le a_i < 2^{24}$).</p>

<p>If several possible colorings exist, print any of them.</p>

