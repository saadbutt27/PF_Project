// Defining some keyboard buttons with their ASCII values
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

// Function for Email Authorization
bool emailAuth(char str[])
{
    // a 2D array which will read from our text file
    char useremails[50][50];
    char userpass[50][50];
    int i = 0;
    int j = 0;
    FILE *fptr;
    char temp;

    bool flag = false;
    bool flag2 = false;

    fptr = fopen("myfile.txt", "r");

    for (i = 0; i < 50; i++)
    {
        counts++;
        j = 0;
        while (1)
        {
            // getc is a character input function, reads every chearacter from the file
            temp = getc(fptr);
            if (temp == EOF)
            {
                flag2 = true;
                break;
            }
            else if (temp == ':')
            {
                useremails[i][j] = '\0';
                break;
            }

            useremails[i][j] = temp;
            j++;
        }

        if (flag2)
        {
            break;
        }

        j = 0;
        while (1)
        {
            temp = getc(fptr);

            if (temp == '\n')
            {
                userpass[i][j] = '\0';
                break;
            }
            userpass[i][j] = temp;

            j++;
        }
    }
    fclose(fptr);

    int c;
    for (c = 0; c < 50; c++)
    {
        if ((strcmp(str, useremails[c])) == 0 && (strcmp(password, userpass[c])) == 0)
        {
            flag = true;
            break;
        }
    }

    if (flag)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function for Email Validation
bool verifyEmail(char email[])
{
    int i, j;
    char pattern[12] = "@email.com";
    bool flag = false;
    bool flag2 = false;
    for (i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            flag = true;
            for (j = 0; j < strlen(pattern); j++)
            {
                if (pattern[j] != email[i])
                {
                    flag = false;
                    flag2 = true;
                    break;
                }
                i++;
            }
        }
        else
        {
            flag = false;
        }
        if (flag2)
        {
            break;
        }
    }
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function for Password Analyzing
bool verifyPassword()
{
    int i = 0;
    bool L = 0, a = 0, A = 0, D = 0, S = 0;
    for (i = 0; password[i]; i++)
    {
        if (strlen(password) >= 8 && strlen(password) <= 19)
        {
            L = 1;
        }
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            a = 1;
        }
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            A = 1;
        }
        if (password[i] >= '0' && password[i] <= '9')
        {
            D = 1;
        }
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') ||
            (password[i] >= '[' && password[i] <= '`') || (password[i] >= '!' && password[i] <= '/') ||
            (password[i] >= '{' && password[i] <= '_'))
        {
            S = 1;
        }
    }

    if (L == 1 && a == 1 && A == 1 && D == 1 && S == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Password Recommender
char *passwordRecomender(char *str)
{
    srand(((unsigned int)time(NULL)));
    int i = 0;
    char passLetters[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789~`!@#$%^&*()_+-={}|[]\\:\"'<;>?,./";
    for (i = 0; i < 15; i++)
    {
        str[i] = passLetters[rand() % strlen(passLetters)];
    }
    str[i] = '\0';
    return str;
}

bool passwordGetter()
{
    int i;
    char ch;
    bool result = false;
    for (i = 0; result == false;)
    {
        printf("\nEnter your password: ");
        while (1)
        {
            ch = getch(); // getch() is a function that holds your console until a conditiion is achieved
            if (ch == ENTER)
            {
                password[i] = '\0';
                break;
            }
            else if (ch == BKSP)
            {
                if (i > 0)                  
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (ch == TAB || ch == SPACE)
            {
                continue; // it'll jump over and begin respective iteration again
            }
            else
            {
                password[i] = ch;
                i++;
                printf("*");
            }
        }
        result = verifyPassword();
        if (result)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// Encryption & Decryption
char *encryptionDecryption(char *str)
{
    int i, a;

    printf("Choose accordingly:\n");
    printf("1. Encrypyt data\n");
    printf("2. Decrypt data\n");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        for (i = 0; (i < 50 && str[i] != '\0'); i++)
            str[i] = str[i] + 5; // using 5 to add up in ascii value to enrypt the input string by user

        printf("\nEncrypted string: ");
        return str;
        break;

    case 2:
        for (i = 0; (i < 50 && str[i] != '\0'); i++)
            str[i] = str[i] - 5; // using 5 to add up in ascii value to decrypt the input string by user

        printf("\nDecrypted string: ");
        return str;
        break;

    default:
        return "false";
    }
}

// Buffer Overflow Checker
void bufferChecker()
{
    char arr[15] = "saadsaad12";
    int i = 0;

    bool buff = false;

    while (buff == false)
    {
        printf("Enter password:\n");
        scanf("%s", arr);

        int length = strlen(arr);

        if (length > 15)
        {
            printf("\nBuffer overflow occured! Enter password of size arround 15\n");
            char password1[17];
            passwordRecomender(password1);
            printf("Password Suggestion: %s\n", password1);
            arr[0] = '\0';
            fflush(stdin);
            continue;
        }
        buff = true;
    }
    if (buff)
    {
        printf("Password is okay: %s", arr);
    }
}

void initialize()
{
    int select;
    int input;
    char fname[30];
    char lname[30];
    char email[30];
    char ch;
    int i = 0;
    bool check = false;
    bool result = false;
    bool flag = false;
    bool flag3 = false;
    char password1[15];
    FILE *fptr;
    char arr[10] = "saadsaad12";
    bool buff = false;

    for (i = 0; i < 54; i++)
    {
        printf("*");
    }
    printf("\n\n######## Welcome to Cyber Security Management ########\n\n");
    for (i = 0; i < 54; i++)
    {
        printf("*");
    }
    while (select != 0)
    {
        printf("\n");
        printf("1. Sign up\n");
        printf("2. Log in\n");
        printf("3. Encryption and Decryption\n");
        printf("4. Password Recommender\n");
        printf("5. Buffer Overflow\n");
        printf("0. Exit\n");

        if (0 == scanf("%d", &select))
        {
            printf("Invalid Input");
            fflush(stdin);
            continue;
        }
        switch (select)
        {
        // Sign Up
        case 1:

            printf("Enter the required information\n");
            while (!flag3)
            {
                flag3 = true;
                printf("Enter your first name: ");
                scanf("%s", fname);
                for (i = 0; i < strlen(fname); i++)
                {
                    if ((fname[i] >= 'a' && fname[i] <= 'z') || (fname[i] >= 'A' && fname[i] <= 'Z'))
                    {
                    }
                    else
                    {
                        printf("Invalid Entry\n");
                        flag3 = false;
                        break;
                    }
                }
            }
            flag3 = false;
            while (!flag3)
            {
                flag3 = true;
                printf("Enter your last name: ");
                scanf("%s", lname);
                for (i = 0; i < strlen(lname); i++)
                {
                    if ((lname[i] >= 'a' && lname[i] <= 'z') || (lname[i] >= 'A' && lname[i] <= 'Z'))
                    {
                    }
                    else
                    {
                        printf("Invalid Entry\n");
                        flag3 = false;
                        break;
                    }
                }
            }

            // An Iteration for E-mail Address
            for (i = 0; check == false;)
            {
                printf("Enter an e-mail address: ");
                scanf("%s", email);
                // comparison between email address's condition
                if ((strcmp(email, "@email.com")) != 0)
                {
                    // A function to check validation of an e-mail
                    check = verifyEmail(email);
                }
                // A function for password getting in secured form and to analyze it
                if (check)
                {
                    if (passwordGetter())
                    {
                        strcat(email, ":");
                        strcat(password, "\n");
                        fptr = fopen("myfile.txt", "a");
                        fputs(email, fptr);
                        fputs(password, fptr);
                        fclose(fptr);
                        break;
                    }
                    else
                    {
                        printf("\nPassword is not Strong Enough\n"
                               "Passord must be greater than 7 and less than  to 20 characters\n"
                               "Password must include lower & upper case letters\n"
                               "Password must contain digits\n"
                               "Password must contain special characters\n");
                        passwordGetter();
                    }
                }
            
                else
                {
                    printf("\nEmail is not valid");
                    verifyEmail(email);
                }
                // if (check && passwordGetter())
                // {
                //     // Filing process for e-mail and password signed up by users
                //     strcat(email, ":");
                //     strcat(password, "\n");
                //     fptr = fopen("myfile.txt", "a");
                //     fputs(email, fptr);
                //     fputs(password, fptr);
                //     fclose(fptr);
                //     break;
                // }
                // else
                // {
                //     printf("\nPassword is not Strong Enough\n"
                //            "Passord must be greater than 7 and less than  to 20 characters\n"
                //            "Password must include lower & upper case letters\n"
                //            "Password must contain digits\n"
                //            "Password must contain special characters\n");
                //     passwordGetter();
                // }
            }

        // User's Information Display
        printf("\nFirst Name: %s", fname);
        printf("\nLast Name: %s", lname);
        printf("\nE-mail: %s", email);
        printf("\nPassword: %s", password);
        printf("\n**********"
               " You can now log in "
               "**********\n");
        break;

    // Log In
    case 2:
        printf("Enter your log in details\n");

        // Loop to check if E-mail is authenticated or not
        while (1)
        {
            printf("Enter Email: ");
            scanf(" %s", email);
            // Function for getting password and to analyze it
            passwordGetter();
            // Function for authorization of e-mail from our collected data in the file
            if (emailAuth(email))
            {
                flag = true;
                break;
            }
            else
            {
                printf("\nUser UnAuthenticated");
                exit(0);
            }
        }

        if (flag)
        {
            printf("\n**********"
                   "Logged In"
                   "**********\n");
            // User Authorization
            // If logged in by an admin
            char admin[20] = "admin123@email.com";
            if ((strcmp(admin, email)) == 0)
            {
                for (i = 0; i < 21; i++)
                {
                    printf("*");
                }
                printf("\n### Welcome Admin ###\n");
                for (i = 0; i < 21; i++)
                {
                    printf("*");
                }
                while (input != 0)
                {
                    printf("\n1. Check for users\n");
                    printf("2. Users updates\n");
                    printf("3. Daily updates\n");
                    printf("4. Business messages\n");
                    printf("5. Assigned Tasks\n");
                    printf("6. Adding features\n");
                    printf("7. Sign Out\n");

                    if (0 == scanf("%d", &input))
                    {
                        printf("Invalid Input");
                        fflush(stdin);
                        continue;
                    }
                    switch (input)
                    {
                    case 1:
                        printf("************** CHECK FOR USERS **************\n");
                        // Function to check user's details by admin
                        getUsers();

                        break;

                    case 2:
                        printf("************** USERS UPDATE **************\n");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker.\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 3:
                        printf("************** Your Daily update regarding your work **************\n");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker.\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 4:
                        printf("*********** YOUR BUSINESS MESSAGES ARE ***********\n");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like .\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 5:
                        printf("\n");
                        printf("************* YOU HAVE FOLLOWING ASSIGNED TASK *************");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker .\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 6:
                        printf("************* ADDING FEATURES *************\n");
                        printf("1.Evaluate the current product offering.\n");
                        printf("2.Perform market research.\n");
                        printf("3.Duplicate records.\n");
                        printf("4.Bulk edit and bulk send records\n");
                        printf("5.Customize your report.\n");

                        break;

                    case 7:
                        printf("Signed Out\n");
                        initialize();
                        break;

                    default:
                        printf("Invalid Input");
                    }
                }
            }
            else
            {
                // If logged in by a user
                for (i = 0; i < 20; i++)
                {
                    printf("*");
                }
                printf("\n### Welcome User ###\n");
                for (i = 0; i < 20; i++)
                {
                    printf("*");
                }
                while (input != 0)
                {
                    printf("1. Daily updates\n");
                    printf("2. Business messages\n");
                    printf("3. Assigned Tasks\n");
                    printf("4. Sign Out\n");

                    if (0 == scanf("%d", &input))
                    {
                        printf("Invalid Input");
                        fflush(stdin);
                        continue;
                    }
                    switch (input)
                    {
                    case 1:
                        printf("**************\n");
                        printf(" Your Daily update regarding your work\n");
                        printf("**************\n");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker.\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 2:
                        printf("***********\n");
                        printf(" YOUR BUSINESS MESSAGES ARE \n");
                        printf("***********\n");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like .\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 3:
                        printf("*************\n");
                        printf("  YOU HAVE FOLLOWING ASSIGNED TASK ");
                        printf("*************\n");
                        printf("1.Lorem Ipsum is simply dummy text of the printing and typesetting industry.\n");
                        printf("2.Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.\n");
                        printf("3.It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.\n");
                        printf("4.It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker .\n");
                        printf("5.Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites .\n");

                        break;

                    case 4:
                        printf("Signed Out\n");
                        initialize();
                        break;

                    default:
                        printf("Invalid Input");
                    }
                }
            }
        }
        break;

    // Encryption & Decryption
    case 3:
        printf("Encryption & Decryption\n");
        char str[50];
        char output[50];
        printf("Enter a string: \n");
        scanf(" %[^\n]s", str);
        strcpy(output, encryptionDecryption(str));
        if ((strcmp(output, "false")) == 0)
        {
            printf("\nInvalid Input\n");
        }
        else
        {
            printf("%s", str);
        }
        break;

    case 4:
        printf("Recommended Password:  %s", passwordRecomender(password1));
        break;

    case 5:
        bufferChecker();
        break;

    case 0:
        exit(0);

    default:
        printf("\nInvalid Input");
        continue;
    }
}
}

void getUsers()
{
    char useremails[50][50];
    char userpass[50][50];
    int i = 0;
    int j = 0;
    FILE *fptr;
    char temp;

    bool flag = false;
    bool flag2 = false;

    fptr = fopen("myfile.txt", "r");

    for (i = 0; i < 50; i++)
    {
        j = 0;
        while (1)
        {
            // getc is a character input function, reads every chearacter from the file
            temp = getc(fptr);
            if (temp == EOF)
            {
                flag2 = true;
                break;
            }
            else if (temp == ':')
            {
                useremails[i][j] = '\0';
                break;
            }

            useremails[i][j] = temp;
            j++;
        }

        if (flag2)
        {
            break;
        }

        j = 0;
        while (1)
        {
            temp = getc(fptr);

            if (temp == '\n')
            {
                userpass[i][j] = '\0';
                break;
            }
            userpass[i][j] = temp;

            j++;
        }
    }
    fclose(fptr);

    counts--;

    for (i = 0; i < counts; i++)
    {

        printf("%s\n", useremails[i]);
    }
}