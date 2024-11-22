# [Platinum II] Two Choreographies - 26113 

[문제 링크](https://www.acmicpc.net/problem/26113) 

### 성능 요약

메모리: 35328 KB, 시간: 144 ms

### 분류

해 구성하기, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 최소 공통 조상, 비둘기집 원리, 트리

### 제출 일자

2024년 11월 22일 12:44:26

### 문제 설명

<p>Somin and Eunjoo are famous dancers and very talented choreographers, but they haven't won a contest recently. To win the contest this year, they are trying to help each other to make new choreographies. Actually, nobody has tried smoothly appending static motions, and they are going to give it a try for the first time!</p>

<p>Somin and Eunjoo want to make two choreographies consisting of $n$ static motions for each of them. They have a good understanding of how to smoothly append static motions, and they concluded that exactly $2n - 3$ unordered pairs of static motions are enough for them to perform freely. The order of static motions in a pair $\{A, B\}$ does not matter, i.e., if motion $B$ can be appended after motion $A$, then $A$ can also be appended after $B$.</p>

<p>The choreographies which Somin and Eunjoo want to perform are as follows. The two choreographies last for the same amount of time, which means that each one should consist of the same number of static motions. Each choreography should end at its first static motion. More precisely, two choreographies $C_1$ and $C_2$ are sequences of distinct $l$ static motions, $C_1 = (a_0, a_1, \dots , a_l)$ and $C_2 = (b_0, b_1, \dots , b_l)$ where $a_0 = a_l$ and $b_0 = b_l$. For the entertainment of the audience, $C_1$ and $C_2$ should be different, that is, there should be some $0 ≤ i ≤ l - 1$ which $\{a_i, a_{i+1}\}$ in $C_1$ is not equal to any of $\{b_j, b_{j+1}\}$ in $C_2$ for $0 ≤ j ≤ l - 1$. (For example, $(1,2,3,4,5,1)$ and $(3,4,5,2,1,3)$ are different but $(1,2,3,4,5,1)$ and $(3,4,5,1,2,3)$ are not.) Also, the audience easily gets bored, so the choreography should not be too short, and contain at least $3$ distinct static motions, that is, $l ≥ 3$.</p>

<p>For this, you are given $2n - 3$ unordered pairs $P$ of static motions from $n$ distinct static motions $m_1, \dots, m_n$ that two dancers can perform. For a pair $\{m_i, m_j\}$ where $i ≠ j$, one of $m_i$ and $m_j$ can appear after the other in the sequence; there is no specific order between them. You should write a program to find two different choreographies $C_1 = (a_0, a_1, \dots , a_l)$ and $C_2 = (b_0, b_1, \dots , b_l)$ of the same length $l ≥ 3$ such that $\{a_i, a_{i+1}\} ∈ P$, $\{b_i, b_{i+1}\} ∈ P$ for any $0 ≤ i ≤ l - 1$, and $a_0 = a_l$ and $b_0 = b_l$.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing a single integer, $n$ ($4 ≤ n ≤ 100\,000$), where $n$ is the number of static motions two dancers can represent. Each static motion is numbered as an integer from $1$ to $n$. The following $2n - 3$ lines represent $2n - 3$ unordered pairs of stack motions, $P$. Each line contains two distinct integers representing two static motions of a pair of $P$. Note that no two pairs in $P$ are identical.</p>

### 출력 

 <p>Your program is to write to standard output. If you cannot find two choreographies of static motions, then print $-1$. If not, you should print exactly three lines. The first line contains an integer $l ≥ 3$ which is the number of distinct static motions in each choreography. The second line contains exactly $l$ integers, separated by a space, each representing a choreography of the $l$ static motions in order. The last repeated motion should be omitted. The third line contains exactly $l$ integers representing the other choreography</p>

