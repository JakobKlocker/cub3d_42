#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mapInfo mapInfo;
	t_mimap minimap;
	if (argc != 2)
	{
		ft_printf("Wrong amount of Arguments.\n");
		return (1);
	}
	initMapInfo(&mapInfo, argv[1]);
	validMapExtention(mapInfo.mapName, &mapInfo);
	mapInfo.Fd = openMap(mapInfo.mapName, &mapInfo);
	getMapInfo(&mapInfo);
	allMapChecks(&mapInfo);
	getPlayerCordinates(&mapInfo, &mapInfo.player);
	openWindow(&mapInfo);
	initRayInfo(&mapInfo.rayInfo, &mapInfo.player, &mapInfo);
	rayCasting(&mapInfo);
	ft_minimapBG(&mapInfo, &minimap);
	mlxLoop(&mapInfo);
}