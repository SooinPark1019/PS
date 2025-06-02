# [Diamond V] Dango Maker - 15555 

[문제 링크](https://www.acmicpc.net/problem/15555) 

### 성능 요약

메모리: 213664 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 5월 31일 03:24:35

### 문제 설명

<p>You are a professional confectioner making dangos, Japanese sweet dumplings. Now, you are about to skewer the dumplings.</p>

<p>The dumplings are placed on a grid of cells with N rows and M columns. Each cell contains one dumpling. The color of each dumpling is either red (R), green (G), or white (W).</p>

<p>You will choose three consecutive dumplings from the cells, and skewer them to a stick. The direction of the chosen three consecutive dumplings must be from left to right, or from top to bottom.</p>

<p>Now, you want to make sticks of dumplings whose colors are red, green, white, in this order. You want to make as many sticks of dumplings as possible. The order of dumplings skewered to a stick must be the same as the order of dumplings chosen from the cells. You are not allowed to skewer more than one sticks to one dumpling.</p>

<p>How many sticks of dumplings can you make?</p>

<p>Given the colors of dumplings placed on the cells, write a program which calculates the maximum number of sticks of dumplings you can make. The colors must be red, green, white, in this order.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<ul>
	<li>The first line of input contains two space separated integers N and M.</li>
	<li>The i-th line (1 ≤ i ≤ N) of the following N lines contains a string of size M consisting of R, G, or W. The j-th character (1 ≤ j ≤ M) of this string is the color of the dumpling in the i-th row from the top, and the j-th column from the left.</li>
</ul>

### 출력 

 <p>White one line to the standard output. The output should contain the maximum number of sticks of dumplings.</p>

