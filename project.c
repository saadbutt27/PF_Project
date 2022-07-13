#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>


#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

bool verifyPassword(char password[]);
bool verifyEmail(char email[]);
void bufferChecker();
void initialize();
void getUsers();

int counts=0;
char password[50];

#include "myFunctions.h"

int main()
{
    initialize();
    return 0;
}