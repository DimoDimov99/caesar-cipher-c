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

int get_action()
{
    char action[9];

    printf("Type 'encrypt' to encrypt a message or type 'decrypt' to decrypt a message\n");
    fgets(action, sizeof(action), stdin);

    for (int i = 0; action[i] != '\0'; i++)
    {
        action[i] = tolower(action[i]);
    }

    if (strcmp(action, "encrypt\n") == 0)
    {
        return ENCRYPT_CHOSEN;
    }
    else if (strcmp(action, "decrypt\n") == 0)
    {
        return DECRYPT_CHOSEN;
    }
    else
    {
        printf("Invalid choice!\n");
        return INVALID_INPUT;
    }
}

void display_result(char message[], int action)
{
    const char *actionTaken =
        (action == ENCRYPT_CHOSEN) ? "Encrypted" : "Decrypted";

    printf("%s message is: %s\n", actionTaken, message);
}
