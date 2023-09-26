#include<iostream>
#include<windows.h>
#include<fstream>
using namespace std;
static int partnerCount=0;
static int customerCount=0;
class partner{
    string name;
    string mail;
    int chargesPerDay;
    string password;
    string city;
    string carName;
    string carModel;
    public:
    void setChargesPerDay(int chargesPerDay){
        this->chargesPerDay=chargesPerDay;
    }
    void setPassword(string password){
        this->password=password;
    }
    void setMail(string mail){
        this->mail=mail;
    }
    void setName(string name){
        this->name=name;
    }
    void setCarName(string carName){
        this->carName=carName;
    }
    void setCity(string city){
        this->city=city;
    }
    void setCarModel(string carModel){
        this->carModel=carModel;
    }
    int getChargesPerDay(){
        return chargesPerDay;
    }
    string getName(){
        return name;
    }
    string getCity(){
        return city;
    }
    string getCarName(){
        return carName;
    }
    string getCarModel(){
        return carModel;
    }
    string getMail(){
        return mail;
    }
    string getPassword(){
        return password;
    }

};
class customer{
    string name;
    string mail;
    string password;
    string city;
    public:
    void setPassword(string password){
        this->password=password;
    }
    void setMail(string mail){
        this->mail=mail;
    }
    void setName(string name){
        this->name=name;
    }
    void setCity(string city){
        this->city=city;
    }
    string getName(){
        return name;
    }
    string getCity(){
        return city;
    }
    string getMail(){
        return mail;
    }
    string getPassword(){
        return password;
    }

};
class bill:public customer{
    public:
    void print_bill(int days,int option,partner* ptrPartner){
        ofstream fout("bill.txt",ios::app |ios::out);
        fout << "Customer Name: " <<ptrPartner[option].getName()<< endl;
        fout << "City: " <<ptrPartner[option].getCity()<<endl;
        fout << "Email: " <<ptrPartner[option].getMail()<< endl;
        fout << "Total Bill: " <<ptrPartner[option].getChargesPerDay()*days<<" $"<< endl<<endl;
        fout.close();
    }
};
class userinterface{
    partner *ptrPartner;
    customer *ptrCustomer;
    public:
    string partnerMail(int num){
           return ptrPartner[num].getMail();
    }
    string partnerPassword(int num){
        return ptrPartner[num].getPassword();
    }
    string customerMail(int num){
        return ptrCustomer[num].getMail();
    }
    string customerPassword(int num){
        return ptrCustomer[num].getPassword();
    }
    void addPartner(){
    string name;
    string mail;
    string password;
    string city;
    string carName;
    string carModel;
    int chargesPerDay;
    int option;
    cin.ignore();
    cout<<endl<<"Enter Name: ";
    getline(cin,name);
    while(true){
    cout<<endl<<"1) Islamabad"<<endl<<"2) Lahore"<<endl<<"3) Karachi"<<endl<<"4) Peshawar"<<endl<<endl<<"Select Your City: ";
    cin>>option;
    if (option==1)
    {
        city="Islamabad";
        break;
    }
    else if (option==2)
    {
        city="Lahore";
        break;
    }
    else if (option==3)
    {
        city="Karachi";
        break;
    }
    else if (option==4)
    {
        city="Peshawar";
        break;
    }
    else{
        cout<<endl<<"Invalid Input"<<endl;
    }
    }
    cin.ignore();
    cout<<"Enter Your Car Name: ";
    getline(cin,carName);
    cout<<"Enter Your Car Model: ";
    getline(cin,carModel);
    cout<<"Enter Rate You Charged Per Day: ";
    cin>>chargesPerDay;
    cin.ignore();
    cout<<"Enter Your Email: ";
    getline(cin,mail);
    cout<<"Enter Your Password: ";
    getline(cin,password);
    if (partnerCount!=0)
    {
        partner *tempPtr=new partner[partnerCount+1];
        for (int i = 0; i < partnerCount; i++)
        {
            tempPtr[i]=ptrPartner[i];
        }
        tempPtr[partnerCount].setName(name);
        tempPtr[partnerCount].setCity(city);
        tempPtr[partnerCount].setCarName(carName);
        tempPtr[partnerCount].setCarModel(carModel);
        tempPtr[partnerCount].setChargesPerDay(chargesPerDay);
        tempPtr[partnerCount].setMail(mail);
        tempPtr[partnerCount].setPassword(password);
        delete [] ptrPartner;
        partnerCount=partnerCount+1;
        ptrPartner=new partner[partnerCount];
        for (int i = 0; i < partnerCount; i++)
        {
            ptrPartner[i]=tempPtr[i];
        }
        delete [] tempPtr;  
        cout<<endl<<"Successfully Registered !"<<endl;
    }
    else{
        ptrPartner=new partner[partnerCount+1];
        ptrPartner[partnerCount].setName(name);
        ptrPartner[partnerCount].setCity(city);
        ptrPartner[partnerCount].setCarName(carName);
        ptrPartner[partnerCount].setCarModel(carModel);
        ptrPartner[partnerCount].setChargesPerDay(chargesPerDay);
        ptrPartner[partnerCount].setMail(mail);
        ptrPartner[partnerCount].setPassword(password);
        partnerCount=partnerCount+1;
        cout<<endl<<"Successfully Registered !"<<endl;
           }
    }
    void addCustomer(){
    string name;
    string mail;
    string password;
    string city;
    int option;
    cin.ignore();
    cout<<endl<<"Enter Name: ";
    getline(cin,name);
    while(true){
    cout<<endl<<"1) Islamabad"<<endl<<"2) Lahore"<<endl<<"3) Karachi"<<endl<<"4) Peshawar"<<endl<<endl<<"Select Your City: ";
    cin>>option;
    if (option==1)
    {
        city="Islamabad";
        break;
    }
    else if (option==2)
    {
        city="Lahore";
        break;
    }
    else if (option==3)
    {
        city="Karachi";
        break;
    }
    else if (option==4)
    {
        city="Peshawar";
        break;
    }
    else{
        cout<<endl<<"Invalid Input"<<endl;
    }
    }
    cin.ignore();
    cout<<"Enter Your Email: ";
    getline(cin,mail);
    cout<<"Enter Your Password: ";
    getline(cin,password);
    if (customerCount>0)
    {
        customer *tempPtr=new customer[customerCount+1];
        for (int i = 0; i < customerCount; i++)
        {
            tempPtr[i]=ptrCustomer[i];
        }
        tempPtr[customerCount].setName(name);
        tempPtr[customerCount].setCity(city);
        tempPtr[customerCount].setMail(mail);
        tempPtr[customerCount].setPassword(password);
        delete [] ptrCustomer;
        customerCount=customerCount+1;
        ptrCustomer=new customer[customerCount];
        for (int i = 0; i < customerCount; i++)
        {
            ptrCustomer[i]=tempPtr[i];
        }
        delete [] tempPtr;  
        cout<<endl<<"Successfully Registered !"<<endl;
    }
    else{
        ptrCustomer=new customer[customerCount+1];
        ptrCustomer[customerCount].setName(name);
        ptrCustomer[customerCount].setCity(city);
        ptrCustomer[customerCount].setMail(mail);
        ptrCustomer[customerCount].setPassword(password);
        customerCount=customerCount+1;
        cout<<endl<<"Successfully Registered !"<<endl;
           }
    }
    void displayPartnerDetails(int index){
         cout<<endl<<"Name: "<<ptrPartner[index].getName();
         cout<<endl<<"City: "<<ptrPartner[index].getCity();
         cout<<endl<<"Car: "<<ptrPartner[index].getCarName();
         cout<<endl<<"Car Model: "<<ptrPartner[index].getCarModel();
         cout<<endl<<"Rate Charged Per Day: "<<ptrPartner[index].getChargesPerDay()<<" $";
         cout<<endl<<"Email: "<<ptrPartner[index].getMail();
         cout<<endl<<"Password: "<<ptrPartner[index].getPassword()<<endl;
    }
    void displayCustomerDetails(int index){
        cout<<endl<<"Name: "<<ptrCustomer[index].getName();
        cout<<endl<<"City: "<<ptrCustomer[index].getCity();
        cout<<endl<<"Email: "<<ptrCustomer[index].getMail();
        cout<<endl<<"Password: "<<ptrCustomer[index].getPassword()<<endl;
    }
    void updatePartner(int index){
        int option3,option;
        string name,city,car,carModel,Email,Password;
        int rateCharged;
        cout<<endl<<"1) Update Name"<<endl<<"2) Update City"<<endl<<"3) Update Car"<<endl<<"4) Update Car Model"<<endl<<"5) Update Rate Charged Per Day"<<endl<<"6) Update Email"<<endl<<"7) Update Password"<<endl<<endl<<"Select OPtion: ";
        cin>>option3;
        cin.ignore();
        if (option3==1)
        {
            cout<<endl<<"Enter Name: ";
            getline(cin,name);
            ptrPartner[index].setName(name);
            cout<<endl<<"Name Successfully Updated !"<<endl;
        }
        else if (option3==2)
        {
            while(true){
    cout<<endl<<"1) Islamabad"<<endl<<"2) Lahore"<<endl<<"3) Karachi"<<endl<<"4) Peshawar"<<endl<<endl<<"Select Your City: ";
    cin>>option;
    if (option==1)
    {
        city="Islamabad";
        break;
    }
    else if (option==2)
    {
        city="Lahore";
        break;
    }
    else if (option==3)
    {
        city="Karachi";
        break;
    }
    else if (option==4)
    {
        city="Peshawar";
        break;
    }
    else{
        cout<<endl<<"Invalid Input"<<endl;
    }
    }
            ptrPartner[index].setCity(city);
            cout<<endl<<"City Successfully Updated !"<<endl;
            cin.ignore();
        }
        else if (option3==3)
        {
            cout<<endl<<"Enter Car Name: ";
            getline(cin,car);
            ptrPartner[index].setCarName(car);
            cout<<endl<<"Car Name Successfully Updated !"<<endl;
        }
        else if (option3==4)
        {
            cout<<endl<<"Enter Car Model: ";
            getline(cin,carModel);
            ptrPartner[index].setCarModel(carModel);
            cout<<endl<<"Car Model Successfully Updated !"<<endl;
        }
        else if (option3==5)
        {
            cout<<endl<<"Enter Rate Charged Per Day: ";
            cin>>rateCharged;
            ptrPartner[index].setChargesPerDay(rateCharged);
            cout<<endl<<"Rate Charged Per Day Updated Successfully !"<<endl;
            cin.ignore();
        }
        else if (option3==6)
        {
            cout<<endl<<"Enter Email: ";
            getline(cin,Email);
            ptrPartner[index].setMail(Email);
            cout<<endl<<"Email Successfully Updated !"<<endl;
        }
        else if (option3==7)
        {
            cout<<endl<<"Enter Password: ";
            getline(cin,Password);
            ptrPartner[index].setPassword(Password);
            cout<<endl<<"Password Successfully Updated !"<<endl;
        }
        else{
            cout<<endl<<"Invalid Input"<<endl;
        }
    }
    void updateCustomer(int index){
             int option3,option;
        string name,city,Email,Password;
        cout<<endl<<"1) Update Name"<<endl<<"2) Update City"<<endl<<"3) Update Email"<<endl<<"4) Update Password"<<endl<<endl<<"Select OPtion: ";
        cin>>option3;
        cin.ignore();
        if (option3==1)
        {
            cout<<endl<<"Enter Name: ";
            getline(cin,name);
            ptrCustomer[index].setName(name);
            cout<<endl<<"Name Successfully Updated !"<<endl;
        }
        else if (option3==2)
        {
            while(true){
    cout<<endl<<"1) Islamabad"<<endl<<"2) Lahore"<<endl<<"3) Karachi"<<endl<<"4) Peshawar"<<endl<<endl<<"Select Your City: ";
    cin>>option;
    if (option==1)
    {
        city="Islamabad";
        break;
    }
    else if (option==2)
    {
        city="Lahore";
        break;
    }
    else if (option==3)
    {
        city="Karachi";
        break;
    }
    else if (option==4)
    {
        city="Peshawar";
        break;
    }
    else{
        cout<<endl<<"Invalid Input"<<endl;
    }
    }
            ptrCustomer[index].setCity(city);
            cout<<endl<<"City Successfully Updated !"<<endl;
            cin.ignore();
        }
        else if (option3==3)
        {
            cout<<endl<<"Enter Email: ";
            getline(cin,Email);
            ptrCustomer[index].setMail(Email);
            cout<<endl<<"Email Successfully Updated !"<<endl;
        }
        else if (option3==4)
        {
            cout<<endl<<"Enter Password: ";
            getline(cin,Password);
            ptrCustomer[index].setPassword(Password);
            cout<<endl<<"Password Successfully Updated !"<<endl;
        }
        else{
            cout<<endl<<"Invalid Input"<<endl;
        }
    }
    void carBooking(){
        int days,option,option1,option2,carNum;
        cout<<endl<<"1) Show Avaliable Cars In All Over Pakistan"<<endl<<"2) Shows Car In Cities"<<endl<<endl<<"Select Option: ";
        cin>>option1;
        if(option1==1){
            if (partnerCount==0)
            {
                cout<<endl<<"NO CARS ARE AVALIABLE"<<endl;
            }
            else{
        cout<<endl<<"ALL AVALIABLE CARS"<<endl;
        for (int i = 0; i < partnerCount; i++)
        {
            cout<<endl<<"CAR "<<i+1<<endl;
            cout<<endl<<"Car: "<<ptrPartner[i].getCarName();
            cout<<endl<<"Car Model: "<<ptrPartner[i].getCarModel();
            cout<<endl<<"City: "<<ptrPartner[i].getCity();
            cout<<endl<<"Rate Charged Per Day: "<<ptrPartner[i].getChargesPerDay()<<" $"<<endl;
        }
        cout<<endl<<"Select Car: ";
        cin>>option2;
        option2=option2-1;
        if ((option2>=0)&&(option2<partnerCount))
        {
            cout<<endl<<"Enter Number Of Days You Want To Booked a Car: ";
            cin>>days;
            cout<<endl<<"Car Has Been Booked !";
            cout<<endl<<"Total Bill: "<<ptrPartner[option2].getChargesPerDay()*days<<" $"<<endl;
            bill storeBill;
            storeBill.print_bill(days,option2,ptrPartner);
        }
        else{
            cout<<endl<<"Invalid Input"<<endl;
        }
        }
    }
    else if (option1==2)
    {
        string city;
      while(true){
    cout<<endl<<"1) Islamabad"<<endl<<"2) Lahore"<<endl<<"3) Karachi"<<endl<<"4) Peshawar"<<endl<<endl<<"Select Your City: ";
    cin>>option;
    if (option==1)
    {
        city="Islamabad";
        break;
    }
    else if (option==2)
    {
        city="Lahore";
        break;
    }
    else if (option==3)
    {
        city="Karachi";
        break;
    }
    else if (option==4)
    {
        city="Peshawar";
        break;
    }
    else{
        cout<<endl<<"Invalid Input"<<endl;
    }
      }
    int j=0;
     for (int i = 0; i < partnerCount; i++)
        {
            if (city==ptrPartner[i].getCity())
            {
                j=j+1;
            cout<<endl<<"CAR "<<j<<endl;
            cout<<endl<<"Car: "<<ptrPartner[i].getCarName();
            cout<<endl<<"Car Model: "<<ptrPartner[i].getCarModel();
            cout<<endl<<"City: "<<ptrPartner[i].getCity();
            cout<<endl<<"Rate Charged Per Day: "<<ptrPartner[i].getChargesPerDay()<<" $"<<endl;
            }
        }
        if (j==0)
        {
            cout<<endl<<"NO CARS AVALIABLE IN YOUR CITY"<<endl;
        }
        else{
            int k=0;
            int arr[j];
            for (int i = 0; i < partnerCount; i++)
            {
                if (city==ptrPartner[i].getCity())
                {
                    arr[k]=i;
                    k=k+1;
                }
            }
            cout<<endl<<"Select Car: ";
        cin>>option2;;
        option2=option2-1;
        if ((option2>=0)&&(option2<j))
        {
            option2=arr[option2];
            cout<<endl<<"Enter Number Of Days You Want To Booked a Car: ";
            cin>>days;
            cout<<endl<<"Car Has Been Booked !";
            cout<<endl<<"Total Bill: "<<ptrPartner[option2].getChargesPerDay()*days<<" $"<<endl;
            bill storeBill;
            storeBill.print_bill(days,option2,ptrPartner);
        }
        else{
            cout<<endl<<"Invalid Input"<<endl;
        }
        }
    }
    else{
        cout<<endl<<"Invalid Input"<<endl;
    }
    
        
    }
    void calCustomerBill(int rateChargedPerDay){
        int days;
        cout<<endl<<"Total Bill: "<<days*rateChargedPerDay<<" $"<<endl;
    }
};
int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY);
    cout<<"\t\t\t\t\t";
    string message = "WELCOME TO RENT A CAR";
    for (char c : message) {
        cout<<c;
        cout.flush();
        Sleep(100);
}
userinterface face;
int option;
string mail;
string password;
while (true)
{
    cout<<endl<<endl<<"1) Login"<<endl<<"2) Register"<<endl<<"3) Exit"<<endl<<endl<<"Select Option: ";
    cin>>option;
    if (option==1)
    {
        cout<<endl<<"1) Login as Partner"<<endl<<"2) Login as Customer"<<endl<<endl<<"Select Option: ";
        cin>>option;
        if (option==1)
        {
            int check1=0;
            int index;
            cin.ignore();
            cout<<endl<<"Enter Email: ";
            getline(cin,mail);
            cout<<"Enter Password: ";
            getline(cin,password);
            for (int i = 0; i < partnerCount; i++)
            {
                if ((face.partnerMail(i)==mail)&&(face.partnerPassword(i)==password))
                {
                    check1=1;
                    index=i;
                    break;
                }
            }
            if (check1==1)
            {
                cout<<endl<<"Login Successfully !"<<endl;
                int option1;
                while(true){
                cout<<endl<<"1) View Details"<<endl<<"2) Update Details"<<endl<<"3) Logout"<<endl<<endl<<"Select Option: ";
                cin>>option1;
                if (option1==1)
                {
                    face.displayPartnerDetails(index);
                }
                else if (option1==2)
                {
                    face.updatePartner(index);
                }
                else if (option1==3)
                {
                    cout<<endl<<"Logout Successfully !"<<endl;
                    break;
                }
                else{
                    cout<<endl<<"Invalid Input"<<endl;
                }
                }
            }
            else{
                cout<<endl<<"User Not Found";
            }  
        }
        else if (option==2)
        {
            int check1=0;
            int index;
            cin.ignore();
            cout<<endl<<"Enter Email: ";
            getline(cin,mail);
            cout<<"Enter Password: ";
            getline(cin,password);
            for (int i = 0; i < customerCount; i++)
            {
                if ((face.customerMail(i)==mail)&&(face.customerPassword(i)==password))
                {
                    check1=1;
                    index=i;
                    break;
                }
            }
                if (check1==1)
                {
                    cout<<endl<<"Login Successfully !"<<endl;
                int option1;
                while(true){
                cout<<endl<<"1) View Details"<<endl<<"2) Update Details"<<endl<<"3) Booked a Car"<<endl<<"4) Logout"<<endl<<endl<<"Select Option: ";
                cin>>option1;
                if (option1==1)
                {
                 face.displayCustomerDetails(index); 
                }
                else if (option1==2)
                {
                 face.updateCustomer(index);
                }
                else if (option1==3)
                {
                  face.carBooking();
                }
                
                else if (option1==4)
                {
                    cout<<endl<<"Logout Successfully !"<<endl;
                    break;
                }
                else{
                    cout<<endl<<"Invalid Input"<<endl;
                }
                }
                }
                else{
                    cout<<endl<<"User Not Found"<<endl;
                }
         
        }
        else{
            cout<<endl<<"Invalid Input";
        }
    }
    else if (option==2)
    {
        int option2;
        cout<<endl<<"1) Register as Partner"<<endl<<"2) Register as Customer"<<endl<<endl<<"Select Option: ";
        cin>>option2;
        if (option2==1)
        {
            face.addPartner();
        }
        else if (option2==2)
        {
            face.addCustomer();
        }  
    }
    else if (option==3)
    {
        break;
    }
    else{
        cout<<endl<<"Invalid Input";
    }  
}
}
