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
	cout<<"CPE BANK"<<endl;
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
		
		for(int j=0;j<46;j++){
			cout<<" ";
			
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

		/*string regis[4]={	" _____  _____  _____  _____  _____  _____  _____  _____ ",
							"| __  ||   __||   __||     ||   __||_   _||   __|| __  |",
							"|    -||   __||  |  ||-   -||__   |  | |  |   __||    -|",
							"|__|__||_____||_____||_____||_____|  |_|  |_____||__|__|"};*/
							cout<<endl;
	for(int i=0;i<4;i++){
		char a=219;
		if(w!=1){
								a=' ';
							}
							for(int j=0;j<42;j++){
			cout<<" ";
			
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
		//cout<<regis[i]<<endl;
		char e=92;
		if(i==0){
			printf("  ___   ___    ___   ___   ___   _____   ___   ___ \n");
		}
		if(i==1){
 		printf(" | _ %c | __|  / __| |_ _| / __| |_   _| | __| | _ %c\n",e,e);
 	}
 		if(i==2){
 		printf(" |   / | _|  | (_ |  | |  %c__ %c   | |   | _|  |   /\n",e,e);
 	}
 		if(i==3){
 		printf(" |_|_%c |___|  %c___| |___| |___/   |_|   |___| |_|_%c\n",e,e,e);
 	}
	}
}
void print_exit(int w){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

	/*string exit[4]={	" _____  __ __  _____  _____ ",                            
						"|   __||  |  ||     ||_   _|",                           
						"|   __||-   -||-   -|  | |  ",                            
						"|_____||__|__||_____|  |_|  ", };*/
	for(int i=0;i<4;i++){
		char a=219;
			for(int j=0;j<11;j++){
					cout<<" ";
				}
				for(int j=0;j<45;j++){
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
		}char e=92;
				if(i==0){
					printf("  ___  __  __  ___   _____ \n");
				}	
				if(i==1){
					printf(" | __| %c %c/ / |_ _| |_   _|\n",e,e);
				}	
				if(i==2){
					printf(" | _|   >  <   | |    | |  \n"); 
				}	
				if(i==3){
					printf(" |___| /_/%c_%c |___|   |_|  \n",e,e);
				}						
		//cout<<exit[i]<<endl;
	}
}

string create_otp(){//create otp
	string otp="";
	string set[36]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	int cur;
	for(int i=0;i<6;i++){
		cur=rand()%36;
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
	//text_size(16);
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
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			
			if(cursor==2){//Exit
				break;
			}
			
		}
		print_logo();
		print_login(cursor);
		cout<<endl<<endl;
		print_regis(cursor);
		cout<<endl<<endl;
		print_exit(cursor);
		
		
		
		
		//Sleep(Gamespeed);
		system("pause");
		system("cls");
		
		
		
		
	}
	
	
}
