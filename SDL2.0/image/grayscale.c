#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Updates the display.
//
// renderer: Renderer to draw on.
// texture: Texture that contains the image.
void draw(SDL_Renderer* renderer, SDL_Texture* texture)
{
    // Clear the renderer
    SDL_RenderClear(renderer);

    // Copy the image to the renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Update the display
    SDL_RenderPresent(renderer);
}

// Event loop that calls the relevant event handler.
//
// renderer: Renderer to draw on.
// colored: Texture that contains the colored image.
// grayscale: Texture that contains the grayscale image.
void event_loop(SDL_Renderer* renderer, SDL_Texture* colored, SDL_Texture* grayscale)
{
    SDL_Event event;
    SDL_Texture* t = colored;
    int i = 1;
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
                    draw(renderer, t); // Redraw the image when resizing
                }
                break;
            case SDL_KEYDOWN:
                i = !i;
                if (i)
                {
                    t = colored;
                }
                else
                {
                    t = grayscale;
                }
                draw(renderer, t);
        }
    }
}

// Loads an image in a surface.
// The format of the surface is SDL_PIXELFORMAT_RGB888.
//
// path: Path of the image.
SDL_Surface* load_image(const char* path)
{
    SDL_Surface* tempSurface = IMG_Load(path);

    if (tempSurface == NULL)
    {
        errx(EXIT_FAILURE, "%s", SDL_GetError());
        return NULL;
    }
    
    SDL_Surface* newSurface = SDL_ConvertSurfaceFormat(tempSurface, SDL_PIXELFORMAT_RGB888, 0);

    if (newSurface == NULL)
    {
        errx(EXIT_FAILURE, "%s", SDL_GetError());
        SDL_FreeSurface(tempSurface);
        return NULL;
    }
    
    SDL_FreeSurface(tempSurface);
    return newSurface;
}

// Converts a colored pixel into grayscale.
//
// pixel_color: Color of the pixel to convert in the RGB format.
// format: Format of the pixel used by the surface.
Uint32 pixel_to_grayscale(Uint32 pixel_color, SDL_PixelFormat* format)
{
    Uint8 r, g, b;
    SDL_GetRGB(pixel_color, format, &r, &g, &b);
    Uint32 color = SDL_MapRGB(format, r, g, b);

    Uint8 average = 0.3*r + 0.59*g + 0.11*b;
    return SDL_MapRGB(format, average, average, average);
}

void surface_to_grayscale(SDL_Surface* surface)
{
    Uint32* pixels = surface->pixels;
    int len = surface->w * surface->h;
    SDL_PixelFormat* format = surface->format;
    SDL_LockSurface(surface);
    for (int i = 0; i < len; i++)
    {
        // Get the original pixel color
        Uint32 original_pixel = pixels[i];

        // Convert the pixel to grayscale
        Uint32 grayscale_pixel = pixel_to_grayscale(original_pixel, format);

        // Replace the original pixel with the grayscale pixel
        pixels[i] = grayscale_pixel;
    }
    SDL_UnlockSurface(surface);
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

    // Load the colored image
    SDL_Surface* coloredSurface = load_image(argv[1]);
    if (coloredSurface == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // Resize the window
    int w = coloredSurface->w;
    int h = coloredSurface->h;
    SDL_SetWindowSize(window, w, h);

    // Create a texture from the colored surface
    SDL_Texture* coloredTexture = SDL_CreateTextureFromSurface(renderer, coloredSurface);
    if (coloredTexture == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // Convert the surface into grayscale
    surface_to_grayscale(coloredSurface);

    // Create a new texture from the grayscale surface
    SDL_Texture* grayscaleTexture = SDL_CreateTextureFromSurface(renderer, coloredSurface);
    if (grayscaleTexture == NULL)
        errx(EXIT_FAILURE, "%s", SDL_GetError());

    // Free the surface
    SDL_FreeSurface(coloredSurface);

    // Initial display of the colored image
    draw(renderer, coloredTexture);

    // Enter the event loop
    event_loop(renderer, coloredTexture, grayscaleTexture);

    SDL_DestroyTexture(coloredTexture);
    SDL_DestroyTexture(grayscaleTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}