
#include "../include/libip.hpp"


void print_arr_int(uint32_t *arr, uint32_t size)
{
    int i;

    for(i = 0; i < size; i++)
        cout << arr[i]  << " " ;
    cout << endl;

}



int main(void)
{
    

    unsigned int i = 0;
    char *value;
    
    value = decimal_to_hex(i, UP);

    cout << "voici la valeur hex: " << value << endl;

    free(value);
    return(0);
}