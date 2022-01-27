
# homework 2: functions, arrays, and pointers

This is the design document for homework 2.

# how the program works

This program consists of a variety of functions that deal with arrays of integers. 

In the `maximum`  function, it takes an array of ints and its length, then returns the maximum element of that array.

The `sum_positive` function will take an array of ints and its length, then returns the sum of all of the elements of that array that are positive.

The `reduce` function combines all of the elements in an array with a specified function then it maintains a current cumulative value and applies the function to the cumulative value and each element of the given array. 

We then have a function for finding the maximum element of an array, summing all positive elements of an array, and counting all negative numers in an array, all with the `reduce` function.

# pseudocode

```
function int maximum(int *nums, int len)
    initialize max = nums[0]
    for (int i = 0; i < len; i++)
        if nums[i] greater than max
            change max to nums[i]
    return max

function int sum_positive(int *nums, int len)
    initialize sum = 0
    for (int i = 0; i < len; i++)
        if nums[i] > 0
            sum += nums[i]
    return sum

function int helper_max(int a, int b)
    initialize UINT_MAX max = a
    if b > a
        max = b
    return a

function int helper_add(int a, int b)
    initialize result = 0
    if a > 0
        result += a
    if b > 0
        result += b
    return result

function int helper_count(int a, int b)
    neg_elems = 0
    if a < 0
        neg_elems += 1
    if b < 0
        net_elems += 1 
    return neg_elems

function int reduce(int *nums, int len, int (*f)(int,int), int initial)
    value = initial
    for (int i = 0; i < len; i++)
        value = f(value, nums[i])
    return initial

function int maximum_with_reduce(int *nums, int size)
    return reduce(int *nums, int len, helper_max(nums, size), int initial)

function int sum_positive_with_reduce(int *nums, int size)
    return reduce(int *nums, int len, helper_add(nums, size), int initial)

function int count_negative_with_reduce(int *nums, int size)
    return reduce(int *nums, int len, helper_count(nums, size), int initial)

```
