#include <stdio.h>   
#include <conio.h>   
int main()  
{  
       printf(" Passed value by the User is: %c", getch()); // print a character entered by the user

    //    printf("Enter a key to exit the console screen.\n");  
        // getch();    

       /*char ch[6] = {0}; int x;  
    for ( x = 0; x < 5; x++) {  
        ch[x] = getch(); // getch() function to take input  
    }  
    printf("Received 5 character Input: %s\n", ch);*/


    /* char pw[10];  
    int x;  
    printf(" Enter password: ");  
    for (x = 0; x < 10; x++)  
    {  
        // accepts the hidden password using the getch() function  
        pw[x] = getch();  
        printf("*"); // print the input chartered in the form of *  
    }  
    pw[x] = '\0';  
    printf( "\n" );  
printf(" You have passed the hidden password: ");  
    for (x = 0; pw[x] != '\0'; x++)  
    {  
        printf("%c", pw[x]);  
}  */
// getch();
    return 0;  
}  