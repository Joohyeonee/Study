import random

random_list = [] 
for i in range(100):
    rand_num = random.randrange(1, 100)
    random_list.append(rand_num)
    

def sequential_search(random_list, input_num):
    index_list = []
    for i in range(len(random_list)):
        if input_num == random_list[i]:
            index_list.append(i)
    return index_list

seq_list = []
for i in range(100):
    seq_num = i+1;
    seq_list.append(seq_num)

def binary_search(seq_list, input_num, start, end):
    index_list = []
    middle = int((start + end)/2)
    
    if input_num == middle:
        index_list.append(middle + 1)
    elif input_num < middle:
        binary_search(seq_list, input_num, start, middle - 1)
    else:
        binary_search(seq_list, input_num, middle + 1, end)
    return index_list