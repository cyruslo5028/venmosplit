#include "VenmoSplit.h"


int main(){
    //Clear the screen for better view
    system("clear");
    bool run = true;
    int num_people =0;
    bill b1;
    cout<<"Welcome to Venmo Split!"<<endl;
    cout<<"How many people you need to split your bill with?: ";
    cin >> num_people;
    cin.clear();
    double total=0.0;
    cout<<"Enter the total amount with tax: $";
    cin >> total;
    cin.clear();
    double tax;
    cout<<"Enter the tax of the bill: $";
    cin >> tax;
    cin.clear();
    b1.set_num_ppl(num_people);
    b1.set_tax(tax);
    b1.set_total_amount(total);
    string name="";
    double amount=0.0;
    cout<<endl;
    for(int i=0;i<num_people;++i){
        printf("%d. Please enter the name: ",i+1 );
        cin.ignore();
        getline(cin,name);
        cout<<"Please enter the amount of that person spent(without tax): $";
        cin>>amount;
        cin.clear();
        b1.add_people(name,amount);
        cout<<"\n";
    }
    b1.print_bill();
    return 0;
}