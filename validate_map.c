#include "../../inc/cub3d.h"
#include "fcntl.h"

static char check_rgb (int rgb)
{
	if (rgb < 0 || rgb > 255)
		return(print_error("Invalid RGB range."), EXIT_FAILURE);
	return(0);
}

static char validate_rgb(char **nsewfc_tex, t_tex *tex)
{
    char **fc[2];
    int i;
    int j;

    int rgbs[6];
    int index;

    fc[0] = ft_split(nsewfc_tex[4],',');
    fc[1] = ft_split(nsewfc_tex[5],',');

    i = 0;
    index = 0;
    while(fc[i])
    {
        j = 0;
        while(fc[i][j])
        {
            if (ft_strlen(fc[i][j]) > 3)
                return (print_error("RGB is not in range."), EXIT_FAILURE);
            rgbs[index] = ft_atoi(fc[i][j]);
            if (check_rgb(rgbs[index]))
                return (EXIT_FAILURE);
            index++;
            j++;
        }
        i++;
    }
    tex.fl_color = rgbs[2] + (rgbs[1] << 8) + (rgbs[0] << 16) + (255 << 24);
    tex.ceil_color = rgbs[5] + (rgbs[4] << 8) + (rgbs[3] << 16) + (255 << 24);
    return (0);
}

static char is_playable(t_map *map, t_calc *calc)
{
    int i;
    int j;
    int nsewcount;

    nsewcount = 0;
    j = 0;
    i = 0;

    while(map->map[j])
    {
        while(map->map[j][i])
        {
            if(map->map[j][i] != 0 || map->map[j][i] != 1 || map->map[j][i] != 'S' 
                || map->map[j][i] != 'N' || map->map[j][i] != 'W' || map->map[j][i] != 'E') //if nsew10space fonksiyonu yaz.
                    return(EXIT_FAILURE);
            if(map->map[j][i] == 'S') //if is_nsew fonksiyonu yaz.
            {
                map->nsew = 'S';
                map->x_player = i;
                map->y_player = j;
                nsewcount++;
            }
            if(map->map[j][i] == 'N')
            {
                map->nsew = 'N';
                map->x_player = i;
                map->y_player = j;
                nsewcount++;
            }
            if(map->map[j][i] == 'W')
            {
                map->nsew = 'W';
                map->x_player = i;
                map->y_player = j;
                nsewcount++;
            }
            if(map->map[j][i] == 'E')
            {
                map->nsew = 'E';
                map->x_player = i;
                map->y_player = j;
                nsewcount++;
            }
            i++;
        }
        j++;
    }

    if (nsewcount != 1)
        return(EXIT_FAILURE)
    
}

char validate_map(t_cube *cube)
{
	if(validate_rgb(map->nsewfc_tex, tex))
		return(print_error("RGB is wrong."),EXIT_FAILURE);
    if(is_playable(map, calc))
        (return(print_error("The map is not playable", EXIT_FAILURE)));
}
