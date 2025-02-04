# [Gold III] JJOOII 2 - 18432 

[문제 링크](https://www.acmicpc.net/problem/18432) 

### 성능 요약

메모리: 10292 KB, 시간: 12 ms

### 분류

이분 탐색, 두 포인터

### 제출 일자

2025년 2월 4일 16:09:53

### 문제 설명

<p>Bitaro received a string S of length N for his birthday present. String S consists of three kinds of characters, <code>J</code>, <code>O</code> and <code>I</code>.</p>

<p>For each positive integer K, we will call the string which consists of K <code>J</code>’s, K <code>O</code>’s, and K <code>I</code>’s in this order <strong>JOI-string of level K</strong>. For example, <code>JJOOII</code> is a JOI-string of level 2.</p>

<p>Bitaro likes a JOI-string of level K, so he is going to make a JOI-string of level K from string S by using the following three operations any number of times in arbitrary order:</p>

<ul>
	<li><strong>Operation 1</strong> Bitaro deletes the first character of S.</li>
	<li><strong>Operation 2</strong> Bitaro deletes the last character of S.</li>
	<li><strong>Operation 3</strong> Bitaro deletes a character of S which is neither the first nor the last.</li>
</ul>

<p>Because using Operation 3 is time-consuming, Bitaro wants to make a JOI-string of level K with as small number of Operation 3 as possible.</p>

<p>Write a program which, given a string S of length N and a positive integer K, prints the smallest number of Operation 3 required to make a JOI-string of level K from S . If it is impossible to make a JOI-string of level K with the operations, print −1 instead.</p>

### 입력 

 <p>Read the following data from the standard input. N and K are integers. S is a string.</p>

<pre>N K
S</pre>

### 출력 

 <p>Write one line to the standard output. The output should contain the smallest number of Operation 3 required to make a JOI-string of level K from S . If it is impossible to make a JOI-string of level K, print −1 instead.</p>

