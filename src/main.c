#include <Cub3d.h>

int main(int argc, char *argv[])
{
    t_data data;
    if (argc != 2)
    {
        //msgs de erro
        return (-1);
    }
    init_struct(&data);
    if (init_map(argv[1], &data) == -1)
        return (-1);
}
