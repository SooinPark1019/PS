# [Platinum IV] Human Resources - 30952 

[문제 링크](https://www.acmicpc.net/problem/30952) 

### 성능 요약

메모리: 4624 KB, 시간: 0 ms

### 분류

해 구성하기, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 2월 27일 05:50:49

### 문제 설명

<p>You work at ECorp and your Human Resources department is migrating employee data from an on-premise system provided by Hooli to a new Cloud Native solution provided by a fresh startup Pied Piper. Sadly the new system does not yet have feature parity with the old one and they need your help to store and display the entire management structure. The system is lean and conscious of resource usage so they can only afford to increase their storage by two kilobits.</p>

### 입력 

 <p>The first line of the input will be a command to execute either <code>ENCODE</code> or <code>DECODE</code>.</p>

<p><strong>Encode</strong></p>

<p>You will receive lines describing managers and their direct reports/subordinates. All lines will start with the name of the manager, followed by a colon, followed by a space-separated list of their direct reports ordered from their most to least favorite. Colons have a trailing space. No manager is listed before their manager, if they have one.</p>

<p><strong>Decode</strong></p>

<p>In the decode case you will be given the output that your program printed in the encode case: a list of all employee names in an arbitrary order, one per line, followed by a single line with a binary string <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>.</p>

### 출력 

 <p><strong>Encode</strong></p>

<p>Your program must first output the names of all the employees, one per line in an arbitrary order (this was a requirement from upper management). One additional line is dedicated for your encoding string <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container> which must consist of ones and zeros and not exceed 2048 characters.</p>

<p><strong>Decode</strong></p>

<p>Output the original structure in the same format as it was originally given. The order of manager definitions does not have to be the same, but every one must come after their manager if they have one. However, the order of reports for any specific manager has to remain the same (from their most to least favorite).</p>

