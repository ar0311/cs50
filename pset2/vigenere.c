#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("\nInvalid command line arguments entered.\n\n");
        printf("Usage: ./vigenere <key>\n");
        printf("where <key> is a single word.\n\n");
        return 1; 
    }
    
    string key = argv[1];
    
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("\nInvalid key entered.\n\n");
            printf("Usage: ./vigenere <key>\n");
            printf("where <key> is a single word.\n\n");
            return 1;
        }
    }
    
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }
       
    string text = GetString();
    
    if (strlen(text) == 0)
    {
        printf("\nNo input given. Exiting.\n");
        return 1;
    }
    
    int track = 0;
    
    for (int i = 0; i < strlen(text); i++ )
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int asc = 'A' + ((text[i] - 'A' + (key[track % strlen(key)] - 'A')) % 26);
                text[i] = asc;
            }
            else
            {
                int asc = 'a' + ((text[i] - 'a' + (key[track % strlen(key)] - 'A')) % 26);
                text[i] = asc;
            }
            
            track ++;
        }       
    }
    
    printf("%s\n", text);
    return 0; 
}
