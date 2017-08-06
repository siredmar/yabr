#include "SDL/SDL.h"
#include "rs232/rs232.h"
#include <unistd.h>

#define CHECK_BIT(var, pos) ((var) & (pos))
#define GET_BIT(var, pos) (((var) >> (pos)) & 0x01u)
#define SET_BIT(var, pos) ((var) |= (1 << (pos)))
#define CLEAR_BIT(var, pos) ((var) &= ~(1 << (pos)))
#define TOGGLE_BIT(var, pos) ((var) ^= (1 << (pos)))
#define CLEAR_BITMASK(var, mask) ((var) &= ~(mask))
#define SET_BITMASK(var, mask) ((var) = (var) | (mask))
#define CHECK_BITMASK(var, mask) ((var) & (mask) == (mask))

unsigned char UartOutput[2] = {0};
int keyPress = 0;
/* Function Prototypes */
void PrintKeyInfo(SDL_KeyboardEvent * key);
void PrintModifiers(SDLMod mod);

const char *comport = "/dev/rfcomm0";
int baudrate = 9600;

/* main */
int main(int argc, char *argv[])
{
    int comport_fd;
    comport_fd = rs232_open_port(argv[1], baudrate);
    if(comport_fd == -1)
    {
        fprintf(stderr, "Could not open serial port\n");
        exit(-1);
    }

    SDL_Event event;
    int quit = 0;

    /* Initialise SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialise SDL: %s\n", SDL_GetError());
        exit(-1);
    }

    /* Set a video mode */
    if (!SDL_SetVideoMode(320, 200, 0, 0)) {
        fprintf(stderr, "Could not set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }

    /* Enable Unicode translation */
    SDL_EnableUNICODE(1);

    /* Loop until an SDL_QUIT event is found */
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                /* Look for a keypress */
                case SDL_KEYDOWN:
                {
                    /* Check the SDLKey values and move change the coords */
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            exit(1);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        UartOutput[0] = 0;
        keyPress = 0;
        //Get the keystates
        unsigned char *keystates = SDL_GetKeyState( NULL );
        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {
            SET_BIT(UartOutput[0], 2);
            printf("forward ");
            keyPress = 1;
        }

        //If down is pressed
        if( keystates[ SDLK_DOWN ] )
        {
            SET_BIT(UartOutput[0], 3);
            printf("back ");
            keyPress = 1;
        }

        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
            SET_BIT(UartOutput[0], 1);
            printf("left ");
            keyPress = 1;
        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
            SET_BIT(UartOutput[0], 0);
            printf("right ");
            keyPress = 1;
        }
        if(keyPress == 1)
        {
            rs232_puts(comport_fd, UartOutput, 1);
            printf("\n");
        }
        printf("\t\t%.2x\n", UartOutput[0]);
        usleep(50000);
    }



    /* Clean up */
    rs232_close_port(comport_fd);
    SDL_Quit();
    exit(0);
}
