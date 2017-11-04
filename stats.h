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
 * @file  stats.h 
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

#ifndef __STATS_H__
#define __STATS_H__

#include <stdint.h>



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
void print_statistics(uint8_t *arr, size_t size);



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
void print_array(uint8_t *arr, size_t size);


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
uint8_t find_median(uint8_t *arr, size_t size);


/**
 * @brief find_mean
 *
 * A function that finds the average value of the given array
 *
 * @param arr -  an array of data
 * @param size - the length of array
 *
 * @return The mean value
 */
uint8_t find_mean(uint8_t *arr, size_t size);


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
uint8_t find_maximum(uint8_t *arr, size_t size);


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
uint8_t find_minimum(uint8_t *arr, size_t size);


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
uint8_t *sort_array(uint8_t *arr, size_t size);

#endif /* __STATS_H__ */

