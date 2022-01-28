
/*
 * All of your code goes in here. You need to finish these functions.
 */
#include <limits.h>

int maximum(int *nums, int len) {
    int max = nums[0];
    for (int i = 0; i < len; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int sum_positive(int *nums, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) {
            sum += nums[i];
        }
    }
    return sum;
}

int helper_max(int a, int b) {
    int max = a;
    if (b > a) {
        max = b;
    }
    return max;
}

int helper_add(int a, int b) {
    int result = 0;
    if (a > 0) {
        result += a;
    }
    if (b > 0) {
        result += b;
    }
    return result;
}

int helper_count(int a, int b) {
    int neg_count;
    if (b < 0) {
        a += 1;
    }
    neg_count = a;
    return neg_count;
}

int reduce(int *nums, int len, int (*f)(int,int), int initial){
    int value = initial;
    for (int i = 0; i < len; i++) {
        value = f(value, nums[i]);
    }
    return value;
}

int maximum_with_reduce(int *nums, int size) {
    return reduce(nums, size, helper_max, INT_MIN);
}

int sum_positive_with_reduce(int *nums, int size) {
    return reduce(nums, size, helper_add, 0);
}

int count_negative_with_reduce(int *nums, int size) {
    return reduce(nums, size, helper_count, 0);
}
