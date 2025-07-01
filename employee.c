/* 3. Create a structure named "Employee" to store employee details such as employee ID, name, and salary.

Write a program to input data for three employees, find the highest salary of employee and display their information. [Apply pointer to structure]*/

#include<stdio.h>
#include<string.h>

struct Employee{
    char id[20];
    char name[50];
    float salary;
};

void inputEmployee(struct Employee* emp);
void displayEmployee(struct Employee* emp);

int main(){
    struct Employee employees[3];
    for(int i = 0 ; i < 3 ; i++){
        printf("ENTER DETAILS OF EMPLOYEE %d :\n",i+1);
        inputEmployee(&employees[i]);
        
    }
    struct Employee* highSalEmp = &employees[0];
    for(int i = 0;i<3;i++){
        if(employees[i].salary > highSalEmp->salary){
            highSalEmp = &employees[i];
        }
    printf("EMPLOYEE WITH HIGHEST SALARY :\n");
    displayEmployee(highSalEmp);
    }
    
return 0;    
}

void inputEmployee(struct Employee* emp){
    printf("ENTER YOUR EID =");
    scanf("%s",emp->id);
    printf("ENTER NAME :");
    scanf("%s",emp->name);
    printf("ENTER THE SALARY =");
    scanf("%f",&emp->salary);
}

void displayEmployee(struct Employee* emp){
    printf("EMPLOYEE ID : %s\n",emp->id);
    printf("EMPLOYEE NAME : %s\n",emp->name);
    printf("EMPLOYEE SALARY : %.2f\n",emp->salary);
}


