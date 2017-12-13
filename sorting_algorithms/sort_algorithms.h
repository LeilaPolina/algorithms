#pragma once
#include<stdlib.h>
#include<cassert>
#include<iostream>

void swap(int* a, int* b);

int* select_sort(int* arr, const int n);

int* bubble_sort(int* arr, const int n);

int* insert_sort(int* arr, const int n);

int* radix_sort(int* arr, const int n);

void merge_sort(int* arr, const int left, const int right);

void quick_sort(int* arr, const int left_index, const int right_index);