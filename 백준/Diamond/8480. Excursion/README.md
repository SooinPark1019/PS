# [Diamond V] Excursion - 8480 

[문제 링크](https://www.acmicpc.net/problem/8480) 

### 성능 요약

메모리: 115068 KB, 시간: 392 ms

### 분류

볼록 껍질을 이용한 최적화, 자료 구조, 다이나믹 프로그래밍, 세그먼트 트리

### 제출 일자

2025년 1월 27일 15:00:05

### 문제 설명

<p>Byteasar is planning a bike trip around Byteland. He has selected n+1 towns that he is going to visit and n roads that connect the pairs of consecutive towns. Each road can be described using two parameters: its length and its impression-factor, which could be either positive or negative.</p>

<p>The last thing that Byteasar has to do is to divide the trip into segments that will correspond to consecutive days of the excursion. Each segment must start and end in one of the selected towns and its length may not exceed D kilometers. The impression-factor of a segment is defined as a square of the sum of impression-factors of the roads forming the segment. More formally, if a segment consists of roads with impression-factors w<sub>1</sub>, w<sub>2</sub>, ..., w<sub>m</sub>, then the impression-factor of the whole segment equals (w<sub>1</sub> + w<sub>2</sub> + ... + w<sub>m</sub>)<sup>2</sup>.</p>

<p>A bit surprisingly, Byteasar would like to minimize the sum of impression-factors of all the segments in his trip. Even though this idea sounds ridiculous, please help him find out how small sum can he get.</p>

### 입력 

 <p>The first line of input contains two integers n and D (1 ≤ n ≤ 100 000, 1 ≤ D ≤ 10<sup>9</sup>) that represent the number of roads in Byteasar's trip and the upper bound for the length of a single segment of the trip. The following n lines contain descriptions of the roads: the i-th line contains two integers d<sub>i</sub> and w<sub>i</sub> (1 ≤ d<sub>i</sub> ≤ D, -10 000 ≤ w<sub>i</sub> ≤ 10 000) that denote the length and the impression-factor of the i-th road.</p>

### 출력 

 <p>The only line of output should contain one integer: the minimum possible sum of impression-factors of all the segments in Byteasar's trip.</p>

