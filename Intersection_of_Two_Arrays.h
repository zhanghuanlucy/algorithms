//
//  Intersection_of_Two_Arrays.h
//  leetcode
//
//  Created by lucy on 16/6/5.
//  Copyright (c) 2016年 lucy. All rights reserved.
//

/**********************description**************************
 Given two arrays, write a function to compute their intersection.
 
 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 **********************************************************/

#ifndef __leetcode__Intersection_of_Two_Arrays__
#define __leetcode__Intersection_of_Two_Arrays__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int *array, int preIndex, int postIndex);
void quickSort(int *array, int preIndex, int postIndex);
int dropRepeat(int *num, int size);
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

#endif /* defined(__leetcode__Intersection_of_Two_Arrays__) */
