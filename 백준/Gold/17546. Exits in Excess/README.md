# [Gold III] Exits in Excess - 17546 

[문제 링크](https://www.acmicpc.net/problem/17546) 

### 성능 요약

메모리: 8292 KB, 시간: 48 ms

### 분류

애드 혹, 해 구성하기, 그래프 이론

### 제출 일자

2025년 4월 22일 14:08:06

### 문제 설명

<p>You own a disco called the Boogie Always Persists Club. The club is famous for its multiple interconnected rooms to twist and shout in. The rooms and the corridors between them form a maze-like structure and for added bonus you have made all the corridors one-way. However, it turns out not everyone is as happy with your club as you are. Recently the fire safety inspectors came by and they were not amused by what they saw: if a fire were to break out in one of the rooms, people would have great difficulty finding the fire exits and might even start running around in circles! They find this completely unacceptable and order you to improve things as quickly as possible. They insist that you have to make sure that no one can run around in circles in the club by removing some of the corridors between the rooms.</p>

<p>You, on the other hand, want to retain the attractiveness of the rooms. You do not want to remove too many corridors, because then people will no longer visit your club. You decide that at most half of the corridors may be removed.</p>

<p>Given the layout of the club, remove at most half of the corridors so that no cycles remain.</p>

### 입력 

 <ul>
	<li>One line containing the number of rooms 1 ≤ n ≤ 10<sup>5</sup> and the number of corridors 0 ≤ m ≤ 2 · 10<sup>5</sup>.</li>
	<li>Then follow m lines, each containing two different 1-based integers u and v indicating a corridor from room u to room v. There will be no corridor from a room to itself, nor will there be more than one corridor from one room to any other single room.</li>
</ul>

### 출력 

 <ul>
	<li>On the first line, print a single integer 0 ≤ r ≤ m/2, the number of corridors to be removed.</li>
	<li>Then print r lines containing the 1-based indices of the corridors that need to be removed to ensure that dancers cannot go around in circles in the disco anymore.</li>
</ul>

<p>If there are multiple valid solutions, you may output any one of them.</p>

