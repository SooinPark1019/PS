# [Diamond V] Game of Stones - 16705 

[문제 링크](https://www.acmicpc.net/problem/16705) 

### 성능 요약

메모리: 28588 KB, 시간: 416 ms

### 분류

많은 조건 분기, 게임 이론, 스프라그–그런디 정리

### 제출 일자

2025년 2월 10일 18:59:06

### 문제 설명

<p>Two players, Petyr and Varys, play a game in which players remove stones from N piles in alternating turns. Petyr, in his turn, can remove at most A stones from any pile. Varys, in his turn, can remove at most B stones from any pile. Each player has to remove at least one stone in his turn. The player who removes the last stone wins.</p>

<p>The game has already started and it is Petyr’s turn now. Your task is to determine whether he can win the game if both he and Varys play the game in the best possible way.</p>

### 입력 

 <p>The first input line contains three integers N, A, and B (1 ≤ N ≤ 10<sup>5</sup> and 1 ≤ A, B ≤ 10<sup>5</sup>). N describes the number of piles and A, B represent Petyr’s and Varys’ restrictions. The second line contains N integers X<sub>1</sub>, . . . , X<sub>N</sub> (1 ≤ X<sub>i</sub> ≤ 10<sup>6</sup>) specifying the current number of stones in all piles.</p>

### 출력 

 <p>Output the name of the winner.</p>

