#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
int main(){
	
	/*if(GetAsyncKeyState(VK_UP) != 0){
			if(cursor>0&&cursor<3){
				cursor--;
			}
		}*/
	string s="";
	while(true){
		
		if(GetAsyncKeyState(0x41) != 0){
			s=s+"A";
		}
		if(GetAsyncKeyState(0x42) != 0){
			s=s+"B";
		}
		if(GetAsyncKeyState(0x43) != 0){
			s=s+"C";
		}
		if(GetAsyncKeyState(0x44) != 0){
			s=s+"D";
		}
		if(GetAsyncKeyState(0x45) != 0){
			s=s+"E";
		}
		if(GetAsyncKeyState(0x46) != 0){
			s=s+"F";
		}
		if(GetAsyncKeyState(0x47) != 0){
			s=s+"G";
		}
		if(GetAsyncKeyState(0x48) != 0){
			s=s+"H";
		}
		if(GetAsyncKeyState(0x49) != 0){
			s=s+"I";
		}
		if(GetAsyncKeyState(0x4A) != 0){
			s=s+"J";
		}
		if(GetAsyncKeyState(0x4B) != 0){
			s=s+"K";
		}
		if(GetAsyncKeyState(0x4C) != 0){
			s=s+"L";
		}
		if(GetAsyncKeyState(0x4D) != 0){
			s=s+"M";
		}
		if(GetAsyncKeyState(0x4E) != 0){
			s=s+"N";
		}
		if(GetAsyncKeyState(0x4F) != 0){
			s=s+"O";
		}
		if(GetAsyncKeyState(0x50) != 0){
			s=s+"P";
		}
		if(GetAsyncKeyState(0x51) != 0){
			s=s+"Q";
		}
		if(GetAsyncKeyState(0x52) != 0){
			s=s+"R";
		}
		if(GetAsyncKeyState(0x53) != 0){
			s=s+"S";
		}
		if(GetAsyncKeyState(0x54) != 0){
			s=s+"T";
		}
		if(GetAsyncKeyState(0x55) != 0){
			s=s+"U";
		}
		if(GetAsyncKeyState(0x56) != 0){
			s=s+"V";
		}if(GetAsyncKeyState(0x57) != 0){
			s=s+"W";
		}if(GetAsyncKeyState(0x58) != 0){
			s=s+"X";
		}if(GetAsyncKeyState(0x59) != 0){
			s=s+"Y";
		}if(GetAsyncKeyState(0x5A) != 0){
			s=s+"Z";
		}
		if(GetAsyncKeyState(VK_BACK) != 0){
			s=s.substr(0,s.size()-1);
		}
		cout<<s;
		Sleep(100);
		system("cls");
	}
	
}

