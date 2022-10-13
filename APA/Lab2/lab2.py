import random
import time

def menu():
    while True:
        print('Alegeti optiunea:\n')
        dificulty = int(input("""
        1.Cel mai favorabil caz;\n
        2.Cazul mediu;\n
        3.Cel mai defavorabil caz;\n
        0.Iesire;\n
        Alegerea:
        """))

        len_arr=int(input("Cu cate elemente lucram? "))

        match dificulty:
            case 1:
                gen_table = [x for x in range(1, len_arr+1)]
                simulation(gen_table)
            case 2:
                gen_table = [random.randint(1, 10000) for x in range(len_arr+1)]
                simulation(gen_table)
            case 3:
                gen_table = [x for x in range(len_arr+1, 0, -1)]
                simulation(gen_table)
            case 0:
                break
            case _:
                print('Asa varianta nu este.')


def quick_sort(nums):
    def _quick_sort(items, low, high):
        if low < high:
            split_index = partition(items, low, high)
            _quick_sort(items, low, split_index)
            _quick_sort(items, split_index + 1, high)

    _quick_sort(nums, 0, len(nums) - 1)


def selectionSort(array, size):
    for s in range(size):
        min_idx = s

        for i in range(s + 1, size):
            if array[i] < array[min_idx]:
                min_idx = i
        (array[s], array[min_idx]) = (array[min_idx], array[s])
    return array


def merge(left_list, right_list):
    sorted_list = []
    left_list_index = right_list_index = 0
    left_list_length, right_list_length = len(left_list), len(right_list)

    for _ in range(left_list_length + right_list_length):
        if left_list_index < left_list_length and right_list_index < right_list_length:
            if left_list[left_list_index] <= right_list[right_list_index]:
                sorted_list.append(left_list[left_list_index])
                left_list_index += 1
            else:
                sorted_list.append(right_list[right_list_index])
                right_list_index += 1
        elif left_list_index == left_list_length:
            sorted_list.append(right_list[right_list_index])
            right_list_index += 1
        elif right_list_index == right_list_length:
            sorted_list.append(left_list[left_list_index])
            left_list_index += 1

    return sorted_list


def merge_sort(nums):
    if len(nums) <= 1:
        return nums
    mid = len(nums) // 2
    left_list = merge_sort(nums[:mid])
    right_list = merge_sort(nums[mid:])

    return merge(left_list, right_list)


def insertion_sort(list1):
    for i in range(1, len(list1)):
        a = list1[i]
        j = i - 1

        while j >= 0 and a < list1[j]:
            list1[j + 1] = list1[j]
            j -= 1

        list1[j + 1] = a
    return list1


def partition(nums, low, high):
    pivot = nums[(low + high) // 2]
    i = low - 1
    j = high + 1
    while True:
        i += 1
        while nums[i] < pivot:
            i += 1

        j -= 1
        while nums[j] > pivot:
            j -= 1

        if i >= j:
            return j
        nums[i], nums[j] = nums[j], nums[i]



def simulation(table):
    print('Tabelul introdus: \n\n', table)

    print("\n-------------------------------------------Quick sort---------------------------------------\n")
    quick_start = time.perf_counter_ns()
    quick_sort(table)
    quick_end = (time.perf_counter_ns() - quick_start) * (10 ** -9)
    print('Tabelul sortat:\n', table,"\n")
    print("Timpul de executie: ", quick_end, "s\n")

    print("\n-------------------------------------------Merge sort---------------------------------------\n")
    merge_start = time.perf_counter_ns()
    merge = merge_sort(table)
    merge_end = (time.perf_counter_ns() - merge_start) * (10 ** -9)
    print('Tabelul sortat:\n', merge,"\n")
    print("Timpul de executie: ",merge_end, "s\n")


    print("\n-------------------------------------------Selection sort---------------------------------------\n")
    selection_start = time.perf_counter_ns()
    selection = selectionSort(table, len(table))
    selection_end = (time.perf_counter_ns() - selection_start) * (10 ** -9)
    print('Tabelul sortat:\n', selection,"\n")
    print("Timpul de executie: ",selection_end, "s\n")

    print("\n-------------------------------------------Insertion sort---------------------------------------\n")
    insertion_start = time.perf_counter_ns()
    insertion = insertion_sort(table)
    insertion_end = (time.perf_counter_ns() - insertion_start) * (10 ** -9)
    print('Tabelul sortat:\n', insertion,"\n")
    print("Timpul de executie: ",insertion_end, "s\n")





menu()
