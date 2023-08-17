#!/usr/bin/python3
def is_pal(number):
    str1 = str(number)
    arr = [a for a in str1]
    le = int(len(arr) / 2)
    for i in range(le + 1):
        if arr[i] != arr[len(arr) - 1 - i]:
            return False
    return True
pal = 0
for a in range(100, 1000):
    for b in range(100, 1000):
        number = a * b
        if is_pal(number) == True:
            if pal < (a * b):
                pal = a * b;
                print(f"{pal} = {a} x {b}")

with open("102-result", "w") as file:
    file.write(str(pal))
print(pal)
