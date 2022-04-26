#include <stdio.h>

#include "ui.h" // TODO: Get this out of here!

char message[100];

int encrypt_message()
{
    int key = get_key();
    if (key == -1)
    {
        return -1;
    }

    printf("Enter message:\n");
    fgets(message, sizeof(message), stdin);
    for (int i = 0; message[i] != '\n'; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key ) % 26) + 'A';
        }
    

        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key ) % 26) + 'a';
        }

        else
        {

        }
    }

    printf("Encrypted message is: %s\n", message);
    return 0;
}

int decrypt_message()
{
    int key = get_key();

    if (key == -1)
    {
        return -1;
    }

    printf("Enter message:\n");
    fgets(message, sizeof(message), stdin);
    for (int i = 0; message[i] != '\n'; i++)
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (((message[i] - 'A' + (26 - key)) % 26) + 'A');
        }
    

        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (((message[i] - 'a' + (26 - key)) % 26) + 'a');

        }


        else
        {

        }
    }

    printf("Decrypted message is: %s\n", message);
    return 0;
}

