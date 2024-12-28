# [Platinum I] Sateliti - 20509 

[문제 링크](https://www.acmicpc.net/problem/20509) 

### 성능 요약

메모리: 96244 KB, 시간: 416 ms

### 분류

해싱, 문자열, 접미사 배열과 LCP 배열

### 제출 일자

2024년 12월 28일 18:30:36

### 문제 설명

<p>For crater exploration purposes, the Arecibo telescope records images of Saturn’s satellites. The scientific team must distinguish between satellite images and group the images by satellite, but it’s not that simple because satellites could be shot from different angles.</p>

<p>Captured images can be displayed as n × m matrices, filled with '<code>*</code>' (crater) and '<code>.</code>' (plain surface). We say that two images correspond to the same satellite if one can get the other by <strong>circular shifts of rows and columns</strong>.</p>

<p>To make the verification process easier, scientists want to find the <strong>lexicographically smallest</strong> image corresponding to the satellite from the given image. When comparing images, we compare strings obtained by concatenating all rows of the image, where characters are compared by ASCII value.</p>

### 입력 

 <p>The first line contains integers n and m (1 ≤ n, m ≤ 1000), the dimensions of the image.</p>

<p>Each of the following n lines contains m characters '<code>*</code>' and '<code>.</code>'. This represents the captured image.</p>

### 출력 

 <p>Output n lines with m characters each, the wanted lexicographically smallest image.</p>

