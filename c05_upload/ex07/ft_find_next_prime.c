/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_next_prime.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tlodeize <tlodeize@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/06 18:14:04 by tlodeize      #+#    #+#                 */
/*   Updated: 2026/02/11 18:18:21 by tlodeize      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>	

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb)) // Keep checking until a prime is found
		nb++;
	return (nb);
}

/* int main(void)
{
	int nb;

	nb = 30;
	printf("The next prime number after %d is %d\n", nb, ft_find_next_prime(nb));
	return (0);
} */

/* 
The function ft_find_next_prime takes an integer nb and returns the next prime number greater than or equal to nb.
It does this by calling ft_is_prime on nb and incrementing nb until it finds a prime number.
The main function demonstrates how to use ft_find_next_prime by finding the next prime number after 30.
The expected output will be: The next prime number after 30 is 31
*/