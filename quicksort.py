def quicksort(s, l, r):
    i = l
    j = r
    pivot = s[i]
    while i < j:
        while s[j] > pivot:
            j -= 1

        if s[j] < pivot:
            s[i] = s[j]
            s[j] = pivot
            i += 1
            print(s)

        while s[i] < pivot:
            i += 1

        if s[i] > pivot:
            s[j] = s[i]
            s[i] = pivot
            j -= 1
            print(s)

    if l < i - 1:
        quicksort(s, l, i - 1)

    if r > i + 1:
        quicksort(s, i+1, r)


if __name__ == '__main__':
    s = [4, 0, 7, 2, 3, 6, 8, 5, 9, 1]
    print(s)
    quicksort(s, 0, 9)
    print(s)
