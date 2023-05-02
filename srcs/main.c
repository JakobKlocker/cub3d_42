#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_mapInfo mapInfo;
    if(argc != 2)
    {
        ft_printf("Wrong amount of Arguments.\n");
        return 1;
    }
    initMapInfo(&mapInfo, argv[1]);
    validMapExtention(mapInfo.mapName, &mapInfo);
    mapInfo.Fd = openMap(mapInfo.mapName, &mapInfo);
    getMapInfo(&mapInfo);
    allMapChecks(&mapInfo);
    getPlayerCordinates(&mapInfo, &mapInfo.player);
    openWindow(&mapInfo);
    setSpawnDir(&mapInfo.player, &mapInfo.rayInfo);
    //initRayInfo(&mapInfo.rayInfo, &mapInfo.player, &mapInfo);
    openAllTextures(&mapInfo);
    rayCasting(&mapInfo);
    mlxLoop(&mapInfo);
}