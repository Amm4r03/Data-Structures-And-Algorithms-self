# converts infix expression to postfix

infixExpression = input("enter the infix expression : ")

infixExpression = infixExpression.replace(" ", "").upper()
infixList = list(infixExpression)

operatorStack = []
postfixExpression = ''

operators = ['+', '-', '*', '/', '^']

i = 0

for char in infixList:
    if char.isalnum():
        postfixExpression += char
    elif char == '(':
        operatorStack.append(char)
    elif char == ')':
        while operatorStack and operatorStack[-1] != '(':
            postfixExpression += operatorStack.pop()
        operatorStack.pop()
    elif char in operators:
        
        while operatorStack:
            postfixExpression += operatorStack.pop()
    print(operatorStack)

while operatorStack:
    postfixExpression += operatorStack.pop()

print(postfixExpression)