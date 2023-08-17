def is_pal(number):
    str1 = str(number)
    arr = [a for a in str1]
    le = int(len(arr) / 2)
    for i in range(le):
        if arr[i] != arr[len(arr) - 1 - i]:
            return False
    return True
pal = 0
for a in range(100, 1000):
    for b in range(100, 1000):
        if is_pal(a * b) == True:
            if pal < (a * b):
                pal = a * b;
                print(f"{pal} = {a} × {b}")

