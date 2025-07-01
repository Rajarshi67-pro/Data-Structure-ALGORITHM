/* 2. Construct a menu driven program using functions that does the following:

      (i) credit an amount

      (ii) debit from the account

     (iii) check account balance

     (iv) display account statement*/
     
#include <stdio.h>
#include <stdlib.h>

double credit(double *balance);
double debit(double *balance);
void checkbal(double balance);
void dispstat(double *transactions, double credits[], double debits[], int credit_count, int debit_count);

int main() {
    double balance = 0.00, transactions[100];
    int choice;
    double credits[100];
    double debits[100];
    int credit_count = 0, debit_count = 0, trans_count = 0;

    while (1) {
        printf(".....BANKING SYSTEM.....\n1. CREDIT\n2. DEBIT\n3. CHECK BALANCE\n4. DISPLAY STATEMENT\n5. EXIT\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                credits[credit_count] = credit(&balance);
                transactions[trans_count++] = credits[credit_count++];
                break;
            case 2:
                debits[debit_count] = debit(&balance);
                transactions[trans_count++] = debits[debit_count++];
                printf("BALANCE AFTER DEBIT: %.2lf\n", balance);
                break;
            case 3:
                checkbal(balance);
                break;
            case 4:
                dispstat(transactions, credits, debits, credit_count, debit_count);
                printf("CURRENT BALANCE IS = %.2lf\n", balance);
                break;
            case 5:
                printf("THANK YOU ! VISIT AGAIN.\n");
                exit(0);
            default:
                printf("INVALID INPUT!\n");
        }
    }
    return 0;
}

double credit(double *balance) {
    double amount;
    printf("ENTER THE AMOUNT TO CREDIT = ");
    scanf("%lf", &amount);
    if (amount > 0) {
        *balance += amount;
        printf("%.2lf AMOUNT CREDITED\n", amount);
        return amount;
    } else {
        printf("INVALID AMOUNT\n");
        return 0;
    }
}

double debit(double *balance) {
    double amount;
    printf("ENTER THE AMOUNT TO DEBIT = ");
    scanf("%lf", &amount);
    if (amount > 0 && amount <= *balance) {
        *balance -= amount;
        printf("%.2lf AMOUNT DEBITED FROM YOUR ACCOUNT\n", amount);
        return amount;
    } else {
        printf("INVALID AMOUNT\n");
        return 0;
    }
}

void checkbal(double balance) {
    printf("YOUR CURRENT BALANCE IS = %.2lf\n", balance);
}

void dispstat(double *transactions, double credits[], double debits[], int credit_count, int debit_count) {
    int i, credit_index = 0, debit_index = 0;
    printf("\n...........| ACCOUNT STATEMENT |...........:\n");
    printf("TRANSACTION NO.   TYPE        AMOUNT\n");
    for (i = 0; i < credit_count + debit_count; i++) {
        if (credit_index < credit_count && (debit_index >= debit_count || transactions[i] == credits[credit_index])) {
            printf("   %d             CREDITED     %.2lf\n", i + 1, credits[credit_index++]);
        } else if (debit_index < debit_count) {
            printf("   %d             DEBITED      %.2lf\n", i + 1, debits[debit_index++]);
        }
    }
}
