# [Gold I] Forward and Backward - 30481 

[문제 링크](https://www.acmicpc.net/problem/30481) 

### 성능 요약

메모리: 2160 KB, 시간: 136 ms

### 분류

수학, 정수론, 제곱근 분할법

### 제출 일자

2024년 10월 9일 14:45:24

### 문제 설명

<p>A distant planetary system has a single sun and N − 1 planets. Each planet is identified by a distinct integer from 2 to N. In planet b, numbers are represented using base b.</p>

<p>A palindromic number is a number that remains the same when its digits are written both forward and backward. In this context, leading zeroes are not considered when determining if a number is palindromic.</p>

<p>The same number can be palindromic in one planet’s base but not in another. For instance, in base 10, the number 33 is palindromic. It is also palindromic in base 2 and base 32 but not in bases such as 3 or 33, since 33<sub>10</sub> = 100001<sub>2</sub> = 1020<sub>3</sub> = 11<sub>32</sub> = 10<sub>33</sub>.</p>

<p>The inhabitants of this planetary system have a peculiar fondness for palindromic numbers and want to know which planets make the number N a palindromic number when represented in their base. Your task is to help them with this cosmic challenge.</p>

### 입력 

 <p>The input consists of a single line that contains an integer N (2 ≤ N ≤ 10<sup>12</sup>) indicating the number to be checked for palindromic representation. N is given in base 10.</p>

### 출력 

 <p>Output a single line with an increasing list of integers in the interval [2, N], indicating the planets in which N is a palindromic number when expressed in the base of the planet’s identifier. Output these integers in base 10. If N is not palindromic in any of the planets, output the character “*” (asterisk) instead.</p>

