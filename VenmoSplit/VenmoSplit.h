#ifndef VENMOSPLIT_H
#define VENMOSPLIT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class bill{
    private:
        struct Node{
            string name;
            double amount;
            Node* next;
        };

        int num_people; // number of poeple in the bill
        double tax; //tax in $
        double tax_percentage; //tax in %
        double total_amount; //total amount with tax
        Node* head = nullptr; //list of people
    
    public:
        
        //default constructor
        bill (){
            num_people = 0;
            tax=0.0;
            total_amount = 0.0;
        }

        //destructor
        ~bill(){
            if(head != nullptr){
                Node* temp = head;
                Node* next = temp->next;
                while(next != nullptr){
                    delete temp;
                    temp =next;
                    next = next->next;
                }
                delete temp;
            }
        }
        //Set number of poeple
        void set_num_ppl(int& n){
            this->num_people = n;
        }
        //Set the total amount of the bill
        void set_total_amount(double amount){
            this->total_amount = amount;
        }
        void set_tax(double tax){
            this->tax = tax;
        }
        // add people to the bill
        void add_people(string name, double amount){
            if(head == nullptr){
                head = new Node();
                head->name = name;
                head->amount = amount;
                head->next = nullptr;
            }
            else{
                Node* temp = head;
                while(temp->next !=nullptr){
                    temp = temp->next;
                }
                temp->next = new Node();
                temp = temp->next;
                temp->amount = amount;
                temp->name = name;
                temp->next = nullptr;
            }
        }
        void print_bill(){
            tax_percentage = tax/(total_amount-tax);
            cout<<"Bill:"<<endl;
            Node* temp = head;
            int count=1;
            while(temp!=nullptr){
                cout<<count<<"."<<temp->name;
                printf(": $%.2f +$%.2f(tax)\nTotal amount(with tax): $%.2f\n\n",temp->amount,\
                (temp->amount * tax_percentage),temp->amount+(temp->amount * tax_percentage));
                temp=temp->next;
                ++count;
            }
        }
};



#endif