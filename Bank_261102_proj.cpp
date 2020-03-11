#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int Gamespeed = 100;

struct People{
	string name;
	string id;
	string password;
	long double money;
};

void print_logo(){
	cout<<"BANK KKK"<<endl;
}


void print_login(int w){
	string login[7]={  	" ___      _______  _______  ___   __    _ ",                             
						"|   |    |       ||       ||   | |  |  | |"   ,                        
						"|   |    |   _   ||    ___||   | |   |_| |"  ,                          
						"|   |    |  | |  ||   | __ |   | |       |"  ,                          
						"|   |___ |  |_|  ||   ||  ||   | |  _    |"  ,                         
						"|       ||       ||   |_| ||   | | | |   |"  ,                          
						"|_______||_______||_______||___| |_|  |__|"  };
					 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
	for(int i=0;i<7;i++){
		char a=219;
		if(w!=0){
			a=' ';
		}
		if(i==1||i==6){
			for(int j=0;j<7;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
			for(int j=0;j<3;j++){
				cout<<" ";
			}
		}else if(i==3||i==4){
			for(int j=0;j<9;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
			cout<<" ";
		}else if(i==2||i==5){
			for(int j=0;j<8;j++){
				cout<<" ";
			}
				for(int j=0;j<2;j++){
				cout<<a;
			}
			for(int j=0;j<2;j++){
				cout<<" ";
			}
		}else{
			for(int j=0;j<12;j++){
				cout<<" ";
			}
				
		}
		
		
		
		cout<<login[i]<<endl;
	}
		
}
void print_regis(int w){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

		string regis[4]={	" _____  _____  _____  _____  _____  _____  _____  _____ ",
							"| __  ||   __||   __||     ||   __||_   _||   __|| __  |",
							"|    -||   __||  |  ||-   -||__   |  | |  |   __||    -|",
							"|__|__||_____||_____||_____||_____|  |_|  |_____||__|__|"};
							cout<<endl;
	for(int i=0;i<4;i++){
		char a=219;
		if(w!=1){
								a=' ';
							}
		if(i==1||i==3){
				for(int j=0;j<6;j++){
					cout<<" ";
				}
			for(int j=0;j<2;j++){
				cout<<a;
			}cout<<" ";
		
		}else if(i==2){
			
				for(int j=0;j<7;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
		
		
		}else{
			for(int j=0;j<9;j++){
				cout<<" ";
			}
		}
		cout<<regis[i]<<endl;
	}
}
void print_exit(int w){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

	string exit[4]={	" _____  __ __  _____  _____ ",                            
						"|   __||  |  ||     ||_   _|",                           
						"|   __||-   -||-   -|  | |  ",                            
						"|_____||__|__||_____|  |_|  ", };
	for(int i=0;i<4;i++){
		char a=219;
			for(int j=0;j<11;j++){
					cout<<" ";
				}
		if(w!=2){
				a=' ';
							}
		if(i==1||i==3){
				for(int j=0;j<6;j++){
					cout<<" ";
				}
			for(int j=0;j<2;j++){
				cout<<a;
			}cout<<" ";
		
		}else if(i==2){
			
				for(int j=0;j<7;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
		
		
		}else{
			for(int j=0;j<9;j++){
				cout<<" ";
			}
		}
							
							
							
		cout<<exit[i]<<endl;
	}
}

string create_otp(){//create otp
	string otp="";
	string set[10]={"0","1","2","3","4","5","6","7","8","9"};
	int cur;
	for(int i=0;i<6;i++){
		cur=rand()%10;
		otp=otp+set[cur];
	}
	return otp;
}

void text_size(int s){//change text size func()
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;

std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

void login(){//Login page func()
	
}

void regis(){//register page func()
	
}

void password(){//Enter password page func()
	
}

int main(){
	
	
	srand(time(0));
	int end=0;
	text_size(16);
	int cursor=0;
	string A[3]={"LOGIN","REGISTER","EXIT"};
	//Main Menu
	while(end!=1){
		
		
		if(GetAsyncKeyState(VK_UP) != 0){//Up State
			if(cursor>0&&cursor<3){
				cursor--;
			}
		}
		if(GetAsyncKeyState(VK_DOWN) != 0){//Down State
			if(cursor>=0&&cursor<2){
				cursor++;
			}
		}
		print_logo();
	/*	for(int i=0;i<3;i++){//print choice
			cout<<setw(10);
			if(cursor==i&&coutpos==1){
				cout<<"|->";
			}else if(cursor==i){
				cout<<"->";
			}else{
				cout<<"  ";
			}
			cout<<A[i]<<endl;
		}*/
		
		
		print_login(cursor);
		print_regis(cursor);
		print_exit(cursor);
		
		
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			
			if(cursor==2){//Exit
				end=1;
			}
			
		}
		
		Sleep(Gamespeed);
		system("cls");
		
		
		
		
	}
	
	
}
