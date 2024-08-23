def quicksort(arr):
    if len(arr) <= 1:
        return arr

    pivot_index = len(arr) // 2
    pivot = arr[pivot_index]
    left, middle, right = [], [], []

    for i in arr:
        if i < pivot:
            left.append(i)
        elif i == pivot:
            middle.append(i)
        else:
            right.append(i)

    return quicksort(left) + middle + quicksort(right)

# Example usage:
my_array = [6, 5, 8, 9, 3, 6, 15, 12, 16]
sorted_array = quicksort(my_array)
print(sorted_array)
