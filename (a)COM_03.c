#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 7
#define FILENAME "random_var.txt"

 main(void)
{
/* Declare variables. */
    int j=0, npts;
    double y[N];
    FILE *random_var;
    double variance_value, mean_value;
    double mean(double x[],int npts);
    double variance(double x[],int npts);
    unsigned int seed;
    int seed2;
    double rand_float(double a, double b);
    int a, b, k;
    FILE *randf;

        printf("\t\t THIS PROGRAM GENERATES RANDOM FLOATING POINTS VALUES \n \t\t\tBETWEEN TWO INPUT LIMITS \n");
        printf("\n");
/* Get seed value from the user. */
printf("Enter a positive integer seed value: \n"); //* A value that stores random number */
scanf("%u",&seed);
srand(seed);
printf("Enter lower limits (a) and the upper limit (b) NB:\"(a < b)\": \n");
scanf("%i %i",&a,&b);

printf("\n");
    randf = fopen("C:\\Users\\sarki_bravo\\Documents\\C level2\\random_var.txt", "w");
        if (randf == NULL)
        {
            printf("the file is empty!");
            exit(1);
        }

        for (k=1; k<=N; k++)
                {
            fprintf(randf, " %f", rand_float(a,b));
                }
        fclose(randf);
        printf("\n");
            printf("\tRandom Numbers between %i and %i have been generated \n \tand stored into the file named: "FILENAME" \n\a", a,b);
printf("\n \n");
             printf("\tTO PRINT THE THEORETICAL AND COMPUTED MEAN AND VARIANCE \n");
    printf("\t\t OF THE RANDOM FLOATING POINT GENERATED \n\n");
    printf("Enter any value to print Results: ");
    scanf("%u", &seed2);
    printf("\n");
            /* formula to calculate the theoretical mean and variance */
            variance_value = sqrt(((b-a)*(b-a))/12);
            mean_value = (a + b)/2;
            printf("\n \n");

    printf("\tTHE THEORETICAL AND COMPUTED MEAN AND VARIANCE \n");
        printf("Theoretical Values are: \n");
        printf("Mean = %f \tVariance = %f", mean_value, variance_value);
        printf("\n");
    printf("\n");
        /* Open file, read data into an array. */
        random_var = fopen(FILENAME,"r");
        if (random_var == NULL)
            printf("Error opening input file. \n");
        else
            {
                while ((fscanf(random_var,"%lf",&y[j])) == 1) /* loop until it reaches the end of file and returns 0 to the operating sys */
                j++;
                npts = j;
                /* Find and print the mean an variance values. */
                printf("The computed values are: \n");
        printf("Mean = %f \tVariance= %f \n",mean(y,npts),variance(y,npts));
         printf("\n");
        /* Close file and exit program. */
        fclose(random_var);
            }
            printf("\n");
        /* Exit program. */
        return 0;

}
double rand_float(double a, double b)
{
    return ((double)rand()/RAND_MAX)*(b-a) + a;
}
/* This function returns the mean value of the */
/* array x with n elements. */
double mean(double x[],int npts)
{
/* Declare and initialize variables. */
int j;
double sum=0;
/* Determine mean value. */
for (j=0; j<=npts-1; j++)
sum += x[j];
/* Return mean value. */
return sum/npts;
}
/* This function returns the variance value of the */
/* array x with n elements. */
double variance(double x[],int npts)
{
/* Declare variables and function prototypes. */
int j;
double sum=0, mu;
double mean(double x[],int npts);
/* Determine variance. */
mu = mean(x,npts);
for (j=2; j<=npts-1; j++)
sum += (x[j] - mu)*(x[j] - mu);
/* Return variance. */
return sum/(npts-1);
}

