# [Platinum I] 부분 문자열 변환 - 16913 

[문제 링크](https://www.acmicpc.net/problem/16913) 

### 성능 요약

메모리: 84216 KB, 시간: 408 ms

### 분류

다이나믹 프로그래밍, KMP, 문자열

### 제출 일자

2024년 12월 23일 21:30:21

### 문제 설명

<p>두 문자열 S와 T가 주어진다. T는 알파벳 소문자로만 이루어져 있고, S는 알파벳 소문자와 물음표로만 이루어져 있다.</p>

<p>S의 모든 물음표를 알파벳 소문자로 바꾸려고 한다. 이때, S의 부분 문자열로 등장하는 T의 개수를 최대로 만들어보자.</p>

### 입력 

 <p>첫째 줄에 S, 둘째 줄에 T가 주어진다. S와 T의 길이는 100,000보다 작거나 같고, 두 길이를 곱한 값은 10,000,000보다 작거나 같다.</p>

### 출력 

 <p>S의 물음표를 알파벳 소문자로 바꿨을 때, 부분 문자열로 등장할 수 있는 T의 개수의 최댓값을 출력한다.</p>

