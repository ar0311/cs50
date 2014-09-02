#include <stdio.h>
#include <cs50.h>

int main(void)
{ 
    int height;

    while (height>23 || height<=0) 
    {
        printf("Height: ");
        height = GetInt();
        
        if (height == 0)
        {
            return 0;
        }
    }

    for(int i = 0; i < height; i++) 
	{
	
        for(int j = 0; j < height-i-1; j++)
        {
            printf(" ");
        }
        
		for(int k = 0; k < i+2; k++)
		{
			printf("#");
		}
		
		printf("\n");
	}
	
	return 0;    
}

