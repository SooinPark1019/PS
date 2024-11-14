# [Platinum I] Museum Visit - 32607 

[문제 링크](https://www.acmicpc.net/problem/32607) 

### 성능 요약

메모리: 28508 KB, 시간: 192 ms

### 분류

이분 탐색, 자료 구조, 다이나믹 프로그래밍, 세그먼트 트리

### 제출 일자

2024년 11월 15일 02:02:14

### 문제 설명

<p>Every day is different in the <em>Groninger Museum</em>. Some days are nice, peaceful and quiet, and you can spend all day looking at the beautiful paintings, sculptures, and other artworks. Other days are busier, when weekends or public holidays fill the museum with hasty visitors, increased prices and screaming children. This discomfort varies a lot: some busy days are better because of extra <em>studentenkorting</em> (student discount) and some of the quiet days get worse because of earthquake risks.</p>

<p>The museum also regularly hosts special limited-time exhibitions, such as those on the local football club FC Groningen, the Martinitoren, or the eierbal (a local delicacy). These exhibitions can be very irregular: some last for weeks, some last only a day, and there may be multiple exhibitions on the same day.</p>

<p>As a proud <em>Grunneger</em>, you want to visit each exhibition at least once. Luckily, you are subscribed to the newsletter so you know the start and end days of all the exhibitions in advance. Additionally, since you are a regular visitor at the museum, you have observed all the crowd and earthquake patterns, so you know exactly how much discomfort you will receive when you visit the museum on any specific day.</p>

<p>On which days should you visit the museum in order to minimize your total discomfort while still seeing all exhibitions that are planned in the foreseeable future? As an example, consider the first sample case. To minimize your total discomfort, you should visit the first two exhibitions on the second day and the last exhibition on the fourth or fifth day.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $m$ ($1\leq n,m\leq 2\cdot10^5$), the number of days in the foreseeable future and the number of exhibitions planned in those days.</li>
	<li>One line with $n$ integers $c$ ($1\leq c\leq 10^9$), describing for each day the discomfort you will receive when you visit the museum.</li>
	<li>$m$ lines, each with two integers $s$ and $e$ ($1\leq s\leq e\leq n$), describing the start and end day of an exhibition. The start and end days are inclusive: the exhibition can be visited on day $s$, day $e$, and any day in between.</li>
</ul>

### 출력 

 <p>Output the minimum total discomfort you will receive when visiting all exhibitions of the Groninger Museum.</p>

