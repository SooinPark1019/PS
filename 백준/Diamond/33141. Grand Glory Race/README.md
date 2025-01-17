# [Diamond V] Grand Glory Race - 33141 

[문제 링크](https://www.acmicpc.net/problem/33141) 

### 성능 요약

메모리: 40540 KB, 시간: 164 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2025년 1월 17일 14:51:28

### 문제 설명

<p>The Kingdom of Arboria has developed a vast network of $N$ villages numbered from $1$ to $N$. These villages are interconnected by $N - 1$ two-way roads, forming an unrooted tree.</p>

<p>These days, the kingdom’s streets are buzzing with excitement over the upcoming Grand Glory Race. This prestigious race has been losing popularity in recent years. Over time, all the runners became so well-prepared that now they all run at the same speed. Because all runners move at the same pace, the order in which they reach each village is determined purely by the starting point, as each runner always takes a shortest path toward the finish line. Thus, it became easy to predict who would win the race, taking away much of the interest.</p>

<p>But this year, the race organizers have introduced some intriguing new rules to make the competition more engaging:</p>

<ul>
	<li><strong>The Crown Village is Still a Mystery</strong>: The race will conclude at the <em>Crown Village</em>, but no one knows yet which village it will be. The suspense is building with speculations, keeping everyone guessing and adding excitement to the event.</li>
	<li><strong>The Racers</strong>: Each <em>leaf village</em> (a village with only one connecting road) will send one runner to participate. These runners will start from their respective leaf villages and race toward the Crown Village along a shortest path. Once a runner reaches the Crown Village, the race ends for them, but other runners continue their journey toward the Crown Village until they arrive.</li>
	<li><strong>Claiming Villages</strong>: To make the race more appealing for every village, the first runner to reach a village claims it. If multiple runners arrive at a village at the same time, the runner starting from the leaf village with the smaller identifier claims the village. This way, even if a runner doesn’t reach the Crown Village first, they can still claim more villages along the way, keeping the race competitive and unpredictable.</li>
</ul>

<p>With these new rules in place, bookmakers across the kingdom are analyzing the odds for different runners. While the order in which the runners reach the Crown Village is easy to determine, what really interests the bookmakers is how many villages each runner can claim during their journey.</p>

<p>To assist the King’s bookmaker, you are tasked with answering queries about various race scenarios. For each query, you’ll be given two numbers: the identifiers of a leaf village $S$ and a village $T$, hypothetically chosen as the Crown Village. Based on this, you need to determine how many villages will be claimed by a runner starting at $S$ if the race ends at $T$.</p>

### 입력 

 <p>The first line contains an integer $N$ ($2 ≤ N ≤ 10^5$) indicating the number of villages in the kingdom. Each village is identified by a distinct integer from $1$ to $N$.</p>

<p>Each of the next $N - 1$ lines contains three integers $U$, $V$ and $L$ ($1 ≤ U, V ≤ N$, $U \ne V$ and $1 ≤ L ≤ 10^4$), representing that there is a two-way road connecting villages $U$ and $V$, with length $L$.</p>

<p>The next line contains an integer $Q$ ($1 ≤ Q ≤ 10^5$) denoting the number of queries.</p>

<p>Each of the next $Q$ lines describes a query with two integers $S$ and $T$ ($1 ≤ S, T ≤ N$), indicating respectively the leaf village where a specific runners starts, and the hypothetical Crown Village (the finish line for this particular query).</p>

<p>It is guaranteed that the villages and roads form a tree, and that $S$ is a leaf in the tree for each query.</p>

### 출력 

 <p>For each query in the input, output a line with an integer representing the number of villages that will be claimed by the runner if the specified Crown Village is chosen as the finish line. Output the results in the same order that the corresponding queries appear in the input.</p>

