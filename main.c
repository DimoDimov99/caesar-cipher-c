#include "ui.h"
#include "cipher.h"

#define SUCCESS 0
#define FAILURE -1

int main()
{
    switch (user_choice())
    {
        case ENCRYPT_CHOSEN:
            return encrypt_message();

        case DECRYPT_CHOSEN:
            return decrypt_message();

        case INVALID_INPUT:
        default:
            return FAILURE;
    }
}
