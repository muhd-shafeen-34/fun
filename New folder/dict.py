# dict_1={1:"aa",2:"bb",3:"cc"}
# dict_2 ={"a":11,"b":22,"c":33}
# dict_3 = {"w":"ee","e":"cc"}
# dict_4 = {}
# for d in (dict_1,dict_2,dict_3):
#     dict_4.update(d)
# print(dict_4)
# dict_1={1:"aa",2:"bb",3:"cc"}
# dict_2 ={"a":11,"b":22,"c":33}
# dict_3=dict_1.copy()
# dict_3.update(dict_2)
# print(dict_3)

# n = input("enter a string which has repeated letters")
# n.upper()
# print("orginal string is: ",n)
# k='$'
# res= n[0]+n[1:].replace(n[0],k)
# print(res)
#sort a dictionary in accending and descending order



my_dict = {'b': 2, 'a': 1, 'c': 3}
sorted_list = sorted(my_dict.items())

sorted_dict = {}
for key, value in sorted_list:
    sorted_dict[key] = value

print(sorted_dict)
print(sorted_list)