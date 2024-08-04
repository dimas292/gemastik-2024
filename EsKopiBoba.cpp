#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    int sum = 0;
    int max = 0; 
    int min = 0; 
    int y = 0; 
    int z = 0; 
    bool same = true; 

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    int amount = sum / N;
    for(int i = 0; i < N; i++){
        if(arr[i] != amount){
            same = false;
            break;
        }
    }
    
    if(same){
        cout << "SESUAI" <<endl;
    }else {
        for(int i = 0; i < N; i++){
            if(arr[i] > amount){
                max = arr[i];
                y = i + 1;
            }
            if(arr[i] < amount){
                min = arr[i];
                z = i + 1;
            }
        }
        int diff = max - min;
        int x = max - amount;
        if(diff / 2 + min == amount){
            cout << x << " " << y <<" " << z <<endl;
        }else {
            cout << "TIDAK SESUAI" <<endl;
        }
    }
    return 0;
}