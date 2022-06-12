#include "ui.h"
#include "cipher.h"

#define SUCCESS 0
#define FAILURE -1

#define MESSAGE_SIZE 100

int main()
{
    char message[MESSAGE_SIZE];
    const int action = user_choice();
    const int key = get_key();
    const int message_result = get_message(message, MESSAGE_SIZE);

    if (action         == INVALID_INPUT ||
        key            == INVALID_INPUT ||
        message_result == INVALID_INPUT   )
    {
        return FAILURE;
    }

    if (action == ENCRYPT_CHOSEN)
    {
        encrypt_message(message, key);
    }
    else if (action == DECRYPT_CHOSEN)
    {
        decrypt_message(message, key);
    }

    display_result(message, action);

    return SUCCESS;
}
