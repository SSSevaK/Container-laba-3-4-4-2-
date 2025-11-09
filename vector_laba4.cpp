#include <iostream>
#include <vector>
#include <algorithm>

bool is_correct(int&);
bool is_natural(int);
bool Fill_mas(std::vector<std::vector<int>>&, int, int);
int Sum_elem(std::vector<std::vector<int>>&, int, int);
int Max_Elem(std::vector<std::vector<int>>&, int, int);
int Min_Elem(std::vector<std::vector<int>>&, int, int);
bool prov_row(int&);
bool prov_col(int&);
void transposed_Arr(int, int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&);
void print_transposed_Arr(int, int, std::vector<std::vector<int>>&);
void print_Arr(int, int, std::vector<std::vector<int>>&);
int sum_main_diagonal(std::vector<std::vector<int>>&, int, int);
void copy(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&, int, int);
void sort(std::vector<std::vector<int>>&, int, int);
void swap_row_or_col(std::vector<std::vector<int>>&, int, int, int, int);
bool numb_max_row(std::vector<std::vector<int>>&, int, int, int, int);
bool numb_min_row(std::vector<std::vector<int>>&, int, int, int, int);

int main()
{
    try
    {
        int row{ 0 };
        int col{ 0 };
        if (!prov_row(row))
        {
            throw false;
        }
        if (!prov_col(col))
        {
            throw false;
        }
        std::vector<std::vector<int>> mas(row,std::vector<int>(col));
        if (!Fill_mas(mas, row, col))
        {
            throw false;
        }
        int max = Max_Elem(mas, row, col);
        int min = Min_Elem(mas, row, col);
        std::cout << "sum E elements around the perimeter " << Sum_elem(mas, row, col) << '\n';
        std::cout << "min element is " << min << '\n';
        std::cout << "max element is " << max << '\n';
        std::vector<std::vector<int>> arr(col, std::vector<int>(row));
        transposed_Arr(row, col, mas, arr);
        std::cout << "this is transposed array : " << '\n';
        print_transposed_Arr(row, col, arr);
        std::vector<std::vector<int>> arr1(row, std::vector<int>(col));
        copy(mas, arr1, row, col);
        sort(arr1, row, col);
        std::cout << "this is sort array : " << '\n';
        print_Arr(row, col, arr1);
        std::cout << "sum main diagonal : " << sum_main_diagonal(mas, row, col) << '\n';
        int row_1 = 0;
        int row_2 = 0;
        if (numb_max_row(mas, row, col, max, row_1) != 0 && numb_min_row(mas, row, col, min, row_2) != 0)
        {
            swap_row_or_col(mas, row_1, row_2, row, col);
            std::cout << "this is swap array : " << '\n';
            print_Arr(row, col, mas);
        }
        else
        {
            std::cout << "max or min numbers more then 1, Unable to sort array";
        }

    }
    catch (bool)
    {
        std::cout << "mistake";
    }
    return 0;
}

bool Fill_mas(std::vector<std::vector<int>>& mas, int row, int col)
{
    std::cout << "Input elements of the array:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "Element [" << i << "][" << j << "]: ";
            if (!is_correct(mas[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}
bool is_correct(int& number)
{
    return(std::cin >> number) ? true : false;
}
bool is_natural(int number)
{
    return(number > 0) ? true : false;
}
int Sum_elem(std::vector<std::vector<int>>& mas, int row, int col)
{
    int sum = 0;
    for (int j = 0; j < col; j++)
    {
        sum += mas[0][j];
        if (row > 1)
        {
            sum += mas[row - 1][j];
        }
    }
    for (int i = 1; i < row - 1; i++)
    {
        sum += mas[i][0];
        if (col > 1)
        {
            sum += mas[i][col - 1];
        }
    }
    return sum;
}
int Min_Elem(std::vector<std::vector<int>>& mas, int row, int col)
{
    int min{ 0 };
    min = mas[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (min > mas[i][j])
            {
                min = mas[i][j];
            }
        }
    }
    return min;
}
int Max_Elem(std::vector<std::vector<int>>& mas, int row, int col)
{
    int max{ 0 };
    max = mas[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (max < mas[i][j])
            {
                max = mas[i][j];
            }
        }
    }
    return max;
}
bool prov_row(int& row)
{
    std::cout << "Input the size of a two-dimensional array\n";
    std::cout << "Number of rows: ";
    if (is_correct(row) && is_natural(row))
    {
        return 1;
    }
    return 0;
}
bool prov_col(int& col)
{
    std::cout << "Number of columns: ";
    if (is_correct(col) && is_natural(col))
    {
        return 1;
    }
    return 0;
}
void transposed_Arr(int row, int col, std::vector<std::vector<int>>& mas, std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[j][i] = mas[i][j];
        }
    }
}
void print_transposed_Arr(int row, int col, std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void print_Arr(int row, int col, std::vector<std::vector<int>>& arr)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int sum_main_diagonal(std::vector<std::vector<int>>& mas, int row, int col)
{
    int length = (row < col) ? row : col;
    int s = 0;

    for (int i = 0; i < length; i++)
    {
        s += mas[i][i];
    }

    return s;
}
void copy(std::vector<std::vector<int>>& mas, std::vector<std::vector<int>>& arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = mas[i][j];
        }
    }
}
void sort(std::vector<std::vector<int>>& arr1, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            int key = arr1[i][j];
            int k = j - 1;
            while (k >= 0 && arr1[i][k] > key)
            {
                arr1[i][k + 1] = arr1[i][k];
                k--;
            }
            arr1[i][k + 1] = key;
        }
    }
}
void swap_row_or_col(std::vector<std::vector<int>>& arr, int max, int min, int row, int col)
{
    if (max == min)
    {
        for (int i = 0; i < row; i++)
        {
            int temp = arr[i][max];
            arr[i][max] = arr[i][min];
            arr[i][min] = temp;
        }
    }
    else
    {
        for (int j = 0; j < col; j++)
        {
            int temp = arr[max][j];
            arr[max][j] = arr[min][j];
            arr[min][j] = temp;
        }
    }
}
bool numb_max_row(std::vector<std::vector<int>>& arr, int row, int col, int max, int row_1)
{
    int temp{ 0 };
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (max == arr[i][j])
            {
                temp++;
            }
        }
    }
    return temp == 1 ? true : false;
}
bool numb_min_row(std::vector<std::vector<int>>& arr, int row, int col, int min, int row_2)
{
    int temp{ 0 };
    min = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (min == arr[i][j])
            {
                temp++;
            }
        }
    }
    return temp == 1 ? true : false;
}