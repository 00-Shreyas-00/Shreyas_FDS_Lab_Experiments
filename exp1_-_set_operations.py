# TESTING ARRAYS. TO VERIFY IF FUNCTIONS BELOW WORK
all_people = ['Shreyas', 'Soham', 'Vidhi', 'Sonal', 'Mugdha', 'Siddharth', 'Vedant', 'Himanshu', 'Bhoumik', 'Amol']
cric = ['Shreyas', 'Soham', 'Vidhi', 'Himanshu', 'Amol']
bad = ['Shreyas', 'Vidhi', 'Mugdha', 'Vedant', 'Bhoumik']
foot = ['Soham', 'Vidhi', 'Siddharth', 'Vedant', 'Bhoumik', 'Amol']


# TAKING INPUT FROM USER. UNCOMMENT IF YOU WANT YOUR OWN INPUTS
# cric=[]
# n=int(input("Enter number of students for cricket: "))
# for i in range(n):
#     cric.append(input("Enter the name of student: "))

# bad=[]
# o=int(input("Enter number of students for badminton: "))
# for i in range(o):
#     cric.append(input("Enter the name of student: "))

# foot=[]
# p=int(input("Enter number of students for football: "))
# for i in range(p):
#     cric.append(input("Enter the name of student: "))


# defining function to find students who play cricket and badminton
def q1(l1,l2):
    l = []
    for i in l1:
        if i in l2:
            l.append(i)
    return l


# defining function to find students who play cricket or badminton but not both
def q2(l1,l2):
    l = []
    for i in l1:
        if i not in l2:
            l.append(i)
    for i in l2:
        if i not in l1:
            l.append(i)
    return l


# defining functon to find number of students who play neither cricket nor badminton
def q3(l1,l2,l3):
    l = []
    for i in l3:
        if i not in l2:
            if i not in l1:
                l.append(i)
    return len(l)


# defining function to find number of students who play cricket and football but not badminton
def q4(l1,l2,l3):
    l = []
    for i in l1:
        if i in l3:
            if i not in l2:
                l.append(i)
    return len(l)


print(q1(cric,bad))
print(q2(cric,bad))
print(q3(cric,bad,foot))
print(q4(cric,bad,foot))
