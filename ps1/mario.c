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
    int blocks = 2;
    // below is leftovers from trying to use masks instead of loops to print the pyramid
    //
    //while (height > 0)
    //{
    //        printf("%*s""%*s\n", (height - 1), "", blocks, "#");
    //        height--;
            //blocks++;

            //printf("%*s\n", blocks, "#");
    //}
    while (height > 0)
    {
        
}

