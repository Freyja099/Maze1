#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <queue>
#include <cstdlib>

class Maze {
private:
    int width, height;
    std::vector<std::vector<int>> grid;

public:
    Maze(int w, int h);
    void GenerateMaze(int difficulty);
    bool IsSolvable() const;
    const std::vector<std::vector<int>>& GetGrid() const;
};

#endif // MAZE_H
