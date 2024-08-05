"""Bubble sort algorithm"""


def bubble_sort(list1):
    checking_len = len(list1) - 1
    sorted = False
    while not sorted:
        sorted = True
        for i in range(0, checking_len):
            if list1[i] > list1[i + 1]:
                sorted = False
                list1[i], list1[i + 1] = list1[i + 1], list1[1]  # swapping of the items
    return list1


'''Selection sorting algorithm'''


def selection_sort(list1):
    list2 = []
    for i in range(0, len(list1)):
        min_item = i
        for j in range(i + 1, len(list1)):
            if list1[min_item] > list1[j]:
                list1[min_item], list1[j] = list1[j], list1[min_item]
            if len(list1) == 1:
                min_item = j
        list2.append(list1[min_item])
    return list2


'''Taking input list from user'''

n = int(input("How many items in the list: "))
my_list = []
for i in range(0, n):
    a = int(input("Enter item: "))
    my_list.append(a)  # adding items to my_list

'''Displaying list'''

print("list before sorting")
print(my_list)
print("list after sorting")
print(bubble_sort(my_list))
