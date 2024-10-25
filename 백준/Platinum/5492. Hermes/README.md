# [Platinum V] Hermes - 5492 

[문제 링크](https://www.acmicpc.net/problem/5492) 

### 성능 요약

메모리: 2980 KB, 시간: 312 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 10월 26일 01:39:30

### 문제 설명

<p>In a modern city for Greek gods, the streets are geometrically arranged as a grid with integer coordinates with streets parallel to the x and y axes. For each integer value Z, there is a horizontal street at y=Z and a vertical street at x=Z. This way, integer coordinate pairs represent the street junctions. During the hot days, the gods rest in cafeterias at street junctions. Messenger Hermes is to send photon messages to gods resting in the cafeterias by only moving along the city streets. Each message is for a single god, and it does not matter if the other gods see the message.</p>

<p>The messages are to be sent in a given order, and Hermes is provided the coordinates of the cafeterias in that order. Hermes starts from (0,0). To send a message to a cafeteria at (Xi,Yi), Hermes only needs to visit some point on the same horizontal street (with y-coordinate Yi) or on the same vertical street (with x-coordinate Xi). Having sent all of the messages, Hermes stops.</p>

<p>You are to write a program that, given a sequence of cafeterias, finds the minimum total distance Hermes needs to travel to send the messages.</p>

### 입력 

 <p>The first line contains one integer N: the number of messages to be sent. The following N lines contain the coordinates of the N street junctions where the messages are to be sent. These N lines are in the order in which the messages are to be sent. Each of these N lines contains two integers: first the x-coordinate and then the y-coordinate of the street junction.</p>

### 출력 

 <p>The file is to contain a single line containing one integer: the minimum total distance Hermes needs to travel to send the messages.</p>

