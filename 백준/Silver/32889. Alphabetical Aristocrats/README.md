# [Silver IV] Alphabetical Aristocrats - 32889 

[문제 링크](https://www.acmicpc.net/problem/32889) 

### 성능 요약

메모리: 2324 KB, 시간: 0 ms

### 분류

정렬, 문자열

### 제출 일자

2025년 1월 10일 21:53:31

### 문제 설명

<p>It is the year 1830 of our Lord, 15 years after the Kingdom of the Netherlands gained independence from its French oppressors. You are secretary of state and aide to his highness William I, Grand Duke of Luxembourg and King of the Netherlands -- an empire that is destined to prosper and stretch across centuries to come. To the King's utter dismay, rogue scoundrels from the south recently dared to defy his benevolent rule. They call themselves Belgians and declared their own kingdom -- a fact that his highness will surely deny for at least another seven to eleven years. King William, in all his wisdom, decided to call upon the most trusted noblemen to scheme a campaign against the insubordinate elements that will last more than nine days.</p>

<p>You are to assemble a list of trustworthy royalty and sort them according to the Dutch rules. The Dutch rules state that surnames are to be compared lexicographically, according to the values of the ASCII characters, and considering only the part starting from the first capital letter. For example, King William compares the surname of his favourite painter Abraham <code>van den Hecken the Younger</code> according to <code>Hecken the Younger</code>.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1\leq n\leq 1000$), the number of surnames.</li>
	<li>$n$ lines, each with a string $s$ ($1\leq |s|\leq50$), one of the surnames. The surnames consist of English letters, spaces, and apostrophes (<code>A-Z</code>, <code>a-z</code>, '<code> </code>', '<code>'</code>').</li>
</ul>

<p>It is guaranteed that the part starting with the first capital letter is unique. Names have no leading, trailing, or consecutive spaces.</p>

### 출력 

 <p>Output the list of surnames, sorted according to the Dutch rules.</p>

