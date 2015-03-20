#ifndef A4_HPP
#define A4_HPP

#include "Maze.hpp"

int nrows_;
int ncols_;
int xpos_;
int ypos_;
int optimal_distance_ = -1;
int current_distance_;
Maze& maze_;

// implement your function distance
int distance(Maze& maze, int sx, int sy, int fx, int fy) {
	if ((sx == fx) && (sy == fy)){return 0}
	maze_ = maze;
	nrows_ = maze.nrow();
	ncols_ = maze.ncol();
	xpos_ = sx;
	ypos_ = sy;
	if (

	return optimal_distance_;
} // distance

void shortest_path(){
	
	
}

bool is_above_available(int cx, int cy) {
	return (!(maze_.is_visited(cx, cy - 1))
}
bool is_below_available(int cx, int cy) {
	return (!(maze_.is_visited(cx, cy + 1))
}
bool is_left_available(int cx, int cy) {
	return (!(maze_.is_visited(cx - 1, cy))
}
bool is_right_available(int cx, int cy) {
	return (!(maze_.is_visited(cx + 1, cy))
}

#endif // A4_HPP
