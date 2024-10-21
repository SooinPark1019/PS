# [Platinum V] Even Odd Game - 32481 

[문제 링크](https://www.acmicpc.net/problem/32481) 

### 성능 요약

메모리: 13820 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2024년 10월 22일 02:01:21

### 문제 설명

<p>As every Saturday, Eve is paying her local game club a visit. Today, Bob has brought a new game he has designed on his own. After thorough investigation, you claim that there exists a dominant strategy, so one player can always win. Bob is hesitant to accept that his game is boring to play, so he challenges you to play a round! Since you claim that there exists a dominant strategy, you may determine who begins the game.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e261f5d1-3284-48c7-b4f7-f7032608bc56/-/preview/" style="width: 681px; height: 300px;"></p>

<p style="text-align: center;">Figure E.1: The cards in the two sample interactions.</p>

<p>The rules are as follows. There are <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> cards on the table, each containing a maths operation (<code>+</code> or <code>*</code>) and an integer, as shown in Figure E.1. Eve and Bob alternate picking cards to manipulate a common number using one of the cards. For instance, if the current value of the number is <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>5</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$5$</span></mjx-container>, and the card says <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>+</mo><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$+3$</span></mjx-container>, then the value gets updated to <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>8</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$8$</span></mjx-container>. Each card can only be used once, and the game ends when all the cards have been used. The player who makes the first move wins if the final number is odd, and the other player wins if the final number is even. Given the list of cards and the starting value, help Eve win the game.</p>

### 입력 

 Empty

### 출력 

 Empty

