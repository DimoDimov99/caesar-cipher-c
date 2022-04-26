#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "cipher.h"

int get_key()
{
    int number;
    printf("Enter key: \n");
    if (scanf("%d", &number) == 1 && (number > 0 && number < 26))
    {
        // while (getchar() != '\n')
        // { }
        // return number;

        if (getchar() == '\n')
        {
            return number;
        }
    }

    printf("Invalid input\n");
    return -1;
}

int user_choice()
{
    char choice[9];

    printf("Type 'encrypt' to encrypt a message or type 'decrypt' to decrypt a message\n");
    fgets(choice, sizeof(choice), stdin);

    // convert for the choice to not be case sensitive
    for (int i = 0; i < sizeof(choice); i++)
    {
        choice[i] = tolower(choice[i]);
    }

    int decrypt_choice = strcmp(choice, "decrypt\n");
    int encrypt_choice = strcmp(choice, "encrypt\n");

    if (decrypt_choice == 0)
    {
        return decrypt_message();
    }

    else if (encrypt_choice == 0)
    {
        return encrypt_message();
    }

    else
    {
        printf("Invalid choice!\n");
        return -1;
    }
}
