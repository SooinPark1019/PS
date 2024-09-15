# [Platinum III] Popping Balloons - 16578 

[문제 링크](https://www.acmicpc.net/problem/16578) 

### 성능 요약

메모리: 8844 KB, 시간: 28 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 9월 15일 18:01:21

### 문제 설명

<p>Ayu is participating in ABC 2018 (Arranging Blocks Competition). In this competition, each contestant is given M minutes and N tasks which should be solved one-by-one in the given order. The contestant who solves the most tasks is the winner. What makes this contest interesting to you (ICPC contestants) is that this contest uses a similar encouragement as ICPC, i.e. balloons. In particular, each time a contestant solves a task, s/he will be given a balloon.</p>

<p>Ayu is convinced that she can defeat all other contestants, except one particular contestant, Budi, her rival. Ayu knows well her skill, i.e. she knows exactly how long it takes for her to solve a particular task. Unsurprisingly, Ayu also knows well Budi’s skill (they are rival for a reason). Let there be two arrays of integers A<sub>1..N</sub> and B<sub>1..N</sub>. A<sub>i</sub> denotes the time (in minutes) needed by Ayu to solve the i<sup>th</sup> task, while B<sub>i</sub> denotes the time (in minutes) needed by Budi to solve the same i<sup>th</sup> task.</p>

<p>Here comes the interesting part. Ayu knows that Budi is very sensitive to any disturbingly loud sound like a balloon being popped. Whenever Budi is surprised (due to a balloon being popped), he will lose his concentration and has to repeat the task he’s doing. For example, suppose Budi needs 10 minutes to solve a particular task. If a balloon pops at the 7<sup>th</sup> minute, then Budi repeats the task at the 7<sup>th</sup> minute (out of his 10 minutes), causing him to solve the task with 7 + 10 = 17 minutes. If two balloon pops, each at the 7<sup>th</sup> and 13<sup>th</sup> minute, then Budi repeats the task at minute 7<sup>th</sup> (out of his 10 minutes), repeats it again at minute 6<sup>th</sup>(out of his 10 minutes), and finally solved the task with 7+ 6+ 10 = 23 minutes. If a balloon pops at the same time Budi supposed to solve the task (i.e. at the 10<sup>th</sup> minute in this example), then Budi will also not solve that task. Therefore, Budi has to spend another 10 minutes (for a total of 10 + 10 = 20 minutes) to solve that particular task in this case.</p>

<p>Ayu plans to exploit Budi’s weakness in order to defeat him, i.e. Ayu will strategically use the balloons (popping them at integer minutes) she gets from solving the tasks. Your task in this problem is to find out whether it is possible for Ayu to have the number of solved tasks to be strictly larger than Budi’s. If it is possible, you should output one (any) working plan on when she should pop the balloons.</p>

<p>Note that if Ayu solves a task at exactly the M<sup>th</sup> minute, then the task is considered as solved. Similarly, if Budi solves a task at exactly the M<sup>th</sup> minute, then the task is considered as solved, except if Ayu decides to pop a balloon at the same time. Also, Ayu can pop a balloon as soon as she receives it. Ayu cannot pop more than one balloon at the same minute. She also cannot pop any balloon after the M<sup>th</sup> minute mark.</p>

### 입력 

 <p>Input begins with a line containing two integers: N M (1 ≤ N ≤ 100000; 1 ≤ M ≤ 10<sup>9</sup>) representing the number of tasks and duration of the competition, respectively. The second line contains N integers A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ 10<sup>9</sup>) representing the time needed by Ayu to solve the i<sup>th</sup> task. The third line contains N integers B<sub>i</sub> (1 ≤ B<sub>i</sub> ≤ 10<sup>9</sup>) representing the time needed by Budi to solve the i<sup>th</sup> task.</p>

### 출력 

 <p>If it is not possible for Ayu to win the competition by having strictly larger number of solved tasks than Budi, simply output −1 in a line. Otherwise, output begins with an integer K in a line representing the number of balloons Ayu needs to pop. The next line contains K integers (each separated by a single space), sorted by increasing order, representing the minute in which Ayu should pop a balloon. You may output any configuration as long as it’s valid, i.e. Ayu has at least one balloon when she pops a balloon, Ayu is not popping a balloon after the contest is over, Ayu is not popping more than one balloon at the same minute, and the configuration causes Ayu to have a larger number of solved tasks than Budi.</p>

