#include <stdio.h>

//Storing User 1. Name, 2. Postal Code, 3. Year
struct Info
{
    char name[25];
    char post[25];
    int Year;
    int age;
};


//User information is stored then displayed.
int uInfo(struct Info* info)
{
    int Age;
    
    printf("-> Enter your name : ");
    scanf("%s", info->name);
    printf("-> Enter your Year of birth : ");
    scanf("%d", &info->Year);
    printf("-> Enter your postal code : ");
    scanf("%s", info->post);
    
    Age = 2024 - info->Year;
    
    printf("\n");
    printf("*********************************************\n");
    printf("Saving person's information in database...\n");
    printf("*********************************************\n");
    
    printf("\n");
    printf("====================\n");
    printf(" Saved Information\n");
    printf("====================\n");
    printf("1. Name : %s\n", info->name);
    printf("2. Age  : %d\n", Age);
    printf("3. Post : %s\n", info->post);
    printf("\n");
    
    
    return Age;
}


//User choice to redirect to a function.
int Choice(int Selection)
{
    int running = 1;
    int Final_Selection = 0;

    
    while(running == 1)
    {
        if (Selection < 1)
        {
            printf("ERROR : Enter a digit more than 0 to make a selection..\n");
        }
        else if (Selection > 3)
        {
            printf("ERROR : Enter a digit less than 3...\n");
        }
        else if ((Selection > 0) && (Selection <= 3))
        {
             Final_Selection = Selection;
            running = 0;
        }
        else
        {
            printf("ERROR: Invalid input, Try again.");
        }
    }
    
    return Final_Selection;
}

//If commands to check for Driving eligiblity.
void Drive(int age)
{
    int Fage = age;
    
    printf("\n");
    printf("*********************\n");
    printf("you are %d years old.\n", Fage);
    printf("*********************\n");
    printf("\n");
    
    printf("RESULT : \n");
    if ((age > 15) && (age < 19))
    {
        printf("Eligible to drive in the company of a person holding a comeplete 'G' license and a driving experience of 4 years\n");
    }
    else if ((age > 19) && (age < 25))
    {
        printf("Permitted to drive..\n");
    }
    else if (age < 15)
    {
        printf("NO!\n Why are you even here?\n");
    }
    else if (age > 99)
    {
        printf("Dead people shouldn't drive.\n");
    }
    else
    {
        printf("ERROR: Invalid input.\n");
    }
}


//If commands to check if the user is allowed to drink.
void Drink(int age)
{
    int Dage = age;
    
    printf("\n**** You are %d years old ***\n", Dage);
    printf("\n");
    
    printf("RESULT:\n");
    
    if ((Dage > 19) && (Dage < 80))
    {
        printf("The person is of the legal age in Ontario and can drink.\n");
    }
    else if (Dage > 80)
    {
        printf("You probably should not drink, It may cause you health issues.\n");
    }
    else if ((Dage < 19) && (Dage > 1))
    {
        printf("The person is is not eligible to drink in Ontario.\n");
    }
    else if (Dage < 1)
    {
        printf("Liar! a person who's not born can't be here..\n");
    }
    else
    {
        printf("ERROR: INVALID INPUT\n");
    }
}

//Main function.

int main(void)
{
    int age;
    int Selection;
    
    struct Info info1;
    printf("=====================\n");
    printf(" Legal Age Dterminer\n");
    printf("=====================\n");
    printf("\n");
    
    age = uInfo(&info1);
    printf("%d is the age saved.\n", age);
   
    do
    {
        printf("\n");
        printf("======================\n");
        printf("  Make a Selection\n");
        printf("======================\n");
        
        printf("-> Press 1 to check \"Driving\" eligiblity.\n-> Press 2 to check \"Alcohol\" drinking eligiblity\n-> Press 3 to \"END\" Program\n");
        printf("\n***** Your selection *****\n");
        printf("-> Select any option [1,2,3] : ");
        scanf("%d", &Selection);
        
        Selection = Choice(Selection);
        
        switch (Selection)
        {
            case 1 :
                printf("CHECKING DRIVER ELIGIBLITY : \n");
                Drive(age);
                break;
            case 2:
                printf("\n CHECKING DRINKING ELIGIBLITY : \n");
                Drink(age);
                break;
            case 3 :
                printf("\nENDING PROGRAM...\n");
                break;
            default :
                printf("Error : Invalid input.\n");
                break;
        }
        
    }while (Selection != 3);
    
    for (int i = 0; i < 5 ; i++)
    {
        printf("*\n");
    }
    printf("PROGRAM EXECUTION SUCCESSFUL.\n");
    printf("Application ended.\n");
    
    return 0;
}
