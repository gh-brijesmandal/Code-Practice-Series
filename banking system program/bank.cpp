#include<iostream>
#include<vector>
#include<string>
#include<fstream>

void showBalance(double &balance, std::vector<std::string> &activity,std::vector<int> &balance_record);
void deposit(double &balance, std::vector<std::string> &activity,std::vector<int> &balance_record);
void withdraw(double &balance, std::vector<std::string> &activity,std::vector<int> &balance_record);

int main(){
    double balance = 0;
    int choice = 0;
    std::ofstream file;
    std::vector<std::string> activity;
    std::vector<int> balance_record;
    std::cout << "******************\n";
    std::cout << "Enter your choice: \n";
    std::cout << "1. Show Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Download Activity Statement's .txt file." << std::endl;
    std::cout << "5. Exit\n";
    std::cout << "******************\n";
    std::cout << "What would you like to do? ";
    std::cin >> choice;
    std ::cout << "\n";

    while (choice != 5){
    switch(choice){
        case 1:
            showBalance(balance,activity,balance_record);
            break;
        case 2:
            deposit(balance,activity,balance_record);
            break;
        case 3:
            withdraw(balance,activity,balance_record);
            break;
        case 4:
            // add up all the contents in a file
            file.open("data.txt");
            if (!file.is_open())
            {
                std::cout << "File could not be opened." << std::endl << std::endl;
                break;
            }
            for(int i = 0; i < activity.size(); i++)
            {
                file << activity[i] << " " << balance_record[i] << "\n";
            }
            std::cout << "File downloaded successfully.\n" << std::endl;
            break;
        case 5:
            break;
        default:
            std::cout << "Please enter a number between 1 to 5, inclusive.\n" << std::endl;
            break;
    }
    std::cout << "******************\n";
    std::cout << "Enter your choice: \n";
    std::cout << "1. Show Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Download Activity Statement's .txt file.\n";
    std::cout << "5. Exit\n";
    std::cout << "******************\n";
    std::cout << "What would you like to do? ";
    std::cin >> choice;
    std ::cout << "\n";
}
    return 0;
}


void showBalance(double &balance, std::vector<std::string> &activity,std::vector<int> &balance_record){
    std::cout << "Your current balance is " << balance << std::endl;
    activity.push_back("Your current balance is ");
    balance_record.push_back(balance);
    std::cout << std::endl;
}

void deposit(double &balance, std::vector<std::string> &activity,std::vector<int> &balance_record){
    double deposit;
    std::cout << "Enter the amount of money that you want to deposit? ";
    std::cin >> deposit;
    std::cout << "You deposited " << deposit << std::endl;
    activity.push_back("You deposited ");
    balance_record.push_back(deposit);
    balance = balance + deposit;
    std::cout << "Current Amount = " << balance << std::endl << std::endl;
}

void withdraw(double &balance, std::vector<std::string> &activity,std::vector<int> &balance_record){
    if (balance == 0.0){
        std::cout << "You have 0 balance. Can't withdraw money.\n" << std::endl;
        activity.push_back("Withdraw denied due to no balance.");
        balance_record.push_back(0);
    }
    else{
    double withdraw;
    std::cout << "Enter the amount of money that you want to withdraw? ";
    std::cin >> withdraw;
    if(withdraw > balance)
    {
        std::cout << "Cannot withdraw more than balance.\n" << std::endl;
        activity.push_back("Withdraw denied due to less balance amount.");
        balance_record.push_back(0);
    }
    else{
    std::cout << "You withdrawed " << withdraw << std::endl;
    activity.push_back("You withdrawed ");
    balance_record.push_back(withdraw);
    balance = balance - withdraw;
    std::cout << "Current Amount = " << balance << std::endl << std::endl;
    }
    }
}
