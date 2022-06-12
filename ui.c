#include "ui.h"

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
    return INVALID_INPUT;
}

int get_message(char message[], int size)
{
    printf("Enter message:\n");

    if (fgets(message, size, stdin) == NULL)
    {
        return INVALID_INPUT;
    }

    return 0;
}

int user_choice()
{
    char choice[9];

    printf("Type 'encrypt' to encrypt a message or type 'decrypt' to decrypt a message\n");
    fgets(choice, sizeof(choice), stdin);

    // convert for the choice to not be case sensitive
    for (int i = 0; choice[i] != '\0'; i++)
    {
        choice[i] = tolower(choice[i]);
    }

    if (strcmp(choice, "encrypt\n") == 0)
    {
        return ENCRYPT_CHOSEN;
    }

    else if (strcmp(choice, "decrypt\n") == 0)
    {
        return DECRYPT_CHOSEN;
    }

    else
    {
        printf("Invalid choice!\n");
        return INVALID_INPUT;
    }
}
