#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void draw(SDL_Renderer* renderer, SDL_Texture* texture, int w, int h)
{
    // Clear the renderer
    SDL_RenderClear(renderer);

    // Copy the image to the renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Update the display
    SDL_RenderPresent(renderer);
}

void event_loop(SDL_Renderer* renderer, SDL_Texture* texture)
{
    SDL_Event event;
    int w, h;

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
                    draw(renderer, texture, w, h); // Redraw the image when resizing
                }
                break;
        }
    }
}

int main(int argc, char** argv)
{
    // Checks the number of arguments.
    if (argc != 2)
        errx(EXIT_FAILURE, "Usage: image-file");

    // Initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // Create a window.
    SDL_Window* window = SDL_CreateWindow("Display image", 0, 0, 640, 400,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // Create a renderer.
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // Load the image as a texture.
    SDL_Surface* imageSurface = IMG_Load(argv[1]);
    if (imageSurface == NULL)
        errx(EXIT_FAILURE, "Failed to load the image: %s", SDL_GetError());

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    draw(renderer, texture, NULL, NULL);

    // Start the event loop.
    event_loop(renderer, texture);

    // Destroy objects and quit.
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
