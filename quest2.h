#pragma once

#include <algorithm>
#include <cstdint>
class Complex
{
public:
    Complex():X{0},Y{0}{};
    Complex(int x, int y):X{x}, Y{y}{};

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
        Complex tmp2 = rhs;
        X = (tmp.X * tmp2.X) - (tmp.Y * tmp2.Y);
        Y = (tmp.X * tmp2.Y) + (tmp.Y * tmp2.X);
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
    friend bool operator< (const Complex& lhs, const Complex& rhs) { return ((lhs.X < rhs.X) || (lhs.Y < rhs.Y)); }
    friend bool operator> (const Complex& lhs, const Complex& rhs) { return rhs < lhs; }
    friend bool operator<=(const Complex& lhs, const Complex& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Complex& lhs, const Complex& rhs) { return !(lhs < rhs); }
    void setX(int x) {X = x;};
    void setY(int y) {Y = y;};
    int getX() {return X;};
    int getY() {return Y;};

private:
    int64_t X, Y;
};

bool engravePoint(Complex& tst)
{
    bool engrave = true;
    bool once = true;
    Complex result{0,0};
    Complex up{1000000, 1000000};
    Complex low{-1000000,-1000000};
    uint8_t counter{0};

    //std::cout << "engrave: " << tst << std::endl;
    while(counter < 100)
    {
        result *= result;
        result /= {100000, 100000};
        result += tst;
        if((result > up) || (result < low))
        {
            engrave = false;
            break;
        }
        counter++;
    } 

    return engrave;
}

void chapter2()
{
    Complex  A, result;

    std::cout << "input a complex number:" << std::endl;
    std::cin >> A;
    
    uint8_t counter = 0;
    while(counter < 3)
    {
        result *= result;
        result /= {10,10};
        result += A;
        counter++;
    }

    std::cout << "Result: " << result << std::endl;
}

void chapter2_1()
{
    constexpr unsigned int grid_size = 1001;
    constexpr unsigned int total_grid_size = grid_size*grid_size;
    constexpr unsigned int step = 1;
    const Complex hor_step{1, 0};
    const Complex ver_step{0, 1};
    Complex start_point{-4591, -68892};
    //Complex start_point{35300, -64910};
    //std::array<unsigned char, total_grid_size> grid;
   // grid.fill('.');

   // std::cout << "Input start coordinates:" << std::endl;
  //  std::cin >> start_point;

    Complex end_point = start_point;
int engraved_points{0};
    for(size_t i{0}; i < total_grid_size; i++)
    {

        if(engravePoint(end_point))
        {
  //          grid[i] = 'X';
            engraved_points++;
        }

        if((i+1) % grid_size)
        {
            end_point += hor_step;
        }
        else
        {
            end_point += ver_step;
            end_point.setX(start_point.getX());
        }
    }
/*
    for(size_t cnt{}; char c : grid)
    {
        std::cout << c << ((++cnt%grid_size) ? "" : "\n");
    }
*/
    std::cout << "Engraved points: " << engraved_points << std::endl; 
}
