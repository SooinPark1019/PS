# [Diamond V] Bit String - 20037 

[문제 링크](https://www.acmicpc.net/problem/20037) 

### 성능 요약

메모리: 236564 KB, 시간: 172 ms

### 분류

다이나믹 프로그래밍, KMP, 문자열

### 제출 일자

2024년 8월 15일 15:44:20

### 문제 설명

<p>A finite sequence of 0 and 1 is called a <em>bit string</em>. The length of a bit string <em>w</em> is the number of symbols contained in <em>w</em>. Note that the empty string is also a bit string of length zero. A substring of a bit string <em>w</em> is a consecutive portion of <em>w</em>. Note that the empty string is a substring of any bit string and any bit string is a substring of itself. For example, consider a bit string 1010 of length four. All substrings of 1010 are listed as follows: 1010, 101, 010, 10, 01, 1, 0, and the empty string. Bit strings 100 and 11 are not substrings of 1010. If a bit string <em>P</em> is a substring of a bit string <em>w</em>, then we say that <em>w</em> contains <em>p</em> as a substring or <em>w</em> contains <em>P</em>, shortly.</p>

<p>Consider all bit strings of length <em>n</em>. It is easy to see that there are exactly 2<sup><em>n</em></sup> bit strings of length <em>n</em> in total. Given a nonnegative integer <em>n</em> and two bit strings <em>P</em><sub>1</sub> and <em>P</em><sub>2</sub>, write a program that outputs the number of bit strings of length <em>n</em> that contain <em>P</em><sub>1</sub> but do not contain <em>P</em><sub>2</sub>.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of three lines. The first line consists of three integers, <em>n</em>, <em>k</em><sub>1</sub>, and <em>k</em><sub>2</sub> (0 ≤ <em>n</em> ≤ 100,000, 0 ≤ <em>k</em><sub>1</sub>, <em>k</em><sub>2</sub> ≤ 10,000), separated by a space. The second line consists of a single bit string, representing <em>P</em><sub>1</sub> whose length is <em>k</em><sub>1</sub>. If <em>k</em><sub>1</sub> = 0, then the second line is empty. The third line consists of a single bit string, representing <em>P</em><sub>2</sub> whose length is <em>k</em><sub>2</sub>. If <em>k</em><sub>2</sub> = 0, then the third line is empty. The three input numbers <em>n</em>, <em>k</em><sub>1</sub>, and <em>k</em><sub>2</sub> satisfy the following conditions: If 0 < <em>k</em><sub>1</sub> ≤ <em>n</em>, then the product of <em>n</em> and <em>k</em><sub>1</sub> does not exceed 10<sup>7</sup>; if 0 < <em>k</em><sub>2</sub> ≤ <em>n</em>, then the product of <em>n</em> and <em>k</em><sub>2</sub> does not exceed 10<sup>7</sup>; if 0 < <em>k</em><sub>1</sub> ≤ <em>n</em> and 0 < <em>k</em><sub>2</sub> ≤ <em>n</em>, then the product of <em>n</em>, <em>k</em><sub>1</sub>, and <em>k</em><sub>2</sub> does not exceed 10<sup>7</sup>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain an integer <em>r</em>, where 0 ≤ <em>r</em> ≤ 1,000,000,006 is the remainder when dividing by 1,000,000,007 the number of bit strings of length <em>n</em> that contain <em>P</em><sub>1</sub> but do not contain <em>P</em><sub>2</sub>.</p>

