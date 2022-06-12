#include <ctype.h>
#include <stdio.h>

void encrypt_message(char message[], int key)
{
    for (int i = 0; message[i] != '\n'; i++)
    {
        if (isupper(message[i]))
        {
            message[i] = ((message[i] - 'A' + key ) % 26) + 'A';
        }
    
        else if (islower(message[i]))
        {
            message[i] = ((message[i] - 'a' + key ) % 26) + 'a';
        }

        else
        {

        }
    }

    // TODO: Move to UI and remove stdio include
    printf("Encrypted message is: %s\n", message);
}

void decrypt_message(char message[], int key)
{
    for (int i = 0; message[i] != '\n'; i++)
    {
        if (isupper(message[i]))
        {
            message[i] = (((message[i] - 'A' + (26 - key)) % 26) + 'A');
        }
    
        else if (islower(message[i]))
        {
            message[i] = (((message[i] - 'a' + (26 - key)) % 26) + 'a');

        }

        else
        {

        }
    }

    printf("Decrypted message is: %s\n", message);
}

