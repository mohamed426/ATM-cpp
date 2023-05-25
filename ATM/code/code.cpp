#include <bits/stdc++.h>
using namespace std;

string cardserial;

void depositreceipt(int cash, int balance)
{
    int choose;
    cout << "Please Choose What Do You Want" << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "1- Print depositreceipt" << endl;
    cout << "2- Save The Environment" << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "=";
    }
    cout << endl;
    cin >> choose;
    if (choose == 1)
    {
        cout << "Your Deposit is : " << cash << "$" << endl;
        cout << "Your Previous Balance was: " << balance << "$" << endl;
        cout << "Your Current Balance is :" << balance + cash << "$" << endl;
    }
    else if (choose == 2)
    {
        cout << "Thanks For Your Trust" << endl;
    }
    else
    {
        return depositreceipt(cash, balance);
    }
}

void withdrawalreceipt(int cash, int balance)
{
    int choose;
    cout << "Please Choose What Do You Want" << endl;
    for (int i = 0(); i < 25; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "1- Print withdrawal receipt" << endl;
    cout << "2- Save The Environment" << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "=";
    }
    cout << endl;
    cin >> choose;
    if (choose == 1)
    {
        cout << "Your Withdrawal is : " << cash << "$" << endl;
        cout << "Your Previous Balance was: " << balance << "$" << endl;
        cout << "Your Current Balance is :" << balance - cash << "$" << endl;
    }
    else if (choose == 2)
    {
        cout << "Thanks For Your Trust" << endl;
    }
    else
    {
        return withdrawalreceipt(cash, balance);
    }
}

void deposit(int& balance, string pin)
{
    int amount;
    cout << "Enter Amount To Deposit" << endl;
    cin >> amount;
    if (amount > 10000)
    {
        cout << "You Can't Deposit More Than 10,000$\n" << endl;
        return deposit(balance,pin);
    }
    else if (amount <= 0)
    {
        cout << "Invalid Input" << endl;
        return deposit(balance,pin);
    }
    else
    {
        int prev_balance = balance;
        balance += amount;
        cout << "Successful Deposit\n" << endl;
        if (pin == "2222")
        {
            ofstream file("balanceuser1.txt");
            file << balance;
            file.close();
        }
        else if (pin == "0000")
        {
            ofstream file("balanceuser2.txt");
            file << balance;
            file.close();
        }
        depositreceipt(amount, prev_balance);
    }
}

void withdrawal(int& balance,string pin)
{
    int amount;
    cout << "Enter Amount To Withdraw" << endl;
    cin >> amount;
    if (amount > balance)
    {
        cout << "You Can't Withdraw More Than " << balance << "$\n" << endl;
        return withdrawal(balance,pin);
    }
    else if (amount <= 0)
    {
        cout << "Invalid Input" << endl;
        return withdrawal(balance,pin);
    }
    else
    {
        int prev_balance = balance;
        balance -= amount;
        cout << "Successful Withdrawal\n" << endl;
        if (pin == "2222")
        {
            ofstream file("balanceuser1.txt");          
            file << balance;     
            file.close();
        }
        else if (pin == "0000")
        {
            ofstream file("balanceuser2.txt");
            file << balance;
            file.close();
        }
        withdrawalreceipt(amount, prev_balance);
    }
}

void screen(int& balance, string pin)
{
    int chooseprocess;
    for (int i = 0; i < 25; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "1- Deposit" << endl;
    cout << "2- Withdraw" << endl;
    cout << "3- Current Balance" << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "=";
    }
    cout << endl;
    cin >> chooseprocess;
    if (chooseprocess == 1)
    {
        deposit(balance,pin);
    }
    else if (chooseprocess == 2)
    {
        withdrawal(balance,pin);
    }
    else if (chooseprocess == 3)
    {
        if (pin == "0000")
        {
            ifstream file("balanceuser2.txt");
            file >> balance;
            cout << "Your Current Balance is " << balance << "$" << endl;
        }
        else if (pin == "2222")
        {
            ifstream file("balanceuser1.txt");
            file >> balance;
            cout << "Your Current Balance is " << balance << "$" << endl;
        }
    }
    else
    {
        cout << "Invalid Process\n" << endl;
        return screen(balance,pin);
    }
}

void checkPIN()
{
    int balance;
    string PIN;
    cout << "Enter Your PIN" << endl;
    cin >> PIN;
    if (cardserial == "123456789" && PIN == "2222")
    {
        ifstream file("balanceuser1.txt");
        file >> balance;
        file.close();
        cout << "Please Choose What Do You Want" << endl;
        screen(balance,PIN);
    }
    else if (cardserial == "111222333" && PIN == "0000")
    {
        ifstream file("balanceuser2.txt");
        file >> balance;
        file.close();
        cout << "Please Choose What Do You Want" << endl;
        screen(balance,PIN);
    }
    else
    {
        cout << "Wrong PIN. Please Try Again\n" << endl;
        return checkPIN();
    }
}

void checkserial()
{
    cout << "Enter Your Card Serial " << endl;
    cin >> cardserial;

    if (cardserial == "123456789" || cardserial == "111222333")
    {
        checkPIN();
    }
    else
    {
        cout << "Wrong Serial. Please Try Again\n" << endl;
        return checkserial();
    }
}

void continue_exit()
{
    int ask;
    cout << "\nIf You Want To Exit Press 0. To Continue Press 1." << endl;
    cin >> ask;
    if (ask == 0)
    {
        cout << ".....Goodbye....." << endl;
    }
    else if (ask == 1)
    {
        cout << "For More Security Please ";
        checkPIN();
        continue_exit();
    }
    else
    {
        cout << "Invalid Input" << endl;
        return continue_exit();
    }
}


int main()
{
    system("color 03");
    checkserial();
    continue_exit();
}