import sys

def print_table(n):
    for i in range(1, 11):
        print(f"{i: >2} * {n} = {i * n: >2}")

print_table(int(sys.argv[1]))