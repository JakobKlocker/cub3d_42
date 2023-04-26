#include "../includes/cub3d.h"

char *malloc1D(t_mapInfo *mapInfo)
{
    char *ret;
    char *tmp;
    char *line;

    ret = calloc(1, 1);
    if(!ret)
        error("malloc", mapInfo);
    line = get_next_line(mapInfo->Fd);
    if(!line)
        error("malloc", mapInfo);
    while(line && *line == '\0')
    {
        free(line);
        line = get_next_line(mapInfo->Fd);
    }
    while(line)
    {
            tmp = ret;
            ret = ft_strjoin(ret, line);
            if(tmp)
                free(tmp);
            tmp = ret;
            ret = ft_strjoin(ret, "\n");
            if(tmp)
                free(tmp);
            free(line);
            line = get_next_line(mapInfo->Fd);
    }
    return ret;
}

char **malloc2D(t_mapInfo *mapInfo)
{
    t_index index;
    char **ret;
    index.i = 0;
    index.j = 0;
    
    ret = malloc(mapInfo->height * sizeof(char*) + 1);
    if(!ret)
        error("malloc", mapInfo);
    while(index.i < mapInfo->height)
    {
        ret[index.i] = malloc(getLenTillChar(mapInfo->map1D + index.j, '\n') + 1);
        if(!ret[index.i])
            error("malloc", mapInfo); 
        index.j += getLenTillChar(mapInfo->map1D + index.j, '\n') + 1;
        index.i++;
    }
    ret[index.i] = NULL;
    return ret;
}

void copy2DMap(t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    index.j = 0;
    while(index.i < mapInfo->height)
    {
        index.k = 0;
        while(mapInfo->map1D[index.j] != '\n')
        {
            mapInfo->map2D[index.i][index.k] = mapInfo->map1D[index.j];
            index.j++;
            index.k++;
        }
         mapInfo->map2D[index.i][index.k] = '\0';
        index.j++;
        index.i++;
    }
}

int getLenTillChar(char* line, char c)
{
    int i = 0;
    while(line &&  line[i] && line[i] != c)
        i++;
    return i;
}

void print2DMap(t_mapInfo *mapInfo)
{
    t_index index;

    index.i = 0;
    index.j = 0;

    while(index.i < mapInfo->height)
    {
        ft_printf("%s\n", mapInfo->map2D[index.i]);
        index.i++;
    }
}
