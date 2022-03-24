# [Gold I] 알파벳 분수 - 23345 

[문제 링크](https://www.acmicpc.net/problem/23345) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

구성적(constructive), 자료 구조(data_structures), 구현(implementation), 스택(stack)

### 문제 설명

<p>알파벳 분수란 분자와 분모가 알파벳으로 이루어진 분수이다. 분자와 분모는 '<code>A</code>'부터 처음 N개의 문자로 이루어져 있어야 한다. 모든 알파벳은 단 한 번만 알파벳 분수에 포함되어 있어야 한며, 분자와 분모에는 하나 이상의 알파벳이 있어야 한다. 알파벳 분수는 '/'를 이용해 분자와 분모를 구분한다. 따라서, <code>ABC/D</code>, <code>CAFE/BD</code>는 알파벳 분수이고, <code>CAF/ABDE</code>, <code>AB/CE</code>, <code>AB/D</code>, <code>B/</code>, <code>ABC</code>는 아니다.</p>

<p>알파벳 확장은 알파벳 분수에 포함된 알파벳을 알파벳의 순서대로 나열하고, 인접한 글자 사이에 '<code>/</code>' 기호를 넣은 뒤, N-1개의 괄호쌍을 이용해 만들 수 있다. 알파벳 분수와 알파벳 확장은 동등한 수식이어야 한다. 예를 들어 CA/BD의 알파벳 확장으로 <code>((A/(B/C))/D</code>가 될 수 있는 이유는 <code>A</code>, <code>B</code>, <code>C</code>, <code>D</code>가 얼마든 두 식의 값이 항상 같기 때문이다. 또 다른 예로 <code>CAF/BED</code>의 알파벳 확장은 <code>(A/(B/((C/D)/(E/F))))</code>이다.</p>

<p>알파벳 분수가 주어진다. 이 분수의 알파벳 확장을 구해보자.</p>

### 입력 

 <p>첫째 줄에 알파벳 분수가 주어진다. </p>

### 출력 

 <p>입력으로 주어진 알파벳 분수의 알파벳 확장을 출력한다. 여러가지가 있는 경우 아무거나 하나만 출력하고, 없는 경우에는 "None"을 출력한다.</p>

