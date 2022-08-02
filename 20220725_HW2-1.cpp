#include <iostream>
#include <stdio.h>
#include <string>
#include "function.h"
using namespace std;

int getmax(int a, int b)
{
    return a > b ? a : b;
}

Polynomial::Polynomial() {}
Polynomial::Polynomial(const int now_greatestPower, const int now_coefficient[51])
{
    for(int i = now_greatestPower; i >= 0; i--)
    {
        this->coefficients[i] = now_coefficient[i];
    }
    this->greatestPower = now_greatestPower;
}
Polynomial Polynomial::add( const Polynomial b) const
{
    Polynomial ans;

    int max = getmax(this->greatestPower, b.greatestPower);
    ans.greatestPower = max;

    for(int i = max; i >= 0; i--)
    {
        ans.coefficients[i] = this->coefficients[i] + b.coefficients[i];
    }

    return ans;
} // add function
Polynomial Polynomial::subtract( const Polynomial b) const
{
    Polynomial ans;

    int max = getmax(this->greatestPower, b.greatestPower);
    ans.greatestPower = max;

    for(int i = max; i >= 0; i--)
    {
        ans.coefficients[i] = this->coefficients[i] - b.coefficients[i];
    }

    return ans;
} // subtract function
Polynomial Polynomial::multiplication( const Polynomial b) const
{
    Polynomial ans;
    ans.greatestPower = this->greatestPower + b.greatestPower;
    int store[101] = {0};

    for(int i = b.greatestPower; i >= 0; i--)
    {
        for(int j = this->greatestPower; j >= 0; j--)
        {
            store[i+j] += this->coefficients[j] * b.coefficients[i];
            //cout << "i+j : " << i+j << ", " << ans.coefficients[i+j] << endl;
        }
    }
    for(int i = ans.greatestPower; i >= 0; i--)
    {
        ans.coefficients[i] = store[i];
    }
    return ans;
} // multiplication function
void Polynomial::output() const
{
    for(int i = this->greatestPower; i > 0; i--)
    {
        cout << this->coefficients[i] << " ";
    }
    cout << this->coefficients[0];
}

