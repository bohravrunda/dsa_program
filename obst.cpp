#include<iostream>
using namespace std;
#define size 10

class obst {
    int p[size];
    int q[size];
    int a[size];
    int w[size][size];
    int c[size][size];
    int r[size][size];
    int n;
public: 
    void get_data() {
        int i;
        cout << "Enter no. of elements: ";
        cin >> n;
        cout << "Enter data:\n";
        for(i = 1; i <= n; i++) {
            cout << "\n a[" << i << "]: ";
            cin >> a[i];
        }
        for(i = 1; i <= n; i++) {
            cout << "\n p[" << i << "]: ";
            cin >> p[i];
        }
        for(i = 0; i <= n; i++) {
            cout << "\n q[" << i << "]: ";
            cin >> q[i];
        }
    }

    void build_obst() {
        int i, j, k, m;
        for(i = 0; i < n; i++) {
            w[i][i] = q[i];
            c[i][i] = r[i][i] = 0;
            w[i][i+1] = q[i] + q[i+1] + p[i+1];
            r[i][i+1] = i+1;
            c[i][i+1] = q[i] + q[i+1] + p[i+1]; 
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;
        for(m = 2; m <= n; m++) { 
            for(i = 0; i <= n - m; i++) {
                j = i + m;
                w[i][j] = w[i][j-1] + p[j] + q[j];
                k = find_min(i, j);
                c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
                r[i][j] = k;
            }
        }
    }
    
    int find_min(int i, int j) {
        int m, k;
        int minimum = 9999;
        for(m = r[i][j-1]; m <= r[i+1][j]; m++) {
            if((c[i][m-1] + c[m][j]) < minimum) {
                minimum = c[i][m-1] + c[m][j];
                k = m;
            }
        }
        return k;
    }

    void build_tree() {
        int i, j, k;
        int queue[20], front = -1, rear = -1;
        cout << "Root is " << r[0][n] << endl;
        cout << "Cost is " << c[0][n] << endl;
        queue[++rear] = 0;
        queue[++rear] = n;
        while(front != rear) { 
            i = queue[++front];
            j = queue[++front];
            k = r[i][j];
            cout << "\n" << k;
            if(r[i][k-1] != 0) {
                cout << "\t\t" << r[i][k-1];
                queue[++rear] = i;
                queue[++rear] = k-1;
            } else {
                if(r[k][j] != 0) {
                    cout << "\t" << r[k][j];
                    queue[++rear] = k;
                    queue[++rear] = j;
                } else {
                    cout << "\t";
                }
            }   
        }
    }
};

int main() {
    obst obj;
    obj.get_data();
    obj.build_obst();
    obj.build_tree();
    return 0;
}

