#include <iostream>

typedef std::string String;

class Bank
{
    public:
        Bank(int balance) : _balance(balance) {}
        void deposit(int amount);
        bool withdraw(int amount);
        operator int() const;
    private:
        int _balance;
};

Bank readBank()
{
    int balance;
    std::cin >> balance;
    return balance;
}

void Bank::deposit(int amount)
{
    _balance += amount;
}

bool Bank::withdraw(int amount)
{
    if (_balance < amount)
        return false;
    _balance -= amount;
    return true;
}

Bank::operator int() const
{
    return _balance;
}

int main()
{
    Bank bank = readBank();
    std::cout << bank << '\n';

    int amount;
    std::cin >> amount;
    bank.deposit(amount);
    std::cout << bank << '\n';

    std::cin >> amount;
    if (bank.withdraw(amount))
        std::cout << bank;
    else
        std::cout << "no enough balance!";
    return 0;
}
