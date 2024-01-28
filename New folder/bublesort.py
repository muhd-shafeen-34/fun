
a=[10,30,20,6,4]
for i in range(0,len(a)):
    for j in range(0,len(a)-i-1):
        if a[j]>a[j+1]:
            b = a[j]
            a[j] = a[j+1]
            a[j+1] = b
print(a)
 
# s = {10,20,100,20,'rama',25}
# for i in s:
#     print(i)
# for j in s:
#     print(j)

# a={10,20,3,4,2,6}
# b={20,11,3,2,10,6}
# c=a.intersection(b)
# print(c)
# a.difference(b)
# print(a)
