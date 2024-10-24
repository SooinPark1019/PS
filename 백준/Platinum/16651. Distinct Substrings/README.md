# [Platinum II] Distinct Substrings - 16651 

[문제 링크](https://www.acmicpc.net/problem/16651) 

### 성능 요약

메모리: 2164 KB, 시간: 12 ms

### 분류

KMP, 문자열

### 제출 일자

2024년 10월 25일 03:19:04

### 문제 설명

<p>Diana bought a Long Random String Generator on some weird website. She planned to generate a long string s of length n and then use its contiguous substrings as passwords for other weird websites.</p>

<p>Soon she discovered that the generated string s of length n was not random at all, but rather a string p of length k repeated many times and then cut to length n. Thus, s[i] = p[i mod k] for all i from 0 to n − 1.</p>

<p>Diana wonders how many different passwords she can get from the generated string. Help her find the number of distinct non-empty substrings in string s.</p>

### 입력 

 <p>The first line of the input contains a string p consisting of k lowercase English letters (1 ≤ k ≤ 1000).</p>

<p>The second line contains an integer n (k ≤ n ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>Output the number of distinct non-empty substrings in s.</p>

