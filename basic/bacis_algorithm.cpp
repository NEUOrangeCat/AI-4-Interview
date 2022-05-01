//
// Created by Orange on 2022/4/13.
//
/*
 * 排序算法：
 *         快速排序、归并排序、桶排序、堆排序
 *
 * 查找算法：
 *         二分查找、哈希表
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;


//堆排序
void heap_adjust(vector<int>& nums, int len, int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    int max_index = index;

    if (left < len && nums[left] > nums[max_index]) max_index = left;
    if (right < len && nums[right] > nums[max_index]) max_index = right;

    if (max_index != index){
        std::swap(nums[index], nums[max_index]);
        heap_adjust(nums, len, max_index);//按照max_index进行递归是通过递归自动调整子树
    }

}

void heap_sort(vector<int>& nums){
    int size = nums.size();
    //构建堆（大顶堆）
    for(int i = size / 2 - 1; i >= 0; --i){
        heap_adjust(nums, size, i);
    }

    //调整堆
    for(int i = size - 1; i >= 1; --i){
        std::swap(nums[0], nums[i]);
        heap_adjust(nums, i, 0);//从索引0开始（堆顶）
    }
}


//二分查找
int binary_search(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (high - low ) / 2 + low;
        int mid_num = nums[mid];
        if ( target == mid_num){
            return mid;
        }else if(target < mid_num){
            high = mid - 1;
        }else if(target > mid_num){
            low = mid + 1;
        }
    }
    return -1;
}


//快速排序
void quick_sort(vector<int>& array, int start, int end){
    /*
     * 49 , 38, 65, 97, 76, 12, 27, 50
     *
     */
    if ( start < end){
        int i = start;
        int j = end;
        int temp = array[i];

        while(i < j){
            while(i < j && array[j] > temp){
                --j;
            }
            array[i] = array[j];
            while(i < j && array[i] <= temp){
                ++i;
            }
            array[j] = array[i];
        }
        //a quick sort has done!
        array[i] = temp;
        //sub
        quick_sort(array, start, i - 1);
        quick_sort(array, i + 1, end);

    }else{
        return;
    }
}


