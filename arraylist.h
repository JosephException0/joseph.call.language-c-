#include<iostream>
#include<cstdlib>
#include"list.h"
using namespace std;

class ArrayList : public List{
    int* array;
    int size;
    int capacity;
    
    public:
    ArrayList(){
        capacity=5;
        size=0;
        array=(int*)calloc(capacity,sizeof(int));
    }
    void add(int num){
        if(size>=capacity){
            capacity*=1.5;
            array=(int*)realloc(array,capacity*sizeof(int*));
        }
        array[size++]=num;
    }
    int get(int pos){
        return array[pos-1];
    }
    int getsize(){
        return size;
    }
    int removelast(){
       return array[--size];
    }
    void _print(){
        cout<<"Size: "<<size<<endl;
        
        for(int i=0;i<size;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
    
};
