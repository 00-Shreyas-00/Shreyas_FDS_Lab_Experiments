"""Insertion sort algorithm"""


def insertion_sort(list1):
    for i in range(1, len(list1)):
        value_to_sort = list1[i]
        while (list1[i - 1] > value_to_sort) and i > 0:
            list1[i - 1], list1[i] = list1[i], list1[i - 1]
            i = i - 1
    return list1


"""Shell sort algorithm"""


def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

    return arr


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
print(insertion_sort(my_list))
