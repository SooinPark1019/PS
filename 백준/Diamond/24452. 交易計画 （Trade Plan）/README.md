# [Diamond V] 交易計画 (Trade Plan) - 24452 

[문제 링크](https://www.acmicpc.net/problem/24452) 

### 성능 요약

메모리: 141516 KB, 시간: 1344 ms

### 분류

자료 구조, 분리 집합, 오프라인 쿼리

### 제출 일자

2025년 6월 14일 13:11:46

### 문제 설명

<p>JOI 合衆国には <var>1</var> から <var>N</var> までの番号が付けられた <var>N</var> 個の都市と，<var>1</var> から <var>M</var> までの番号が付けられた <var>M</var> 本の道路がある．道路 <var>i</var> (<var>1 ≦ i ≦ M</var>) は，都市 <var>U<sub>i</sub></var> と都市 <var>V<sub>i</sub></var> を双方向に結んでいる．</p>

<p>JOI 合衆国は <var>1</var> から <var>K</var> までの番号が付けられた <var>K</var> 個の州からなる．都市 <var>j</var> (<var>1 ≦ j ≦ N</var>) は州 <var>S<sub>j</sub></var> に属している．また，どの州も少なくとも <var>1</var> つの都市を含む．</p>

<p>JOI 合衆国の産業大臣である K 理事長は，これから <var>Q</var> 回の交易を行いたいと考えている．<var>k</var> 番目の交易 (<var>1 ≦ k ≦ Q</var>) は，都市 <var>A<sub>k</sub></var> から都市 <var>B<sub>k</sub></var> にいくつかの道路や都市を通って特産品を輸送するというものである．ただし，この交易に協力してくれるのは州 <var>S<sub>A<sub>k</sub></sub></var> と 州 <var>S<sub>B<sub>k</sub></sub></var> のみ (<var>S<sub>A<sub>k</sub></sub> = S<sub>B<sub>k</sub></sub></var> の場合は州 <var>S<sub>A<sub>k</sub></sub></var> のみ) であり，これらの州に属していない都市を通ると特産品は盗まれてしまう．</p>

<p>K 理事長は特産品が盗まれないように交易を行うような輸送経路があるのかを調べたい．都市と道路の配置，州と交易の情報が与えられたとき，各交易について特産品を無事届けることが可能かを判定するプログラムを作成せよ．</p>

### 입력 

 <p>入力は以下の形式で標準入力から与えられる．</p>

<pre><var>N</var> <var>M</var> <var>K</var>
<var>U<sub>1</sub></var> <var>V<sub>1</sub></var>
<var>U<sub>2</sub></var> <var>V<sub>2</sub></var>
<var>:</var>
<var>U<sub>M</sub></var> <var>V<sub>M</sub></var>
<var>S<sub>1</sub></var> <var>S<sub>2</sub></var> <var>…</var> <var>S<sub>N</sub></var>
<var>Q</var>
<var>A<sub>1</sub></var> <var>B<sub>1</sub></var>
<var>A<sub>2</sub></var> <var>B<sub>2</sub></var>
<var>:</var>
<var>A<sub>Q</sub></var> <var>B<sub>Q</sub></var></pre>

### 출력 

 <p>標準出力に <var>Q</var> 行で出力せよ．<var>k</var> 行目 (<var>1 ≦ k ≦ Q</var>) には，<var>k</var> 番目の交易において特産品を届けることが可能であれば <code>1</code> を，不可能であれば <code>0</code> を出力せよ．</p>

