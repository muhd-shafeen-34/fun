class Menu:
    def __init__(self,a):
        self.a = a
    def factorial(self):
        factorials = 1
        if self.a >= 1:
            for i in range (1, self.a+1):
                factorials = factorials * i
            print ("Factorial of the given number is: ",factorials)
            
    def fib(self):
        x = 0
        b = 1
        if self.a == 1:
            print(self.a)
        else:
            print(x)
            print(b)
            for i in range(2,self.a):
                c = x + b
                x = b
                b = c
                print(c)
                
    def compute(self):
        temp=str(self.a)
        t1=temp+temp
        t2=temp+temp+temp
        comp=self.a+int(t1)+int(t2)
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
        obj1 = Menu(x)
        print(obj1.factorial())               
    elif choice == 2:
        x = int(input("enter a number to find fibonacci series : "))
        obj2 = Menu(x)
        print(obj2.fib())
    elif choice == 3:
        x = int(input("enter a number to compute : "))
        obj3 = Menu(x)
        print(obj3.compute())    
    elif choice == 4:
        print("exiting...")
    else:
        print("wrong input....")            