#Дэбильный калькулятор v2

oper = input ("Select needed operation (+,-,/,*): ")

a = float(input("Give the first number: "))
b = float(input("Give the second number: "))

if oper == "+":
    c = a + b
    print("Result: " + str(c))
elif oper == "-":
    c = a - b
    print("Result: " + str(c))
elif oper == "/":
    c = a / b
    print("Result: " + str(c))
elif oper == "*":
    c = a * b
    print("Result: " + str(c))
else:
    print("Unknown operation.")