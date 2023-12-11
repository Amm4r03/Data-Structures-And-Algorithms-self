# notes from video
video link [here](https://www.youtube.com/watch?v=B31LgI4Y4DQ)

## infix notation
`<operand> <operator> <operand>`

### order of operation
1. parentheses
2. exponents (right to left)
3. multiplication and division (left to right)
4. addition and subtraction (left to right)

## Prefix notation
also known as **polish notation**

`<operator><operand><operand>`

|Infix expression|Prefix expression|
|:---:|:---:|
|2+3|+23|
|p-q|-pq|
|a+b*c|+a*bc|

## postfix notation
also known as **reverse polish notation**

`<operand> <operand> <operator>`

> postfix notation easiest to parse and least costly in terms of time and memory to evaluate

|Infix expression|Prefix expression|corresponding postfix expression|
|:---:|:---:|:---:|
|2+3|+23|23+|
|p-q|-pq|pq-|
|a+b*c|+a*bc|abc*+|
