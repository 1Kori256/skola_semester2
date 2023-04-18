import sys


def solve(expression):
    try:
        expression = expression.strip().split()
        
        stack = []
        for element in expression:
            if element in ["+", "-", "*", "/"]:
                b = stack.pop(-1)
                a = stack.pop(-1)
                if element == "+":
                    stack.append(a + b)
                elif element == "-":
                    stack.append(a - b)
                elif element == "*":
                    stack.append(a * b)
                elif element == "/":
                    stack.append(a // b)
                
            else:
                stack.append(int(element))

        if len(stack) != 1:
            raise ValueError

        return stack[-1]

    except Exception as e:
        if type(e) == ZeroDivisionError:
            return "Zero division"
        else:
            return "Malformed expression"


if __name__ == "__main__":
    for line in sys.stdin:
        if len(line.strip().split()) > 0:
            print(solve(line))