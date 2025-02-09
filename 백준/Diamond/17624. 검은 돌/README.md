# [Diamond IV] 검은 돌 - 17624 

[문제 링크](https://www.acmicpc.net/problem/17624) 

### 성능 요약

메모리: 2784 KB, 시간: 156 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2025년 2월 8일 08:53:43

### 문제 설명

<p>정점들의 집합 V(≠ ∅)와 간선들의 집합 E를 가진 그래프 T = (V, E)가 트리라 함은 T의 임의의 두 정점 u와 v사이에 항상 경로가 존재하고 그 경로는 하나뿐인 경우이다.</p>

<p>트리 T = (V, E)안의 서브트리 S = (<span style="text-decoration:overline;">V</span>, <span style="text-decoration:overline;">E</span>)란, <span style="text-decoration:overline;">V</span> ⊆ V, <span style="text-decoration:overline;">E</span> ⊆ E 이면서 위의 트리의 성질을 만족하는 그 자체로 트리인 그래프이다.</p>

<p>그런데 트리 T의 어떤 정점들에는 검은 돌이 놓여있다. 검은 돌은 한 정점에 많아야 하나씩만 놓일 수 있다.</p>

<p>우리는 다음과 같은 질의 q = (i, j)를 던질 것이고 여러분들은 이 질의에 답해야한다:</p>

<ul>
	<li>트리 T 안에 정확히 i개의 정점을 가지고 이중에 j개의 정점에 검은 돌이 놓여 있는 서브트리 S가 존재하는가?</li>
</ul>

<p>예를 들어서, 아래 <그림 1>에서 9개 정점을 가진 트리가 주어진다. 여기서 질의 q = (5, 3)에 대해서 위의 조건을 만족하는 정점 1, 2, 3, 4, 6으로 이루어진 서브트리가 존재한다. 하지만 질의 q<sub>2</sub> = (4, 3)에 대해서는 조건을 만족하는 서브트리는 존재하지 않는다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3f7be6eb-5029-4b54-99cb-49b5989f1438/-/preview/" style="width: 234px; height: 145px;"></p>

<p style="text-align: center;"><그림 1></p>

<p>N개의 정점을 가진 트리와 Q개의 질의 q가 주어질 때, 각각의 질의에 대한 답 중에서 ‘존재한다’는 답의 총 개수를 출력하시오.</p>

### 입력 

 <p>입력의 첫 줄에는 트리 T의 정점의 개수를 나타내는 정수 N(1 ≤ N ≤ 5,000)과 정점들에 놓여있는 검은 돌의 개수 B(0 ≤ B ≤ N)가 주어진다. 여기서, 트리 T의 정점은 1부터 N까지 정수로 나타낸다. 두 번째 줄에는 검은 돌이 놓여 있는 정점을 나타내는 B개의 정수 x(1 ≤ x ≤ N)가 주어진다. 이어지는 N-1개 줄 각각에 T에서 간선이 존재하는 두 정점을 나타내는 정수 u, v(1 ≤ u, v ≤ N)가 주어진다. 다음 줄에는 질의의 개수 Q(1 ≤ Q ≤ 1,000,000)가 주어지고, 이어지는 Q개의 줄 각각에 하나의 질의 q = (i, j)를 나타내는 두 정수 i, j(1 ≤ i ≤ N, 0 ≤ j ≤ min(i, B))가 주어진다.</p>

### 출력 

 <p>각각의 질의에 대한 답 중에서 ‘존재한다’는 답의 총 개수를 출력한다.</p>

