# [Gold II] Lots of Towers of Hanoi - 25835 

[문제 링크](https://www.acmicpc.net/problem/25835) 

### 성능 요약

메모리: 2156 KB, 시간: 248 ms

### 분류

해 구성하기

### 제출 일자

2024년 12월 28일 19:05:54

### 문제 설명

<p>In the original Towers of Hanoi game, there are three towers of disks. In the initial configuration, all of the disks are on a single tower such that the radii of the disks are sorted in order from smallest to largest, from top to bottom. Here is a picture of the starting position of the original game:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/84644ef1-f862-4938-8dfa-01978f639b98/-/preview/" style="width: 347px; height: 157px;"></p>

<p>The disks are typically labeled 1 to n, where n is the number of disks, with 1 representing the smallest disk and n representing the largest disk. In this diagram, the towers are labeled A, B and C. The goal of the game is to transfer all the disks to a different tower via a sequence of moves. On a single move, one may move the top disk of any tower onto the top disk of another tower, provided that the disk being placed on top is smaller than the disk below it. Alternatively, one may move the top disk of any tower onto an empty tower. To signify a move, it’s good enough to simply specify a starting and ending tower. For example, in the above diagram, performing the moves A to B followed by A to C, followed by B to C would result in disks 3, 4, and 5 on tower A and disks 1 and 2 on tower C.</p>

<p>Luckily, the manufacturers of the game have splurged on the number of towers and have produced a set with k towers instead of just 3 towers. Due to the generality, the towers are labeled 1 through k, instead of A, B and C. The manufacturers have decided to include n = k(k−1)/2 disks with the set. The directions on the box containing the puzzle claim that the puzzle can be solved with 2(k-1)<sup>2</sup> or fewer moves. Write a program to prove the manufacturer’s conclusion.</p>

<p>Given the value of k, the number of towers in the Towers of Hanoi game, the number of the starting tower of all the disks, s, and the number of the ending tower of all the disks, e, create a sequence of at most 2(k-1)<sup>2</sup> moves that solves the puzzle.</p>

### 입력 

 <p>The first and only input line contains three integers: k (3 ≤ k ≤ 1000), representing the number of towers in the game, s (1 ≤ s ≤ k), representing the starting tower for the k(k−1)/2 disks, and e (1 ≤ e ≤ k, e ≠ s), representing the ending tower for the k(k−1)/2 disks.</p>

### 출력 

 <p>The first line of output should contain a single positive integer, m, number of moves in your solution. The following m lines should contain the contents of each move, in the sequence they are made to solve the puzzle. For each move, simply output two space separated integers, a and b (a ≠ b), representing the starting and ending towers, respectively, for that particular move.</p>

