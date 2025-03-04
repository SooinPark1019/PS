# [Platinum V] Exhibition - 16981 

[문제 링크](https://www.acmicpc.net/problem/16981) 

### 성능 요약

메모리: 6244 KB, 시간: 48 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 3월 4일 11:25:16

### 문제 설명

<p>You are going to hold an exhibition of pictures. In the exhibition, you will put some pictures into frames and exhibit them, lining them up in a row.</p>

<p>There are N candidate pictures for the exhibition, numbered from 1 through N. The picture i (1 ≤ i ≤ N) has size S<sub>i</sub> and value V<sub>i</sub>.</p>

<p>Also, there are M frames for the pictures, numbered from 1 through M. The frame j (1 ≤ j ≤ M) has size C<sub>j</sub>. Only pictures of size at most C<sub>j</sub> can be put into the frame j. At most one picture can be put into a frame.</p>

<p>Every picture to be exhibited must be put into a frame. For the sake of appearance, they must satisfy the following conditions:</p>

<ul>
	<li>For any neighboring two pictures, the size of the frame containing the right picture must be at least the size of the frame containing the left picture.</li>
	<li>For any neighboring two pictures, the value of the right picture must be at least the value of the left picture.</li>
</ul>

<p>You want to exhibit as many pictures as possible.</p>

<p>Write a program which, given the number of pictures, the number of frames, and their sizes and values, calculates the maximum number of pictures to be exhibited.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<pre>N M
S<sub>1</sub> V<sub>1</sub>
.
.
.
S<sub>N</sub> V<sub>N</sub>
C<sub>1</sub>
.
.
.
C<sub>M</sub></pre>

### 출력 

 <p>Write one line to the standard output. The output should contain the maximum number of pictures to be exhibited.</p>

