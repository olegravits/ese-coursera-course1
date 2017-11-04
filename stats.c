/******************************************************************************
 * Copyright (C) 2017 by Oleg Ravits
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Oleg Ravits are not liable for any misuse of this material. 
 *
 *****************************************************************************/

/*
 * @file stats.c 
 * @brief assignment 1
 *
 * A simple program to analyze an array of unsigned char data items and report analytics
 * on the maximum, minimum, mean, and median of the data set. 
 * In addition, we need to reorder this data set from large to small.
 * All statistics will be rounded down to the nearest integer.
 * After analysis and sorting is done, we will need to print that data to the screen.
 *
 * @author Oleg Ravits
 * @date 2017-11-2
 *
 */


#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

void main() {
    uint8_t test[SIZE] =     { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

    print_statistics(test, SIZE);

}


/* Implementation File Code Here */


/**
 * @brief print_statistics
 *
 * A function that prints the statistics of an array 
 * including minimum, maximum, mean, and median
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return none
 */
void print_statistics(uint8_t *arr, size_t size){
    size_t i;
    uint8_t *s_arr; /*s_arr: is temporary to be sorted array*/
    
    s_arr = (uint8_t *)malloc(sizeof(uint8_t)*SIZE);

    if(!s_arr){
	printf("print_statistics(): malloc error \n");
    	return;
    }

    for(i=0; i < SIZE; i++){
	*(s_arr + i) = *(arr + i);
    }

    s_arr = sort_array(s_arr, SIZE);

    print_array(arr, SIZE);

    //print_array(s_arr, SIZE);

    printf("-------------------\n");
     printf("Statistics report:\n");
//    printf("(rounded down to \nthe nearest integer.)\n");
    printf("-------------------\n");
    printf("The median  value of array: %u \n",find_median(s_arr,SIZE));
    printf("The average value of array: %u \n",find_mean(s_arr,SIZE));
    printf("The maximum value of array: %u \n",find_maximum(s_arr,SIZE));
    printf("The minimum value of array: %u \n",find_minimum(s_arr,SIZE));
    printf("\n");

    free(s_arr); //deallocating memory of temporary array    
}


/** 
 
 * @brief print_array
 *
 * A function prints the array to the screen
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return none
 */
void print_array(uint8_t *arr, size_t size){
    size_t i;
    printf("\n------------- \n");
    printf("The array is: \n");
    printf("------------- \n");
    for(i = 0; i < size; i++){
	if ((i > 0) && (i % 20 == 0))
	    printf("\n");
	printf("%3u ", *(arr + i) );
    }
    printf("\n\n");
}


/**
 * @brief find_median
 *
 * A function that finds the median value 
 * of the sorted array with descending order
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return The value of median
 */
uint8_t find_median(uint8_t *s_arr, size_t size){
    return s_arr[size/2];
}


/**
 * @brief find_mean
 *
 * A function that finds the average value of the given array
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return The mean value rounded down to the nearest integer.
 */
uint8_t find_mean(uint8_t *s_arr, size_t size){
    uint32_t mean = 0; /*uint32_t type to avoid overflow*/

    if (s_arr == NULL)
	return 0;

    if (size <= 0){
	size = 1;
    }

    for(int i = 0; i < size; i++){
	mean += s_arr[i];
    }

    return (uint8_t)(((((float)mean)/size)*2+1)/2); //rounding down to the nearest integer
}


/**
 * @brief find_maximum
 *
 * A function that finds the maximum value
 * of the sorted array with descending order
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return The maximum value
 */
uint8_t find_maximum(uint8_t *s_arr, size_t size){
    return s_arr[0];
}


/**
 * @brief find_minimum
 *
 * A function that finds the minimum value 
 * of the sorted array with descending order
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return The minimum value
 */
uint8_t find_minimum(uint8_t *s_arr, size_t size){
    return s_arr[size-1];
}


/**
 * @brief sort_array
 *
 * Function that sorting (in-place) the array with 
 * descending order by insertion sorting algorithm
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return The pointer to the sorted array
 */
uint8_t *sort_array(uint8_t *arr, size_t size){
    size_t i,j;
    uint8_t v;

    for(i = 1; i < size; i++){
	v = arr[i];
	j = i;
	while(arr[j-1] < v && j >= 1){
	    arr[j] = arr[j-1];
	    j--;
	}
	arr[j] = v;
    }

    return arr;
}




