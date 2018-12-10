#include <cstring>
#include <iostream>

/* 信息: 用例1: 受限函数(你的程序调用了一些不允许使用的函数。)

class String
{
private:
    char* _;
public:
    String(char const* s);
    std::ostream& show(std::ostream& o) const;
    ~String();
};

String::String(char const* s) : _(new char[std::strlen(s) + 1])
{
    std::strcpy(_, s);
}

std::ostream& String::show(std::ostream& o) const
{
    return o << _;
}

std::ostream& operator<<(std::ostream& o, String const& s)
{
    return s.show(o);
}

String::~String()
{
    delete[] _;
}

class Stock
{
private:
    String company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock(String const& co = "", long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    std::ostream& show(std::ostream& o)const;
    const Stock & topval(const Stock & s) const;
};

std::ostream& operator<<(std::ostream& o, Stock const& s)
{
    return s.show(o);
}

const int STKS = 4;

int main()
{
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    std::cout << "Stock holdings:\n";
    int st;
    {
        std::string before;
        for (st = 0; st < STKS; st++)
        {
            std::cout << before << stocks[st];
            before = " ";
        }
    }
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
    std::cout << "\n\nMost valuable holding:\n" << *top;
    return 0;
}

Stock::Stock(String const& co, long n, double pr) : company(co), share_val(pr)
{
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    set_tot();
}

Stock::~Stock()
{
}

void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

std::ostream& Stock::show(std::ostream& o) const
{
    std::ios_base::fmtflags orig =
        o.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::streamsize prec = o.precision(3);
    o << "Company: " << company << " Shares: " << shares << '\n';
    o << "Share Price: $" << share_val;
    o.precision(2);
    o << " Total Worth: $" << total_val;
    o.setf(orig, std::ios_base::floatfield);
    o.precision(prec);
    return o;
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
*/
using namespace std;
class Stock
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
  //  Stock();        // default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s) const;
};
const int STKS = 4;
int main()
{
// create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";
    int st;
    {
        std::string before = "";
        for (st = 0; st < STKS; st++)
        {
            cout << before;
            before = " ";
            stocks[st].show();
        }
    }
// set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);
// now top points to the most valuable holding
    std::cout << "\n\nMost valuable holding:\n";
	top->show();
    return 0; 
}
// constructors
Stock::Stock(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
}

// other methods
void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company << " Shares: " << shares << '\n';
    cout << "Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val;

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
