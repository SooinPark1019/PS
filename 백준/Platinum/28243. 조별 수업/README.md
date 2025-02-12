# [Platinum III] 조별 수업 - 28243 

[문제 링크](https://www.acmicpc.net/problem/28243) 

### 성능 요약

메모리: 436032 KB, 시간: 188 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 제출 일자

2025년 2월 13일 07:24:52

### 문제 설명

<p>송도고등학교의 박상진 선생님은 조별 수업에서 버스를 타는 학생은 없고 모두가 협력할 수 있는 획기적인 방법을 고안해내셨다!</p>

<p style="text-align: center;"><img alt="" height="284" src="https://upload.acmicpc.net/5f502241-d02b-44a5-ad77-350b6ddfcb08/-/preview/" width="386"></p>

<p style="text-align: center;">박상진 선생님의 획기적인 방법을 사용하지 않은 보통의 조별 수업 상황이다.</p>

<p>그 방법은 바로 조를 특별한 방식으로 짜는 것이다.</p>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>번부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>번까지의 번호가 배정된 학생들 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>명이 임의의 순서로 일렬로 서 있을 때, 이를 연속한 구간 여러 개로 나누어 조를 짠다. 이때 모든 구간에 대해 각 구간의 길이가 구간에 속한 학생들의 번호 중 최솟값과 같아야 올바른 조 짜기 방법이 된다.</p>

<p>박상진 선생님은 학생들이 일렬로 서 있을 수 있는 모든 경우에 대한 올바른 조 짜기 방법의 수의 합을 알고 싶다. 선생님을 도와 이를 구하는 프로그램을 작성하여라.</p>

<p>단, 답이 너무 커질 수 있으니 답을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9+7$</span></mjx-container>로 나눈 나머지를 출력한다.</p>

### 입력 

 <p>첫 번째 줄에 학생 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>이 주어진다.</p>

### 출력 

 <p>학생들이 일렬로 서 있을 수 있는 모든 경우에 대한 올바른 조 짜기 방법의 수의 합을 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>10</mn><mn>9</mn></msup><mo>+</mo><mn>7</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10^9+7$</span></mjx-container>로 나눈 나머지를 출력하여라.</p>

