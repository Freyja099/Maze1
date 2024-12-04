#include "MazeGame.h"

MazeGame::MazeGame(int screenW, int screenH)
    : screenWidth(screenW), screenHeight(screenH), maze(screenW / tileSize, screenH / tileSize),
      player({1, 1}), difficulty(3), gameFinished(false), mazeCompleted(false) {}

void MazeGame::Run() {
    InitWindow(screenWidth, screenHeight, "Maze Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (!gameFinished) {
            if (difficulty == 3) {
                ShowLevelSelection();
            } else if (mazeCompleted) {
                ShowMazeCompletionScreen();
            } else {
                PlayGame();
            }
        } else {
            ShowEndScreen();
        }
    }
    CloseWindow();
}

// Implementation for the other member functions goes here...
