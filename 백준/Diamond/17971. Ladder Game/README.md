# [Diamond V] Ladder Game - 17971 

[문제 링크](https://www.acmicpc.net/problem/17971) 

### 성능 요약

메모리: 2252 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2024년 11월 18일 11:37:08

### 문제 설명

<p>Consider a situation that we need to distribute <em>n</em> gifts to <em>n</em> people fairly and randomly. For this purpose one ancient technique is popular in Asia, and is usually used to represent a random permutation. Chinese call it Ghost Leg (畫鬼腳), Japanese Budda Lots (あみだくじ) and Korean Ladder Game (사다리타기). We first start with some terms. This ladder consists of several vertical poles and horizontal bars connecting two adjacent vertical poles. From the top of each vertical pole, a path is traced through the ladder using the following three steps:</p>

<ol>
	<li>When tracing a vertical pole, continue downwards until an end of the first bar is reached, then continue along the bar.</li>
	<li>When tracing a bar, continue along it until the end of the bar is reached, then continue down the vertical pole.</li>
	<li>Repeat Step 1 and Step 2 until the bottom of a vertical pole is reached.</li>
</ol>

<p>Figure D.1(a) shows a ladder <em>L</em> with three vertical poles and three bars. The vertical poles are numbered with 1, … , <em>n</em> from left to right. The paths of tracing these three vertical poles are shown in (b), (c), and (d). The input (1, 2, 3) is permuted finally to <em>π<sub>L</sub></em> = (3, 2, 1) by the ladder <em>L</em>. Note that we do not allow the case that two immediately adjacent horizontal bars meet at some point (like <em>w</em> in Figure D.1(e)) because there is no unique way in tracing at the point.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/155fd3af-c7dc-462e-9e88-14bd88a1d940/-/crop/1206x370/14,0/-/preview/" style="width: 603px; height: 185px;"></p>

<p style="text-align: center;">Figure D.1: Tracing the ladder.</p>

<p>You are given a ladder <em>L</em> which achieves a permutation <em>π<sub>L</sub></em>. If the permutation <em>π<sub>L</sub></em> is unchanged after removing a set of bars containing a particular bar, then the bar is said to be redundant for <em>π<sub>L</sub></em>. Your task is to find all redundant bars for <em>π<sub>L</sub></em>. This is equivalent to constructing a minimal ladder by removing all redundant bars from <em>L</em>. In the minimal ladder of <em>L</em>, the removal of any non-empty set of bars from the ladder gives a different permutation from <em>π<sub>L</sub></em>.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing one integers <em>n</em> (3 ≤ <em>n</em> ≤ 50), where <em>n</em> is the number of vertical poles. The vertical poles are ordered from left to right. Let <em>d</em><sub><em>i</em>,<em>j</em></sub> denote the depth of the <em>j</em>-th bar between the <em>i</em>-th and (<em>i</em> + 1)-th poles from the top, which is an integer between 1 and 1,000. In the following <em>n</em> − 1 lines, the <em>i</em>-th line contains the sequence of depths <em>d</em><sub><em>i</em>,<em>j</em></sub>, where 1 ≤ <em>i</em> < <em>n</em>, <em>j</em> ≥ 1 and <em>d</em><sub><em>i</em>,<em>j</em></sub> < <em>d</em><sub><em>i</em>,<em>j</em>+1</sub>. Notice that this depth sequence is ended with zero (0), which is not a depth but just a marker to indicate the end of the sequence. See Figure D.2 for illustration.</p>

<table class="table table-bordered" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width: 33%; text-align: center;"><img alt="" src="https://upload.acmicpc.net/81d432b8-ffdc-4cef-a960-eec25607f80e/-/crop/357x378/0,0/-/preview/" style="width: 178px; height: 188px;"></td>
			<td style="width: 34%; text-align: center;"><img alt="" src="https://upload.acmicpc.net/81d432b8-ffdc-4cef-a960-eec25607f80e/-/crop/427x378/417,0/-/preview/" style="width: 213px; height: 189px;"></td>
			<td style="width: 33%; text-align: center;"><img alt="" src="https://upload.acmicpc.net/81d432b8-ffdc-4cef-a960-eec25607f80e/-/crop/344x378/890,0/-/preview/" style="width: 172px; height: 189px;"></td>
		</tr>
		<tr>
			<td style="width: 33%; text-align: center;">(a) Depth <em>d</em><sub><em>i</em>,<em>j</em></sub> of the bars</td>
			<td style="width: 34%; text-align: center;">(b) Sample input 1</td>
			<td style="width: 33%; text-align: center;">(c) Sample input 2</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">Figure D.2: Depths of the bars between two adjacent poles in the ladder.</p>

### 출력 

 <p>Your program is to write to standard output. Print a set of the bars to be remained in a minimal ladder for <em>π<sub>L</sub></em>. The first line should contain <em>k</em>, the number of the bars remained in the minimal ladder. Then, each line of the following <em>k</em> lines should contain two indices <em>i</em> and <em>j</em> of <em>d</em><sub><em>i</em>,<em>j</em></sub> of the bar in the minimal ladder. Note that the minimal ladder is not unique.</p>

