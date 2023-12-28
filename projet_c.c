#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100

//global structure to hold customer data
typedef struct customer{
    char name[100];
    int acc_no;
    float balance;
}customer;

//function to create a new account

void createAccount(customer customer_list[], int *customer_count){

    if ( *customer_count < max){
       printf("Enter the name : ");
       scanf("%s", customer_list[*customer_count].name);
       printf("Enter the account number : ");
       scanf("%d",&customer_list[*customer_count].acc_no);
       printf("Enter the balance : ");
       scanf("%d",&customer_list[*customer_count].balance);
       (*customer_count)++;   
       printf("Your account has been created successfully. \n");
    

    }
     
}


//function to deposit an amount

void deposit(customer customer_list[], int customer_count){
    int acc_no;

    int amount;
        printf("Enter the account number : ");
        scanf("%d",&acc_no);
        printf("Enter the amount to deposit : ");
        scanf("%d", &amount);
        for (int i=0 ; i < customer_count ; i++){
            if (customer_list[i].acc_no==acc_no){
                customer_list[i].balance+=amount;
                printf("Amount deposited successfully .\n");
                return;
            }
    }
    printf("Account number not found ! .\n");
}

//function to withdraw amount

void withdraw(customer customer_list[] ,int customer_count){

    int acc_no;
    int amount;
    printf("Enter the account number : ");
    scanf("%d",&acc_no);
    printf("Enter the amount to withdraw : ");
    scanf("%d",&amount);
    for (int i=0 ; i<customer_count ; i++){
        if (customer_list[i].acc_no==acc_no){
            if (customer_list[i].balance >= amount){
                customer_list[i].balance -= amount;
                printf("Amount withdrawn successfully .\n");
            }else{
                printf("Insufficient balance ! .\n");
            }
            return;
        }
    }
    printf("Acount number not found ! .\n");
}

//function to display customer details

void display(customer customer_list[], int customer_count){

    int acc_no;
    printf("Enter the account number : ");
    scanf("%d",&acc_no);
    for (int i=0 ; i < customer_count ; i++){
        if ( customer_list[i].acc_no==acc_no){
            printf("Name : %S\n", customer_list[i].name);
            printf("Balance : %d\n", customer_list[i].balance);
            return;
        }
    }
    printf("Account not found !.\n ");
}

//function to display the list of customers

void displayAccounts(customer customer_list[] , int customer_count){

    printf("\nAccount Number \tName\t\tBalance\t\n");
    for (int i=0 ; i < customer_count ; i++){
        printf("%d\t\t%s\t\t%2.f\n", customer_list[i].acc_no, customer_list[i].name, customer_list[i].balance);
    }
}

//function to update the information of an account

void update(customer customer_list[], int customer_count){

    int acc_no;
    char new_name[100];
    int i;
    printf("Enter the account number : ");
    scanf("%d", &acc_no);
    for( i=0; i < customer_count; i++){
        if (customer_list[i].acc_no == acc_no){
            printf("Enter the new account name : ");
            scanf("%s", new_name);
            strcpy(customer_list[i].name, new_name);
            printf("The bank account with account number %d has been updated successfully .\n ", customer_list[i].acc_no);
            return;
        }
    }
    printf("Account not found !.\n ");
}    

//function to delete an existing bank account

void delete(customer customer_list[], int customer_count){

    int acc_no;
    int i;
    int j;
    printf("Enter the account number : ");
    scanf("%d", &acc_no);
    for(i = 0; i < customer_count; i++){
        if (customer_list[i].acc_no == acc_no){
            break;
        }
    }
    if (i == customer_count){
        printf("Account not found ! .\n");
        return;
    }
    for (j=i ; j < customer_count ; j++){
        customer_list[j] = customer_list[j+1];
    }
    --customer_count;
    printf("Bank account with account number %d has been successfully deleted .\n", acc_no);
}

// main function 

int main(){

    customer customer_list[max];
    int customer_count=0;
    int choice;

    do {

        printf((".\n\t\t Welcome To The Bank Account Management System \n"));
        printf("\n\n1. Create New Account \n");
        printf("2. Update The Information Of An Existing Account \n");
        printf("3. Deposit \n");
        printf("4. Withdraw \n");
        printf("5. Delete An Existing Account \n");
        printf("6. Display The Information Of An Existing Account \n");
        printf("7. Display The List Of Customers \n");
        printf("8. Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch (choice){
           case 1:
              createAccount(customer_list, &customer_count);
              break;
           case 2:
               update(customer_list, customer_count);
               break;
            case 3:
                deposit(customer_list, customer_count);
                break;
            case 4:
                withdraw(customer_list, customer_count);
                break;
            case 5:
                delete(customer_list, customer_count);
                break;
            case 6:
                display(customer_list, customer_count);
                break;
            case 7:
                displayAccounts(customer_list, customer_count);
                break;
            case 8:
                printf("Goodbye ! \n");      
                break;       
            default:
                printf("Invalid choice. Please try again ! \n");
        }
    
    }while (choice != 8 );

    return 0;
}