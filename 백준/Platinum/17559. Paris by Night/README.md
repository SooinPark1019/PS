# [Platinum II] Paris by Night - 17559 

[문제 링크](https://www.acmicpc.net/problem/17559) 

### 성능 요약

메모리: 2336 KB, 시간: 3384 ms

### 분류

기하학, 정렬, 스위핑, 두 포인터

### 제출 일자

2025년 1월 6일 19:35:32

### 문제 설명

<p>During her trip to Paris for SWERC, Morgane graded every monument she visited. On this last night of the week, she plans to go in some hot-air balloon and take two 180° panoramic photographs of the city, thereby getting a perfect 360° view. She would like both photographs to be approximately as nice as each other.</p>

<p>Hence, she will proceed as follows. She chooses two monuments, that we will call the boundary monuments, and asks the balloon pilot to go between these monuments. From there, she takes two 180°<sup> </sup>pictures: each picture shows one side of Paris, both sides being delimited by the two boundary monuments. Each picture receives a grade, which is the sum of the grades of the monuments that it shows, including the boundary monuments on both pictures. Finally, if the pictures have grades A and B, the goal of Morgane is to minimize the difference between A and B (in absolute value).</p>

<p>The visibility from the balloon is such that all monuments can be seen in either of the two photographs.</p>

<p>You must assist Morgane in choosing appropriate boundary monuments. In order to do this, you are given a list of the monuments. For every monument visited by Morgane, this list contains a line which indicates the Cartesian coordinates of the monument location, along with the monument’s grade. You should give the minimal possible difference, among all pairs of pictures that Morgane may take, between the grades of the two pictures.</p>

### 입력 

 <p>The input comprises several lines, each consisting of integers separated with single spaces:</p>

<ul>
	<li>the first line contains the number N of monuments;</li>
	<li>each of the N next lines contains three integers associated with each monument: the X coordinate, the Y coordinate and the grade G of the monument represented on that line.</li>
</ul>

### 출력 

 <p>The output should consist of a single line, whose content is an integer, the minimal difference (in absolute value) between the grades of a pair of photographs that Morgane may take.</p>

