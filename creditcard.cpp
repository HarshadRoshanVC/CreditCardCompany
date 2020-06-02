
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Global Constant
const double CREDIT_LIMIT = 1500.00;
// Struct
struct CreditCard
{
string FirstName;
string LastName;
string CCN;
double balance;
};
//Function prototypes
void ChargeToCard(CreditCard & CC, double money);
void print(const CreditCard & CC);
void bubbleSort(CreditCard ccArr[], int flag, int len);
int LinearSearch(const CreditCard ccArr[], const CreditCard & CC,
int flag, int len);
void print(const CreditCard arr[], int len);
void makePaymentToCard(CreditCard & CC, double money);
//Array Capacity
const int MAX = 100;
// Main function
int main()
{
cout<<fixed<<showpoint<<setprecision(2);
CreditCard CC1 = {"JIM", "JONES", "56738", 0.0};
ChargeToCard(CC1, 200.99);
CreditCard CC2={"ADAM", "ASHLEY", "12345", 0.0};
ChargeToCard(CC2, 2000.00);
CreditCard CC3 = {"BERTHA", "MAPOS", "34567", 0.0};
ChargeToCard(CC3, 800.91);
CreditCard CC4 = {"LISA", "BRAVE", "98765", 0.0};
ChargeToCard(CC4, 1001.23);
CreditCard CC5 = {"WILLY", "NILLY", "23413", 0.0};
ChargeToCard(CC5, 700.00);
CreditCard CC6 = {"JILL", "QUIRK", "67895", 0.0};
ChargeToCard(CC6, 1400.91);
CreditCard CardArray[MAX];
CardArray[0] = CC1;
CardArray[1] = CC2;
CardArray[2] = CC3;
CardArray[3] = CC4;
CardArray[4] = CC5;
CardArray[5] = CC6;
bool done = false;
while (!done)

{
cout << "Enter the menu item number below and then press enter key." <<
endl
<< "1. Print credit card list in its current state.\n"
<< "2. Sort based on last name.\n"
<< "3. Sort based on credit card number\n"
<< "4. Sort based on balance.\n"
<< "5. Search based on last name.\n"
<< "6. Search based on credit card number.\n"
<< "7. Exit.\n";
int choice;
cin >> choice;
if (choice == 7)
{
    done = true;
}
else if (choice == 1)
{
    print(CardArray,6);//printing 6 card holder details
}
else if (choice == 2)
{
    cout<<"Array sorted based on last name is below"<<endl;
    bubbleSort(CardArray,1,6);
}
else if (choice == 3)
{
    cout<<"Array sorted based on credit card number is below"<<endl;
    bubbleSort(CardArray,2,6);
}
else if (choice == 4)
{
    cout<<"Array sorted based on balance is below"<<endl;
    bubbleSort(CardArray,3,6);
}
else if (choice == 5)
{
    string last;//for last name
    int result;//for return value of search
    cout<<"Enter last name of card holder in all capital [For example adams must be entered as ADAMS:";
    cin>>last;
    CreditCard temp;//creating temporary structure for storing last name and pass to function
    temp.LastName=last;
    result=LinearSearch(CardArray,temp,1,6);
    
    if(result!=-1){//checking return value is -1 if so else will work
        print(CardArray[result]);
    }else{
        cout<<"Record with name "<<last<<" not found"<<endl;
    }
    
}
else if (choice == 6)
{
    string CCNo;
    cout<<"Enter credit card number:";
    cin>>CCNo;
    CreditCard temp;
    temp.CCN=CCNo;
    int result=LinearSearch(CardArray,temp,2,6);
    if(result!=-1){
        print(CardArray[result]);
    }else{
        cout<<"credit card number -"<<CCNo<<" not found"<<endl;
    }
}
else
{
cout << "This menu item is not yet implemented.\n";
}
}
}
// Function defintions
void print(const CreditCard & CC)
{
        cout<<"Credit Card Number:"<<CC.CCN<<endl;
        cout<<"Name:"<<CC.FirstName<<" "<<CC.LastName<<endl;
        cout<<"Amount owed:$"<<CC.balance<<endl;
        cout<<"_____________________________________"<<endl;
}
void print(const CreditCard arr[], int len)
{
    for(int i=0;i<len;i++){
        cout<<"Credit Card Number:"<<arr[i].CCN<<endl;
        cout<<"Name:"<<arr[i].FirstName<<" "<<arr[i].LastName<<endl;
        cout<<"Amount owed:$"<<arr[i].balance<<endl;
        cout<<"_____________________________________"<<endl;
    }
}
int LinearSearch(const CreditCard ccArr[], const CreditCard & CC, int flag, int
len)
{
    if(flag==1){//searching using last name
        for(int i=0;i<len;i++){
            if(ccArr[i].LastName==CC.LastName){
                return i;
            }
        }
    }else if(flag==2){//searching using credit card number
        for(int i=0;i<len;i++){
            if(ccArr[i].CCN==CC.CCN){
                return i;
            }
        }
    }
    return -1;
}
void bubbleSort(CreditCard ccArr[], int flag, int len)
{
    if(flag==1){//sorting based on last name
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-i-1;j++){
                if(ccArr[j].LastName.compare(ccArr[j+1].LastName)>0){
                    CreditCard temp=ccArr[j];
                    ccArr[j]=ccArr[j+1];
                    ccArr[j+1]=temp;
                }
            }
        }
    }else if(flag==2){//sorting based on credit card number
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-i-1;j++){
                if(ccArr[j].CCN>ccArr[j+1].CCN){
                    CreditCard temp=ccArr[j];
                    ccArr[j]=ccArr[j+1];
                    ccArr[j+1]=temp;
                }
            }
        }
    }else if(flag==3){//sorting based on balance
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-i-1;j++){
                if(ccArr[j].balance>ccArr[j+1].balance){
                    CreditCard temp=ccArr[j];
                    ccArr[j]=ccArr[j+1];
                    ccArr[j+1]=temp;
                }
            }
        }
    }
    print(ccArr,len);
}// Function
void ChargeToCard(CreditCard & CC, double money)
{
    if(CC.balance+money>CREDIT_LIMIT){//checking credit limit
        cout<<"Hello "<<CC.FirstName<<" "<<CC.LastName<<endl;//notification of failure
        cout<<"Charging $"<<money<<" will exceed credit limit. Transaction declined"<<endl;
        cout<<"_____________________________________"<<endl;
    }else{
        CC.balance=CC.balance+money;
    }
}
void makePaymentToCard(CreditCard & CC, double money)
{
    CC.balance=CC.balance-money;
}
