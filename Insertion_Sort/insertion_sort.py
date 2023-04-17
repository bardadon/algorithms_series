def insertion_sort(arr):

    for j in range(1, len(arr)):
        key = arr[j]
        i = j - 1

        while arr[i] > key and i >= 0:
            arr[i+1] = arr[i]
            i -= 1

        arr[i+1] = key

    return arr

arr = [5, 2, 4, 6, 1]
sorted_array = insertion_sort(arr)
print(sorted_array)
