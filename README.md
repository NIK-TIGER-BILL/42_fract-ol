# 42-fract-ol
## Discover 2D programming and the psychedelic universe of fractals in this project, using minilibX.

<p align="center">
	<img  src="https://user-images.githubusercontent.com/84707645/132736988-dbdd08fe-eef1-4c0d-8e70-c6401aab27c6.gif" width="400" height="400" /> 
</p>

Subject is presented in the [en.subject.pdf](https://github.com/lavrenovamaria/42-fract-ol/files/7128672/en.subject.pdf)

## Credits 

* [Veritasium: this equation will change how you see the world](https://www.youtube.com/watch?v=ovJcsL7vyrk)
* [Vsauce: the Mandelbrot Set](https://www.youtube.com/watch?v=MwjsO6aniig)
* [The Mandelbrot Set Explained](https://www.youtube.com/watch?v=7MotVcGvFMg)
* [42Docs. MiniLibX. Getting started](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* [MiniLibX. Basic introduction, tutorials, tips & tricks.](https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html) 
* [Pixel drawing with the minilibx](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)
* [Managing events with the minilibx](https://aurelienbrabant.fr/blog/events-with-the-minilibx)

* [RGBA color model](https://en.wikipedia.org/wiki/RGBA_color_model#Representation)

## Knowledge of fractol. The Mandelbrot Set

<img width="901" alt="133981535-b4c77c88-b3ff-4c00-aa5d-eb98a145ec19" src="https://user-images.githubusercontent.com/84707645/134631006-f2d3fb0f-b1ac-491d-b9e1-f7dffc99613a.png">



The Mandelbrot set with the real and imaginary axes labeled.


```c
typedef struct		s_complex
{
	double			re;
	double			im;
}			t_complex;
```

## Let's draw a pixel on the screen!

### 1. Initializing
Before doing anything, we need to include <mlx.h> library. To init MiniLibX, let's start with this:

```c
#include <mlx.h>

int main(void)
{
	void *mlx;
	
	mlx = mlx_init();
}
```
`mlx_init` creates a structure that contains all the stuff the minilibx will need in order to do its things.
### 2. Open the window
When we run the previous code, nothing pops up and nothing is rendered, because we didn't create the window. Call `mlx_new_window` to open a window. This function returns a pointer to the window we just created. We can also give a height, width and a title to our window. And we need to call `mlx_loop` to render the window.\
`int mix_loop(void *mlx_ptr)` 
* Both X-Window and MacOSX graphical systems are bi-directionnal. On one hand, the program sends orders to the screen to display pixels, images, and so on. On the other hand, it can get information from the keyboard and mouse associated to the screen. To do so, the program receives "events" from the keyboard or the mouse. To receive events, you must use this function. This function never returns. It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event. A single parameter is needed, the connection identifier mlx_ptr. Clicking anywhere in the window with the mouse is an event. Pressing a key is another. Events are basically everything the user can do to interact with the program.


```c
#include <mlx.h>

int main(void)
{
	void *mlx;
	void *mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "mlx_test");
	mlx_loop(mlx);
}
```
Now we have a window with 1920 width, 1080 height and "mlx_test" title.

### 3. Draw!

```c
typedef struct		s_img {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}			t_img;

```
Since pixel is basically an int type, it is 4 bytes. But this can be different if we are dealing with small [endian](https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/).\
`void *img` refers to the address `mlx_new_image` returns. `bits_per_pixel` is total number of bits stored for each pixel in a graphic image. We also need to understand that bytes are not aligned, so `line_length` may be different from the actual window width. So we need `mlx_get_data_addr` to compute the memory address offset with the line lenght set through.

We can get it with the following formula:
* int index = (y * line_length + x * (bits_per_pixel / 8));

For this example, let's assume we want to get the pixel at coordinates (5, 10). What we want is the 5th pixel of the 10th row. Window/image dimensions are 600x300.

To begin with, let's find the correct row. The previous `mlx_get_data_addr` call provided us the `line_length` value, which is basically the amount of bytes taken by one row of our image. It is equivalent to `image_width * (bpp / 8)`.

In our case, an `int` is four bytes, so it is `600 * 4 = 2400`. Therefore we can say that the first row begins at the index `0`, the second one at the index `2400`, the third one at the index `4800`, and so on. Thus we can find the correct row index by doing `2400 * 10`.

To find the correct column, we will need to move in the row by the given number of pixels. In our case, we want to move 5 pixels "right". To do that, we need to multiply `5` by the number of bytes a pixel actually takes (here `4`). Thus we will do `5 * 4 = 20`.

If we summarize, we can find the correct index with the following computation: `index = 2400 * 10 + 5 * 4`.

That's it! We just need to generalize the formula using the values `mlx_get_data_addr` provided us. The following formula is the one we'll use:

`index = line_length * y + x * (bits_per_pixel / 8)`

Since `line_length` is the number of bytes in one horizontal line of the image, it is moved to a memory address equal to the y-coordinate of the pixel coordinate as (line_length * y-coordinate). Since `bits_per_pixel` is the number of bits per pixel, dividing by 8 to convert to bytes gives bytes per pixel. (bits_per_pixel / 8 * y coordinate). You can finally get the memory address of the pixel at (x, y) coordinates by moving the memory address as much as the x coordinate.

`char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);`

`mlx_get_data_addr` returns the address of the starting point in memory where the image is stored as a char * type pointer. We're getting a pointer on `char`, which usually means we're going to naviguate in the array one byte at a time (not one pixel at a time, a pixel usually takes more than one byte as we've seen before). If mlx_get_data_addr() is called successfully, values are assigned to the following three parameters:
* `bits_per_pixel` will be filled with the number of bits needed to represent a pixel color (also called the depth of the image).
* `line_lenght` is the number of bytes used to store one line of the image in memory. This information is needed to move from one line to another in the image.
* The `endian` parameter indicates whether the pixel color is stored in little endian (0 specified) or big endian (1 specified).


```c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}
```
We will use `my_mlx_pixel_put` because `mlx_pixel_put` is very, very slow. This is because when you put a pixel on the window, it immidiately loads the frame before it is fully rendered. For this reason we will buffer all pixels before loading them into the window. 

Finally, we can draw an image inside a specific window with a `mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);`
* Can draw inside image, and can dump the image inside a specified window at any time to display it on the screen. Three identifiers are needed here, for the connection to the display, the window to use, and the image. The (x, y) coordinates define where the image should be placed in the window.

### 4. Using keyboard

In order to receive input from keyboard/mouse/etc. in MiniLibX, you need to know the concept of [events](https://en.wikipedia.org/wiki/Event_(computing)). An event is an action or event that can be detected and handled by a program. miniLibX `mlx_loop()` needs a loop statement to handle events. This function waits for an event to be received and generates the event.

`int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param);`
* First, specify the identifier of the window for which you want to generate an event, then specify the event [status](https://refspecs.linuxfoundation.org/LSB_3.2.0/LSB-Desktop-generic/LSB-Desktop-generic/libx11-ddefs.html), then mask, next parameter is a function pointer parameter that receives the address of the function to be executed when the corresponding event occurs, and last is a parameter that sends parameter data necessary for the function called with.
* `func_ptr` is a pointer to a function that returns an int and that takes undefined parameters. Beware, `(*func_ptr)()` is not the same as `(*func_ptr)(void)`: the last means NO argument while the first means "any set of arguments".

## Usage 

* `make` to compile this project.
* `./fractol_name`
