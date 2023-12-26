#include<iostream>
#include<numeric>
#include<vector>
#include<fstream>
using namespace std;
class user{
    string firstname;
    string lastname;
    int mobilenumber;
    string username;
    int password;
    public:
    user(){
        cout<<"\n################ -------- WELCOME ------- ############"<<endl;
        cout<<"\n"<<endl;
        int k;
        cout<<" 1.Register \n 2.Login \n 3.Exit "<<endl;
        cout<<"Enter Choice"<<" ";
        cin>>k;
        switch(k){                                                                   
    case 1:
    Register();
    break;
    case 2:
    login();
    break;
    case 3:
    cout<<"Thankyou"<<endl;
    break;

}
        }

     void Register(){
        cout<<"ENTER YOUR NAME"<<endl;
        cin>>firstname;
        cout<<"ENTER YOUR LAST NAME"<<endl;
        cin>>lastname;
        cout<<"CREATE A USER NAME"<<endl;
        cin>>username;
        cout<<"CREATE A PASSWORD"<<endl;
        cin>>password;
        cout<<"ENTER YOUR MOBILE NUMBER"<<endl;
        cin>>mobilenumber;
        cout<<"DETAILS SAVED"<<endl;
        cout<<"---------------LOGIN------------------"<<endl;
        cout<<endl;
        ofstream fout1("usernames.dat",ios::app);
        fout1<<username<<"\t"<<password<<"\n";
        ofstream fout("resta.dat",ios::app);
        fout<<firstname<<"\t\t"<<lastname<<"\t\t"<<username<<"\t\t"<<password<<"\t\t"<<mobilenumber<<"\n";
        fout.close();
        fout1.close();
        login();
    }
     void login(){
        string j;
        int p;
        string l;
        cout<<"ENTER USERNAME"<<endl;
        cin>>j;
        cout<<"ENTER PASSWORD"<<endl;
        cin>>p;
        ifstream fin("usernames.dat",ios::in);
        string user;
        int pass;
        while(user!=j){
        fin>>user>>pass;
        if(fin.eof()){
            cout<<"Invalid Username\n";
            break;
        }
        }
        if(pass==p){
            cout<<"SUCCESSFULLY LOGGEDIN"<<endl;
        }
        else{
            cout<<"Invalid Credentials"<<endl;
            cout<<"DO YOU WANT TO SIGN????"<<endl;
            cin>>l;
            if(l=="yes"||l=="YES"){
                Register();
            } 
            else{
              cout<<"LOGIN AGAIN"<<endl;
              login();
            }
        }}
        
          
     
      
};
class ALL : public user{
    
    vector<int> q;
    double amount=0;
    int totaltables=100;
    int t;
    public:
    ALL(){
        
        cout<<"\n 1. MENU\n 2. TABLE BOOKING\n 3.CANCEL RESERVATION\n 4.exit"<<endl;
        int k;
        cout<<"Enter Choice"<<" ";
        cin>>k;
        switch(k){
            case 1:
            
            displaymenu();
            break;
            case 2:
            tablebooking();
            break;
            case 3:
            cancelbooking();
            break; 
            case 4:
            break;       }
    }
    void displaymenu(){
        bool i =true;
        while(i){
     cout<<"\n----------  MENU  ----------\n"<<endl;
     
     cout<<"\n 1.BEVERAGE\n 2.SABJI\n 3. snacks\n 4. roti \n5.exit"<<endl ;
     int o;
     cout<<"Enter choice"<<" ";
     cin>>o;
     if(o==1){
        cout<<"\n---------------  BEVERAGES  ------------\n"<<endl;
        cout<<"1.BUTTER MILK   25 "<<endl;
        cout<<"2.tea           45"<<endl;
        cout<<"3.cold coffee   75"<<endl;
        cout<<"4.aam ras       80"<<endl;
        int e;
        cout<<"your order??"<<endl;
        cin>>e;
        switch(e){
            case 1:
            q.push_back(25);
            break;
            case 2:
            q.push_back(45);
            break;
            case 3:
            q.push_back(75);
            break;
            case 4:
            q.push_back(80);
            break;
            case 5:
            false;
            break;
        }

     }
     else if(o==2){
        cout<<"\n----------------SABJI-------------\n"<<endl;
        cout<<"1.shahi paneer     180"<<endl;
        cout<<"2.punjabi paneer   140"<<endl;
        cout<<"3.kadhai paneer    190"<<endl;
        cout<<"4.Palak paneer     200"<<endl;
        cout<<"5.mix veg          120"<<endl;  
        cout<<"enter order"<<endl;
        int h;
        cin>>h;
        switch(h){
            case 1:
            q.push_back(200);
            break;
            case 2:
            q.push_back(180);
            break;
            case 3:
            q.push_back(140);
            break;
            case 4:
            q.push_back(190);
            break;
            case 5:
            q.push_back(120);
            break;
        }
      
     }
     else if(o==3){
        cout<<"\n----------------SNACKS-------------\n"<<endl;
        cout<<"1. pav bhaji       90"<<endl;
        cout<<"2. sandwich        70"<<endl;
        cout<<"3. chowmein        90"<<endl;
        cout<<"4. maggie          50"<<endl;
        cout<<"enter order"<<endl;
        int y;
        cin>>y;
        switch(y){
            case 1:
            q.push_back(90);
            break;
            case 2:
            q.push_back(70);
            break;
            case 3:
            q.push_back(90);
            break;
            case 4:
            q.push_back(50);
            break;}
     }
     else if(o==5){
        i=false;
       

     }
     
     else {
        cout<<"\n-----------------ROTI-------------\n"<<endl;
        cout<<"1.tandoori roti            rs 10"<<endl;
        cout<<"2.plain roti               rs 8"<<endl;
        cout<<"3.plain roti with butter   rs 10"<<endl;
        cout<<"enter order"<<endl;
        int m;
        cin>>m;
        switch(m){
            case 1:
            q.push_back(10);
            break;
            case 2:
            q.push_back(8);
            break;
            case 3:
            q.push_back(10);
            break;
            
    }}

        
        amount = accumulate(q.begin(),q.end(),0);
        
            }}
     
    
    void tablebooking(){
        string customername;
        int p;
        cout<<"\nEnter total number of people"<<endl;
        cin>>p;
        cout<<"TIME SLOT \n 1. 10 a.m. to 1 p.m \n 2. 1 p.m to 4 p.m \n 3. 4 p.m to 7 p.m"<<endl;
        int l;
        cin>>l;
        if(p>=4){
        t = p/4;} else{t=1;}
        if(totaltables<=100){
            totaltables = totaltables -t;
            cout<<"\nEnter customer name"<<endl;
            cin>>customername;
            cout<<"\nEnter mobile number"<<endl;
            int mob;
            cin>>mob;
            cout<<"Do you want to order food"<<endl;
            string j;
            cin>>j;
            if(j=="yes"||j=="YES"){
                displaymenu();
            }
            if(amount>0){
            cout<<"\n             -----------  Successfully booked  --------------        \n"<<endl;
            cout<<" Customer id:"<<mob<<endl;
            cout<<" Customer name: "<<customername<<endl;
            cout<<" Amount : "<<amount<<endl;
            cout<<" total table booked:"<<t;}
            else{
           cout<<"\n             -----------  Successfully booked  --------------        \n"<<endl;
            cout<<" Customer id:"<<mob<<endl;
            cout<<" Customer name: "<<customername<<endl;
            cout<<" total table booked:"<<t;}
            }
        }
        
    void cancelbooking(){
    int k ;
     totaltables = totaltables +t;
     cout<<"enter customer id"<<endl;
     cin>> k;
     cout<<"--------  BOOKING CANCELLED  ----------"<<endl;

    }


};
int main(){
ALL o;
}
