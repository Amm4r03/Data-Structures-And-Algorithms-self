# converts infix expression to postfix

infixExpression = input("enter the infix expression : ")

infixExpression = infixExpression.replace(" ", "").upper()
infixList = list(infixExpression)

operatorStack = []
postfixExpression = ''

precedence = {
    '^' : 3,
    '*' : 2,
    '/' : 2,
    '+' : 1,
    '-' : 1
}

operators = ['+', '-', '*', '/', '^']

for char in infixList:
    if char.isalnum():
        postfixExpression += char
    else:
        if precedence[char] > precedence[operatorStack[-1]]:
            operatorStack.append(char)
        else:
            while precedence[char] < precedence[operatorStack[-1]]:
                popped = operatorStack.pop()
                postfixExpression += popped

print(postfixExpression)