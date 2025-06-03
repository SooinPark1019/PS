# [Platinum V] Asking for Money - 28040 

[문제 링크](https://www.acmicpc.net/problem/28040) 

### 성능 요약

메모리: 10096 KB, 시간: 52 ms

### 분류

그래프 이론, 그래프 탐색

### 제출 일자

2025년 6월 3일 17:51:53

### 문제 설명

<p>The International Commission for the Prevention of Cons is studying the possible effects of a pyramid scheme in a town. The scheme is as follows: someone asks a person for \$$1$ and tells them to ask two other people for \$$1$ each and to tell each of them to ask for money from two others just as they are doing. In this way, the victim thinks that they are going to earn \$$1$. As there is a finite number of people in the world, not everyone can earn money this way, this is a con.</p>

<p>The $N$ people in town are susceptible to the con, that is, they are willing to give \$$1$ and later ask for money from two other people. However, they are willing to participate only once, that is, if they are asked for money again they will not give it or ask anyone. Once a person is asked for money, they give it immediately but can take some time before asking the other two people. The con starts with someone from outside the town asking someone in the town for money. This triggers a sequence of requests for money within the town.</p>

<p>For example, in the picture below we depict a town with five people. An arrow from $A$ to $B$ indicates that $A$ would ask $B$ for the money.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 160px; height: 155px;"></p>

<p>In this example, $B$ can lose money. We can check that with the following scenario.</p>

<ol>
	<li>Someone from outside the town asks $A$ for money.</li>
	<li>$A$ asks $B$ for money.</li>
	<li>$A$ asks $C$ for money.</li>
	<li>$C$ asks $D$ for money.</li>
	<li>$B$ asks $C$ for money.</li>
	<li>$B$ asks $D$ for money.</li>
</ol>

<p>Observe that when $B$ asks $C$ and $D$ for money, they will not give it to $B$ since they have already given money to someone else.</p>

<p>For each person in the town you know whom they are going to ask for money. Your task is to determine who in the town can lose money.</p>

### 입력 

 <p>The first line contains an integer $N$ ($3 ≤ N ≤ 1000$) indicating the number of people in the town. Each person is identified by a distinct integer from $1$ to $N$. For $i = 1, 2, \dots , N$, the $i$-th of the next $N$ lines contains two integers $X_i$ and $Y_i$ ($1 ≤ X_i , Y_i ≤ N$, $X_i , Y_i \ne i$ and $X_i \ne Y_i$), representing that person $i$ would ask for money to person $X_i$ and person $Y_i$.</p>

### 출력 

 <p>Output a single line with a string of length $N$ such that its $i$-th character is the uppercase letter “<code>Y</code>” if person $i$ can lose money, and the uppercase letter “<code>N</code>” otherwise.</p>

