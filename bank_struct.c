#include <stdio.h>
#include <string.h>

typedef struct bank_acc
{
    char name[34];
    int Acc_num;
    char ifsc[13];
    float balance;
}acc;
void display(acc b);
void display(acc b){
     printf("The Name of Acc. Holder: %s\n", b.name);
    printf("The Account Number: %d\n", b.Acc_num);
    printf("The IFSC Code: %s\n", b.ifsc);
    printf("The Balance of the Acc. Holder: %.2f\n", b.balance);
}


int main(){
    acc accounts[100];
    int count=0;
    char choice;
   do{ 
        printf("Enter the details for account %d:\n", count+1);

        printf("Enter the Name of Acc. Holder:\n");
        scanf("%s", accounts[count].name);

        printf("Enter the Account Number:\n");
        scanf("%d", &accounts[count].Acc_num);

        printf("Enter the IFSC Code:\n");
        scanf("%s", accounts[count].ifsc);

        printf("Enter the amount paid by the Acc. Holder:\n");
        scanf("%f", &accounts[count].balance);

        printf("\nAccount created successfully!\n");
        count++;
        printf("Do you want to create another account? (y/n): ");
        scanf(" %c", &choice);
   }while (choice== 'y'||choice== 'Y');
   
   printf("\nAccount Created!\n");
   for (int i = 0; i < count; i++) {
        printf("\nAccount %d:\n", i + 1);
        display(accounts[i]);
    }
    return 0;
}