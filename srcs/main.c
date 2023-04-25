#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_mapInfo mapInfo;
    t_player player;

    if(argc != 2)
    {
        ft_printf("Wrong amount of Arguments.\n");
        return 1;
    }
    initMapInfo(&mapInfo, argv[1]);
    validMapExtention(mapInfo.mapName);
    mapInfo.Fd = openMap(mapInfo.mapName);
    getMapInfo(&mapInfo);
    allMapChecks(&mapInfo);
    getPlayerCordinates(&mapInfo, &player);
    openWindow(&mapInfo);
    createBG(&mapInfo);
    DDA(&mapInfo, &player);
}