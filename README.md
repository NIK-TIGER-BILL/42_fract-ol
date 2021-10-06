# 42-fract-ol
## Discover 2D programming and the psychedelic universe of fractals in this project, using minilibX.

<p align="center">
	<img  src="https://user-images.githubusercontent.com/84707645/132736988-dbdd08fe-eef1-4c0d-8e70-c6401aab27c6.gif" width="400" height="400" /> 
</p>

Subject is presented in the [en.subject.pdf](https://github.com/lavrenovamaria/42-fract-ol/files/7128672/en.subject.pdf)


## Usage 

* `make` to compile this project.  
* `./fractol <name>`  
  
Names fractals:
 - Mandelbrot  
 - Julia  
 - Burning Ship  

## Mandelbrot

<img width="400" alt="Mandelbrot" src="https://hsto.org/getpro/habr/post_images/54d/995/30a/54d99530ad6812e953f08198805c5020.jpg">

## Julia

<img width="400" alt="Julia" src="https://i.ytimg.com/vi/vf5L2RoqL9k/maxresdefault.jpg">

# Burning Ship

<img width="400" alt="Burning_Ship" src="https://upload.wikimedia.org/wikipedia/commons/2/25/Burning_ship_fractal_entire.png">

Construction is carried out using complex numbers:
```c
typedef struct		s_complex
{
	double			re;
	double			im;
}			t_complex;
```


## Credits 

* [Veritasium: this equation will change how you see the world](https://www.youtube.com/watch?v=ovJcsL7vyrk)
* [Vsauce: the Mandelbrot Set](https://www.youtube.com/watch?v=MwjsO6aniig)
* [The Mandelbrot Set Explained](https://www.youtube.com/watch?v=7MotVcGvFMg)
* [42Docs. MiniLibX. Getting started](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* [MiniLibX. Basic introduction, tutorials, tips & tricks.](https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html) 
* [Pixel drawing with the minilibx](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)
* [Managing events with the minilibx](https://aurelienbrabant.fr/blog/events-with-the-minilibx)
* [RGBA color model](https://en.wikipedia.org/wiki/RGBA_color_model#Representation)
