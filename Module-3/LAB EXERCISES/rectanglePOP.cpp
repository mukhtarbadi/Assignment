#include <iostream>
using namespace std;

int main() {
    int length, width;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    int area = length * width;

    cout << "Area of rectangle: " << area;
    return 0;
}
