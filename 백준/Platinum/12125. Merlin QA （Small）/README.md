# [Platinum V] Merlin QA (Small) - 12125 

[문제 링크](https://www.acmicpc.net/problem/12125) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

애드 혹, 그리디 알고리즘

### 제출 일자

2025년 1월 8일 00:29:10

### 문제 설명

<p>Edythe is a young sorceress working in the quality assurance department of Merlin, Inc. -- a magic spell factory. Her job is to test the magic spells that Merlin himself invents. Each spell requires precise amounts of certain ingredients and transforms them into other amounts of other ingredients. Edythe's job is to cast each spell exactly once in order to verify that the spell works correctly.</p>

<p>She can cast a spell only if she has the required amount of each ingredient. If she has already created ingredients of the right type from previous spells, Edythe must use those first. However, if she still needs more ingredients, she is allowed to take them from Merlin's storehouse. She has no ingredients to start with, but at the end, she gets to keep all the extra ingredients that she created and didn't use.</p>

<p>Edythe wants to make as much profit as possible from her apprenticeship! She has to cast each of the <strong>N</strong> given spells exactly once, but she is free to do so in any order. Assuming that each spell works as expected, which ordering lets her earn the most money in the end?</p>

<p>For example, imagine that the test plan contains the following 3 spells:</p>

<ol>
	<li>Inputs: <span>$</span>7 worth of gold. Outputs: <span>$</span>5 worth of sulfur.</li>
	<li>Inputs: nothing. Outputs: <span>$</span>10 worth of gold, <span>$</span>10 worth of sulfur.</li>
	<li>Inputs: <span>$</span>3 worth of gold, <span>$</span>20 worth of sulfur. Outputs: <span>$</span>2 worth of toads.</li>
</ol>

<p>Note that the first spell converts gold into sulfur, the second spell conjures up gold and sulfur from nothing, and the third spell converts gold and sulfur into toads.</p>

<p>If Edythe were to cast these spells in the order 1, 2, 3, then she would start by fetching <span>$</span>7 worth of gold from the storehouse for spell #1. That would let her cast spells #1 and #2, giving her <span>$</span>10 worth of gold and <span>$</span>15 worth of sulfur. For the final spell, she would need <span>$</span>3 worth of gold and <span>$</span>20 worth of sulfur. She would have to use all of the sulfur she created so far, <span>$</span>3 worth of gold, and <span>$</span>5 more worth of sulfur that she fetched from the storehouse. This would leave her with <span>$</span>9 worth of ingredients at the end (<span>$</span>7 worth of gold and <span>$</span>2 worth of toads).</p>

<p>But there is a better plan. If she cast the spells in the order 3, 1, 2, she would have <span>$</span>27 worth of ingredients at the end (<span>$</span>10 worth of gold, <span>$</span>15 worth of sulfur, and <span>$</span>2 worth of toads).</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>.  <strong>T</strong> test cases follow. Each one starts with a line containing <strong>N</strong> and <strong>M</strong>. <strong>M</strong> is the number of kinds of ingredients in the world. Each of the next <strong>N</strong> lines contains <strong>M</strong> integers describing a spell. Each integer is the value (or cost) of the corresponding ingredient. Negative integers are the dollar costs of the input ingredients; positive integers are the dollar values of the output ingredients; and zeros denote ingredients that are neither produced nor consumed by the spell. This also implies that no spell can simultaneously consume and produce the same ingredient.</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 100.</li>
	<li>1 ≤ <strong>N</strong> ≤ 100.</li>
	<li>-100 ≤ Each integer in each spell ≤ 100.</li>
	<li>1 ≤ <strong>M</strong> ≤ 2.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the largest value of ingredients Edythe can have at the end.</p>

