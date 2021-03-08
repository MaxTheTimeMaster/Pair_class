#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <time.h>
#define int long long
using namespace std;


template <typename T1, typename T2>
class Pair{
public:
    T1 first;
    T2 second;

    Pair ()= default;

    Pair  (const T1 a, const T2 b){
        first = a;
        second = b;
    }

    Pair  (const Pair & copied){
        first = copied.first;
        second = copied.second;
    }

    Pair  & operator=(const Pair & copied){
        first = copied.first;
        second = copied.second;
        return (*this);
    }

    bool operator==(const Pair & other) const {
        if (other.first == first && other.second == second){
            return true;
        }
        return false;
    }

    bool operator!=(const Pair & other){
        if (other == this){
            return false;
        }

        return true;
    }

    friend bool operator>(Pair   a, Pair  b){
        if (a.first > b.first){
            return true;
        }

        if(a.first < b.first){
            return false;
        }

        if (a.second > b.second){
            return true;
        }

        return false;
    }

    friend bool operator>=(Pair  a, Pair  b){
        if (a > b){
            return true;
        }
        else if (a == b){
            return true;
        }

        return false;
    }

};


template <typename T>
vector <T> mySort(vector <T> &a){
    int s = a.size();

    for (int i = 0; i < s; i++){
        for (int j = 0; j < s - 1; j++){
            if (a[j] > a[j + 1]){
                T g = a[j];
                a[j] = a[j + 1];
                a[j + 1] = g;
            }
        }
    }

    return a;
}



signed main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }

    }

    return 0;
}
