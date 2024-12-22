# [Platinum IV] Hat Stand - 17801 

[문제 링크](https://www.acmicpc.net/problem/17801) 

### 성능 요약

메모리: 5252 KB, 시간: 20 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2024년 12월 22일 21:35:00

### 문제 설명

<p>You own several hats, some of which you wear more than others. Because wearing all n at once would be impractical, you store the spares on a rack with n − 1 hooks. The first hook is a half metre from the door, the second one metre, the third a metre-and-a-half, and so on. This means that walking from and to the door to the ith hook involves i metres of walking.</p>

<p>Tonight you will need to make a series of public appearances, each time wearing headgear appropriate to the role. When you come back from one engagement, you will take the hat you need from its hook and exchange it with the one you had been wearing before. This means that hats can move around as the night goes on.</p>

<p>Given the plan for tonight, and assuming you are already wearing the first one, what is the best way to arrange the hats on the rack before setting off so as to minimise the number of metres walked?</p>

### 입력 

 <ul>
	<li>The first line of input contains two integers: c and n (1 ≤ c, n ≤ 10<sup>5</sup>), the number of hats in total and the length of the itinerary respectively.</li>
	<li>The second line of input contains n integers: v<sub>1</sub> . . . v<sub>n</sub> (1 ≤ v ≤ c; v[i] ≠ v[i − 1]), the order of hats you need to put on. You are already wearing the first one, and you never need to wear the same hat twice consecutively.</li>
</ul>

### 출력 

 <p>Output the minimum number of metres you need to walk, once you have optimised your hat rack.</p>

<p>Next, output c − 1 integers: an initial ordering of the hat rack that gives minimum walking distance, starting from place 1. This should include exactly once every hat except the first.</p>

<p>If there are multiple correct answers, you may output any one of them.</p>

