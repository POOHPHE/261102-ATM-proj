#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
int Gamespeed = 100;
struct People{
	string name;
	string id;
	long double money;
};
void print_logo(){
	cout<<"BANK KKK"<<endl;
}
void text_size(int s){
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

void login(){
	
}

void regis(){
	
}


int main(){
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
