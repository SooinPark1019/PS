# [Platinum II] Saba1000kg - 18180 

[문제 링크](https://www.acmicpc.net/problem/18180) 

### 성능 요약

메모리: 21868 KB, 시간: 1908 ms

### 분류

자료 구조, 분리 집합, 제곱근 분할법

### 제출 일자

2024년 10월 9일 21:20:40

### 문제 설명

<p>There are many different streams in Viking rock movement. Old Icelandic granite rock, Middle Danish dusty Viking rock, Late Finngail dark green rock, Fjord boulder avalanche rock, and many others, a complete list of all popular streams would overflow this page many times. The Scandinavian Ministry of Higher Education studies various ways the streams influence each other. They are currently planning a huge experiment, when a number of suitably chosen volunteers will be distributed over an archipelago of uninhabited small islands, and the researchers want to observe the mutual influence of their rock styles and preferences over a relatively long period of time.</p>

<p>The inhabitants on one island will always influence each other. Some pairs of the islands are situated close enough for their inhabitants to influence each other, while the distances between other pairs prevent any direct influence. In the latter case, the inhabitants of such islands may still influence each other, but only indirectly, if there are one or more other islands that are inhabited and relay the influence.</p>

<p>There are several proposals on the distribution of the volunteers among the islands. For each of these distributions, the Ministry would like to know the number of independent groups of inhabitants that will form in the archipelago. Two groups of island inhabitants, each occupying one or more islands, are considered independent, if there is no possibility of their mutual influence, not even in the indirect way.</p>

<p>Help the Ministry to evaluate their proposals.</p>

### 입력 

 <p>The first input line contains three integers, N, E, P (1 ≤ N ≤ 10<sup>5</sup>, 0 ≤ E ≤ 10<sup>5</sup>, 1 ≤ P ≤ 10<sup>5</sup>). N is the number of islands in the archipelago, E is the number of pairs of islands that allow direct influence, and P is the number of proposals to be evaluated. The islands are labeled from 1 to N.</p>

<p>The next E lines specify the pairs of islands that allow direct mutual influence. Each of these lines contains two integers A and B denoting the labels of two different islands. No pair of islands occurs more than once.</p>

<p>Each of the next P lines describes one proposal. Each line starts with a number of islands inhabited under that proposal M (1 ≤ M ≤ N) and then contains pairwise distinct labels of M inhabited islands. No other island will be inhabited under the respective proposal.</p>

<p>The sum of the sizes of all proposals (all numbers M) does not exceed 10<sup>5</sup>.</p>

### 출력 

 <p>For each proposal, print a line with the number of independent groups that will form in the archipelago.</p>

