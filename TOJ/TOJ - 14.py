import sys
sys.set_int_max_str_digits(0)
s = input()
a = int(input())
b = int(input())
if (s == "mul"):
    print(a * b)
elif (s == "pow"):
    print(a ** b)
