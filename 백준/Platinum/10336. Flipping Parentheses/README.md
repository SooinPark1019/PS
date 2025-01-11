# [Platinum II] Flipping Parentheses - 10336 

[문제 링크](https://www.acmicpc.net/problem/10336) 

### 성능 요약

메모리: 28408 KB, 시간: 984 ms

### 분류

자료 구조, 세그먼트 트리

### 제출 일자

2025년 1월 12일 01:02:10

### 문제 설명

<p>A string consisting only of parentheses ‘(’ and ‘)’ is called balanced if it is one of the following.</p>

<ul>
	<li>A string “()” is balanced.</li>
	<li>Concatenation of two balanced strings are balanced.</li>
	<li>When a string s is balanced, so is the concatenation of three strings “(”, s, and “)” in this order.</li>
</ul>

<p>Note that the condition is stronger than merely the numbers of ‘(’ and ‘)’ are equal. For instance, “())(()” is not balanced.</p>

<p>Your task is to keep a string in a balanced state, under a severe condition in which a cosmic ray may flip the direction of parentheses.</p>

<p>You are initially given a balanced string. Each time the direction of a single parenthesis is flipped, your program is notified the position of the changed character in the string. Then, calculate and output the leftmost position that, if the parenthesis there is flipped, the whole string gets back to the balanced state. After the string is balanced by changing the parenthesis indicated by your program, next cosmic ray flips another parenthesis, and the steps are repeated several times.</p>

### 입력 

 <p>The input consists of a single test case formatted as follows.</p>

<pre>N Q
s
q<sub>1</sub>
.
.
.
q<sub>Q</sub></pre>

<p>The first line consists of two integers N and Q (2 ≤ N ≤ 300000, 1 ≤ Q ≤ 150000). The second line is a string s of balanced parentheses with length N. Each of the following Q lines is an integer q<sub>i</sub> (1 ≤ q<sub>i</sub> ≤ N) that indicates that the direction of the q<sub>i</sub>-th parenthesis is flipped.</p>

### 출력 

 <p>For each event q<sub>i</sub>, output the position of the leftmost parenthesis you need to flip in order to get back to the balanced state.</p>

<p>Note that each input flipping event q<sub>i</sub> is applied to the string after the previous flip q<sub>i</sub>−1 and its fix.</p>

