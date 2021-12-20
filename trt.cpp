#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{
    if (b == 0) {
        return a;
    }
    if (a < b) {
        return gcd(b, a);
    }
    return gcd(b, a % b);
}

bool isRelativelyPrime(int m[]) 
{
    if(gcd(m[0], m[1]) == 1) {
        if (gcd(m[1], m[2]) == 1) {
            return gcd(m[0], m[2]) == 1;
        }
    }
    return false;
}


int inverse(int a, int b)
{
    int i = 1;
    while(i < b)
    {
        if(fmod(a * i, b) == 1)
            return i;
        i++;
    }
    return 0;
}


int main()
{
    int a[3], m[3];

    for (int i = 0; i < 3; i++) {
        cout<<"Enter a"<<i+1<<":- ";
        cin>>a[i];
        cout<<"Enter m"<<i+1<<":- ";
        cin>>m[i];
    }

    if (isRelativelyPrime(m)) {
        int M = m[0] * m[1] * m[2];

        int M1 = M/m[0];
        int M2 = M/m[1];
        int M3 = M/m[2];

        int M1i = inverse(M1, m[0]);
        int M2i = inverse(M2, m[1]);
        int M3i = inverse(M3, m[2]);

        int temp = (a[0]*M1*M1i + a[1]*M2*M2i + a[2]*M3*M3i);

        int result = temp % M;

        cout<<"x = "<<result<<endl;
    }

    return 0;
}