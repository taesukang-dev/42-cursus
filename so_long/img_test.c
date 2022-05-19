#include "so_long.h"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  // 괄호 == offset
    *(unsigned int *)dst = color;
}

int main(int ac, char *av[])
{
    void    *mlx;
    void    *mlx_win;
    t_data  *img1;
    t_data  *img2;
    t_data  *img3;
    t_data  *img4;
    t_data  *img5;
    t_data  *img6;
    int     img_width;
    int     img_height;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
    img1 = mlx_xpm_file_to_image(mlx, "./static/floor_64.xpm", &img_width, &img_height);
    img2 = mlx_xpm_file_to_image(mlx, "./static/babyyoda_64.xpm", &img_width, &img_height);
    img3 = mlx_xpm_file_to_image(mlx, "./static/collection_64.xpm", &img_width, &img_height);
    img4 = mlx_xpm_file_to_image(mlx, "./static/darth_64.xpm", &img_width, &img_height);
    img5 = mlx_xpm_file_to_image(mlx, "./static/mandalo_front_64.xpm", &img_width, &img_height);
    img6 = mlx_xpm_file_to_image(mlx, "./static/wall_64.xpm", &img_width, &img_height);

    int x, y = 0;
    while(1)
    {
        if (x == 1920 && y >= 1080)
            break ;
        if (x == 1920)
        {
            x = 0;
            y += 64;
        }
        mlx_put_image_to_window(mlx, mlx_win, img1, x, y);
        x += 64;
    }
    mlx_put_image_to_window(mlx, mlx_win, img2, 64, 0);
    mlx_put_image_to_window(mlx, mlx_win, img3, 128, 0);
    mlx_put_image_to_window(mlx, mlx_win, img4, 192, 0);
    mlx_put_image_to_window(mlx, mlx_win, img5, 256, 0);
    mlx_put_image_to_window(mlx, mlx_win, img6, 320, 0);

    mlx_loop(mlx);
    return 0;
}