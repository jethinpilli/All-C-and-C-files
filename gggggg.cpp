#include<iostream>
using namespace std;

int main(){

    int ar[100],sz,cnt = 0;

    cout << "Enter size of the array : ";
    cin >> sz;

    cout << "Enter elements in array (Separated by space): ";
    for(int i = 0; i < sz; i++)cin >> ar[i];

    for(int i = 0; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            if(ar[i] == ar[j]){
                cnt++;
                break;
            }
        }
    }
    cout << endl << "Total number of duplicate elements found in array = " << cnt << endl;

    return 0;
}
