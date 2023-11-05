#include <iostream>
using namespace std;

const int MAX = 100;

class SparseMatris {
    int row, col, num;
    int data[MAX][3];
public:
    SparseMatris(int r, int c, int n) {
        row = r;
        col = c;
        num = n;
    }
    void read() {
        cout << "Enter the elements of the matris:\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int x;
                cin >> x;
                if (x != 0) {
                    data[num][0] = i;
                    data[num][1] = j;
                    data[num][2] = x;
                    num++;
                }
            }
        }
    }
    void display() {
        cout << "Sparse Matris:\n";
        for (int i = 0; i < num; i++) {
            cout << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the matris: ";
    cin >> n;
    SparseMatris s(n, n, 0);
    s.read();
    s.display();
    return 0;
}
