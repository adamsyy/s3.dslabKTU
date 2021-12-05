
#include <stdio.h>

void inputPoly(int, int[2][100]);
void printPoly(int, int[2][100]);


void polyAdd(int poly1[2][100], int poly2[2][100], int size1, int size2)
{
    int sum[2][100], size3;
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (poly1[0][i] == poly2[0][j]) 
        {
            sum[0][k] = poly1[0][i];
            sum[1][k] = poly1[1][i] + poly2[1][j]; 
            i++;
            j++;
        }
        else if (poly1[0][i] > poly2[0][j])
        {
            sum[0][k] = poly1[0][i];
            sum[1][k] = poly1[1][i]; 
            i++;
        }
        else
        {
            sum[0][k] = poly2[0][j];
            sum[1][k] = poly2[1][j]; 
            j++;
        }
        k++;
    }
    while (i < size1) 
    {
        sum[0][k] = poly1[0][i];
        sum[1][k] = poly1[1][i];
        i++;
        k++;
    }
    while (j < size2) 
    {
        sum[0][k] = poly2[0][j];
        sum[1][k] = poly2[1][j];
        j++;
        k++;
    }
    size3 = k;

    printf("\nSum of Polynomials: ");
    printPoly(size3, sum);
}


int main()
{

    int poly1[2][100], poly2[2][100];
    int size1, size2;
    printf("\nEnter number of terms in first polynomial  ");
    scanf("%d", &size1);
    if (size1 < 0 || size1 > 100)
    {
        printf("\nInvalid size or size exceeded max limit (100) ");
        return 0;
    }
    inputPoly(size1, poly1);
    printf("\nEnter number of terms in first polynomial  ");
    scanf("%d", &size2);
    if (size2 < 0 || size2 > 100)
    {
        printf("\nInvalid size or size exceeded max limit (100) ");
        return 0;
    }
    inputPoly(size2, poly2);

    printf("\nFirst Polynomial: ");
    printPoly(size1, poly1);
    printf("\nSecond Polynomial: ");
    printPoly(size2, poly2);
    polyAdd(poly1, poly2, size1, size2);
}


void inputPoly(int size, int poly[2][100])
{
    printf("\nEnter the coeffiecent and power of polynomial, in descending order of power");
    printf("\nFor example: 3X^(5) + 4x^(2) + x + 6 is entered as 3 5 4 2 1 1 6 0\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &poly[1][i]);
        scanf("%d", &poly[0][i]);
    }
}


void printPoly(int size, int poly[2][100])
{
    for (int i = 0; i < size; i++)
    {
        printf(" %dx^(%d) ", poly[1][i], poly[0][i]);
        i < size - 1 ? printf("+") : printf("");
    }
}