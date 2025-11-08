#pragma once

class Complex
{
public:
    Complex():X{0},Y{0}{};
    Complex& operator=(const Complex& other )
    {
        X = other.X;
        Y = other.Y;
        return *this;
    }

    Complex& operator+=(const Complex& rhs)
    {
        X += rhs.X;
        Y += rhs.Y;
        return *this;
    }

    friend Complex operator+(Complex lhs, const Complex& rhs)
    {
        lhs += rhs;
        return lhs;
    }
    
    Complex& operator-=(const Complex& rhs)
    {
        X -= rhs.X;
        Y -= rhs.Y;
        return *this;
    }

    friend Complex operator-(Complex lhs, const Complex& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    Complex& operator*=(const Complex& rhs)
    {
        Complex tmp = *this;
        X = (tmp.X * rhs.X) - (tmp.Y * rhs.Y);
        Y = (tmp.X * rhs.Y) + (tmp.Y * rhs.X);
        
        return *this;
    }

    friend Complex operator*(Complex lhs, const Complex& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    Complex& operator/=(const Complex& rhs)
    {
        X /= rhs.X;
        Y /= rhs.Y;
        return *this;
    }

    friend Complex operator/(Complex lhs, const Complex& rhs)
    {
        lhs /= rhs;
        return lhs;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& num)
    {
        os << "[" << num.X << "," << num.Y << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& num)
    {
        is >> num.X >> num.Y;
        return is;
    }
private:
    int X, Y;
};

void chapter2()
{
    Complex num1, num2, result;

    std::cout << "input a complex number:" << std::endl;
    std::cin >> num1;
    std::cout << "input a second one:" << std::endl;
    std::cin >> num2;

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << "Addition:\n";
    result = num1 + num2;
    std::cout << result << std::endl;

    std::cout << "Substraction:\n";
    result = num1 - num2;
    std::cout << result << std::endl;

    std::cout << "Multiplication:\n";
    result = num1 * num2;
    std::cout << result << std::endl;

    std::cout << "Division:\n";
    result = num1 / num2;
    std::cout << result << std::endl;
}
