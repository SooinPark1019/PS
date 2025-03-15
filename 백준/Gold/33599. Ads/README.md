# [Gold III] Ads - 33599 

[문제 링크](https://www.acmicpc.net/problem/33599) 

### 성능 요약

메모리: 6776 KB, 시간: 344 ms

### 분류

그리디 알고리즘, 수학, 두 포인터

### 제출 일자

2025년 3월 15일 14:57:28

### 문제 설명

<p>You have $n$ videos on your watchlist on the popular platform YooCube. The $i$-th video lasts $d_i$ minutes.</p>

<p>YooCube has recently increased the frequency of their ads. Ads are shown only between videos. After finishing a video, an ad is shown if either of these two conditions is true:</p>

<ul>
	<li>three videos have been watched since the last ad;</li>
	<li>at least $k$ minutes have passed since the end of the last ad.</li>
</ul>

<p>You want to watch the $n$ videos in your watchlist. Given that you have just watched an ad, and that you can choose the order of the $n$ videos, what is the minimum number of ads that you are forced to watch? You can start a new video immediately after the previous video or ad ends, and you don’t have to watch any ad after you finish.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains an integer $t$ ($1 ≤ t ≤ 100\, 000$) — the number of test cases. The descriptions of the $t$ test cases follow.</p>

<p>The first line of each test case contains two integers $n$ and $k$ ($1 ≤ n ≤ 100\, 000$, $1 ≤ k ≤ 30\, 000$) — the number of videos in your watchlist and the parameter that determines when ads are shown.</p>

<p>The second line contains $n$ integers $d_1, d_2, \dots , d_n$ ($1 ≤ d_i ≤ 10\, 000$) — the lengths of the videos.</p>

<p>The sum of the values of $n$ over all test cases does not exceed $10^6$.</p>

### 출력 

 <p>For each test case, print the minimum number of ads that you need to watch.</p>

