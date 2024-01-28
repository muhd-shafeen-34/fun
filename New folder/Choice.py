def factorial(a):
        factorials = 1
        if a >= 1:
            for i in range (1, a+1):
                factorials = factorials * i
            print ("Factorial of the given number is: ",factorials)
            
def fib(a):
    x = 0
    b = 1
    if a == 1:
        print(a)
    else:
        print(x)
        print(b)
        for i in range(2,a):
            c = x + b
            x = b
            b = c
            print(c)
                
    def computee(a):
        temp=str(a)
        t1=temp+temp
        t2=temp+temp+temp
        comp=a+int(t1)+int(t2)
        print(temp," + ",t1," + ",t2)
        print("The value is:",comp)
    
choice = 1
while choice !=4:
    print("1. facorial")
    print("2. fibonacci series upto a given number")
    print("3. compute n+nn+nnn")
    print("press 4for Exit")
    choice = int(input('enter a choice: '))
    if choice == 1:
        x = int(input("enter a number to find factorial : "))
        factorial(x)           
    elif choice == 2:
        x = int(input("enter a number to find fibonacci series : "))
        fib(x)
    elif choice == 3:
        x = int(input("enter a number to compute : "))
        computee(x)
        
    elif choice == 4:
        print("exiting...")
    else:
        print("wrong input....")            