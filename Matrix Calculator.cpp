#include <iostream>
#include <iomanip>

using namespace std;

//Matrix Input function
void MatrixInput (char Symbol [60], int Storage [60][5][5], int RowsColumns[60][1][2])
{
    int i, m, n, x;
    char input;
    cout << setfill(' ') << setw(15) << " " << "NOTE: Matrices should not be more than 60 in number" << endl << endl << "How many matrices would you like to allocate: " ;
    cin >> x; // Allocates the number of matrices
    cout << endl;
    for (int k = 1; k < x+1; k++) // The first storage matrix is left for later addition, substraction, multiplication, transpose results
    {
        cout << "Please enter the character of your Matrix: ";
        cin >> Symbol [k]; // Allocates corresponding letter to the corresponding matrix
        cout << endl;
        cout << "How many rows does your Matrix " << Symbol[k] << " have: " ;
        cin >> RowsColumns[k][0][0]; // First Row first column is used to store the number of rows
        cout << endl;
        cout << "How many columns does your Matrix " << Symbol[k] << " have:";
        cin >> RowsColumns[k][0][1]; // First Row second column is used to store the number of columns
        cout << endl;
        m = RowsColumns[k][0][0];
        n = RowsColumns[k][0][1];
            for (i = 0; i < m; i ++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << Symbol[k] << i+1 << j+1 << ": ";
                    cin >> Storage [k][i][j];
                }
            }
            cout << endl;
    }
}

// Matrix searching function using character
void MatrixAccess (char Symbol[60], int Storage [60][5][5], int RowsColumns[60][1][2])
{
    int i, j, m, n;
    char input, chr;
    do
    {
        cout << "Enter the letter of the matrix you want to access: ";
        cin >> input;
        cout << endl;
        for (int k = 1; k < 60; k++)
        {
        if (input == Symbol[k])
        {
            m = RowsColumns[k][0][0];
            n = RowsColumns[k][0][1];
            cout << "\tMatrix " << Symbol[k] << endl << endl;
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    cout << "      " << Storage[k][i][j] << "      ";
                if (j == n - 1)
                    cout << endl;
                }
            }
        }
        }
        cout << endl;
    cout << "Do you want to search another Matrix (Press n to stop the search): ";
    cin >> chr;
    cout << endl;
    }
    while (chr != 'n');
}

// Adding Matrix function
void MatrixAddition(char Symbol[60], int Storage[60][5][5], int RowsColumns[60][1][2])
{
    int i, j, n, o, e, f, r, c, a; // 'o' used to count the symbols of the first matrix, 'r' & 'c' to count rows & columns for the 1st matrix, 'e' and 'f' are used to count rows & columns of second matrix
    char input, chr; // 'n' used to count the symbols of the second matrix
    cout << "Please enter the letter of the first matrix: ";
    cin >> chr;
    cout << endl;
    for (o = 1; o < 60; o++)
    {
        if (chr == Symbol[o])
        {
            a = o; // Storing the value of 'o' for later use
            r = RowsColumns[o][0][0]; // 'r' is used to count number of rows of first matrix
            cout << "\tMatrix " << Symbol[o] << endl << endl;
            for (i = 0; i < r; i++)
            {
                c = RowsColumns[o][0][1]; // 'c' is used to count number of columns of first matrix
                for (j = 0; j < c; j++)
                {
                    cout << "      " << Storage[o][i][j] << "      ";
                    if (j == c - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    o = a; // o's value would have been 60 giving us a garbage value at the end of addition
    cout << "Please enter the letter of the second matrix: ";
    cin >> input;
    cout << endl;
    for (n = 1; n < 60; n++)
    {
        if (input == Symbol[n])
        {
            a = n; // Store the value of 'n' for later use
            e = RowsColumns[n][0][0]; // 'e' is used to count number of rows of second matrix
            cout << "\tMatrix " << Symbol[n] << endl << endl;
            for (i = 0; i < e; i++)
            {
                f = RowsColumns[n][0][1]; // 'f' is used to count number of columns of second matrix
                for (j = 0; j < f; j++)
                {
                    cout << "      " << Storage[n][i][j] << "      ";
                    if (j == f - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    n = a; // n's value would have been 60 giving us a garbage value at the end of addition
    if (r == e && c == f) // Checks row of 1st matrix = row of 2nd matrix & column of 1st matrix = column of 2nd matrix
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                Storage[0][i][j] = Storage[o][i][j] + Storage[n][i][j]; //Adds first matrix and second matrix
            }
        }
        cout << "\tMatrix " << Symbol[o] << " + " << Symbol[n] << endl << endl;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << "      " << Storage[0][i][j] << "      "; // Prints the added matrices
                if (j == c - 1)
                    cout << endl;
            }
        }
        cout << endl;
    }

    else cout << "Rows and columns of the matrices are not equal.";
}

// Substracting Matrix function
void MatrixSubstraction(char Symbol[60], int Storage[60][5][5], int RowsColumns[60][1][2])
{
    int i, j, n, o, e, f, r, c, a; // 'o' used to count the symbols of the first matrix, 'r' & 'c' to count rows & columns for the 1st matrix, 'e' and 'f' are used to count rows & columns of second matrix
    char input, chr; // 'n' used to count the symbols of the second matrix
    cout << "Please enter the letter of the first matrix: ";
    cin >> chr;
    cout << endl;
    for (o = 1; o < 60; o++)
    {
        if (chr == Symbol[o])
        {
            a = o; // Storing the value of 'o' for later use
            r = RowsColumns[o][0][0]; // 'r' is used to count number of rows of first matrix
            cout << "\tMatrix " << Symbol[o] << endl << endl;
            for (i = 0; i < r; i++)
            {
                c = RowsColumns[o][0][1]; // 'c' is used to count number of columns of first matrix
                for (j = 0; j < c; j++)
                {
                    cout << "      " << Storage[o][i][j] << "      ";
                    if (j == c - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    o = a; // o's value would have been 60 giving us a garbage result at the end of substraction
    cout << "Please enter the letter of the second matrix: ";
    cin >> input;
    cout << endl;
    for (n = 1; n < 60; n++)
    {
        if (input == Symbol[n])
        {
            a = n; // Store the value of 'n' for later use
            e = RowsColumns[n][0][0]; // 'e' is used to count number of rows of second matrix
            cout << "\tMatrix " << Symbol[n] << endl << endl;
            for (i = 0; i < e; i++)
            {
                f = RowsColumns[n][0][1]; // 'f' is used to count number of columns of second matrix
                for (j = 0; j < f; j++)
                {
                    cout << "      " << Storage[n][i][j] << "      ";
                    if (j == f - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    n = a; // n's value would have been 60 giving us a garbage result at the end of substraction
    if (r == e && c == f) // Checks row of 1st matrix = row of 2nd matrix & column of 1st matrix = column of 2nd matrix
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                Storage[0][i][j] = Storage[o][i][j] - Storage[n][i][j]; // Substracts first matrix and second matrix
            }
        }
        cout << "\tMatrix " << Symbol[o] << " + " << Symbol[n] << endl << endl;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << "      " << Storage[0][i][j] << "      "; // Prints the substracted matrices
                if (j == c - 1)
                    cout << endl;
            }
        }
        cout << endl;
    }

    else cout << "Rows and columns of the matrices are not equal." << endl;
}

// Multiplying Matrix function
void MatrixMultiplication(char Symbol[60], int Storage[60][5][5], int RowsColumns[60][1][2])
{
    int i, j, n, o, e, f, r, c, a, constant, x; // 'o' used to count the symbols of the first matrix, 'r' & 'c' to count rows & columns for the 1st matrix, 'e' and 'f' are used to count rows & columns of second matrix
    char input, chr, b; // 'n' used to count the symbols of the second matrix, 'a' is used as a temporary storage of the matrix location, 'constant' is used to store the constant value
    cout << "How do you want to multiply?" << endl << "1. A matrix with a scalar" << endl << "2. A matrix with a matrix" << endl;
    cin >> x;
    cout << endl;
    if (x == 1)
    {
    cout << "Please enter the letter of the matrix you want to multiply: ";
    cin >> b;
    cout << endl;
    for (o = 1; o < 60; o++)
    {
        if (b == Symbol[o])
        {
            a = o; // Storing the value of 'o' for later use
            r = RowsColumns[o][0][0]; // 'r' is used to count number of rows of the matrix
            cout << "\tMatrix " << Symbol[o] << endl << endl;
            for (i = 0; i < r; i++)
            {
                c = RowsColumns[o][0][1]; // 'c' is used to count number of columns of the matrix
                for (j = 0; j < c; j++)
                {
                    cout << "      " << Storage[o][i][j] << "      ";
                    if (j == c - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    o = a;
    cout << "Please enter the constant number that you want to multiply with: ";
    cin >> constant;
    cout << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            Storage[0][i][j] = constant * Storage[o][i][j];
        }
    }
    cout << "\tMatrix " << constant << " * " << Symbol[o] << endl << endl;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << "      " << Storage[0][i][j] << "      ";
            if (j == c - 1)
                cout << endl;
        }
    }
    cout << endl;
}
    else if (x == 2)
    {
    cout << "Please enter the letter of the first matrix: ";
    cin >> chr;
    cout << endl;
    for (o = 1; o < 60; o++)
    {
        if (chr == Symbol[o])
        {
            a = o; // Storing the value of 'o' for later use
            r = RowsColumns[o][0][0]; // 'r' is used to count number of rows of first matrix
            cout << "\tMatrix " << Symbol[o] << endl << endl;
            for (i = 0; i < r; i++)
            {
                c = RowsColumns[o][0][1]; // 'c' is used to count number of columns of first matrix
                for (j = 0; j < c; j++)
                {
                    cout << "      " << Storage[o][i][j] << "      ";
                    if (j == c - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    o = a; // o's value would have been 60 giving us a garbage value at the end of multiplication
    cout << "Please enter the letter of the second matrix: ";
    cin >> input;
    cout << endl;
    for (n = 1; n < 60; n++)
    {
        if (input == Symbol[n])
        {
            a = n; // Store the value of 'n' for later use
            e = RowsColumns[n][0][0]; // 'e' is used to count number of rows of second matrix
            cout << "\tMatrix " << Symbol[n] << endl << endl;
            for (i = 0; i < e; i++)
            {
                f = RowsColumns[n][0][1]; // 'f' is used to count number of columns of second matrix
                for (j = 0; j < f; j++)
                {
                    cout << "      " << Storage[n][i][j] << "      ";
                    if (j == f - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
    n = a; // n's value would have been 60 giving us a garbage value at the end of multiplication
    if (r == e && c == f) // Checks column of 1st matrix = row of 2nd matrix
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    Storage[0][i][j] += Storage[o][i][k] * Storage[n][k][j]; // Multiplies first matrix and second matrix
                }
            }
        }
        cout << "\tMatrix " << Symbol[o] << " * " << Symbol[n] << endl << endl;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << "      " << Storage[0][i][j] << "      "; // Prints the multiplied matrices
                if (j == c - 1)
                    cout << endl;
            }
        }
    }
    cout << endl;
    }
    else cout << "Rows and columns of the matrices are not equal.";
}

// Matrix Transpose function
void MatrixTranspose(char Symbol [60], int Storage [60][5][5], int RowsColumns[60][1][2])
{
    int r, c;
    char input;
    cout << "Enter the symbol of the Matrix you want to Transpose: ";
    cin >> input;
    cout << endl;
    for (int k = 0; k < 60; k++)
    {
        if (input == Symbol [k])
        {
            r = RowsColumns[k][0][0];
            cout << "  Transpose Matrix " << Symbol[k] << endl << endl;
            for (int i = 0; i < c; i++)
            {
                c = RowsColumns[k][0][1];
                for (int j = 0; j < r; j++)
                {
                    cout << "      " << Storage [k][j][i] << "      ";
                    if (j == r - 1)
                        cout << endl;
                }
            }
        }
    }
    cout << endl;
}

void MatrixDeterminant(char Symbol[60], int Storage[60][5][5], int RowsColumns[60][1][2])
{
    int r, temp, c, i, j, k;
    char l;
    cout << "Please enter the letter of a matrix: ";
    cin >> l;
    cout << endl;
    for (k = 1; k < 60; k++)
    {
        if (l == Symbol[k])
            temp = k;
            r = RowsColumns[k][0][0]; // 'r' stores the number of rows
            c = RowsColumns[k][0][1]; // 'c' stores the number of columns
            cout << "\tMatrix " << Symbol[k] << endl;
            cout << endl;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << "      " << Storage[k][i][j] << "      "; // this prints the matrix in rows and columns
                if (j == c - 1)
                    cout << endl;
            }
        }
    }
    for (i = 0; i < 5; i ++)
    {
        for (j = 0; j < 5; j++)
            Storage[0][i][j] = 0;
    }
    k = temp;
    if (r == 2 && c == 2) // it keeps holding a garbage value of 'r' & 'c'. WE DONNOT KNOW WHY!!! HELP!!!
    {
        Storage[0][0][0] = ((Storage [k][0][0] * Storage [k][1][1]) - (Storage[k][0][1] * Storage[k][1][0]));
    }
    else if (r == 3 && c == 3)
    {
        Storage[0][0][0] = ((Storage[k][0][0] * ((Storage[k][1][1] * Storage[k][2][2]) - (Storage[k][1][2] * Storage[k][2][1])) -
                            (Storage[k][0][1] * ((Storage[k][1][0] * Storage[k][2][2]) - (Storage[k][1][2] * Storage[k][2][0]))) +
                            (Storage[k][0][2] * ((Storage[k][1][0] * Storage[k][2][1]) - (Storage[k][1][1] * Storage[k][2][0])))));
    }
    cout << "Determinant of Matrix " << Symbol[k] << ": " << Storage[0][0][0];
}

void Menu ()
{
    int x;
    char s[60];
    int S[60][5][5];
    int RC [60][1][2];
    cout << setfill(' ') << setw(30) << "#" << setfill('#') << setw(46) << "#" << endl <<
    setfill(' ') << setw(30) << "#" << setfill(' ') << setw(46) << "#" << endl <<
    setfill(' ') << setw(30) << "#" << setfill(' ') << setw(46) << "#" << endl;
    cout << setfill(' ') << setw(30) << '#' << "    Welcome to your Matrix Calculator        #" << endl <<
    setfill(' ') << setw(30) << "#" << setfill(' ') << setw(46) << "#" << endl <<
    setfill(' ') << setw(30) << "#" << setfill(' ') << setw(46) << "#" << endl
    << setfill(' ') << setw(30) << "#" << setfill('#') << setw(46) << "#" << endl;
    cout << setfill(' ') << setw(10) << " " << endl;
    MatrixInput(s, S, RC);
    do
    {
    cout << "\tWhat would you like to do?" << endl;
    cout << "\t1. Addition of Matrix" << endl << "\t2. Substraction of Matrix" << endl << "\t3. Multiplication of Matrix" << endl << "\t4. Transpose of Matrix" << endl <<
    "\t5. Determinant of a Matrix" << endl << "\t6. Access a Matrix" << endl << "\t7. Re-add Matrix Again" << endl << "\t0. To end the program" << endl;
    cin >> x;
    cout << endl;
    if (x == 1)
    {
        MatrixAddition(s, S, RC);
    }
    if (x == 2)
    {
        MatrixSubstraction(s, S, RC);
    }
    if (x == 3)
    {
        MatrixMultiplication(s, S, RC);
    }
    if (x == 4)
    {
        MatrixTranspose(s, S, RC);
    }
    if (x == 5)
    {
        MatrixDeterminant(s, S, RC);
    }
    if (x == 6)
    {
        MatrixAccess(s, S, RC);
    }
    if (x == 7)
    {
        MatrixInput(s, S, RC);
    }
    }
    while (x != 0);
}

int main()
{
    Menu();
    return 0;
}
