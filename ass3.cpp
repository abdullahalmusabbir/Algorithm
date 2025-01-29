#include<bits/stdc++.h>
using namespace std;

struct Bank
{
    string name;
    int amount,id,password,number;
    Bank(): name(""),amount(0),id(0),password(0),number(0) {}

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Amount: "<<amount<<endl;
        cout<<"Number: "<<number<<endl;

    }

    void update_name(string new_name)
    {
        name=new_name;
    }
    void update_amount(int new_amount)
    {
        amount=new_amount;
    }
    void update_number(int new_number)
    {
        number=new_number;
    }
    void update_password(int new_password)
    {
        password=new_password;
    }
};

void welcome()
{
    cout<<"\t\t\t\t\tMy Banking System\t\t\t\t\t" <<endl;
}

int find_customer(struct Bank acc[],int sz,int key,string username)
{
    for(int i=0;i<sz;i++)
    {
        if(username==acc[i].name){
            if(key==acc[i].password)
               return i;
        }
    }
    return -1;
}

int main ()
{
    struct Bank b[100];
    string name;
    int option,id,idx,amnt,opsn_updt,lopsn,password,k=4;

    b[0].name="Rashik",b[0].amount=10,b[0].id=12,b[0].password=1234,b[0].number=01234;
    b[1].name="Nabil",b[1].amount=100,b[1].id=13,b[1].password=1235,b[1].number=01234;
    b[2].name="Kulsum",b[2].amount=1000,b[2].id=14,b[2].password=1236,b[2].number=01234;
    b[3].name="Rukaiya",b[3].amount=10000,b[3].id=15,b[3].password=1237,b[3].number=01234;
    welcome();

    while(true)
    {
        cout<<"1.Sign Up"<<endl;
        cout<<"2.Sign In"<<endl;
        cin>>lopsn;
        if(lopsn==1)
        {
            for(int j=k;j<100;j++)
            {

            cout<<"Name: "<<endl;
            cin>>b[j].name;
            cout<<"Password: "<<endl;
            cin>>b[j].password;
            cout<<"Amount: "<<endl;
            cin>>b[j].amount;
            cout<<"Number: "<<endl;
            cin>>b[j].number;
            b[j].id=j+12;
            k++;
            break;

            }

        }
        else if(lopsn==2)
        {
            cout<<"User Name: "<<endl;
            cin>>name;
            cout<<"Password: "<<endl;
            cin>>password;
            idx=find_customer(b,100,password,name);
            if(idx==-1)
            {
                cout<<"Account not found"<<endl;
                continue;
            }
            cout<<"Please select one option from below menu."<<endl;
            cout<<"1.View Details\n2.Deposit Amount\n3.Withdraw Amount\n4.check Balance\n5.Update Record\n6.Exit"<<endl;
            cin>>option;

            while(true){

              if(option==6)
              {
                cout<<"Program Terminated"<<endl;
                break;
              }
              else if(option==1)
              {
                int psn1;
                while(true){
                b[idx].display();
                cout<<"1.Back"<<endl;
                cin>>psn1;
                if(psn1==1)
                    break;
                }
              }
              else if(option==2)
              {
                cout<<"Enter The Amount You Want To Deposit\n"<<endl;
                cin>>amnt;

                b[idx].update_amount(b[idx].amount+amnt);
              }
              else if(option==3)
              {
                cout<<"Enter the amount you want to withdraw\n"<<endl;
                cin>>amnt;
                if((b[idx].amount-amnt)<0)
                {
                    cout<<"You Don't Have Suficient Balance."<<endl;
                }
                else
                {
                    b[idx].update_amount(b[idx].amount-amnt);
                }
              }

              else if(option==4)
              {
                  int psn2;
                  while(true)
                  {
                  cout<<"Your Current Balance Is: "<<b[idx].amount<<endl<<endl;

                  cout<<"1.Back"<<endl;
                  cin>>psn2;
                  if(psn2==1)
                    break;
                  }

              }

              else if(option==5)
              {
                cout<<"Whta do you want to update?\n1.Name\n2.Number\n3.Password"<<endl;
                cin>>opsn_updt;
                if(opsn_updt==1)
                {
                    string name;
                    cout<<"Input Name: "<<endl;
                    cin>>name;
                    b[idx].update_name(name);
                }
                else if(opsn_updt==2)
                {
                    int number;
                    cout<<"Input Number: "<<endl;
                    cin>>number;
                    b[idx].update_number(number);
                }
                else if(opsn_updt==3)
                {
                    int password;
                    cout<<"Input Password: "<<endl;
                    cin>>password;
                    b[idx].update_password(password);
                }

              }

            }
        }
    }
   return 0;
}
