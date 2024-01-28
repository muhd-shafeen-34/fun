a=input("enter number")
sum=0
for i in a:
    sum=sum+int(i)**len(a)
if sum==int(a):
    print("amstrong")
else:
    print("not amstrong")

