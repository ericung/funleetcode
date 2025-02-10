typedef struct {
    int* nums;
    int numsSize;
    int k;
} KthLargest;

int compare(const void* a, const void* b);

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *largest = malloc(sizeof(KthLargest));
    largest->k = k;

    if (numsSize >= k) {
        largest->nums = malloc(sizeof(int*)*numsSize);
        largest->numsSize = numsSize;
        memset(largest->nums, 0, sizeof(int)*(numsSize));
        qsort(nums, numsSize, sizeof(int), compare);
        memcpy(largest->nums, nums, sizeof(int)*numsSize);
    } else if (numsSize == 0) {
        largest->nums = malloc(sizeof(int*)*k);
        largest->numsSize = k;
        memset(largest->nums, -10000, sizeof(int)*k);
    } else {
        largest->nums = malloc(sizeof(int*)*k);
        largest->numsSize = k;
        qsort(nums, numsSize, sizeof(int), compare);
        memset(largest->nums, -10000, sizeof(int)*k);
        memcpy(largest->nums, nums, sizeof(int)*numsSize);
        qsort(largest->nums, k, sizeof(int), compare);
    }
    

    return largest;
}

int kthLargestAdd(KthLargest* obj, int val) {
    int i = 0;
    int j = 1;

    while (i < obj->numsSize) {
        if (obj->nums[i] < val) {
            i++;
        } else {
            break;
        }
    }

    while (j < i) {
        obj->nums[j-1] = obj->nums[j];
        j++;
    }

    if (i > 0) {
        obj->nums[i-1] = val;
    }

    return (obj->nums)[(obj->numsSize) - (obj->k)];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->nums);
    free(obj);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/