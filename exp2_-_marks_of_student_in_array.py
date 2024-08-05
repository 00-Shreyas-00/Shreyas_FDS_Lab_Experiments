# TESTING ARRAY
students = [
 ['Shreyas', 60.5],
 ['Soham', 60.5],
 ['Vidhi', 80.4],
 ['Sonal', 79.0],
 ['Mugdha', 85.5],
 ['Siddharth', -1],
 ['Vedant', 83.7],
 ['Himanshu', 88.8],
 ['Bhoumik', 50.0],
 ['Amol', -1]
]


# # COMMENT IN IF YOU WANT TO TYPE
# # ALSO COMMENT OUT THE FUNCTION CALL
# def getStudents():
#     n = int(input("Enter number of students: "))
#     students = []
#     for i in range(n):
#         name = input("Enter name of student: ")
#         marks = float(input(f"Enter {name}'s marks: "))
#         students.append([name, marks])
#     return students


def average(l):
    present = []
    for i in range(len(l)):
        if i == -1:
            continue
        else:
            present.append(l[i][1])
    sum = 0
    for i in present:
        sum = sum+i
    return sum/len(present)


def maxmin(l):
    max = l[0][1]
    min = l[0][1]

    for i in range(len(l)):
        if l[i][1] > max:
            max = l[i][1]
    for i in range(len(l)):
        if l[i][1] == -1:
            continue
        if l[i][1] < min:
            min = l[i][1]
    return max,min


def absent(t):
    absent = []
    for i in range(len(t)):
        if t[i][1] == -1:
            absent.append(t[i][1])
    return len(absent)


def highestfrequency(t):
    freq_dict = {}
    for i in range(len(t)):
        if t[i][1] == -1:
            continue
        if t[i][1] in freq_dict:
            freq_dict[t[i][1]] += 1
        else:
            freq_dict[t[i][1]] = 1
    return max(freq_dict, key=freq_dict.get)


# # COMMENT OUT THE FUNCTION CALL BELOW IF YOU WANT TO TYPE
# students=getStudents()

print(f'Highest score of class: {average(students)}')
print(f'Lowest score of class: {maxmin(students)}')
print(f'Absent for test: {absent(students)}')
print(f'Marks scored by most students: {highestfrequency(students)}')
