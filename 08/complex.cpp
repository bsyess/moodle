#include <iostream>

template<typename Arithmetic>
class Complex
{
    public:
        Complex(Arithmetic real, Arithmetic imag = 0) : _real(real), _imag(imag) {}
        template<typename FormattedOutputStream>
        void O(FormattedOutputStream&) const;
        Complex<Arithmetic> operator~() const;
        Complex<Arithmetic> operator+(Complex<Arithmetic> c) const;
        Complex<Arithmetic> operator-(Complex<Arithmetic> c) const;
        Complex<Arithmetic> operator*(Complex<Arithmetic> c) const;
    private:
        Arithmetic _real;
        Arithmetic _imag;
};

Complex<int> const a(3, 4);

template<typename Arithmetic, typename FormattedOutputStream>
FormattedOutputStream& operator<<(FormattedOutputStream& out, Complex<Arithmetic> c)
{
    c.O(out);
    return out;
}

bool Main()
{
    int real;
    if (!(std::cin >> real))
        return false;
    std::cout << "imaginary:";
    int imag;
    std::cin >> imag;
    Complex<int> const c(real, imag);
    std::cout << 'c' << c << "complex conjugate" << ~c << 'a' << a << "a + c" << a + c;
    std::cout << "a - c" << a - c << "a * c" << a * c << "2 * c" << Complex<int>(2) * c;
    return true;
}

int main()
{
    do
        std::cout << "Enter a complex number (q to quit):\nreal:";
    while (Main());
    std::cout << "Done!";
    return 0;
}

template<typename Arithmetic>
template<typename FormattedOutputStream>
void Complex<Arithmetic>::O(FormattedOutputStream& out) const
{
    out << " is (" << _real << ',' << _imag << "i)\n";
}

template<typename Arithmetic>
Complex<Arithmetic> Complex<Arithmetic>::operator~() const
{
    return Complex<Arithmetic>(_real, -_imag);
}

template<typename Arithmetic>
Complex<Arithmetic> Complex<Arithmetic>::operator+(Complex<Arithmetic> c) const
{
    return Complex<Arithmetic>(_real + c._real, _imag + c._imag);
}

template<typename Arithmetic>
Complex<Arithmetic> Complex<Arithmetic>::operator-(Complex<Arithmetic> c) const
{
    return Complex<Arithmetic>(_real - c._real, _imag - c._imag);
}

template<typename Arithmetic>
Complex<Arithmetic> Complex<Arithmetic>::operator*(Complex<Arithmetic> c) const
{
    return Complex<Arithmetic>(_real * c._real - _imag * c._imag, _real * c._imag + _imag * c._real);
}
