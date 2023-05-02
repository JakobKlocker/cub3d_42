#include "../includes/cub3d.h"

t_texture openTexture(t_mapInfo *mapInfo, char *path)
{
    t_texture ret;
    ret.img = mlx_xpm_file_to_image(mapInfo->mlx.mlx, path, &ret.width, &ret.height);
    if(!ret.img)
        error("open", mapInfo);
    ret.path = path;
    ret.addr.img = mlx_get_data_addr(ret.img, &ret.addr.bpp, &ret.addr.sizeLine, &ret.addr.endian);
    return ret;
}

void openAllTextures(t_mapInfo *mapInfo)
{
    mapInfo->E = openTexture(mapInfo, mapInfo->ETexture);
    mapInfo->W = openTexture(mapInfo, mapInfo->WTexture);
    mapInfo->N = openTexture(mapInfo, mapInfo->NTexture);
    mapInfo->S = openTexture(mapInfo, mapInfo->STexture);
}

unsigned int getColorPixel(t_texture tex, int y, int x)
{
    unsigned int pos = y * tex.addr.sizeLine + x * (tex.addr.bpp / 8);
    int* addr = (int*)tex.addr.img;
    return(*(int*)((char*)addr + pos));
}
