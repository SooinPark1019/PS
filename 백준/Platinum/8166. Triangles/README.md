# [Platinum IV] Triangles - 8166 

[문제 링크](https://www.acmicpc.net/problem/8166) 

### 성능 요약

메모리: 2336 KB, 시간: 340 ms

### 분류

기하학, 수학, 누적 합, 정렬

### 제출 일자

2025년 1월 13일 04:04:53

### 문제 설명

<p>n pairwise disjoint points in the plane are given (n ≥ 3). There are <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mfrac><mjx-frac><mjx-num><mjx-nstrut></mjx-nstrut><mjx-mrow size="s"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-mrow></mjx-num><mjx-dbox><mjx-dtable><mjx-line></mjx-line><mjx-row><mjx-den><mjx-dstrut></mjx-dstrut><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-den></mjx-row></mjx-dtable></mjx-dbox></mjx-frac></mjx-mfrac></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mfrac><mrow><mi>n</mi><mo>⋅</mo><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>1</mn><mo stretchy="false">)</mo><mo>⋅</mo><mo stretchy="false">(</mo><mi>n</mi><mo>−</mo><mn>2</mn><mo stretchy="false">)</mo></mrow><mn>6</mn></mfrac></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\( \frac {n⋅(n-1)⋅(n-2)}{6} \)</span></mjx-container> triangles whose vertices are some pairwise different points among them (including degenerate triangles, i.e. ones whose vertices are collinear).</p>

<p>We want to calculate the sum of areas of all the triangles with vertices in the given points.</p>

<p>Those parts of the plane that belong to many triangles are to be calculated multiple times. We assume that the area of degenerate triangles (i.e. those with collinear vertices) is zero.</p>

<p>Write a programme that:</p>

<ul>
	<li>reads from the standard input the coordinates of the points in the plane,</li>
	<li>determines the sum of the areas of all the triangles with vertices in the given points,</li>
	<li>prints out the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is one integer n (3 ≤ n ≤ 3,000) denoting the number of selected points. Each of the following  lines contains two integers x<sub>i</sub> and y<sub>i</sub> (0 ≤ x<sub>i</sub>,y<sub>i</sub> ≤ 10,000) separated by a single space and denoting the coordinates of the ith point (for i=1,2,…,n). No pair (ordered) of coordinates appears more than once.</p>

### 출력 

 <p>In the first and only line of the standard output there should be one real number equal to the sum of the areas of all the triangles with vertices in the given points. The outcome should be printed out with exactly one digit after dot and should not differ from the correct value by more than 0.1.</p>

