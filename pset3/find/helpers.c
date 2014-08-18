/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int min = 0;
    int mid;
    int max = n - 1;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (values[mid] == value || values[min] == value || values[max] == value)
        {
            return true;
        }
        else if (values[mid] > value) // search left
        {
            max = mid - 1;
        }
        else if (values[mid] < value) // search right
        {
            min = mid + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap(i, values);
            }
        }
        n--;
    } while (n > 0);
    
    return;
}

/**
 * Swaps two adjacent elements in a array of integers, starting with first
 */
void swap(int first, int values[])
{
    int temp;
    temp = values[first];
    values[first] = values[first + 1];
    values[first + 1] = temp;
}
