// function to find valid solution path through maze
// from start ch to end ch
// should be recursive
const char* find_path(char** maze, int height, int width, char start, char end)
{
	// allocate new path
	char *path = new char[512];
	path[0] = '\0';

	// pass path on as function parameter (easiest way i can think of)
	if (foundPath(maze, height, width, start, end, path))
		return path;

	return "no solution";
}

bool foundPath(char** maze, int height, int width, char start, char end, char* path)
{
	int row, col, rowE, colE;
	bool starting = find_marker(start, maze, height, width, row, col);
	bool ending = find_marker(end, maze, height, width, rowE, colE);

	// base case, complete if contains no end markers in maze
	if (!ending)
		return true;

	// recursive step
	// If can go North
	if (row - 1 >= 0) {
		// if North block contains end
		if (maze[row - 1][col] == end)
		{
			// mark maze appropriately
			maze[row - 1][col] = '#';
			maze[row][col] = '#';
			strcat(path, "N");
			return foundPath(maze, height, width, start, end, path);
		}

		// if North block contains space
		else if (maze[row - 1][col] == ' ')
		{
			maze[row - 1][col] = start;
			maze[row][col] = '#';
			strcat(path, "N");
			
			// if deadend
			if(!foundPath(maze, height, width, start, end, path))
			{
				// forget this path
				maze[row - 1][col] = ' ';
				maze[row][col] = start;
				path[strlen(path) - 1] = '\0';
			} else {
				// not deadend, keep going
				return foundPath(maze, height, width, start, end, path);
			}
		}
	}

	// Other directions uses the same principle
	// South
	if (row + 1 < height) {
		if (maze[row + 1][col] == end) {
			maze[row + 1][col] = '#';
			maze[row][col] = '#';
			strcat(path, "S");
			return foundPath(maze, height, width, start, end, path);
		}
		else if (maze[row + 1][col] == ' ') {
			maze[row + 1][col] = start;
			maze[row][col] = '#';
			strcat(path, "S");
			if(!foundPath(maze, height, width, start, end, path)) {
				maze[row + 1][col] = ' ';
				maze[row][col] = start;
				path[strlen(path) - 1] = '\0';
			} else {
				return foundPath(maze, height, width, start, end, path);
			}
		}
	}

	// East
	if (col + 1 < width) {
		if (maze[row][col + 1] == end) {
			maze[row][col + 1] = '#';
			maze[row][col] = '#';
			strcat(path, "E");
			return foundPath(maze, height, width, start, end, path);
		} else if (maze[row][col + 1] == ' ') {
			maze[row][col + 1] = start;
			maze[row][col] = '#';
			strcat(path, "E");
			if(!foundPath(maze, height, width, start, end, path)) {
				maze[row][col + 1] = ' ';
				maze[row][col] = start;
				path[strlen(path) - 1] = '\0';
			} else {
				return foundPath(maze, height, width, start, end, path);
			}
		}
	}

	// West
	if (col - 1 < width) {
		if (maze[row][col - 1] == end) {
			maze[row][col - 1] = '#';
			maze[row][col] = '#';
			strcat(path, "W");
			return foundPath(maze, height, width, start, end, path);
		}
		else if (maze[row][col - 1] == ' ') {
			maze[row][col - 1] = start;
			maze[row][col] = '#';
			strcat(path, "W");
			if(!foundPath(maze, height, width, start, end, path)) {
				maze[row ][col - 1] = ' ';
				maze[row][col] = start;
				path[strlen(path) - 1] = '\0';
			} else {
				return foundPath(maze, height, width, start, end, path);
			}
		}
	}

	// all adjacent blocks are occupied
	return false;
}