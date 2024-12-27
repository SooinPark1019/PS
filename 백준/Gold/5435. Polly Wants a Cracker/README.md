# [Gold IV] Polly Wants a Cracker - 5435 

[문제 링크](https://www.acmicpc.net/problem/5435) 

### 성능 요약

메모리: 9920 KB, 시간: 40 ms

### 분류

브루트포스 알고리즘, 다이나믹 프로그래밍

### 제출 일자

2024년 12월 28일 03:09:08

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images2/pirat.png" style="float:right; height:163px; width:123px">In the pirate society, each pirate captain is obligated to obtain a pet. This pet should be at the side (or on the shoulder) of a pirate captain at all times, especially during conversations with good doers who wish to challenge the captain’s evil ways.</p>

<p>Greedbeard is the infamous and feared captain of the pirate ship Greatlooter. His pet is the infamous and feared parrot known as Polly. As a parrot, Polly likes to mimic the conversations he overhears. Unfortunately, Polly is not very good at mimicking the sentences he hears. For this reason, Greedbeard has taken it upon himself to assist Polly as he learns to speak the human tongue.</p>

<p>Greedbeard noted that Polly is able to speak whole sentences, but often makes one or more of the three following mistakes:</p>

<ol>
	<li>Polly mixes up the sentence by placing words in the wrong order. E.g. instead of saying “polly wants a cracker”, Polly will say “polly cracker a wants”;</li>
	<li>Polly forgets some words in a sentence. E.g. instead of saying “polly wants a cracker”, Polly will say “polly a cracker”;</li>
	<li>Finally, Polly mixes up, adds or removes consonants and vowels<sup>2</sup> in his words. So instead of saying “polly wants a cracker”, Polly will say “polly wantsu a trackets”.</li>
</ol>

<p>Note that Polly never mimics the same word twice in a sentence. The captain always knows the original sentence that Polly is trying to mimic.</p>

<p>Captain Greedbeard is not interested in the first two mistakes. However, mixing up letters or adding/removing letters from a word makes his blood boil. Therefore, each time Polly makes mistakes in a sentence by mixing up letters, the captain will take away one cracker from his lunch, for each letter he mixes up. The number of crackers that the captain removes per word, is the minimum number of edits needed to transform the spoken word into the word that Polly was trying to say. An edit is defined as either an insertion, deletion or substitution of a single letter.</p>

<p>It is not always clear how words in the mimicked sentence correspond to words in the original sentence. Greedbeard assumes the mimicked words are matched with the original words in such a way that the total number of mistakes is minimal.</p>

<p>For instance, if Polly should have said: “polly wants a cracker” and says: “polly crackets wantsu”, the captain will remove 3 crackers from his lunch. These are 2 crackers for messing up the word “cracker” and 1 cracker for adding a letter to the word “wants”. He does not care that the word “a” is missing, or that words are spoken in the wrong order.</p>

<p><sup>2</sup>Read: mixes up, adds or removes letters</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>A line containing a single string (1 ≤ length ≤ 1000), representing the sentence that Polly is trying to mimic;</li>
	<li>A line containing a single string (1 ≤ length ≤ 1000), the sentence that Polly has spoken.</li>
</ul>

<p>Additional notes:</p>

<ul>
	<li>The sentence Polly mimics consists of one to eight words.</li>
	<li>A word is a sequence of lowercase letters. Each word ends with a space, or with the end of the sentence.</li>
	<li>A sentence does not contain a sequence of multiple spaces.</li>
</ul>

### 출력 

 <p>For every test case in the input, the output should contain one integer on a single line: the number of crackers that Greedbeard will withhold from Polly’s lunch.</p>

