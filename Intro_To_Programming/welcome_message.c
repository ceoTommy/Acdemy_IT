/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:52:09 by tford             #+#    #+#             */
/*   Updated: 2022/02/28 13:27:28 by tford            ###   ########.fr       */
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

static char	*welcome_str(t_welcome_txt *wel_txt)
{
	char	*str;

	str = ft_strjoin(wel_txt->c_prefix, wel_txt->c_name);
	str = ft_strjoin(str, wel_txt->c_suffix);
	str = ft_strjoin(str, wel_txt->customer_name);

	return (str);
}

//write error message

int main()
{
	t_welcome_txt 	wel_txt;
	char[512] 		scan_buf;

	wel_txt.c_prefix = "Welcome to ";
	wel_txt.c_name = "FDS";
	wel_txt.c_suffix = " - ";

	while (wel_txt.name == NULL)
	{
		printf("Enter your name: ");
		scanf("%s", scan_buf);
		if (is_valid_name(scan_buf))
			wel_txt.customer_name = ft_strtrim(scan_buf, " ");
	}
	printf("%s", welcome_str(&wel_txt));
}
