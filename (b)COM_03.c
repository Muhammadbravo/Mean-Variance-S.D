#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500
#define FILENAME "random_vvar.txt"
int main(void)
{
/* Declare variables. */
unsigned int seed, result;
int k;
double a1=0, b1=500, a2=0, b2=500;
double rand_floatA(double a1, double b1);
double rand_floatB(double a2, double b2);
FILE *randv;
int j, count=0;
float aa1=3.134, aa2=0.536, bb1=4.886, bb2=7.464;
double sqn1[N], sqn2[N], mean_value1, mean_value2, sum1=0, sum2=0;
float mean1 , mean2, variance1, variance2;
FILE *rands;

             printf("\tTHIS PRORAGM COMPARE THE GENERATES THEORITICAL AND COMPUTED MEANS \n");
                        printf("\t\t OF TWO SEQUENCE OF 500 POINTS \n\n");
/* Get seed value from the user. */
printf("Enter a positive integer seed value: \n");
scanf("%u",&seed);
srand(seed);
/* Generate and print two sequence of 500 points. */
printf("Two sequence of \"500 Points\" has been generated and stored into the file named "FILENAME": \n");
randv = fopen("C:\\Users\\sarki_bravo\\Documents\\C level2\\random_vvar.txt", "w");
        if (randv == NULL)
        {
            printf("the file is empty!");
            exit(1);
        }

        for (k=1; k<=500; k++)
            {
            fprintf(randv, "\t%f\n \t\n%f",rand_floatA(a1,b1),rand_floatB(a2,b2));
            }
    fclose(randv);
    printf("\n");
/* Exit program. */

printf("Enter any value to print the results: \n\a");
scanf("%u", &result);
srand(result);

printf("\n");
 variance1 = sqrt(((bb1-aa1)*(bb1-aa1))/12);
 mean1 = (aa1 + bb1)/2;
 variance2 = sqrt(((bb2-a2)*(bb2-aa2))/12);
mean2 = (aa2 + bb2)/2;

    printf("The theoritical Mean and Variance for Sequence 1 are: \n");
    printf("mean_value1 = %.f \t variance_value1 = %.1f", mean1,variance1);
    printf("\n\n");
    printf("The theoritical Mean and Variance for Sequence 2 are: \n");
    printf("mean_value2 = %.f \t variance_value2 = %.f", mean2,variance2);
    printf("\n\n");
/* Open file, read data into an array, */
/* and compute the mean of the two sequence. */
    randv = fopen(FILENAME,"r");
    if (randv == NULL)
    printf("Error opening input file. \n");
        else
        {
/* Input and process data. */
        for (j=0; j<=N-1; j++)
            {
        (fscanf(randv,"%lf %lf",&sqn1[j],&sqn2[j]));
            sum1 += sqn1[j];
            sum2 += sqn2[j];
        }
        mean_value1 = (sum1/ N)/500*8;
        mean_value2 = (sum2/N)/500*8;

            printf("The Computed Mean values are: \n");
        printf("Mean_value1 = %f \nMean_value2= %f \n", mean_value1, mean_value2);
         printf("\n");
         fclose(randv);
        }
    /* stores the results in  file folder */
    rands = fopen("C:\\Users\\sarki_bravo\\Documents\\C level2\\raandom_var.txt", "w");
        if (rands == NULL)
        {
            printf("the file is empty!");
            exit(1);
        }

        fprintf(rands,"The computed Mean values are: \n");
       fprintf(rands, "Mean_value1 = %f \tMean_value2= %f \n", mean_value1, mean_value2);
         printf("\n");
         fclose(rands);
    printf("\n");

return 0;
}
double rand_floatA(double a1, double b1) /* function to compute the first sequence*/
{
    return ((double)rand()/RAND_MAX)*500;
}
double rand_floatB(double a2, double b2) /* function to compute the second sequence*/
{
    return ((double)rand()/RAND_MAX)*500;
}
