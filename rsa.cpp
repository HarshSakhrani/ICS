#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    while (1)
    {
        int temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

int main()
{
    int a = 3, b = 11, n, e = 2;
    double d, phi, msg = 13;

    n = a * b;
    phi = (a - 1) * (b - 1);

    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }
    // Public Key: (e, n)

    for (int i = 1; i < 100; i++)
    {
        d = ((phi * i) + 1);
        if (fmod(d, e) == 0)
        {
            d = d / e;
            break;
        }
    }

    // Private Key: (d, n)

    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    double c = fmod(pow(msg, e), n);
    cout << "Encrypted Message: " << c << endl;

    double p = fmod(pow(c, d), n);
    cout << "Decrypted Message: " << p << endl;

    return 0;
}
