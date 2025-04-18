# [Platinum IV] 걷는 산타클로스 - 5552 

[문제 링크](https://www.acmicpc.net/problem/5552) 

### 성능 요약

메모리: 8300 KB, 시간: 68 ms

### 분류

수학, 정렬

### 제출 일자

2025년 3월 16일 13:14:53

### 문제 설명

<p>작년에 산타클로스는 노원구에 사는 아이들에게 크리스마스 선물을 전달해주는 것을 까먹었다. 큰 상처를 받은 아이들을 위해서 산타클로스는 아이들에게 초콜릿 케이크를 선물하기로 했다. 산타클로스는 다음 크리스마스 선물을 준비해야 하기 때문에, 이동 계획을 생각해야 한다.</p>

<p>노원구는 남북 방향으로 도로가 W개, 동서 방향으로 도로가 H개 있고, 도로는 바둑판 모양이다. 남북 방향 도로는 서쪽부터 1, 2, ..., W로, 동서 방향 도로는 남쪽부터 1, 2, ..., H로 번호가 매겨져 있다. 서쪽에서 x번째 남북 방향 도로와 남쪽에서 y번째 동서 방향 도로가 만나는 교차로는 (x,y)이다. 노원구에는 집이 N개가 있고, 모든 집은 교차로 위에 있다. 산타클로스는 도로만 이용할 수 있고, 인접한 교차로 사이를 이동하는데 걸리는 시간은 1이다.</p>

<p>모든 집에는 아이가 있다. 따라서, 산타클로스는 모든 집에 초콜릿 케이크를 선물해야 한다. 크리스마스가 아니기 때문에, 산타가 루돌프를 타고 집을 이동하는 것은 매우 위험하다. 따라서, 루돌프를 타고 한 교차로에 내린 뒤, 그 위치부터 걸어다니면서 케이크를 선물하기로 했다.</p>

<p>산타는 초콜릿 케이크를 하나만 들 수 있다. 따라서, 어떤 집에 케이크를 선물하면, 다시 루돌프가 있는 교차로로 돌아와야 한다.</p>

<p>산타는 모든 집에 케이크를 선물할 때 드는 시간을 최소로 하려면, 어디에서 내려야 하는지 궁금해졌다. 이때, 마지막 집에 케이크를 선물하고, 다시 루돌프에게 돌아오는 시간은 포함하지 않는다.</p>

<p>집의 위치 정보가 주어졌을 때, 어떤 교차로에 내려야 모든 집에 초콜릿 케이크를 선물하는데 드는 시간이 가장 작아지는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 각 방향 도로의 개수 W와 H가 주어진다. (1 ≤ W,H ≤ 10<sup>9</sup>)</p>

<p>둘째 줄에는 집의 개수 N이 주어진다. (1 ≤ N ≤ 10<sup>5</sup>)</p>

<p>셋째 줄부터 N개 줄에는 집의 위치가 주어진다. 한 교차로에 집이 두 개 이상 있는 경우는 없다.</p>

### 출력 

 <p>첫째 줄에 모든 집에 케이크를 배달하는데 드는 최소 시간을 출력하고, 둘째 줄에 내려야하는 교차로의 위치를 출력한다. 만약, 그러한 교차로가 여러개라면, 가장 서쪽에 있는 교차로를 출력한다. 또, 그러한 교차로가 여러개라면 가장 남쪽에 있는 교차로를 출력한다.</p>

