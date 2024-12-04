#include "Maze.h"

Maze::Maze(int w, int h) : width(w), height(h), grid(h, std::vector<int>(w, 0)) {}

void Maze::GenerateMaze(int difficulty) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                grid[y][x] = 1;
            } else {
                grid[y][x] = (rand() % difficulty == 0) ? 1 : 0;
            }
        }
    }
    grid[1][1] = grid[height - 2][width - 2] = 0;

    for (int y = 2; y < height - 2; y += 2) {
        for (int x = 2; x < width - 2; x += 2) {
            grid[y][x] = 1;
            int direction = rand() % 4;
            switch (direction) {
                case 0: grid[y - 1][x] = 1; break;
                case 1: grid[y + 1][x] = 1; break;
                case 2: grid[y][x - 1] = 1; break;
                case 3: grid[y][x + 1] = 1; break;
            }
        }
    }
}

bool Maze::IsSolvable() const {
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == width - 2 && y == height - 2) return true;

        for (const auto& [dx, dy] : std::vector<std::pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && grid[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

const std::vector<std::vector<int>>& Maze::GetGrid() const {
    return grid;
}
