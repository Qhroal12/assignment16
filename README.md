1) 코드 오류 수정

- 수업시간에 진행한 https://github.com/kmu-datastructure-ju/data-structure/tree/master/Calculator 코드에는 오류가 존재한다. 해당 소스코드의 오류를 정상 동작하도록 수정한다.

- 또한, Postfix의 evalPostfix까지 정상적으로 동작하도록 코드를 수정하여 코드를 제출한다.

- 각 진행 과정에서 현재 연산 상태를 매번 출력하여 진행 과정이 보이도록 해야하며, 코드는 수업 시간 코드를 수정하여 활용하여야 한다.



예시)

입력: 

3 + 4 * (5 + 6) * 7



출력: 

Transform:

- Postfix: 3 | Stack: 

- Postfix: 3 | Stack: +

- Postfix: 3 4 | Stack: +
...

- Postfix: 3 4 5 6 + * 7 | Stack: + *

- Postfix: 3 4 5 6 + * 7 * + | Stack: 



- Result: 3 4 5 6 + * 7 * +



Eval:

- Postfix: 3 4 5 6 + * 7 * + 

- Current: 3 | Stack: 3

- Current: 4 | Stack: 3 4

- Current: 5 | Stack: 3 4 5

- Current: 6 | Stack: 3 4 5 6

- Current: + | Stack: 3 4 11

...

- Current: * | Stack: 3 308

- Current: + | Stack: 311



- Result: 311
