#include "shell.h"

/**
 * *_strncpy - concatenates two strings
 * up to n bytes of src
 * @dest: string arguement
 * @src: string arguement
 * @n: integer value of bytes to pring src
 * Return: final string
 */

char *_strncpy(char *dest, char *src, int n)
{
        int i = 0;

        while (src[i] != '\0' && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }
        return (dest);
}
