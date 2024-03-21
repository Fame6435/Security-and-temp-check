/*
Submitted By: <Faheem>
   Homework Number: <8>
    Credit to: Faheem Khan
Submitted on <11/18/2022>
  By submitting this program with my name,
   I affirm that the creation and modification
         of this program is primarily my own work.
         */
/* this program will ask the user for name and password before granting access to the system. It will read the names and IDs
of people in file iddate-3.txt and compare the user's input to those in the file and if correct will display the user's name and ID. after that it will scan the temperature measurements
 in file temp-1.txt and calculate the average for each row and display the output*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>



int main(void) {

    FILE *idfile, *tempFile; //assign variables
    idfile = fopen("iddata-3.txt", "r"); //variable for name and IDs file
    tempFile = fopen("temp-1.txt", "r"); //variable for temperature measurements file
    int num = 0;

    char Name[20], username[20]; //assign arrays
    int ID, userId;

    printf("this is Faheem Khan\n\n");

    if ((idfile == NULL) || (tempFile == NULL)) {  //if at least one file is not found
        printf("File(s) not found");
    }
    else{


       while(num==0)
        {
            printf("Enter Name\n");  //asks user for input
            scanf("%s", username);
            printf("Enter ID\n");
            scanf("%d", &userId);
            idfile = fopen("iddata-3.txt", "r");
            while ((fscanf(idfile, "%s %d", Name, &ID) == 2))
            {
                if ((strcmp(Name, username)==0)&&(ID== userId)) //decides if user name and/or data corresponds with one in file
                    {
                        printf("Name   ID\n");  //displays output
                        printf("-----------\n");
                        printf("%s, %d", Name, ID);
                        num=1;
                    }
            }
            fclose(idfile); //closes file
        }


    }

    fclose(tempFile);


}

