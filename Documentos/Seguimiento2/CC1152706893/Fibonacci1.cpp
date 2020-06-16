#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Introduzca el numero de terminos de la serie: ";
    cin >> n;
    cout << "Los " << n << " primeros numeros de la serie de Fibonacci son:" << endl;
 
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
   
   if (n <= 0) {
        cout << n << endl;
    }
    else if (n <= 1) {
        cout << n << endl;
    }
    else {
        for (int i = 2; i <= n; i++) {
            a.push_back(a[i - 1] + a[i - 2]);
           
            cout << a[i];
        }
    }
}
