#include <iostream>
using namespace std;

class Rect {
public:
    int len, wid;

    void input() {
        cout << "Enter length: ";
        cin >> len;
        cout << "Enter width: ";
        cin >> wid;
    }

    void rect() {
        int area = len * wid;
        cout << "Area of rectangle: " << area;
    }
};

int main() {
    Rect r;   // object
    r.input();
    r.rect();
    return 0;
}
