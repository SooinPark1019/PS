# [Platinum III] Acrobat - 13973 

[문제 링크](https://www.acmicpc.net/problem/13973) 

### 성능 요약

메모리: 65396 KB, 시간: 284 ms

### 분류

자료 구조, 분리 집합, 오일러 경로, 그래프 이론

### 제출 일자

2025년 2월 13일 06:17:29

### 문제 설명

<p>An acrobat wants to make her last and greatest performance, so that she is forever remembered. She will perform a tightrope walking act, unlike anything that has been done before. Tightrope walking is the art of walking along a thin wire or rope while maintaining one’s balance.</p>

<p>To make it a breath-taking experience, each rope she will be walking on will be hanging over a deep canyon formed between two neighboring hills. In fact, an even more original aspect of her act will be that the endpoints of the ropes will not be nailed on the hilltops, but rather held by trained assistants standing on each hill. Specifically, assistants A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>n</sub> will be standing on the first hill, in this order, and B<sub>1</sub>, B<sub>2</sub>, ..., B<sub>n</sub> will be standing on the second hill, each one of them standing opposite to the respective assistant on the first hill. This means that for each i, A<sub>i</sub> is standing across the canyon opposite to B<sub>i</sub>. Also, each rope is held between exactly two people standing in different hills, say A<sub>i</sub> and B<sub>j</sub>. As the ropes are really tight, after the acrobat moves across a rope and gets to the other side, it snaps, so she cannot use it again.</p>

<p>The acrobat wants to start at a rope’s end on the first hill, walk on every rope exactly once (remember, ropes are destroyed after their use) and continue in this way untilshe returns to the point where she started and all ropes have been destroyed. After walking on a rope and reaching its end, she wants to start walking on another rope that is held by the assistant that is located there.</p>

<p>However, her assistants have already taken their places and are holding the ropes in the way they wanted, without asking her for directions. Depending on the initial positions of the ropes, the acrobat sees that it may not be possible to perform her act as she planned. Fortunately, she can make two types of changes:</p>

<ul>
	<li>1: Given a rope between A<sub>i</sub> and B<sub>j</sub>, she can tell these two assistants to simultaneously throw their end of the rope to the assistant standing opposite to them, so after this the rope will be held between B<sub>i</sub> and A<sub>j</sub>.</li>
	<li>2: On the second hill (which is far from her audience and she won’t be noticed) she can walk between the positions of any pair of assistants B<sub>i</sub> and B<sub>j</sub>.</li>
</ul>

<p>Your task is to check if it is possible for the acrobat to perform her act with a relatively small number of such changes and, if so, find the changes that need to be made.</p>

### 입력 

 <p>In the first line of the input there will be two numbers N and M: N is the number of assistants on each hill and M is the number of ropes that the assistants initially hold. Each of the following M rows will contain two integers i and j, separated with a space, denoting that a rope is held by assistants A<sub>i</sub> and B<sub>j</sub>. Initially, there will not be two different ropes held by the same pair of assistants. (However, note that this could be true after applying changes of type-1.)</p>

### 출력 

 <p>The first line of the output there should contain a single integer number. If the requirements cannot be met no matter how many changes are applied, this number should be −1. Otherwise, it should be equal to the number of changes that should be made. </p>

<p>In case the first line of the output contains a positive integer K, each of the following K lines should contain one change that should be applied. If a type-1 change is required (i.e., assistants A<sub>i</sub> and B<sub>j</sub> to simultaneously throw their end of the rope to the assistant standing opposite to them), then the corresponding line should contain “1 i j”. This change is valid only if there exists initially a rope between A<sub>i</sub> and B<sub>j</sub>. If a type-2 change is required (i.e., walk the path between assistants B<sub>i</sub> and B<sub>j</sub>), then the corresponding line should contain “2 i j”.</p>

