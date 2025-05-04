# [Gold V] Easy Assembly - 26285 

[문제 링크](https://www.acmicpc.net/problem/26285) 

### 성능 요약

메모리: 3516 KB, 시간: 4 ms

### 분류

값 / 좌표 압축, 자료 구조, 그리디 알고리즘, 해시를 사용한 집합과 맵, 정렬, 집합과 맵

### 제출 일자

2025년 5월 4일 19:28:42

### 문제 설명

<p>Emma loves playing with blocks. She has several cubic blocks of the same size that are numbered with <strong>distinct</strong> integers written on them. She assembles towers from those blocks by stacking them vertically. </p>

<p>A configuration of her game is a set of towers that she has assembled from the blocks. Emma can perform two kinds of operations on a configuration of towers:</p>

<ul>
	<li><strong>Split</strong> any tower with more than one block in it by taking any number of blocks from the top of the tower and moving them to a new tower keeping their order, so that the top block of the old tower becomes the top block of the new tower. As a result of this operation, the number of towers increases by one.</li>
	<li><strong>Combine</strong> any two towers by moving blocks from one tower on top of the other tower in the same order. As a result of this operation, the number of towers decreases by one.</li>
</ul>

<p>Emma wants to stack all the blocks into a single tower so that all blocks come in order sorted by the numbers --- from the block with the minimal number at the top to the block with the maximal number at the bottom. Emma wants to do as little of splitting and combining operations as possible. Your task is to find the minimal number of operations she has to make and output how many splits and combines are needed.</p>

### 입력 

 <p>The first line of the input file contains an integer $n$ ($1 \le n \le 10\,000$) --- the number of towers in the initial configuration. Next $n$ lines describe towers. Each tower $i$ is described by a line that starts with the number $k_i$ ($k_i \ge 1$; $\sum_1^n{k_i} \le 10\,000$) --- the number of blocks in the tower, followed by $k_i$ numbers $b_{i,j}$ ($1 \le b_{i,j} \le 10^9$) --- numbers written on the blocks in the $i$-th tower, listed from top to bottom. All block numbers listed in the input are different. </p>

### 출력 

 <p>Output a line with two integers $s$ and $c$ --- the number of split and combine operations Emma should make to get a single tower with blocks sorted by their numbers, so that the total number of operations is minimized.</p>

