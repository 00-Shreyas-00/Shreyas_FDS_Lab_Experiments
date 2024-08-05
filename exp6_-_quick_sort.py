"""Quick sort algorithm"""


def quick_sort(list1):
    if len(list1) <= 1:
        return list1
    else:
        pivot = list1.pop()
        greater_values = []
        lesser_values = []
        for item in list1:
            if item < pivot:
                lesser_values.append(item)
            else:
                greater_values.append(item)
        return quick_sort(lesser_values) + [pivot] + quick_sort(greater_values)


'''Taking input from user'''
n = int(input("How many items in the list: "))
my_list = []
for i in range(0, n):
    a = int(input("Enter item: "))
    my_list.append(a)  # adding items to my_list


'''Displaying list'''
print("list before sorting")
print(my_list)
print("list after sorting")
print(quick_sort(my_list))
