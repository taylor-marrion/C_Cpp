#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LENGTH 10

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus]);
void printGrades(int assigns, int stus, int grades[assigns][stus]);
void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH]);
void printStudents(int stus, char students[stus][NAME_LENGTH]);
void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[]);
void printFinalLetterGrades(int stus, double final_grades[]);
void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[]);

int main(int argc, char *argv[])
{
	// check valid arguments
	if (argc != 2) {
		printf("Syntax Error: ./<exec> <input file>\n");
		exit(1);
	}

	FILE *ifp = NULL;
	ifp = fopen(argv[1], "r");

	if (ifp == NULL) {
		// file did not open correctly
		printf("Could not open file for reading!\n");
		exit(1);
	}

	// get assigns
	int assigns;
	fscanf(ifp, "%d", &assigns);

	// get stus
	int stus;
	fscanf(ifp, "%d", &stus);

	// create arrays
	int grades[assigns][stus];
	char students[stus][NAME_LENGTH];
	double final_grades[stus];

	// get students
	getStudents(ifp, stus, students);
	// print students
	printStudents(stus, students);
	// get grades
	getGrades(ifp, assigns, stus, grades);
	// print grades
	printGrades(assigns, stus, grades);
	// calculate grades
	calcGrades(assigns, stus, grades, final_grades);
	// print letter grades
	printFinalLetterGrades(stus, final_grades);
	// print names and percentages
	printPercentageGrades(stus, students, final_grades);

	// close input file pointer
	fclose(ifp);

	return 0;
}

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus])
{
	for (int i = 0; i < assigns; i++){
		for (int j = 0; j < stus; j++){
			fscanf(ifp, "%d", &grades[i][j]);
		}
	}
}

void printGrades(int assigns, int stus, int grades[assigns][stus])
{
	for (int i = 0; i < assigns; i++){
		for (int j = 0; j < stus; j++){
			printf("%10d", grades[i][j]);
		}
		printf("\n");
	}
}

void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH])
{
	for (int i = 0; i < stus; i++){
		fscanf(ifp, "%s", &students[i]);
	}
}

void printStudents(int stus, char students[stus][NAME_LENGTH])
{
	for (int i = 0; i < stus; i++){
		printf("%10s", students[i]);
	}
	printf("\n\n");
}

void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[])
{
	for (int i = 0; i < stus; i++){
		for (int j = 0; j < assigns; j++){
			final_grades[i] += (grades[j][i] * 1.0);
		}
		final_grades[i] /= assigns;
	}
}

void printFinalLetterGrades(int stus, double final_grades[])
{
	char grade;
	for (int i = 0; i < stus; i++){
		if (final_grades[i] >= 90.0) {
			grade = 'A';
		} else if (final_grades[i] >= 80.0){
			grade = 'B';
		} else if (final_grades[i] >= 70.0){
			grade = 'C';
		} else if (final_grades[i] >= 60.0){
			grade = 'D';
		} else {
			grade = 'F';
		}

		printf("%10c", grade);
	}
	printf("\n\n\n\n");
}

void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[])
{
	for (int i = 0; i < stus; i++){
		printf("%10s : %.2f %\n", students[i], final_grades[i]);
	}
}