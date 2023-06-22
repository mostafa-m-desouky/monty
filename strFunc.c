#include "monty.h"

/**
 * compare_str - copy of strcp function .
 * @str1: string one
 * @str2: string tow
 * Return: return 0 if str1 is == to str2.
 */
int compare_str(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;
	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}

/**
 * seaRch - copy of strsch function
 * @str: string
 * @chart: character
 * Return: 1 or 0
 * amine mohamed
 */
int seaRch(char *str, char chart)
{
	int conter = 0;

	while (str[conter] != '\0')
	{
		if (str[conter] == chart)
		{
			break;
		}
		conter++;
	}
	if (str[conter] == chart)
		return (1);
	else
		return (0);
}

/**
 * tokenStr - prsing string int multiple part
 * @str: str to parse
 * @delim: the delim
 * Return: return null
 */
char *tokenStr(char *str, char *delim)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!str)
		str = ultimo;
	while (str[i] != '\0')
	{
		if (seaRch(delim, str[i]) == 0 && str[i + 1] == '\0')
		{
			ultimo = str + i + 1;
			*ultimo = '\0';
			str = str + j;
			return (str);
		}
		else if (seaRch(delim, str[i]) == 0 && seaRch(delim, str[i + 1]) == 0)
			i++;
		else if (seaRch(delim, str[i]) == 0 && seaRch(delim, str[i + 1]) == 1)
		{
			ultimo = str + i + 1;
			*ultimo = '\0';
			ultimo++;
			str = str + j;
			return (str);
		}
		else if (seaRch(delim, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
