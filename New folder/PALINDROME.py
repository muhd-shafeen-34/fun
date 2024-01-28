string = input("enter your strung ")
pali = string[: :-1]
if string == pali:
    print("the given ",string,"is palindrome")
else:
    print("the given ",string,"is not palindrome")
    