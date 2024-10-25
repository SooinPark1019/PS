# [Gold II] Dividing DNA - 25995 

[문제 링크](https://www.acmicpc.net/problem/25995) 

### 성능 요약

메모리: 13808 KB, 시간: 496 ms

### 분류

그리디 알고리즘, 두 포인터

### 제출 일자

2024년 10월 25일 19:32:59

### 문제 설명

<p>At the Bacteria And Protein Centre, you own a large collection of DNA. In fact, new strands of DNA come in all the time. To organise the vast amount of data, you identify each piece by its unique substrings: substrings that do not already occur in the database.</p>

<p>Your database can quickly determine whether a given piece of DNA occurs as a substring in the database or not. Naturally, if a certain DNA string is found in the database, it also contains all its substrings.</p>

<p>You now want to determine the <em>uniqueness</em> of a given piece of DNA: the maximal number of disjoint substrings it contains that are absent from the database.</p>

<p>You are given the length <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> of the query string <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.014em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2026"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.014em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>q</mi><mn>1</mn></msub><mo>…</mo><msub><mi>q</mi><mi>n</mi></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$q_1\dots q_n$</span></mjx-container>, and you can repeatedly ask the database whether it contains the substring <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msub><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.014em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D456 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msub><mjx-mo class="mjx-n" space="2"><mjx-c class="mjx-c2026"></mjx-c></mjx-mo><mjx-msub space="2"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: -0.15em; margin-left: -0.014em;"><mjx-texatom size="s" texclass="ORD"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D457 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msub></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>q</mi><mi>i</mi></msub><mo>…</mo><msub><mi>q</mi><mrow data-mjx-texclass="ORD"><mi>j</mi><mo>−</mo><mn>1</mn></mrow></msub></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$q_i\dots q_{j-1}$</span></mjx-container>.</p>

<p>As an example, consider the first sample interaction. In this case, the database contains strings "<code>TGC</code>" and "<code>CT</code>", and the query string is "<code>CTGCAA</code>". It has uniqueness <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3$</span></mjx-container>, because it can be split into the new substrings "<code>CTGC</code>", "<code>A</code>", and "<code>A</code>". The new substring "<code>CTGC</code>" cannot be split up further: for example, the subdivision "<code>CT</code>" and "<code>GC</code>" is not allowed, because both substrings occur (possibly as substrings) in the database. Note that the actual characters in the string are not used in the interaction.</p>

<p>You may use at most <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2n$</span></mjx-container> queries to the database.</p>

### 입력 

 Empty

### 출력 

 Empty

