#include "./includes/fdf.h"





/* Rotation functions. Input angle in radians

void            rotate(t_point vertex, float x_angle, float y_angle, float z_angle)
{
    rotate_x(vertex, x_angle);
    rotate_y(vertex, y_angle);
    rotate_z(vertex, z_angle);
}

void            do_yawn(t_point vertex, float angle)
{
    vertex->
}
*/

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/* Bresenham's line algorithm */

void            draw_line(t_img *data, int x0, int y0, int x1, int y1)
{
    int     dx;
    int     dy;
    int     sx;
    int     sy;
    int     err;
    int     e2;

    dx = abs(x1 - x0);
    dy = -abs(y1 - y0);
    sx = x0 < x1 ? 1 : -1;
    sy = y0 < y1 ? 1 : -1;
    err = dx + dy;
    while (1)
    {
        my_mlx_pixel_put(data, x0, y0, 0x00FF0000);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_img  img;
    int     x0_pos;
    int     y0_pos;
    int     x1_pos;
    int     y1_pos;


    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Stoopid window");
    img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    x0_pos = 300;
    y0_pos = 25;
    x1_pos = 10;
    y1_pos = 250;
    draw_line(&img, x0_pos, y0_pos, x1_pos, y1_pos);
    draw_line(&img, 100, 300, 350, 20);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);

    return (0);
}
