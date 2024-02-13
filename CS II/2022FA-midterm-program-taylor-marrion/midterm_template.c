#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10  // Do NOT change this line!

/**
 * Structure definition should go here.
 * 
 * You should typedef this to point2d
 */
struct point2d_def
{
	int x;
	int y;
};
typedef struct point2d_def point2d;


/** Function prototypes **/
void fill(char filename[], point2d P[]);
int getdist(point2d p, point2d q);
void closest(point2d P[], int G[2*N][2*N]);
void grid(point2d P[], int G[2*N][2*N]);
void printpoints(char filename[], point2d P[]);
void printgridxy(char filename[], int G[2*N][2*N]);

int main(int argc, char *argv[])
{
	/**
	 * Do not change anything in main!  Also do not change the #define at the top 
	 * of the program, or any of the function definitions/prototypes.
	 */
	if (argc != 3)
	{
		printf("Syntax Error: ./a.out <infile> <outfile>\n");
		exit(1);
	}

	point2d P[N];
	int G[2*N][2*N] = {0};

	fill(argv[1], P);
	grid(P, G);
	printpoints(argv[2], P);
	printgridxy(argv[2], G);


	return 0;
}

void fill(char filename[], point2d P[])
{
	/**
	 * This function opens and reads from the input file.  You should close the 
	 * file when you are done with it.  Read the points into the array of 
	 * structures in this function.
	 *
	 * Don't forget to check if the file name is valid.
	 */
	FILE *ifp = NULL;
	ifp = fopen(filename, "r");

	if (ifp == NULL) {
		// file did not open correctly
		printf("Could not open file for reading!\n");
		exit(1);
	}

	for (int i = 0; i < N; i++){
		fscanf(ifp, "%d %d", &P[i].x, &P[i].y);
	}

	// close input file pointer
	fclose(ifp);
}

int getdist(point2d p, point2d q)
{
	/**
	 * This function gets the distance between 2 points and returns that value.
	 * 
	 * Yes, you need to do some math here...
	 * 
	 * You should return the squared distance, rather than taking the square root.
	 */
	int dist, vert, horiz;

	vert = q.y - p.y;
	horiz = q.x - p.x;
	dist = (vert * vert) + (horiz * horiz);

	return dist;
}

void closest(point2d P[], int G[2 * N][2 * N])
{
	/**
	 * This function finds the 2 points that are the closest.
	 * 
	 * You should call the getdist() function from inside here.
	 */

	// find the 2 points that are closest
	int closest = INT_MAX;
	int temp;
	int points[2];

	for (int i = 0; i < N-1; i++){
		for (int j = i+1; j < N; j++){
			temp = getdist(P[i], P[j]);
			if (temp < closest){
				closest = temp;
				points[0] = i;
				points[1] = j;
			}
		}
	}

	// set values in G to unique values
	int high_val = 2 * N - 1;
	int row, col;
	for (int i = 0; i < 2; i++){
		row = high_val - P[points[i]].y;
		col = P[points[i]].x;
		G[row][col] = 2;
	}
}

void grid(point2d P[], int G[2 * N][2 * N])
{
	/**
	 * This function will transfer all the points from your structure into a 
	 * 2D array used as the grid.
	 * 
	 * You will call the closest() function from inside here.
	 */

	// set G for each of the N points
	int high_val = 2 * N - 1;
	int row, col;
	for (int i = 0; i < N; i++){
		row = high_val - P[i].y;
		col = P[i].x;
		G[row][col] = 1;
		//printf("%d: (%2d, %2d) -> [%d][%d]\n", i, P[i].x, P[i].y, row, col);	// TESTING
	}

	closest(P, G);
}

void printpoints(char filename[], point2d P[])
{
	/**
	 * This function will print off the list of all the points you have in the 
	 * following form:
	 * 
	 * num: (x, y)
	 * 
	 * ex.
	 * 0: ( 4,  1)
	 * 1: (12, 13)
	 * 
	 * **Note the spacing!**
	 * 
	 * You need to open the output file here and write to it.
	 */
	FILE *ofp = NULL;
	ofp = fopen(filename, "w");

	if (ofp == NULL) {
		// file did not open correctly
		printf("Could not open file for writing!\n");
		exit(1);
	}

	for (int i = 0; i < N; i++){
		fprintf(ofp, "%d: (%2d, %2d)\n", i, P[i].x, P[i].y);
	}

	// close output file pointer
	fclose(ofp);
}

void printgridxy(char filename[], int G[2 * N][2 * N])
{
	/**
	 * This function will print out your 2D array (the grid)
	 * 
	 * Use ' ' for spots without a point,
	 * use '*' for spots with a point,
	 * use 'X' for the 2 points that are closest.
	 * 
	 * Put 1 space between each element, for example you should print "* "
	 * instead of just "*".
	 * 
	 * 
	 * You should also have a top and bottom made of 50 hyphens (-)
	 * 
	 * This should be printed to the same file as the points were.
	 * Be careful not to overwrite the file!
	 */
	FILE *ofp = NULL;
	ofp = fopen(filename, "a");

	if (ofp == NULL) {
		// file did not open correctly
		printf("Could not open file for writing!\n");
		exit(1);
	}

	int border = 50;
	for (int i = 0; i < border; i++){
		fprintf(ofp, "-");	// no built-in way to repeatedly print char
	}
	fprintf(ofp, "\n");

	int size = 2 * N;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			int temp = G[i][j];
			switch(temp){
				case 0:
					fprintf(ofp, "  ");
					break;
				case 1:
					fprintf(ofp, "* ");
					break;
				case 2:
					fprintf(ofp, "X ");
					break;
			}
		}
		fprintf(ofp, "\n");
	}

	for (int i = 0; i < border; i++){
		fprintf(ofp, "-");
	}
	fprintf(ofp, "\n");

	// close output file pointer
	fclose(ofp);
}