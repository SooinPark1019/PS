# [Gold II] Interrail Pass - 32603 

[문제 링크](https://www.acmicpc.net/problem/32603) 

### 성능 요약

메모리: 2616 KB, 시간: 48 ms

### 분류

이분 탐색, 다이나믹 프로그래밍

### 제출 일자

2024년 11월 15일 02:02:51

### 문제 설명

<p>Interrail passes are the fun and cheap way to see more of Europe, especially if you combine your train trip with Businesslike And Penny-saving Computation! In particular, you would like to find the cheapest way to pay for your planned travels. You plan to take the train on $n$ travel days, that are not necessarily consecutive. The individual fare is different for every day, and perhaps you can save money by buying some interrail passes.</p>

<p>There are $k$ different types of interrail passes with varying costs. Each type of interrail pass can be obtained multiple times. An interrail pass is active for a period of $p$ consecutive days, that starts on a day of your choice. The interrail pass covers the first $d$ travel days during this period, which do not have to be consecutive. Note that an active interrail pass cannot be "paused": a day of travel counts towards the day count of each active pass, even when you pay the individual fare that day.</p>

<p>As an example, consider the fourth sample input, visualized in Figure I.1. It is definitely cheaper to buy interrail passes than to pay $4$ individual fares. The cheapest solution is to buy two interrail passes of the first type, rather than one interrail pass of the second type.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 365px; height: 100px;"></p>

<p style="text-align: center;">Figure I.1: Visualization of the types of interrail passes for the fourth sample input in a webshop. The first one can be activated for a period of $5$ days, and can be used for $3$ days within that period. The second one has a period of $30$ days, and can be used for $5$ days during that period.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $k$ ($1\leq n\leq 10\,000$, $0\leq k\leq 100$), the number of planned travel days, and the number of types of interrail passes available. \item $n$ lines, each with two integers $t$ and $f$ ($0\leq t \leq 10^6$, $1\leq f\leq 10^5$), the travel day and the individual fare for that day. The $n$ travel days are distinct and given in increasing order.</li>
	<li>$k$ lines, each with three integers $p$, $d$, and $c$ ($1\leq p\leq 10^6$, $1\leq d\leq p$, $1\leq c\leq 10^5$), indicating a type of interrail pass that is valid for a period of $p$ days, covers the first $d$ travel days in that period, and costs $c$.</li>
</ul>

### 출력 

 <p>Output the minimum amount you need to spend to cover all your planned travels.</p>

