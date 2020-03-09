#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
 main(){
	string A[3]={"text1","text2","text3"};
	int cursor=0;
	int coutpos=0;
	while(true){
		if(GetAsyncKeyState(VK_UP) != 0){
			if(cursor>0&&cursor<3){
				cursor--;
			}
		}
		if(GetAsyncKeyState(VK_DOWN) != 0){
			if(cursor>=0&&cursor<2){
				cursor++;
			}
		}
		if(GetAsyncKeyState(VK_RETURN) != 0){
			if(coutpos==0){
				coutpos=1;
			}else{
				coutpos=0;
			}
			
			
		}
		for(int i=0;i<3;i++){
			if(cursor==i&&coutpos==1){
				cout<<"|->";
			}else if(cursor==i){
				cout<<"->";
			}else{
				cout<<"  ";
			}
			cout<<A[i]<<endl;
		}
		system("cls");
		
	}
}
