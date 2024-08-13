
#include "cub3d.h"

void free_map(t_data *game)
{
    size_t i;


    if (game->map)
    {
        i = 0;
        while (i < game->map_rows)
        {
            if (game->map[i])
                free(game->map[i]);
            i++;
        }
        free(game->map);
        game->map = NULL;
    }

}

void clean_up(t_data *game)
{
    if (!game)
        return;

    // Free texture paths
    if (game->no)
    {
        free(game->no);
        game->no = NULL;
    }
    if (game->so)
    {
        free(game->so);
        game->so = NULL;
    }
    if (game->we)
    {
        free(game->we);
        game->we = NULL;
    }
    if (game->ea)
    {
        free(game->ea);
        game->ea = NULL;
    }

    // Free map and other resources
    if (game->map)
        free_map(game);
}

int error_msg(t_data *game, char *mess, int status)
{
    if (game->fd > 0)
        close(game->fd);
    clean_up(game);
    ft_putstr_fd("cub3D: Error", 2);
    if (mess)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(mess, 2);
    }

    exit(status);
}
