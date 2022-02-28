#include <stdio.h>
#include "42Cursus_Libft/libft.h"

int is_included(char *name, char *invalid_chars)
{
    int i;

    i = 0;
    while (invalid_chars[i] != '\0')
    {
        if (ft_strchr(name, invalid_chars[i]) != NULL)
            return(1);
        i++;
    }
    return(0);
}

int is_valid_name(char *name, char *invalid_chars)
{
    if (name == NULL)
    {
        printf("fscan failed\n");
        return(0);
    }
    else if (*name == '\0')
    {
        printf("empty name entered\n");
        return(0);
    }
    else if (is_included(name, invalid_chars))
    {
        printf("invalid character in name. %s not allowed\n", invalid_chars);
        return(0);
    }
    return (1);
}

char    *str_company_name(char **names, int as_initials)
{
    int     words;
    char    *name;
    int     word_len;
    
    words = 0;
    word_len = 0;
    if (names == NULL)
        return (NULL);
    while (names[words] != NULL)
    {
        word_len += ft_strlen(names[words]);
        words++;
    }
    if (as_initials)
    {
        name = (char *) ft_calloc(words + 1, sizeof(char));
        if (name == NULL)
            return (NULL);
        word_len = 0;
        while(word_len < words)
        {
            name[word_len] = names[word_len][0];
            word_len++;
        }
    }
    else
    {
        word_len += words - 1;
        name = (char *) ft_calloc((word_len + 1), sizeof(char));
        if (name == NULL)
            return (NULL);
        word_len = 0;
        while (word_len < words)
        {
            ft_strlcat(name, names[word_len], ft_strlen(names[word_len]) + 1);
            word_len++;
        }
    }
    return (name);
}

int main()
{
    char    *name;
    char    *output;
    char    *invalid_chars;
    int     as_initials = 0;
    char    *names[4] = {"Fancy", "Development", "Services", NULL};
    char    *company_name;

    name = (char *)malloc(512 * sizeof(char));
    printf("Your name: ");
    scanf("%s", name);
    invalid_chars = "<>./!@#$+=^&*()1234567890";
    while (!is_valid_name(name, invalid_chars))
    {
        printf("Your name: ");
        scanf("%s", name);
    }
    //company name
    company_name = str_company_name(names, as_initials);

    output = ft_strjoin("Welcome to ", company_name);
    printf("\n%s - %s", output, name);

    printf("\e[33m" "\n\n" "VAR LOGGING\n" "\e");
    printf("\e[35m" "name: [%s]\n", name);
    printf("output: [%s]\n", output);
    printf("invalid_chars: [%s]\n", invalid_chars);
}
