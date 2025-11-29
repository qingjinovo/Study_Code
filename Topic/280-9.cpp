#include <iostream>
using namespace std;
class num
{
public:
    double average()
    {
        return (sum / n);
    }
    void num_display()
    {
        cout << "sum is " << sum << endl;
        cout << "average is " << average() << endl;
    }
    num(double p, double q)
    {
        quantity = q;
        price = p;
        n += q;
        sum += p * q;
    }

private:
    double price, quantity;
    static double discount;
    static double sum;
    static int n;
};
double num::sum=0;
int num::n=0;
int main()
{
    num a(23.5, 5), b(24.56, 12), c(21.5, 100);
    a.num_display();
    return 0;
}