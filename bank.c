#include <stdio.h>

float loadBalance() {
    float balance;
    FILE *fp = fopen("balance.txt", "r");

    if (fp == NULL) {
        // File doesn't exist → start with 0 balance
        return 0.0;
    }

    fscanf(fp, "%f", &balance);
    fclose(fp);

    return balance;
}

void saveBalance(float balance) {
    FILE *fp = fopen("balance.txt", "w"); // REWRITE mode
    fprintf(fp, "%.2f", balance);
    fclose(fp);
}

int main() {
    int choice;
    float balance, amt;
    int senderAcc, receiverAcc;

    balance = loadBalance();

    do {
        printf("\n--- BANK MENU ---\n");
        printf("1. View Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Pay To Bank\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Current Balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amt);

                if (amt > 0) {
                    balance += amt;
                    saveBalance(balance);
                    printf("Deposit successful!\n");
                } else {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amt);

                if (amt > balance) {
                    printf("Insufficient balance!\n");
                } else if (amt <= 0) {
                    printf("Invalid amount!\n");
                } else {
                    balance -= amt;
                    saveBalance(balance);
                    printf("Withdrawal successful!\n");
                }
                break;

            case 4:
                printf("Enter Sender Account No: ");
                scanf("%d", &senderAcc);

                printf("Enter Receiver Account No: ");
                scanf("%d", &receiverAcc);

                printf("Enter Amount: ");
                scanf("%f", &amt);

                if (amt > balance) {
                    printf("Insufficient balance!\n");
                } else if (amt <= 0) {
                    printf("Invalid amount!\n");
                } else {
                    balance -= amt;
                    saveBalance(balance);
                    printf("Payment successful!\n");
                }
                break;

            case 5:
                saveBalance(balance);
                printf("Thank you for using the bank!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
