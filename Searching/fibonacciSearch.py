"""Write a Python Program to maintain Club members sorted on RollNo in ascending order Write a Function Ternary Search 
weather a Student is a club Member or Not """

def fibonacciSearch(arr, key):
    n = len(arr)
    offset = -1
    f2 = 1
    f1 = 0
    f = f1 + f2
    while(f < n - 1):
        f2 = f1
        f1 = f
        f = f1 + f2

    while(f > 1):
        i = min(offset + f1, n -1)


        if(key > arr[i]):
            f = f2
            f2 = f1
            f1 = f -f2
            offset = i
        elif(key < arr[i]):
            f = f1
            f2 = f2 - f1
            f1 = f -f2
        else:
            return i

    if(f == 1 and arr[offset + 1] == key):
        return offset + 1
    return -1

arr = [10, 20 , 30, 40, 50, 60]


rollNo = int(input("Enter Roll No : "))
index = fibonacciSearch(arr, rollNo)
print(index)



if(index != -1):
    print("Student is a Part of a Club")
else:
    print("student is Not a Member of a Club")
