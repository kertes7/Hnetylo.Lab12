 #include <iostream> 

#include <Windows.h> 

#include <string> 

  

class BankAccount { 

protected: 

    double balance; 

    std::string accountNumber; 

  

public: 

    BankAccount(const std::string& accNum, double bal) 

        : accountNumber(accNum), balance(bal) { 

    } 

  

    bool withdraw(double amount) { 

        SetConsoleCP(1251); 

        SetConsoleOutputCP(1251); 

        if (amount > balance) { 

            std::cout << "Недостатньо коштів." << std::endl; 

            return false; 

        } 

        balance -= amount; 

        return true; 

    } 

  

    void displayBalance() const { 

        std::cout << "Номер рахунку: " << accountNumber << ", Баланс: " << balance << std::endl; 

    } 

}; 

  

class SavingsAccount : public BankAccount { 

private: 

    double interestRate; 

  

public: 

    SavingsAccount(const std::string& accNum, double bal, double rate) 

        : BankAccount(accNum, bal), interestRate(rate) { 

    } 

  

    void applyInterest() { 

        balance += balance * (interestRate / 100); 

    } 

  

    void displayAccountDetails() const { 

        SetConsoleCP(1251); 

        SetConsoleOutputCP(1251); 

        displayBalance(); 

        std::cout << "Процентна ставка: " << interestRate << "%" << std::endl; 

    } 

}; 

  

int main() { 

    SetConsoleCP(1251); 

    SetConsoleOutputCP(1251); 

    SavingsAccount sa("7945", 5000.0, 10.0); 

  

    sa.displayAccountDetails(); 

    sa.applyInterest(); 

    std::cout << "Після нарахування відсотків:" << std::endl; 

    sa.displayAccountDetails(); 

  

    sa.withdraw(750.0); 

    std::cout << "Після зняття коштів:" << std::endl; 

    sa.displayAccountDetails(); 

  

    sa.withdraw(2000.0);  

  

    return 0; 

}   
