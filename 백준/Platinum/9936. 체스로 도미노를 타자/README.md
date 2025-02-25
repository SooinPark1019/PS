# [Platinum III] 체스로 도미노를 타자 - 9936 

[문제 링크](https://www.acmicpc.net/problem/9936) 

### 성능 요약

메모리: 96416 KB, 시간: 112 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 2월 22일 08:01:40

### 문제 설명

<p>상근이는 N행 3열로 이루어진 체스판을 가지고 있다. </p>

<p>상근이가 잠시 외출한 사이 창영이는 체스판의 모든 칸에 정수를 썼고, 바닥에 도미노 K개를 놓고 도망갔다.</p>

<p>외출에서 돌아온 상근이는 애지중지 하는 체스판에 정수가 쓰여 있는 것을 보고 큰 충격에 빠졌다.</p>

<p>창영이는 상근이가 슬퍼하는 모습을 견딜 수가 없었다. 창영이는 도미노를 모두 사용해 체스판을 덮으려고 한다. 도미노의 크기는 2×1이고, 도미노를 모두 사용해 체스판을 덮어야 한다. 도미노는 서로 겹칠 수 없고, 회전 시킬 수 있다. 도미노는 항상 체스판의 두 칸을 차지해야 한다.</p>

<p>도미노를 이용해 체스판을 덮는 방법은 여러 가지가 있다. 이때, 도미노로 덮은 칸에 쓰여 있는 수의 합의 최댓값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1000, 1 ≤ K ≤ 1000)</p>

<p>다음 N개 줄에는 체스판의 i번째 행에 쓰여 있는 수 세 개가 주어진다. 모든 수는 절댓값이 10<sup>6</sup>보다 작은 정수이다.</p>

### 출력 

 <p>첫째 줄에 도미노 K개를 이용해 덮은 칸에 쓰여 있는 수를 모두 더했을 때, 합의 최댓값을 구하는 프로그램을 작성하시오.</p>

