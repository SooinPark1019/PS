# [Gold IV] Computational Geometry - 8290 

[문제 링크](https://www.acmicpc.net/problem/8290) 

### 성능 요약

메모리: 3584 KB, 시간: 0 ms

### 분류

해 구성하기, 기하학

### 제출 일자

2024년 12월 26일 20:05:05

### 문제 설명

<p>Byteasar is preparing the hardest task for the last online round of Algorithmic Engagements 2012. You should not be surprised by the fact that this task is about computational geometry, and more precisely, computing intersections of a polygon and different circles.</p>

<p>Everyone knows that the most difficult part of computational geometry is dealing with special cases. Byteasar has managed to find out that the most evil special case in his task happens when the area of a polygon equals the number of its vertices. Moreover, the edges of the polygon should be parallel to OX or OY axis and every two consecutive edges should be perpendicular. The edges may not intersect apart from pairs of consecutive edges which obviously meet at the same vertex.</p>

<p>Byteasar is having problems with generating such polygons, so he asked you for help.</p>

### 입력 

 <p>The first and only line of input contains one integer n (2 ≤ n ≤ 10,000) denoting the number of vertices of the polygon.</p>

### 출력 

 <p>If no polygon with n vertices satisfies Byteasar's requirements, your program should output a single word NIE (i.e., no in Polish). Otherwise the output should consist of n lines. The i-th line should contain two integers x<sub>i</sub> and y<sub>i</sub> representing the coordinates of the i-th vertex. The vertices should be given in the same order as they appear on the perimeter of the polygon (the direction along the perimeter in which the vertices are given may be arbitrary). No coordinate may exceed 10<sup>9</sup> by the absolute value.</p>

