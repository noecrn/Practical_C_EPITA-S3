#include <err.h>
#include <SDL2/SDL.h>

#define MIN(a, b) ( ( (a) < (b) ) ? (a) : (b) )
#define MAX(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define DIM(x, a, b) ( MIN(MAX(x, a), b) )

// Initial width and height of the window.
const int INIT_WIDTH = 640;
const int INIT_HEIGHT = 400;

// Initial (fake) position of the mouse pointer.
const int INIT_MOUSE_X = INIT_WIDTH / 10;
const int INIT_MOUSE_Y = INIT_HEIGHT;

// Ratio used to reduce the length of a segment.
const double RATIO = 0.7;

// Recursive function that draws the fractal canopy.
void v(SDL_Renderer* renderer, int x, int y, double len, double a, int level, int top_level, double step_angle)
{
    if (level == 0)
    {
        int y1 = y - len;
        SDL_RenderDrawLine(renderer, x, y, x, y1);
        v(renderer, x, y1, RATIO * len, 0, 1, top_level, step_angle);
    }
    else if (level <= top_level)
    {
        int x1 = x - len * sin(a + step_angle);
        int y1 = y - len * cos(a + step_angle);
        
        int x2 = x - len * sin(a - step_angle);
        int y2 = y - len * cos(a - step_angle);
        
        SDL_RenderDrawLine(renderer, x, y, x1, y1);
        SDL_RenderDrawLine(renderer, x, y, x2, y2);
        
        v(renderer, x1, y1, RATIO * len, a + step_angle, level + 1, top_level, step_angle);
        v(renderer, x2, y2, RATIO * len, a - step_angle, level + 1, top_level, step_angle);
    }
}

// Implement a basic sin function.
double angle_sin(double radians)
{
    int i;
    double result = 0;
    double term = radians;
    double num = radians;
    double den = 1;
    for (i = 1; i < 10; i++)
    {
        num = -num * radians * radians;
        den = den * (2 * i) * (2 * i + 1);
        term = num / den;
        result += term;
    }
    return result;
}

// Implement a basic cos function.
double angle_cos(double radians)
{
    int i;
    double result = 0;
    double term = 1;
    double num = 1;
    double den = 1;
    for (i = 1; i < 10; i++)
    {
        num = -num * radians * radians;
        den = den * (2 * i) * (2 * i - 1);
        term = num / den;
        result += term;
    }
    return result;
}

void draw(SDL_Renderer* renderer, int w, int h, int mouse_x, int mouse_y)
{
    if (w < 20 || h < 20)
        return;

    int top_level = DIM(mouse_y / (h / 11), 0, 10);
    double step_angle = DIM(M_PI / (2.0 + mouse_x / (w / 18.0)), M_PI / 20, M_PI / 2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    v(renderer, w / 2, h, h / 4, 0, 0, top_level, step_angle);
    
    SDL_RenderPresent(renderer);
}

void event_loop(SDL_Renderer* renderer)
{
    int w = INIT_WIDTH;
    int h = INIT_HEIGHT;
    int mouse_x = INIT_MOUSE_X;
    int mouse_y = INIT_MOUSE_Y;

    draw(renderer, w, h, mouse_x, mouse_y);

    SDL_Event event;

    while (1)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                return;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    w = event.window.data1;
                    h = event.window.data2;
                    draw(renderer, w, h, mouse_x, mouse_y);
                }
                break;
            case SDL_MOUSEMOTION:
                mouse_x = event.motion.x;
                mouse_y = event.motion.y;
                draw(renderer, w, h, mouse_x, mouse_y);
                break;
        }
    }
}

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow("Dynamic Fractal Canopy", 0, 0, INIT_WIDTH, INIT_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    event_loop(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
