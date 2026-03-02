#include "../include/libip.hpp"

void process_decimal_to_hex(char *buffer,size_t n, int i, int up)
{
    char value[] = "0123456789abcdef";
    char value_up[] = "0123456789ABCDEF";

    if(n == 0)
        return;

    if(up == UP)
        buffer[i] = value_up[n % 16];
    else
        buffer[i] = value[n % 16];

    process_decimal_to_hex(buffer, n / 16, i - 1, up);
 }

void size_decimal_to_hex(size_t n, size_t *size)
{
    if(n == 0)
        return;
    *size += 1;
    size_decimal_to_hex(n / 16, size);

}

char  *decimal_to_hex(size_t n, int up)
{
    size_t size;
    char *buffer;

    size = 0;
    if(n == 0)
        size = 1;
    else
        size_decimal_to_hex(n, &size);
    buffer = (char *)malloc(sizeof(char) * (size + 1));
    if(!buffer)
        return(NULL);
    buffer[size] = '\0';
    if(n == 0)
    {
        buffer[0] = '0';
        return(buffer);
    }
    process_decimal_to_hex(buffer, n, size - 1, up);
    return(buffer);
}