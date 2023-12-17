# attempt 3

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

for symbol in infixList:
    if symbol.isalnum():
        postfixExpression += symbol
    elif symbol == '(':
        operatorStack.append(symbol)
    elif symbol == ')':
        while operatorStack and operatorStack[-1] != '(':
            postfixExpression += operatorStack.pop()
        operatorStack.pop()
    elif symbol in operators:
        while operatorStack and operatorStack[-1] != '(' and precedence[operatorStack[-1]] >= precedence[symbol]:
            postfixExpression += operatorStack.pop()
        operatorStack.append(symbol)

while operatorStack:
    postfixExpression += operatorStack.pop()
    
print(postfixExpression)


# for char in infixList:
#     if char.isalnum():
#         postfixExpression += char
#     elif char in operators:
#         if not(operatorStack) or operatorStack[-1] == '(':
#             operatorStack.append(char)
#         elif char == '^' and operatorStack[-1] == '^':
#             operatorStack.append(char)
#         elif precedence[char] <= precedence[operatorStack[-1]]:
#             while operatorStack and operatorStack[-1] != '(' and precedence[char] <= precedence[operatorStack[-1]]:
#                 popped = operatorStack.pop()
#                 postfixExpression += popped
#                 postfixExpression += char
#     elif char == '(':
#         operatorStack.append(char)
#     elif char == ')':
#         while operatorStack and operatorStack[-1] != '(':
#             popped = operatorStack.pop()
#             postfixExpression += popped
#         operatorStack.pop()
#     while operatorStack:
#         postfixExpression += operatorStack.pop()

# print(postfixExpression)