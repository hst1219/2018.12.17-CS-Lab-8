#include "stdio.h"
#include "stdlib.h"
#pragma warning(disable:4996)

struct Studentdata {
	int ST;
	char lastname[16];
	char firstname[11];
	double BMI;
};

	int main() {

		FILE *cfPtr;

		struct Studentdata student = { 0, "" , "", 0.0 };

		if ((cfPtr = fopen("students.dat", "wb")) == NULL)
		{
			printf("File could not be opened.\n");
		}

		else {
			printf("Enter your student ID -1 to end input)\n ? ");
			scanf("%d", &student.ST);

			rewind(cfPtr);

			while (student.ST != -1)
			{
				printf("Enter lastname, firstname, BMI\n? ");
				scanf("%s%s%lf", student.lastname, student.firstname, &student.BMI);

				fwrite(&student, sizeof(struct Studentdata), 1, cfPtr);

				printf("Enter student ID , -1 to endinput)\n ? ");
				scanf("%d", &student.ST);
			}
			fclose(cfPtr);
		}

		printf("\n\n\n\n");
		

		if ((cfPtr = fopen("students.dat", "rb")) == NULL)
			printf("File could not be opened.\n");
		else {
			printf("%6s%16s%20s%15s \n", "STUDENTID", "Last Name", "First Name", "BMI");

			while (1) {
				fread(&student, sizeof(struct Studentdata), 1, cfPtr);
				if (feof(cfPtr)) break;
				if (student.ST != 0)
					printf("%6d%16s%20s            %lf\n",student.ST, student.lastname,student.firstname, student.BMI);
			}
			fclose(cfPtr);
		}
		




		system("pause");
		return 0;
	}
