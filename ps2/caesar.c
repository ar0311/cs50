#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("\nInvalid command line arguments entered.\n\n");
        printf("Usage: ./caesar <key>\n");
        printf("where <key> is a positive numeric value.\n\n");
        return 1; 
    }
    
    int key = atoi(argv[1]);
    
    if (key <= 0)
    {
        printf("\nInvalid key entered.\n\n");
        printf("Usage: ./caesar <key>\n");
        printf("where <key> is a positive numeric value.\n\n");
        return 1;
    }
    
    printf("%d\n",key);
}
