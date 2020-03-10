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

string create_pin(){//create pin
	string pin="";
	string set[10]={"0","1","2","3","4","5","6","7","8","9"};
	int cur;
	for(int i=0;i<6;i++){
		cur=rand()%10;
		pin=pin+set[cur];
	}
	return pin;
}

void text_size(int s){//change text size func()
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = s;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

void login(){//Login func()
	
}

void regis(){//register func()
	
}


int main(){
	
	
	srand(time(0));
	int end=0;
	text_size(80);
	int cursor=0,coutpos=0;
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
		for(int i=0;i<3;i++){//print choice
			cout<<setw(10);
			if(cursor==i&&coutpos==1){
				cout<<"|->";
			}else if(cursor==i){
				cout<<"->";
			}else{
				cout<<"  ";
			}
			cout<<A[i]<<endl;
		}
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			if(coutpos==0){
				coutpos=1;
			}else{
				coutpos=0;
			}
			if(cursor==2){//Exit
				end=1;
			}
			
		}
		
		Sleep(Gamespeed);
		system("cls");
		
		
		
		
	}
	
	
}
