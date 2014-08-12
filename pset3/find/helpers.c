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

void swap();

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
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

void swap(int first, int values[])
{

}
