#include "cub3d.h"

int is_number(char *str)
{
    size_t i;
    int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ')
            return (0);
        if (ft_isdigit(str[i]))
            result = result * 10 + str[i] - '0';
        if (result > 255)
            return (0);
        i++;
    }
    i = 0;
    while (str[i] && str[i] == ' ')
        i++;
    if (ft_strlen(str) == i)
        return (0);
    return (1);
}

int ft_array_len(char **str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}
