/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvanbesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:40:45 by tvanbesi          #+#    #+#             */
/*   Updated: 2020/12/10 17:40:47 by tvanbesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strdcat(char *s1, char *s2)
{
	char	*r;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(r = malloc(len)))
		return (NULL);
	ft_strlcpy(r, s1, len);
	ft_strlcat(r, s2, len);
	free(s1);
	free(s2);
	return (r);
}
