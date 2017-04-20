/**
 *_strlen - Function that
 * returns the length fo a string
 * @s: pointer to a string
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	if (*s == '\0')
	{
		return (0);
	}
		i = (_strlen(++s));
		return (i + 1);
}
