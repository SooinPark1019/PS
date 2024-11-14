# [Diamond V] Levelling Locks - 32606 

[문제 링크](https://www.acmicpc.net/problem/32606) 

### 성능 요약

메모리: 8296 KB, 시간: 44 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 11월 15일 02:02:25

### 문제 설명

<p>Oh, snap! A recent power outage not only left Groningen in darkness, but even worse, it caused a complete system failure of the city's historic and obsolete lock system, closing off the waterways. The lock consists of a series of identical chambers, with a gate between each pair of adjacent chambers that can be opened or closed. The system failure, however, caused all the gates to remain closed, blocking the water flow between the chambers. Normally, this would not bother you, but you are eagerly awaiting a shipment of your favourite snack: eierballen.</p>

<p>Fortunately, Lotte, a professional scuba diver, is up to the task of repairing the old lock. She devised a plan that is as simple as it is daring:</p>

<p>Lotte is currently aboard a helicopter en route to the lock. Upon arrival, she will dive into the cold water of a chamber of her choosing and start opening gates manually. By swimming in the already connected chambers, she can open the next closed gate to either her left or her right, forcing the water levels to equalize between the connected chambers.</p>

<p>However, swimming in deep waters is dangerous and should be avoided where possible. The danger of her mission can be quantified by the maximum depth she must swim to open all gates. Clearly, Lotte cannot avoid swimming in the water depth that eventually arises when all chambers are connected. But can she avoid swimming in any deeper water?</p>

<p>As an example, consider the first sample case, visualized in Figure L.1. When connecting chambers in the order given by the sample answer, Lotte will never swim in any water that is deeper than the final water level.</p>

<p>Help Lotte determine the order in which to connect the chambers to open all gates without exceeding the final water depth, or determine that it is impossible.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c1f6b97d-0f20-4038-95a8-0a2adf73ac31/-/preview/" style="width: 512px; height: 263px;"></p>

<p style="text-align: center;">Figure L.1: Visualization of the first sample case. The horizontal dashed line indicates the final water level. Lotte can connect all chambers without swimming in any water that is deeper than this level.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-msup space="3"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><mn>2</mn><mo>⋅</mo><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le n \le 2\cdot 10^5$</span></mjx-container>), the number of chambers.</li>
	<li>One line with <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> integers <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$a$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>a</mi><mo>≤</mo><msup><mn>10</mn><mn>8</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le a \le 10^8$</span></mjx-container>), the water level in each chamber.</li>
</ul>

<p>The space occupied by the gates is negligibly small.</p>

### 출력 

 <p>If it is possible to open all gates without exceeding the final water depth, output the order in which Lotte first enters, thus connects, each of the <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> chambers. Otherwise, output "<code>impossible</code>".</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

