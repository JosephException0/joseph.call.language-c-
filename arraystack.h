#include "arraylist.h"
#include "stack.h"

class ArrayStack: public Stack{

    ArrayList* list;
    
    public:
    
    ArrayStack(){
        list=new ArrayList();
    }
    
    void push(int num){
        list->add(num);
    }
    int top(){
        return list->get(list->getsize());
    }
    int pop(){
        return list->removelast();
    }
    int size(){
        return list->getsize();
    }
    bool isEmpty(){
        return size()==0;
    }
    void print(){
        list->_print();
    }
    int checkbalance(string mystring){
    	
    	for(int i=0;i<mystring.length();i++){
    		char ch=mystring[i];
    		if(ch=='(' || ch=='['|| ch=='{'){
    			push(ch);
			}else if(ch==')' || ch==']' || ch=='}'){
				if(isEmpty()){
					return 3;
				}
					
				char top=this->top();
				if((ch==')' && top!='(' )|| (ch==']' && top!='[') || (ch=='}' && top!='{') ){
				//	cout << "Mismatch found: " << ch << " does not match " << top << endl; //debug trick
					return 1;
				}
				pop();
			}
		}
		if(!isEmpty()){
			return 2;
		}
    	return 0;
	}
};
