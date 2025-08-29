import math
import os
import random
import re
import sys

#
# Complete the 'lilysHomework' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def lilysHomework(arr):
    # Write your code here
    def min_swaps(t):
        n=len(arr)
        vid={v:i for i,v in enumerate(arr)}
        swaping=0
        arr_copy=arr[:]
        for k in range(n):
            cv=t[k]
            if arr_copy[k]!=cv:
                swaping+=1
                sid=vid[cv]
                vid[arr_copy[k]]=sid
                arr_copy[sid],arr_copy[k]=arr_copy[k],arr_copy[sid]
        return swaping
    sorted_arr=sorted(arr)
    return min(min_swaps(sorted_arr),min_swaps(sorted_arr[::-1]))
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = lilysHomework(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
