def fast_sort(a, low, high):
    for i in range(len(a)):
        pivot = int((a[low] + a[high]) / 2)
        if pivot < a[low]:
            count = a[low]
            a[low] = pivot
            pivot = count
        if pivot > a[high]:
            count = a[high]
            a[high] = pivot
            pivot = a[high]
        if high == low + 1:
            break
        fast_sort(a, low,  pivot)
        fast_sort(a, pivot,  high)
    return a
