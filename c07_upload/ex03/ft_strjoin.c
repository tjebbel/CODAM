/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tlodeize <tlodeize@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 13:49:55 by tlodeize      #+#    #+#                 */
/*   Updated: 2026/02/12 13:31:41 by tlodeize      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	if (!str)
        return 0;
		
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int ft_total_length(int size, char **strs, char *sep)
{
	int i;
	int total;

	i = 0;
	total = 0;
	
	while (i < size)
	{
		total = total + ft_strlen(strs[i]);
	}
	total = total + (size -1) * ft_strlen(sep) + 1;
	return (total);
}

char	*ft_strcat(char *dest, char *src)
{
	int idest;
	int isrc;

	idest = 0;
	isrc = 0;
	
	while (dest[idest] !='\0')
	{
		idest++;
	}
	while (src[isrc] != '\0')
	{
		dest[idest] = src[isrc];
		idest++;
		isrc++;
	}
	dest[idest] ='\0';
	return (dest);
}

char *populate_str(char *ptr, int size, char **strs, char *sep)
{
	int i;

	i = 0;
	
	while(i <size)
	{
		ptr = ft_strcat(ptr, strs[i]);
		if (i != size -1)
			ptr = ft_strcat(ptr,sep);
		i++;
	}
	return (ptr);
}

char *ft_strjoin(int size, char **strs, char *sep) 
{
    char *ptr;

    if (size == 0) {
        return (char *)malloc(sizeof(char));
    }

    ptr = (char *)malloc(ft_total_length(size, strs, sep) * sizeof(char));
    if (!ptr) {
        return NULL;
    }

    return populate_str(ptr, size, strs, sep);
}

/* int main() {
    char *strs[] = {"Hello", "World", "from", "C"};
    char *sep = ",";
    int size = sizeof(strs) / sizeof(strs[0]);

    char *result = ft_strjoin(size, strs, sep);
    if (result) {
        printf("Joined String: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
 */