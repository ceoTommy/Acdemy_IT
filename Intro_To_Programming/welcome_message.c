/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:52:09 by tford             #+#    #+#             */
/*   Updated: 2022/03/04 12:33:50 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Libft/libft.h"

typedef struct s_welcome_txt{
	const char 	*c_prefix;
	const char	*c_name;
	const char	*c_suffix;
	const char	*customer_name;
}	t_welcome_txt;

//joins all contents of the welcome struct
//into one string
static char	*join_welcome_str(t_welcome_txt *wel_txt)
{
	char	*str;

	str = ft_strjoin(wel_txt->c_prefix, wel_txt->c_name);
	str = ft_strjoin(str, wel_txt->c_suffix);
	str = ft_strjoin(str, wel_txt->customer_name);

	return (str);
}

//name is a not NULL and all alphabetical
int	is_valid_name(const char *str)
{
	if (str == NULL)
	{
		printf("Error: no name entered");
		return (0);
	}

	while (*str)
	{
		if (!ft_isalpha(*str))
		{
			printf("Must be only alphabetical characters\n");
			return (0);
		}
		str++;
	}
	return (1);
}

int main()
{
	t_welcome_txt 	wel_txt;
	char 			scan_buf[512];

	wel_txt.c_prefix = "Welcome to ";
	wel_txt.c_name = "FDS";
	wel_txt.c_suffix = " - ";
	wel_txt.customer_name = NULL;

	while (wel_txt.customer_name == NULL)
	{
		printf("Enter your name: ");
		scanf("%s", scan_buf);
		if (is_valid_name(scan_buf))
			wel_txt.customer_name = ft_strtrim(scan_buf, " ");
	}
	printf("%s", join_welcome_str(&wel_txt));
}
