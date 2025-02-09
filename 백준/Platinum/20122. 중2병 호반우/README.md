# [Platinum IV] 중2병 호반우 - 20122 

[문제 링크](https://www.acmicpc.net/problem/20122) 

### 성능 요약

메모리: 18408 KB, 시간: 584 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2024년 12월 24일 18:00:36

### 문제 설명

<p>17세의 호반우가 길을 건너간다는 특성이 있다면 15세의 호반우에게는 중2병이 찾아온다는 특성이 있다!</p>

<p>중2병에 걸린 호반우들은 인간들을 호반우빔으로 죽이는 망상을 자주 한다.</p>

<p>그들이 하는 망상의 내용은 구체적으로 이러하다.</p>

<ol>
	<li>감옥은 <em>N</em> × <em>M</em> 크기의 격자판으로 이루어져 있고 감옥에는 사람 한 명이 갇혀있다.</li>
	<li>사람들은 호반우 도축, 호반우 감금, 호반우 우권 침해 셋 중 하나의 죄명을 가지고 있다.</li>
</ol>

<p>호반우는 호반우빔을 사용해 이 사람들을 죽일 계획을 가지고 있다..!!</p>

<p>사람들은 호반우빔에 맞게되면 탈모가 생기며 빠른 시간안에 죽는다.</p>

<p>호반우빔은 격자 모양의 감옥 <strong>왼쪽 경계 혹은 위쪽 경계</strong>에서 격자와 평행한 방향으로만 발사할 수 있다.</p>

<p>발사한 호반우빔은 <strong>격자를 순서대로 관통</strong>해서 반대쪽 경계까지 도달한다.</p>

<p>따라서, <strong>왼쪽에서 오른쪽으로 가는 호반우빔</strong>을 발사하거나 <strong>위쪽에서 아래쪽으로 가는 호반우빔</strong>을 발사할 수 있는 것이다.</p>

<p>호반우는 죽이기만 하면 재미없으니까 죽일 때 마다 점수를 계산하는데 호반우 도축자를 죽이면 1명당 <em>a</em>점, 호반우 감금자를 죽이면 1명당 <em>b</em>점을 얻게 되고 호반우 우권 침해자를 죽이면 앞으로 얻을 점수가 <em>c</em>배가 된다.</p>

<p>호반우는 최대한 많은 점수를 얻고 싶었지만 안타깝게도 호반우는 사칙 연산을 할 줄 모른다.</p>

<p>호반우를 위해 호반우가 얻을 수 있는 최소 점수와 최대 점수를 알려주자!</p>

### 입력 

 <p>첫 번째 줄에 <em>N, M, a, b, c </em>(1 ≤ <em>N</em>, <em>M</em> ≤ 10, -100 ≤ <em>a, b</em> ≤ 100, -2 ≤ <em>c</em> ≤ 2) 가 공백으로 구분되어 주어진다. </p>

<p>2번째 줄부터 <em>N</em>+1번째 줄 까지는 격자의 정보가 공백으로 구분되어 주어진다.</p>

<p>각 칸별로</p>

<p>0인 경우 사람이 존재하지 않는 감옥</p>

<p>1인 경우 호반우 도축을 저지른 사람</p>

<p>2인 경우 호반우 감금을 저지른 사람</p>

<p>3인 경우 호반우 우권 침해를 저지른 사람이다.</p>

<p>호반우 우권 침해자는 항상 20명 이하이다.</p>

### 출력 

 <p>문제에서 설명한 최솟값과 최댓값을 공백으로 구분하여 순서대로 출력한다.</p>

