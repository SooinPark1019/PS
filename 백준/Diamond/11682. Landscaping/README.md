# [Diamond V] Landscaping - 11682 

[문제 링크](https://www.acmicpc.net/problem/11682) 

### 성능 요약

메모리: 100436 KB, 시간: 24 ms

### 분류

최대 유량, 최대 유량 최소 컷 정리

### 제출 일자

2025년 1월 25일 11:49:51

### 문제 설명

<p>Preparations for a good harvest in Spring start now and farmer John is preparing his field for a good season. He went over-budget last year, as the tractors moving up and down the hills needed more fuel than he expected.</p>

<p>When harvesting, his tractors need to move both horizontally and vertically across all the land. In the image, you can see a region at low altitude in light green and a region at high altitude in dark green. When harvesting, his tractors will have to cross all the hills marked in red and they will have to go up or down 8 times.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11682/1.png" style="height:240px; width:245px"></p>

<p>This year, he is wondering whether he should level some parts of his field before sowing in order to lower his harvesting costs later on. Can you help him decide where the bulldozers should work in order to lower his costs?</p>

<p>Farmer John knows that his tractors need A additional euros when moving between adjacent patches of land at different heights. He can also pay B euros to either increase or decrease the height of any patch in his field.</p>

<p>What is the minimum amount of money he will have to pay this season?</p>

<p>Given a description of the field, the price to change the height of a patch of land and the price his tractors pay when moving between adjacent patches, the goal is to find out the minimum amount that farmer John will have to pay this year.</p>

### 입력 

 <p>The first line consists of 4 space separated integers, N, M, A and B. N and M represent the dimensions of his N ×M field, A represents the cost to move between adjacent patches of land at different levels and B is the cost to change any patch of land.</p>

<p>The next N lines each have M characters and represent farmer John’s field. A ’.’ signals a patch of land at a low level and a ’#’ represents a patch of land at a high level.</p>

### 출력 

 <p>You should output a single line with a single integer representing the minimum amount of money that farmer John will have to pay.</p>

