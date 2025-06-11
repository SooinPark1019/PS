# [Platinum II] 철도 - 22029 

[문제 링크](https://www.acmicpc.net/problem/22029) 

### 성능 요약

메모리: 13952 KB, 시간: 88 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 해 구성하기, 너비 우선 탐색, 깊이 우선 탐색

### 제출 일자

2025년 6월 11일 17:26:58

### 문제 설명

<p>사이가 나쁜 A, B 두 나라가 있다. A나라는 B나라를 침략하기 위해 B나라의 철도망을 알아내려 한다. B나라에 여러 차례 스파이를 보냈지만 항상 의미있는 정보를 캐기 전 잡혔기 때문에, A나라가 알고 있는 정보는 다음이 전부이다. </p>

<ul>
	<li>B나라의 철도망은 모두 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 역으로 이루어져 있고, 각 역은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>까지 번호가 붙어 있다.</li>
	<li>서로 다른 어떤 두 역을 고르더라도 직접 철로로 이어져 있거나, 철로로 이어진 다른 역(들)을 통해서 이어져 있다. </li>
	<li>어떤 두 역을 고르더라도 이 둘을 연결하는 경로는 정확히 하나이다.</li>
	<li>자신과 자신을 철로로 직접 이은 경우는 없다. </li>
</ul>

<p>스파이를 보내는 것은 한계가 있음을 깨닫고, A나라는 B나라 철도회사 고위 간부를 매수하여 철도망을 그린 그림을 얻어내려고 한다. 이 그림을 직접 보내면 배신자가 누구인지 알려질 것이므로, 배신자는 다음과 같이 그림을 고쳐서 A나라에 보낼 것이다.</p>

<ul>
	<li>철도망을 그린 그림 위에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>개의 가짜 철로를 그린다. 즉, 그림에서 철로로 직접 연결되지 않은 서로 다른 두 역 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$a$</span></mjx-container>와 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>b</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$b$</span></mjx-container>를 골라서, 이 둘을 가짜 철로로 직접 잇는다. 이를 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>번 반복한다.</li>
	<li>하나의 역에 <strong>특별한 표시</strong>를 한다.</li>
	<li>마지막으로, 역들의 번호를 모두 지운다. </li>
</ul>

<p>배신자는 최종적으로 얻은 그림을 A나라에 전송한다. 이 정보만으로는 B나라의 철도망을 그린 그림이라는 것을 알기 어렵기 때문에, 비밀 정보가 유출되었다는 사실을 아무도 모를 것이다.   </p>

<p>이 계획이 성공하기 위해서는 다음과 같은 문제가 해결되어야 한다. </p>

<ul>
	<li>A나라가 받은 그림에는 역들의 번호가 지워져 있고, 또한 어느 철로가 진짜이고 가짜인지 표시되어 있지 않다. 알 수 있는 것은 어느 역에 <strong>특별한 표시</strong>가 되어 있는지, 그리고 가짜 철로를 총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>K</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$K$</span></mjx-container>군데 놓았다는 사실뿐이다.  </li>
	<li>따라서, 보내는 쪽에서는 받는 쪽이 그림만 보고 어느 철로가 진짜이고 어느 철로가 가짜인지 알 수 있도록 적절한 위치에 가짜 철로를 놓고, 적절한 역에 <strong>특별한 표시</strong>를 해야 한다.</li>
	<li>또한 받는 쪽에서는 보내는 쪽이 그림을 고친 방법을 이해하고, 받은 그림에서 원래 철도망을 그린 그림을 </li>
	<li>구해야 한다.</li>
</ul>

<p>위에서 설명한 것처럼, 철도망을 그린 그림을 고치는 함수와, 이 그림으로부터 진짜 철도망을 구하는 함수 둘이 필요하다. A나라는 여러분에게 이 일을 맡기려고 한다.</p>

### 입력 

 Empty

### 출력 

 Empty

