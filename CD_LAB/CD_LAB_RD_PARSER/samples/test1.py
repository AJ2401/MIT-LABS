# This is a comment
import pandas
import random

def main():
    s = "This is a string literal"
    a = 10
    b = 25.6
    c = a + b * a / b - a % b + 1
    print(c)
    if c == 0:
        print("c is zero")
    else:
        print("c is not zero")

if __name__ == '__main__': main()