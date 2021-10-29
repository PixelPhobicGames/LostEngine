#include <raylib.h>

typedef struct Player{

    // Cords

    int X;
    int Y;

    int OldX;
    int OldY;

    int Width;
    int Height;
    int Direction;

    bool Moving;

    bool DrawingEnabled;

    // Stats

    int Attack;
    int Speed;
    int Defense;
    int Stamina;

    // Animation Frames 

    Texture2D FacingFrame1;
    Texture2D FacingFrame2;
    Texture2D FacingFrame3;

    Texture2D BackFrame1;
    Texture2D BackFrame2;
    Texture2D BackFrame3;

    Texture2D RightFrame1;
    Texture2D RightFrame2;
    Texture2D RightFrame3;

    Texture2D LeftFrame1;
    Texture2D LeftFrame2;
    Texture2D LeftFrame3;

}Player;


static Player LostPlayer;

