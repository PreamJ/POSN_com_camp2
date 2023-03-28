#include <iostream>
using namespace std;

int *resize(int a[], int size) {
    int *temp = new int[size*2];
    for (int i=0; i<size; i++) {
        *(temp + i) = a[i];
    }
    delete[] a;
    a = temp;
    size *= 2;
    return a;
}

int main() {
    int size = 4;
    int *a = new int[size]{1, 2, 3, 4};
    a = resize(a, size); size *= 2;
    for (int i=0; i<size; i++){
        cout << *(a + i) << endl;
    }
    return 0;
}
