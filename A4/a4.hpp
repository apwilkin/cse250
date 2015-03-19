#ifndef A4_HPP
#define A4_HPP

#include "Maze.hpp"

int nrows_;
int ncols_;
Maze& maze_;
// implement your function distance
int distance(Maze& maze, int sx, int sy, int fx, int fy) {
	maze_ = maze;
	nrows_ = maze.nrow();
	ncols_ = maze.ncol();
} // distance

bool is_above(int cx, int cy) {
	maze_.is_visited(cx, cy - 1)
}

bool is_below(int cx, int cy) {
	
}

bool is_left(int cx, int cy) {
	
}

bool is_right(int cx, int cy) {
	
}

#endif // A4_HPP
