#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

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
    
    printf("\nPlease enter your plaintext: ");   
    string plaintext = GetString();
    int len = strlen(plaintext);
    
    if (len == 0)
    {
        printf("\nNo input given. Exiting.\n");
        return 1;
    }
    
    string ciphertext = plaintext;
    for (int i = 0; i < len; i++ )
    {
        int asc = ciphertext[i] + key;
        ciphertext[i] = asc;        
    }
    
    printf("%s\n", ciphertext);
    
    
    
}
