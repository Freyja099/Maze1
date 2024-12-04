#ifndef MAZEGAME_H
#define MAZEGAME_H

#include "Player.h"
#include "Maze.h"
#include "raylib.h"

class MazeGame {
private:
    const int screenWidth;
    const int screenHeight;
    Maze maze;
    Player player;
    int difficulty;
    bool gameFinished;
    bool mazeCompleted;
    double startTime;
    double elapsedTime;

    void ShowLevelSelection();
    void PlayGame();
    void ShowMazeCompletionScreen();
    void ShowEndScreen();

public:
    MazeGame(int screenW, int screenH);
    void Run();
};

#endif // MAZEGAME_H
