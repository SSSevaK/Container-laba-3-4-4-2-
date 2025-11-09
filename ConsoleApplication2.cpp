#include <iostream>
#include <ctime>
#include <random>
#include <cmath>
#include <array>
#include <vector>
#include <algorithm>

template<class T>
bool is_correct(T&);
template<class T>
bool check_size(T);
template<typename Container>
bool input_mass(int&, double&, int, Container&);
template<typename Container>
double min_element(int, Container&);
template<typename Container>
void min_numb_elem(double, int, Container&);
template<typename Container>
bool negative_number(int, Container&, int&, int&);
template<typename Container>
void SumBetNegNumb(int, Container&);
template<typename Container>
double sum(int, int, int, Container&);
template<typename Container>
void sort_arr(int, double, Container&);
template<typename Container>
void print_arr(int, Container&);
template<typename Container>
void rand_numb(int, int, int, Container&);
template<typename Container>
bool randNumb_function(short, Container&);
template<typename Container>
bool inputNumb_function(short, Container&);
int input_sizeOfArr(short&);
int input_typeOfArr(short&);
bool rundfunc(short, short);
bool staticfunc(short, short);

int main()
{
    short type{ 0 };
    short size{ 0 };
    short type_mass{ 0 };
    try
    {
        std::cout << "if you wont static mass input 1, if you wont dinamic imput 2" << '\n';
        if (!input_sizeOfArr(type_mass))
        {
            throw false;
        }
        if (type_mass == 2)
        {
            rundfunc(size, type);
        }
        if (type_mass == 1)
        {
            staticfunc(size, type);
        }
        if (type_mass != 1 && type_mass != 2)
        {
            return false;
        }
    }
    catch (bool)
    {
        std::cout << "mistake";
    }
    return 0;
}

template<class T>
bool is_correct(T& number)
{
    return (std::cin >> number) ? true : false;
}
template<class T>
bool check_size(T number)
{
    return (number > 0 && number < 100) ? true : false;
}
template<typename Container>
bool input_mass(int& prov, double& temp, int size, Container& arr)
{
    for (int i = 0; i < size; i++)
    {
        if (is_correct(temp))
        {
            arr[i] = temp;
        }
        else
        {
            return false;
        }
    }
    return true;
}
template<typename Container>
double min_element(int size, Container& arr)
{
    double min_number = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min_number)
        {
            min_number = arr[i];
        }
    }
    return min_number;
}
template<typename Container>
void min_numb_elem(double min, int size, Container& arr)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == min)
        {
            std::cout << i + 1 << '\n';
        }
    }
}
template<typename Container>
bool negative_number(int size, Container& arr, int& min, int& max)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            min = i;
            for (int j = size - 1; j >= 0; j--)
            {
                if (arr[j] < 0)
                {
                    max = j;
                    return true;
                }
            }
        }
    }
    return false;
}
template<typename Container>
double sum(int min, int max, int size, Container& arr)
{
    double sum_numb{ 0 };
    for (int i = min + 1; i < max; i++)
    {
        sum_numb += arr[i];
    }
    return sum_numb;
}
template<typename Container>
void sort_arr(int size, double X,Container& arr)
{
    std::sort(arr.begin(), arr.end());
}
template<typename Container>
void print_arr(int size, Container& arr)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << '\n';
    }
}
template<typename Container>
void rand_numb(int a, int b, int size, Container& arr)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (b - a + 1) + a;
    }
}
template<typename Container>
bool randNumb_function(short size, Container& arr)
{
    short a;
    short b;
    try
    {
        std::cout << "input range of numbers" << '\n';
        if (!is_correct(a))
        {
            throw false;
        }
        if (!is_correct(b))
        {
            throw false;
        }
        if (a > b)
        {
            std::swap(a, b);
        }
        srand(time(NULL));
        rand_numb(a, b, size, arr);
        std::cout << "array is :" << '\n';
        print_arr(size, arr);
        std::cout << "the numbers of the minimum array elements is :" << '\n';
        min_numb_elem(min_element(size, arr), size, arr);
        SumBetNegNumb(size, arr);
        double X;
        if (!is_correct(X))
        {
            throw false;
        }
        std::cout << " sorted array " << '\n';
        sort_arr(size, X, arr);
        print_arr(size, arr);
    }
    catch (bool)
    {
        return false;
    }
    return true;
}
template<typename Container>
bool inputNumb_function(short size, Container& arr)
{
    try
    {
        double temp{ 0 };
        int prov = 1;
        std::cout << "input " << size << " numbers" << '\n';
        if (!input_mass(prov, temp, size, arr))
        {
            throw false;
        }
        std::cout << "the numbers of the minimum array elements is :" << '\n';
        min_numb_elem(min_element(size, arr), size, arr);
        SumBetNegNumb(size, arr);
        double X;
        std::cout << " input number X. This number need for array sorting " << '\n';
        if (!is_correct(X))
        {
            throw false;
        }
        std::cout << " sorted array " << '\n';
        sort_arr(size, X, arr);
        print_arr(size, arr);
    }
    catch (bool)
    {
        return false;
    }
    return true;
}
int input_sizeOfArr(short& size)
{
    try
    {
        if (is_correct(size) == 0)
        {
            throw false;
        }
        if (check_size(size) == 0)
        {
            throw false;
        }
    }
    catch (bool)
    {
        return 0;
    }
    return size;
}
int input_typeOfArr(short& type)
{
    try
    {
        std::cout << "if you want random number press 1 , if you want to enter numbers, enter 2" << '\n';
        if (is_correct(type) == 0)
        {
            throw false;
        }
        if (check_size(type) == 0)
        {
            throw false;
        }
    }
    catch (bool)
    {
        return 0;
    }
    return type;
}
template<typename Container>
void SumBetNegNumb(int size, Container& arr)
{
    int min = 0;
    int max = 0;
    if (!negative_number(size, arr, min, max))
    {
        std::cout << "We don't have negative numbers.";
    }
    else
    {
        if (min == max)
        {
            std::cout << "1 neg element, therefore sum = 0 ." << '\n';
        }
        else
        {
            std::cout << "sum between " << min + 1 << " and " << max + 1 << " elements is " << '\n';
            std::cout << sum(min, max, size, arr) << '\n';
        }
    }
    std::cout << " input number X. This number need for array sorting " << '\n';
}
bool rundfunc(short size, short type)
{
    try
    {
        std::cout << "input size of mass > 0 but < 100" << '\n';
        if (!input_sizeOfArr(size))
        {
            throw false;
        }
        if (!input_typeOfArr(type))
        {
            throw false;
        }
        std::vector<double> arr(size);
        if (type == 2)
        {
            if (!inputNumb_function(size, arr))
            {
                throw false;
            }
        }
        if (type == 1)
        {
            if (!randNumb_function(size, arr))
            {
                throw false;
            }
        }
        if (type != 1 && type != 2)
        {
            throw false;
        }
    }
    catch (bool)
    {
        return false;
    }
    return true;
}
bool staticfunc(short size, short type)
{
    const short Max_size{ 100 };
    std::array<double, Max_size> arr{};
    try
    {
        std::cout << "input size of mass > 0 but < 100" << '\n';
        if (!input_sizeOfArr(size))
        {
            throw false;
        }
        if (!input_typeOfArr(type))
        {
            throw false;
        }
        if (type == 2)
        {
            if (!inputNumb_function(size, arr))
            {
                throw false;
            }
        }
        if (type == 1)
        {
            if (!randNumb_function(size, arr))
            {
                throw false;
            }
        }
        if (type != 1 && type != 2)
        {
            throw false;
        }
    }
    catch (bool)
    {
        return false;
    }
    return true;
}