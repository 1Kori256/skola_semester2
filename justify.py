import sys, math


def print_spaced(words):
    if len(words) == 0: return
    num_of_spaces = LINE_WIDTH - sum([len(word) for word in words])
    num_of_words = len(words) - 1
    for word in words[:-1]:
        print(word, end="")
        x = math.ceil(num_of_spaces / num_of_words)
        print(" " * x, end="")
        num_of_spaces -= x
        num_of_words -= 1
    print(words[-1])

if __name__ == "__main__":
    try:
        # Test input
        LINE_WIDTH = sys.argv[1]
        if not LINE_WIDTH.isdigit(): raise ValueError
        LINE_WIDTH = int(LINE_WIDTH)
        if LINE_WIDTH < 1: raise ValueError

        # Script
        add_empty_line = False
        current_ans_line = []
        current_sum = -1
        for line in sys.stdin:
            line = line.split()
            if len(line) == 0:
                if len(current_ans_line) > 0:
                    print(*current_ans_line)
                    add_empty_line = True
                current_ans_line = []
                current_sum = -1
            elif add_empty_line == True:
                print()
                add_empty_line = False

            for word in line:
                if current_sum + len(word) + 1 <= LINE_WIDTH:
                    current_sum += len(word) + 1
                    current_ans_line.append(word)
                else:
                    print_spaced(current_ans_line)
                    current_sum = len(word)
                    current_ans_line = [word]

        if len(current_ans_line) > 0:
            print(*current_ans_line)

    except:
        print("Error")