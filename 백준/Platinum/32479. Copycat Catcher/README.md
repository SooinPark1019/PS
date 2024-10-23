# [Platinum II] Copycat Catcher - 32479 

[문제 링크](https://www.acmicpc.net/problem/32479) 

### 성능 요약

메모리: 17908 KB, 시간: 184 ms

### 분류

브루트포스 알고리즘, 자료 구조, 해시를 사용한 집합과 맵, 문자열

### 제출 일자

2024년 10월 23일 17:08:55

### 문제 설명

<p>Your university recently established the Graduate Code Plagiarism Control (GCPC) initiative to get hold of the ever-increasing load on the graders for the computer science assignments. Currently, the graders need to check the code of assignments manually for plagiarism. The GCPC aims to simplify this part of the graders' jobs by performing the plagiarism checks automatically.</p>

<p>Code consists of tokens separated by spaces. Tokens are strings of alphabetical letters, numerals, and brackets. If a token consists of only a single alphabetical letter (upper or lowercase), it is a variable in the code.</p>

<p>The GCPC wants the plagiarism checker to compare query pieces of code to a reference code. Specifically, it should check whether each query could have been obtained by selecting a contiguous string of tokens from the reference and consistently renaming variables.</p>

<p>Variables are consistently renamed if no two occurrences of the same variable are renamed to different variables, and if no two different variables are renamed to the same variable.</p>

<p>The GCPC has asked you to develop the plagiarism checker.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>A description of the reference, consisting of:
	<ul>
		<li>One line containing an integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><mn>2</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\leq n \leq 2\,000$</span></mjx-container>), the number of tokens in the reference.</li>
		<li>One line containing <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> tokens, each consisting only of the characters '<code>a</code>'-'<code>z</code>', '<code>A</code>'-'<code>Z</code>', '<code>0</code>'-'<code>9</code>', '<code>(</code>' and '<code>)</code>'.</li>
	</ul>
	</li>
	<li>An integer <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>q</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$q$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>q</mi><mo>≤</mo><mn>2</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \leq q \leq 2\,000$</span></mjx-container>), the number of queries.</li>
	<li><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c22C5"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>⋅</mo><mi>q</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2\cdot q$</span></mjx-container> lines, each two lines in the same format as the reference.</li>
</ul>

<p>It is guaranteed that each query as well as the reference consist of at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2\,000$</span></mjx-container> characters (excluding spaces). Tokens are separated by single spaces.</p>

### 출력 

 <p>For each query, output "<code>yes</code>" if the query could have been obtained from the reference, and "<code>no</code>" otherwise.</p>

