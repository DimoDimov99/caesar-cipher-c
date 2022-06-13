#include <ctype.h>

void encrypt_message(char message[], int key)
{
    for (int i = 0; message[i] != '\n'; i++)
    {
        const char letterA = isupper(message[i]) ? 'A' :
                             islower(message[i]) ? 'a' : 0;

        if (letterA)
        {
            message[i] = ((message[i] - letterA + key ) % 26) + letterA;
        }
    }
}

void decrypt_message(char message[], int key)
{
    for (int i = 0; message[i] != '\n'; i++)
    {
        const char letterA = isupper(message[i]) ? 'A' :
                             islower(message[i]) ? 'a' : 0;

        if (letterA)
        {
            message[i] = (((message[i] - letterA + (26 - key)) % 26) + letterA);
        }
    }
}
