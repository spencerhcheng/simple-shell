#include "shell.h"

/**
 * _strcmp - Function that compares two strings,
 * s1 and s2. It returns integer displaying
 * difference in value between the two strings.
 * Compares the first n bytes of s1 and s2.
 * @s1: string one
 * @s2: string two
 * Return: integer difference
 */

int _strcmp(const char *s1, const char *s2)
{
        int i = 0;

        while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        {
                i++;
        }
        if (s1[i] != s2[i])
        {
                return (s1[i] - s2[i]);
        }
        return (0);
}

