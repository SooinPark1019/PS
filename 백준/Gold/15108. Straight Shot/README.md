# [Gold IV] Straight Shot - 15108 

[문제 링크](https://www.acmicpc.net/problem/15108) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

기하학, 수학, 매개 변수 탐색

### 제출 일자

2024년 12월 27일 15:02:16

### 문제 설명

<p>You have a toy robot that walks straight at a constant speed v, and you wish for it to travel on the two-dimensional plane from (0, 0) to (X, 0). If the plane were empty, you could start the robot facing straight east from the origin, and it would walk there in X/v time. Unfortunately, between the start and the destination are n moving sidewalks, each moving directly north or south, which affect the robot’s position while it is walking.</p>

<p>The direction that robot is facing is not changed by the sidewalks; the robot will face in the same orientation for the entire duration of its walk. These sidewalks are aligned with the y-axis and are infinitely long. You still must get the robot to go from start to finish, but you’ll need to adjust the orientation of the robot at the start. Given that you choose this direction correctly, so that the robot arrives exactly at the destination, how long will it take the robot to get there?</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15108/1.png" style="height:260px; width:407px"></p>

<p>One final caveat: You don’t want the toy robot to walk for too long. If the robot cannot reach the destination in at most twice the time it would take in the absence of all moving sidewalks (i.e., 2X/v), indicate this.</p>

### 입력 

 <p>The first line consists of three space-separated numbers n, X, and v (0 ≤ n ≤ 100; 1 ≤ X ≤ 1,000,000; 1.0 ≤ v ≤ 100.0). Note that v is not necessarily an integer.</p>

<p>Each of the next n lines contains three space-separated numbers l<sub>i</sub>, r<sub>i</sub>, and v<sub>i</sub> (0 ≤ l<sub>1</sub> < r<sub>1</sub> ≤ l<sub>2</sub> < r<sub>2</sub> ≤ · · · ≤ l<sub>n</sub> < r<sub>n</sub> ≤ X; −100.0 ≤ v<sub>i</sub> ≤ 100.0), describing the ith moving sidewalk. The integer l<sub>i</sub> denotes the left edge of the sidewalk, the integer r<sub>i</sub> denotes the right edge of the sidewalk, and the decimal number v<sub>i</sub> denotes the speed of the sidewalk. A positive speed means the sidewalk moves north, while a negative speed means the sidewalk moves south.</p>

### 출력 

 <p>If the robot cannot reach the destination in at most twice the time it would take in the absence of all moving sidewalks, output “Too hard” on a single line (without quotation marks).</p>

<p>Otherwise, output, on a single line, the travel time of the robot from the start to the destination, rounded and displayed to exactly three decimal places.</p>

