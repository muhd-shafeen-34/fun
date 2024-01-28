x = int(input('enter the number'))
a = 0
b = 1
if x == 1:
        print(a)
elif x<0:
        print("enter a positive number")
else:
     print(a)
     print(b)
     for i in range(2,x):
        c = a + b
        a = b
        b = c
        print(c)

