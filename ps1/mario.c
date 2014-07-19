#include <stdio.h>
#include <cs50.h>

int main(void)
{ 
    int height;
    while (height>23 || height<=0) 
    {
        printf("Height: ");
        height = GetInt();
    }
    // below is leftovers from trying to use masks instead of loops to print the pyramid
    //
    //while (height > 0)
    //{
    //        printf("%*s""%*s\n", (height - 1), "", blocks, "#");
    //        height--;
            //blocks++;

            //printf("%*s\n", blocks, "#");
    //}
    
    for(int i = 0; i < height; i++) 
	{
		// print the spaces
        for(int j = 0; j < height-i-1; j++)
        {
            printf(" ");
        }
        // print the hashes
		for(int k = 0; k < i+2; k++)
		{
			printf("#");
		}
		printf("\n");
	}
	return 0;    
}

