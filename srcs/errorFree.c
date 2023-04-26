#include "../includes/cub3d.h"

void free2D(char **str)
{
    int i;
    i = 0;

    if(!str)
        return;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

//Don't free mapName, it's copied from the arg
void freeExit(t_mapInfo *mapInfo)
{
    if(mapInfo->map1D)
        free(mapInfo->map1D);
    if(mapInfo->map2D)
        free2D(mapInfo->map2D);
    if(mapInfo->NTexture)
        free(mapInfo->NTexture);
    if(mapInfo->ETexture)
        free(mapInfo->ETexture);
    if(mapInfo->STexture)
        free(mapInfo->STexture);
    if(mapInfo->WTexture)
        free(mapInfo->WTexture);
    if(mapInfo->FColor)
        free2D(mapInfo->FColor);
    if(mapInfo->CColor)
        free2D(mapInfo->CColor);
    freeMlx(mapInfo);
    exit(1);
}

void freeMlx(t_mapInfo *mapInfo)
{
    if(mapInfo->mlx.mlx && mapInfo->mlx.win)
        mlx_destroy_window(mapInfo->mlx.mlx, mapInfo->mlx.win);
    //if(mapInfo->mlx.mlx)
        //free mlx init here
    //free with mlx destory window
}

void error(char *error, t_mapInfo *mapInfo)
{
    if(ft_strcmp(error, "RGB") == 0)
        ft_printf("Error\n Invalid RGB Values\n");
    else if(ft_strcmp(error, "wall") == 0)
        ft_printf("Error\n Map not surrounded by Walls\n");
    else if(ft_strcmp(error, "invChar") == 0)
        ft_printf("Error\n Only '0', '1', 'N', 'S', 'E', 'W' or ' ' inside the map allowed\n");
    else if(ft_strcmp(error, "malloc") == 0)
        ft_printf("Error\n malloc failed\n");
    else if(ft_strcmp(error, "identif") == 0)
        ft_printf("Error\n Invalid Map identifier\n");
    else if(ft_strcmp(error, ".cub") == 0)
        ft_printf("Error\n Map name invalid, must end with .cub\n");
    else if(ft_strcmp(error, "open") == 0)
        ft_printf("Error\n Couldn't open file\n");
    else if(ft_strcmp(error, "mlx") == 0)
        ft_printf("Error\n Mlx function failed\n");
    else
        ft_printf("Error\n");
    freeExit(mapInfo);
}
