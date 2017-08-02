#include <iostream>
#include<string>
#include<list>
using namespace std;
class save_account
{
public:
	float interest_rate;
	int yearnum;
	float evaluate(float money)
	{
		cout<<"Enter number of year"<<endl;
		cin>>yearnum;
		interest_rate=yearnum*(money*(1/10));
		return interest_rate;
	}
};
class current_account
{
	public:
	//const float interest_rate=0;
};
class Account:public save_account,public current_account
{
public:
	string account_num;
	string state_of_account;
	bool tybe;

};
class Person
{
public:
	string Name, Address, Phone;
	//virtual void Display() = 0;
};
class Client:public Person
{
public:
	int client_id;
	string Username, Password;
	Account account;
	float balance;
	friend int client_menu();
	void deposit()
	{
		float x;
		cout << "enter the deposit :";
		cin >> x;
		balance += x;
		cout << "Done" << endl;
	}
	void withdraw()
	{
		float x;
		cout << "your balance is " << balance << endl;
		cout << "enter money :";
		cin >> x;
		if (x > balance)
			cout << "erorr" << endl;
		else
		{
			balance -= x;
			cout << "Done" << endl;
		}
	}
	void update()
	{
		cout << "Enter {1} for Update Clinet Name" << endl;
		cout << "Enter {2} for Update User Name" << endl;
		cout << "Enter {3} for Update Clinet Password" << endl;
		cout << "Enter {4} for Update Account Number" << endl;
		cout << "Enter {5} for Update Address" << endl;
		cout << "Enter {6} for Update Phone" << endl;
		cout << "Enter {7} for Update State of Account" << endl;
		cout<<"Else To Return"<<endl;
		int x;
		cin>>x;
		switch (x)
		{
		case 1:
		{
				  cout << "Enter the New Name : ";
				  cin >>Name;
				  break;
		}
		case 2:
		{
				  cout << "Enter the New Username : ";
				  cin >>Username;
				  break;
		}
		case 3:
		{
				  cout << "Enter the New Password : ";
				  cin >>Password;
				  break;
		}
		case 5:
		{
				  cout << "Enter the New Address : ";
				  cin >>Address;
				  break;
		}
		case 6:
		{
				  cout << "Enter the New Phone : ";
				  cin >>Phone;
				  break;
		}
		{
				  cout << "Enter the State of Account (Active or Close) : ";
				  cin >>account.state_of_account;
				  break;
		}
		default:
			break;
		}
	  
	}
	void display_details()
	{
		cout<<"Name is :"<<Name<<endl;
		cout<<"Your Id is : "<<this->client_id<<endl;
		cout<<"Address is :"<<Address<<endl;
		cout<<"Phone is :"<<Phone<<endl;
		cout<<"Account Number is :"<<account.account_num<<endl;
		cout<<"Your Balance is :"<<balance<<endl;
	}
};
class Employee:public Person
{
public:
	int employee_id;
	string position, college, year_of_graduation, total_grade;
	friend istream& operator >>(istream &is, Employee &obj);
	void add_account(list<Client>& myclint)
	{
		Client obj;
		cout<<"Enter Your Name : ";
		cin>>obj.Name;
	    cout<<"Enter Your Address: ";
		cin>>obj.Address;
		cout<<"Enter Your Phone Number : ";
		cin>>obj.Phone;
		cout<<"Enter Your Account Number : "<<endl;
		cin>>obj.account.account_num;
	    cout<<"Enter Type of The account (1 for saveing/else for currunt) : ";
		char c;
		cin>>c;
		if(c=='1')
			obj.account.tybe=true;
		else
			obj.account.tybe=false;
	    cout<<"Enter Type of The account (Active/Close) : ";
		cin>>obj.account.state_of_account;
		cout<<"Enter Your Initial Balance : ";
		cin>>obj.balance;
		cout<<"Enter Your User Name : ";
		cin>>obj.Username;
		cout<<"Enter Your Password : ";
		cin>>obj.Password;
		obj.client_id=myclint.size();
		myclint.push_back(obj);
	    cout<<"Account Created.."<<endl;
	}
	void close_account(list<Client>& myclint)
	{
		string x;
		bool flag=true;
		cout<<"Enter account Number : ";
		cin>>x;
		list<Client>::iterator it;
		it=myclint.begin();
		while(it!=myclint.end())
		{
			if(it->account.account_num==x)
			{
				it->account.state_of_account="Close";
				flag=false;
				break;
			}
			it++;
		}
		if(flag)
			cout<<"Sorry No Account "<<endl;
		else
			cout<<"Done"<<endl;
	}
	void menu(list<Client>& myclint)
	{
		int x;
		cout<<"Enter (1) To Add An Account"<<endl;
		cout<<"Enter (2) To Close An Account"<<endl;
		cout<<"Else To Return"<<endl;
		cin>>x;
		switch (x)
		{
		case 1:
			{
				add_account(myclint);
				break;
			}
		case 2:
			{
				close_account(myclint);
			}
		default:
			break;
		}
	}
};
class bank_manger
{
public:
	list<Employee>employee_list;
	void Add_emp()
	{
		Employee obj;
		cout<<"Enter Name of New Employee : ";
		cin>>obj.Name;
		cout<<"Enter Address of New Employee : ";
		cin>>obj.Address;
		cout<<"Enter Phone of New Employee : ";
		cin>>obj.Phone;
		cout<<"Enter position of New Employee : ";
		cin>>obj.position;
		cout<<"Enter The College From Which He Graduated : ";
		cin>>obj.college;
		cout<<"Enter His Year Of Graduation : ";
		cin>>obj.year_of_graduation;
		cout<<"Enter His Total Grade : ";
		cin>>obj.total_grade;
		obj.employee_id=employee_list.size();
		employee_list.push_back(obj);
		cout<<endl<<endl<<"Succesfly Adding"<<endl;
	}
	void delete_emp()
	{
		cout<<"What Employee Id  You Want TO Delete : "<<endl; 
		int x;
		cin>>x;
		if(x>employee_list.size()-1)
			cout<<"Sorry No Employee With That Id"<<endl;
		else
		{
			list<Employee>::iterator it=employee_list.begin();
			while (it!=employee_list.end())
			{
				if(it->employee_id==x)
				{
					employee_list.erase(it,it);
					break;
				}
				it++;
			}
		}
	}
	void menu()
	{
		int x;
		cout<<"Enter {1} For Add New Employee"<<endl;
		cout<<"Enter {2} For Delete Current Employee"<<endl;
		cout<<"Else TO Return"<<endl;
		cin>>x;
		switch (x)
		{
		case 1:
			{
				Add_emp();
				break;
			}
		case 2:
			{
				delete_emp();
				break;
			}
		default:
			break;
		}
	}
};
class Bank
{
	string Bank_Name;
	bank_manger manger;
public:
	list<Client>clint_list;
	list<Employee>employee_list;
	void start()
	{
		bool flag=true;
		int x;
		while (flag)
		{
		cout<<"Enter 1 For Client "<<endl;
		cout<<"Enter 2 For Employee "<<endl;
		cout<<"Enter 3 For Manger "<<endl;
		cout<<"Else To Exit"<<endl;
		cin>>x;
		switch (x)
		{
		case 1:
			{
				list<Client>::iterator it=clint_list.begin();
		string N, P;
		bool find=false;
		cout << "Enter your Username :";
		cin >> N;
		cout << "Enter your Password :";
		cin >> P;
		while (it!=clint_list.end())
		{
			if(N==it->Username&&P==it->Password)
			{
				find=true;
				break;
			}
			it++;
		}
		if (!find)
		{
			cout << "Wrong Username or Password" << endl;
			return;
		} 	
		else
		{
			it->balance+=it->account.evaluate(it->balance);
			cout<<it->balance<<endl<<endl;
			int x=client_menu();
			switch (x)
			{
			case 1:{it->deposit();break;}
			case 2:{it->withdraw();break;}
			case 3:{it->display_details();break;}
			case 4:{it->update();break;}
			default:
				break;
			}
		}
		break;
			}
		case 2:
			{
				Employee obj;
				obj.menu(clint_list);
				break;
			}
		case 3:
			{
				manger.menu();
				break;
			}
		default:
			{
				flag=false;
			break;
			}
		}
		}
	}
};
int client_menu()
{
	
		cout << "Enter {1} for Deposit" << endl;
		cout << "Enter {2} for withdraw" << endl;
		cout << "Enter {3} for Display details" << endl;
		cout << "Enter {5} for Update Your Information" << endl;
		int x;
		cin>>x;
		return x;
}
int main()
{
	Bank my_bank;
	my_bank.start();
	return 0;
}