//
//  Intersection_of_Two_Arrays.c
//  leetcode
//
//  Created by lucy on 16/6/5.
//  Copyright (c) 2016年 lucy. All rights reserved.
//

#include "Intersection_of_Two_Arrays.h"

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1Size == 0 || nums2Size == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    quickSort(nums1, 0, nums1Size-1);
    quickSort(nums2, 0, nums2Size-1);
    
    int newSize1 = dropRepeat(nums1, nums1Size);
    int newSize2 = dropRepeat(nums2, nums2Size);
    
    int size3 = newSize1<newSize2 ? newSize1 : newSize2;
    int *nums3 = (int *)malloc(size3 * sizeof(int));
    memset(nums3, 0, size3);
    
    int index1=0;
    int index2=0;
    int index3=0;
    while((index1 < newSize1) && (index2 < newSize2))
    {
        if(nums1[index1] == nums2[index2])
        {
            nums3[index3++] = nums1[index1];
            index1++;
            index2++;
        }
        else if(nums1[index1] < nums2[index2])
        {
            index1++;
        }
        else
        {
            index2++;
        }
    }
    *returnSize = index3;
    return nums3;
}

int dropRepeat(int *num, int size)
{
    int i = 0;
    int j = 1;
    while(j < size)
    {
        if(num[j] == num[i])
        {
            j++;
        }
        else
        {
            num[++i] = num[j++];
        }
    }
    return i+1;
}

void quickSort(int *array, int preIndex, int postIndex)
{
    int position = 0;
    if(preIndex < postIndex)
    {
        position = partition(array, preIndex, postIndex);
        quickSort(array, preIndex, position-1);
        quickSort(array, position+1, postIndex);
    }
    else
        return;
}

int partition(int *array, int preIndex, int postIndex)
{
    int temp = array[preIndex];
    
    while(preIndex < postIndex)
    {
        while((preIndex < postIndex) && (array[postIndex] >= temp))
        {
            postIndex--;
        }
        array[preIndex] = array[postIndex];
        while((preIndex < postIndex) && (array[preIndex] < temp))
        {
            preIndex++;
        }
        array[postIndex] = array[preIndex];
    }
    array[preIndex] = temp;
    return preIndex;
}
