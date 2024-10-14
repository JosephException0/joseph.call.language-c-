#include<iostream>
#include"arraystack.h"
int main(){
    
    Stack* stack = new ArrayStack();
    int n;
    char op;
    string mystring;
    cout<<"choose(add-a, print-p, r-remove, t-top, s-size, e-empty, S-input parenthesis, c-checkparenthesis): "<<endl;
    do{
        cin>>op;
        switch(op){
            
            case 'a':
                cin>>n;
                stack->push(n);
                break;
            case 'p':
                stack->print();
                break;
            case 'r':
                cout<<"Remove: "<<stack->pop()<<endl;
                break;
            case 't':
                cout<<"Top: "<<stack->top()<<endl;
                break;
            case 's':
                cout<<"Size: "<<stack->size()<<endl;
                break;
            case 'e':
                cout<<(stack->isEmpty()==0 ? "Not Empty": "Empty")<<endl;
                break;
            case 'S':
            	cin>>mystring;
            	break;
            case 'c':
            	int a=stack->checkbalance(mystring);
            	if(a==0){
            		cout<<"String is balanced"<<endl;
				}else if(a==1){
					cout<<"String is mismatched"<<endl;
				}else if(a==2){
					cout<<"String is lacks closing"<<endl;
				}else if(a==3){
					cout<<"String lacks opening"<<endl;
				}
				break;
				
        }
        
        
    }while(op != 'x');
    return 0;
}
