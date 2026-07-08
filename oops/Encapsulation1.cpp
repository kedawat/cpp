#include <iostream>

class BankAccount{
    private:
        int accountId;
        double balance;

    public:    
        BankAccount(int id, double initBalance): accountId(id), balance(initBalance) {};

        int getAccountId() const{
            return accountId;
        }

        double getBalance() const{
            return balance;
        }

        // Mutating operations, enforcing invariants
        void deposit(double amount) {
            if (amount < 0.0) {
                throw std::invalid_argument("Deposit amount must be non-negative");
            }
            balance += amount;
        }

        void withdraw(double amount) {
            if (amount < 0.0) {
                throw std::invalid_argument("Withdraw amount must be non-negative");
            }
            if (amount > balance) {
                throw std::runtime_error("Insufficient funds");
            }
            balance -= amount;
        }    
};

int main(){
    BankAccount acc(1001, 500.0);

    acc.deposit(250.0);
    acc.withdraw(100.0);

    std::cout << "Account " << acc.getAccountId()
              << " balance: " << acc.getBalance() << "\n";

    // The following line would be a compile-time error:
    // acc.balance = -100.0;  // balance is private, cannot be accessed

    return 0;
}
