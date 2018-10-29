/*********************************************************************************************
*	 This program helps a prospective borrower calculate the monthly payment for a loan.     *
*    The program also prints the amortization (payoff) table to show the balance of the      *
*    loan after each monthly payment.                                                        *
*                                                                                            *
*	 Name: Jonathan Jones							                                         *
*	 Date: 10/23/2018								                                         *
*********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Included this after watching YouTube video on how to do powers in C.

//Function Declarations
void GetData (double* principalAmount, double* interestRatePerYear, int* numYears);
int CalculateMonths (int numYears);
double CalculateInterestPerMonth (double interestRatePerYear);
double CalculateMonthlyPayment (double principalAmount, double interestRatePerYear, int numYears, int numMonths, double interestRatePerMonth);
void PrintInformation (double principalAmount, double interestRatePerYear, int numYears, int numMonths, double interestRatePerMonth, double monthlyPayment);
void PrintAmortizationTable (double principalAmount, double interestRatePerYear, int numYears, int numMonths, double interestRatePerMonth, double monthlyPayment);


//Start of Main
int main (void)
{
    //Local Declarations
    int numMonths;
    int numYears;
    double interestRatePerYear;
    double interestRatePerMonth;
    double principalAmount;
    double monthlyPayment;

    //Statements
    GetData (&principalAmount, &interestRatePerYear, &numYears);


    numMonths = CalculateMonths (numYears);


    interestRatePerMonth = CalculateInterestPerMonth (interestRatePerYear);


    monthlyPayment = CalculateMonthlyPayment (principalAmount, interestRatePerYear, numYears, numMonths, interestRatePerMonth);


    PrintInformation (principalAmount, interestRatePerYear, numYears, numMonths, interestRatePerMonth, monthlyPayment);


    PrintAmortizationTable (principalAmount, interestRatePerYear, numYears, numMonths, interestRatePerMonth, monthlyPayment);

return 0;
}  //End of Main


/* ====================== GetData =======================
	This function prompts the user to enter data that is
	needed for the program to calculate the users loan
	payment information.
*/
void GetData (double* principalAmount, double* interestRatePerYear, int* numYears)

{
    //Local Declarations
    int principalCounter = 3; //Set the counter to 3.
    int interestCounter = 3; //Set the counter to 3.
    int yearCounter = 3; //Set the counter to 3.

    //Statements
    printf("This program helps a prospective borrower calculate the monthly payment for a loan.\n");
    printf("It also prints the amortization table to show the balance of the loan after each monthly payment.\n\n");

    do
    {
        printf("Please enter the amount of the loan (Principal): "); //Prompt user to enter the amount they are borrowing.
        scanf("%lf", principalAmount); //Saves it to this variable using pointer.

        if (*principalAmount <= 0) //If the user enters bad data than this chunk of code executes.
        {
        printf("\aERROR: Your loan amount has to be greater than $0. Try again.\n");
        principalCounter--; //This subtracts one from the counter if the user entered bad data. This will get the user out of the loop after 3 bad data entries.
        }

        if (principalCounter == 0) // If the counter reaches 0 then this code will run.
        {
            printf("\a\n\nYou failed to enter the correct loan amount 3 times in a row.\n");
            printf("Please look over your data and make sure your entering correct information.\n");
            printf("If you continue to have issues please contact: jjones30@wvup.edu\n\n");
            exit(100); //Program will shut down with this error code so that if the user needs to contact me, they can give me this code so that I know where to begin to look.
        }
    }
    while (*principalAmount <= 0);

    do
    {
        printf("Please enter the interest rate for your loan per year: "); //Prompt user to enter Interest rate per year.
        scanf("%lf", interestRatePerYear); //Saves it to this variable using pointer.

        if (*interestRatePerYear < 0) //If the user enters bad data than this chunk of code executes.
        {
        printf("\aERROR: Your interest rate can't be negative. It has to be 0 or higher. Try again.\n");
        interestCounter--; //This subtracts one from the counter if the user entered bad data. This will get the user out of the loop after 3 bad data entries.
        }

        if (interestCounter == 0) // If the counter reaches 0 then this code will run.
        {
            printf("\a\n\nYou failed to enter the correct interest rate 3 times in a row.\n");
            printf("Please look over your data and make sure your entering correct information.\n");
            printf("If you continue to have issues please contact: jjones30@wvup.edu\n\n");
            exit(101); //Program will shut down with this error code so that if the user needs to contact me, they can give me this code so that I know where to begin to look.
        }
    }
    while (interestRatePerYear < 0);

    do
    {
        printf("Number of years? "); //Prompts user to enter number of years loan is for.
        scanf("%d", numYears); //Saves it to this variable using pointer.

        if (*numYears < 0) //If the user enters bad data than this chunk of code executes.
        {
        printf("\aERROR: Number of years borrowed has to be greater than 0. Try again.\n");
        yearCounter--; //This subtracts one from the counter if the user entered bad data. This will get the user out of the loop after 3 bad data entries.
        }

        if (yearCounter == 0) // If the counter reaches 0 then this code will run.
        {
            printf("\a\n\nYou failed to enter the correct number of years 3 times in a row.\n");
            printf("Please look over your data and make sure your entering correct information.\n");
            printf("If you continue to have issues please contact: jjones30@wvup.edu\n\n");
            exit(102); //Program will shut down with this error code so that if the user needs to contact me, they can give me this code so that I know where to begin to look.
        }
    }
    while (*numYears <= 0);

    system("cls"); //Clears screen.

return;
}  //End of GetData.


/* ====================== CalculateMonths =====================
    This formula used to calculate the number of months
    in the the user borrowed money for.
	It then returns the result to main as variable numMonths.
*/
int CalculateMonths (int numYears)

{
    //Local Declarations
    int numMonths;

    //Statements
    numMonths = numYears * 12;

return numMonths;
}  //End of CalculateMonths.

/* ====================== CalculateInterestPerMonth ====================
	This formula is used to calculate interest per month.
	It then returns the result to main as variable interestRatePerMonth.
*/
double CalculateInterestPerMonth (double interestRatePerYear)

{
    //Local Declarations
    double interestRatePerMonth;

    //Statements
    if (interestRatePerYear > 0) //This runs when the interest rate is greater than 0.
    {
        interestRatePerMonth = (interestRatePerYear / 12) /100;
    }
    else //Runs when above if statement isn't true. That means your interest rate has to be 0 as that is the only other possible outcome.
    {
        interestRatePerMonth = 0;
    }

return interestRatePerMonth;
}  //End of CalculateInterestPerMonth.


/* ====================== CalculateMonthlyPayment ====================
	This formula is used to calculate the users monthly payment.
	It then returns the result to main as variable monthlyPayment.
*/
double CalculateMonthlyPayment (double principalAmount, double interestRatePerYear, int numYears, int numMonths, double interestRatePerMonth)

{
    //Local Declarations
    double P;
    double Q;
    double monthlyPayment;

    //Statements
    if (interestRatePerMonth > 0) //This runs the normal formula if interest rate per month is greater than 0.
    {
        P = pow((1 + interestRatePerMonth), numMonths); //pow is included in math.h library. This makes doing powers easy. Power number is placed after comma and wrapped in ().
        Q = P / (P - 1);
        monthlyPayment = principalAmount * interestRatePerMonth * Q;
    }
    else //This runs when your interest rate per month is 0. You got a great deal.
    {
        monthlyPayment = principalAmount / numMonths;
    }

return monthlyPayment;
}  //End of CalculateMonthlyPayment.

/* ====================== PrintInformation ====================
	This function prints the users basic loan information.
*/
void PrintInformation (double principalAmount, double interestRatePerYear, int numYears, int numMonths, double interestRatePerMonth, double monthlyPayment)

{
    //Statements
    printf("The amount of the loan (principal): \t %.2lf\n\n", principalAmount);
    printf("Interest rate/year (percent): \t\t %.1lf\n\n", interestRatePerYear);
    printf("Interest rate/month (decimal): \t\t %lf\n\n", interestRatePerMonth);
    printf("Number of years: \t\t\t %d\n\n", numYears);
    printf("Number of months: \t\t\t %d\n\n", numMonths);
    printf("Monthly payment: \t\t\t %.2lf\n\n", monthlyPayment);

return;
}  //End of PrintInformation.

/* ====================== PrintAmortizationTable ====================
	This function prints the users loan payoff table. It is broken
	down so that they can see what to expect on a month to month
	basis.
*/
void PrintAmortizationTable (double principalAmount, double interestRatePerYear, int numYears, int numMonths, double interestRatePerMonth, double monthlyPayment)

{
    //Local Declarations
    int counter;
    double oldBalance;
    double newBalance;
    double interestPaid;
    double principalPaid;

    //Statements
    oldBalance = principalAmount;

    printf("\n\tMonth\t\t  Old  \t\tMonthly\t\t Interest\tPrincipal\t  New\n"); //Header top line.
    printf("\t     \t\tBalance\t\tPayment\t\t   Paid  \t  Paid   \tBalance\n\n"); //Header bottom line.
    for (counter = 1; counter <= numMonths; counter++) //Used a for loop since we know how many times loop needs to be run.
    {
        interestPaid = oldBalance * interestRatePerMonth;
        principalPaid = monthlyPayment - interestPaid;
        newBalance = oldBalance - principalPaid; //This gets the new balance.
        printf(" %10d  %18.2lf  %14.2lf  %14.2lf  %14.2lf  %14.2lf\n\n", counter, oldBalance, monthlyPayment, interestPaid, principalPaid, newBalance); //Used printf formatter capability to make columns line up correctly.
        oldBalance = newBalance; //Old balance is now equal to the new balance. The program will start with this on the next loop.
    }

    printf("\nTotal amount paid: %.2lf\n\n", numMonths * monthlyPayment);

return;
}  //End of PrintAmortizationTable.


/*************Test Data**************
*   INTPUT                          *
*   Principal: 5000.00              *
*   Interest rate/year: 11          *
*   Number of Years: 1              *
*   OUTPUT                          *
*   Principal: 5000.00              *
*   Interest rate/year: 11          *
*   Number of Years: 1              *
*   Interest rate/month: 0.009167   *
*   Number of months: 12            *
*   Monthly payment: 441.91         *
************************************/
