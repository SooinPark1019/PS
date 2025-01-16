# [Platinum II] Connect Five - 32891 

[문제 링크](https://www.acmicpc.net/problem/32891) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹, 기하학

### 제출 일자

2025년 1월 17일 05:21:09

### 문제 설명

<p>In the town of Nattanham, all roads run either north to south, or east to west, and span the entire town. Furthermore, all roads are an equal distance apart. This makes navigating the town extremely easy.</p>

<p>Unfortunately, the roads are quite poor and could do with a fresh layer of asphalt. However, there is not enough money to fix all the roads, so some sections of road need to be given priority.</p>

<p>The mayor has selected five locations in town that he considers to be of great importance: the city hall, the police station, the hospital, the fire department, and of course the mayor's house. Each of these locations is at an intersection.</p>

<p>The mayor wishes that, for each pair of these important locations, it becomes possible to get from one to the other along a shortest path that consists entirely of refurbished road. Within this restriction, the mayor would like to refurbish the smallest amount of road. The intersections do not count toward this amount. Figure C.1 depicts an optimal configuration of refurbished roads.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1dd922dc-e07c-4cd8-9f8c-e5ba784ff960/-/preview/" style="width: 550px; height: 400px;"></p>

<p style="text-align: center;">Figure C.1: Illustration of Sample Input 1, with the locations labelled by their initial letters, and a possible way of refurbishing the minimum number of road segments (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>22</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$22$</span></mjx-container>). The point <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn><mo>,</mo><mn>0</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(0,0)$</span></mjx-container> is located at the bottom-left corner of the grid.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>Five lines, each with two integers <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container> and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>x</mi><mo>,</mo><mi>y</mi><mo>≤</mo><mn>1000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0 \le x, y \le 1000$</span></mjx-container>), the grid coordinates of each of the five important locations.</li>
</ul>

<p>It is guaranteed that the locations are distinct.</p>

### 출력 

 <p>Output the minimum number of road segments that need to be refurbished.</p>

