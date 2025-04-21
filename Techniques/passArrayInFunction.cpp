#include<iostream>
using namespace std;

int f(int arr[][67][98]){
    //this is the way to pass 3D array to a function
    //arrays are always passed without reference
    //vectors are always passed by reference
}

int f1(int arr[][56]){
    //way to pass 2D array
}

int main(){
    int arr[34][67][98];
    int arr2[6][56];

    return f(arr);
    return f1(arr2);
}