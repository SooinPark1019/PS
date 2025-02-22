# [Platinum III] 微生物実験 (Bug Party) - 5553 

[문제 링크](https://www.acmicpc.net/problem/5553) 

### 성능 요약

메모리: 41976 KB, 시간: 988 ms

### 분류

이분 탐색, 자료 구조, 그리디 알고리즘, 우선순위 큐, 세그먼트 트리

### 제출 일자

2025년 2월 15일 18:24:03

### 문제 설명

<p>あなたは Just Odd Inventions 社を知っているだろうか? この会社の業務は「ただ奇妙な発明 (just odd inventions)」をすることである．ここでは略して JOI 社と呼ぶ．</p>

<p>JOI 社では多くの微生物を 1 つのシャーレに生きたまま閉じ込める研究をしている．調査対象の微生物は N 匹存在し，1, 2, · · · , N という番号がついている．各微生物はシャーレに閉じ込められると，foo (fatally odd object) と呼ばれる有害物質を一瞬のうちにシャーレ内に放出する．各微生物が放出する foo の量は知られている．シャーレに閉じ込められた全微生物が放出した foo はシャーレ内の各微生物が均等に摂取する．各微生物の foo 許容量は知られており，この量を超えて foo を摂取すると微生物は死んでしまう．</p>

<p>微生物 i の foo 放出量は a<sub>i</sub> ミリグラム，foo 許容量は b<sub>i</sub> ミリグラムである．すなわち，シャーレに微生物 i<sub>1</sub>, i<sub>2</sub>, · · · , i<sub>k</sub> を閉じ込めたとき，シャーレ内の各微生物はそれぞれ (a<sub>i<sub>1</sub></sub> + a<sub>i<sub>2</sub></sub> + · · · + a<sub>i<sub>k</sub></sub>)/k ミリグラムの foo を摂取し，シャーレ内の微生物 i は，この摂取量が b<sub>i</sub> より大きいと死んでしまう．</p>

<p>JOI 社からの委託により，あなたは出来るだけ多くの微生物をシャーレに生きたまま閉じ込めなければならない．ただし，微生物の死骸はシャーレ内の環境に悪影響を及ぼすため，シャーレ内のどの微生物も foo の摂取で死んではならない．</p>

<p>なお，JOI 社が「ただ奇妙な発明」をすることでどうやって利益を得ているかは，今もって謎であり，JOI社内でも社長以外の誰も知らない．</p>

<p>調査対象の微生物数と，各微生物の foo 放出量と foo 許容量が与えられたとき，1 つのシャーレに閉じ込めることができる微生物数の最大値を求めるプログラムを作成せよ．</p>

### 입력 

 <p>標準入力から以下の入力を読み込め．</p>

<ul>
	<li>1 行目には整数 N が書かれており，調査対象の微生物が N 匹存在することを表す．</li>
	<li>続く N 行には各微生物の情報が書かれている．i + 1 行目 (1 ≤ i ≤ N) には，正整数 a<sub>i</sub>, b<sub>i</sub> が空白を区切りとして書かれており，微生物 i の foo 放出量が a<sub>i</sub> ミリグラムで foo 許容量が b<sub>i</sub> ミリグラムであることを表す</li>
</ul>

### 출력 

 <p>標準出力に，1 つのシャーレに閉じ込めることができる微生物数の最大値を 1 行で出力せよ．</p>

