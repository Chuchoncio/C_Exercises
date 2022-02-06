#include <iostream>

using namespace std;

inline float cubo(const float s) { return s*s*s; }

int main()
{
    cout << "El cubo de lado 5 tiene volumen: " << cubo(5) << "cm^3" << endl;
    return 0;
}
