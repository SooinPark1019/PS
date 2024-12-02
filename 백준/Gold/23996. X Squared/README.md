# [Gold I] X Squared - 23996 

[문제 링크](https://www.acmicpc.net/problem/23996) 

### 성능 요약

메모리: 2020 KB, 시간: 8 ms

### 분류

애드 혹

### 제출 일자

2024년 12월 2일 22:26:45

### 문제 설명

<p>The hot new toy for this year is called "X Squared". It consists of a square <b>N</b> by <b>N</b> grid of tiles, where <b>N</b> is odd. Exactly 2 × <b>N</b> - 1 of the tiles are labeled with an <code>X</code>, and the rest are blank (which we will represent with the <code>.</code> character). In each move of the game, the player can either choose and exchange two rows of tiles, or choose and exchange two columns of tiles. The goal of the game is to get all of the <code>X</code> tiles to be on the two main diagonals of the grid, forming a larger X shape, as in the following example for <b>N</b> = 5:</p>

<pre><code>X...X
.X.X.
..X..
.X.X.
X...X</code></pre>

<p>You are about to play with your X Squared toy, which is not yet in the goal state. You suspect that your devious younger sibling might have moved some of the tiles around in a way that has broken the game. Given the current configuration of the grid, can you determine whether it is possible to win or not?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <b>T</b>. <b>T</b> test cases follow. Each one begins with one line with an integer <b>N</b>, the size of the grid. <b>N</b> more lines with <b>N</b> characters each follow; the j-th character on the i-th of these lines is <code>X</code> if the tile in the i-th row and j-th column of the grid has an X, or <code>.</code> if that tile is blank.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where <code>x</code> is the test case number (starting from 1) and <code>y</code> is <code>POSSIBLE</code> if it is possible to win, and <code>IMPOSSIBLE</code> otherwise.</p>

