#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

int Gamespeed = 100;
int cursor=0;
int end=0;
string page="main";
struct People{
	string id;
	string name;
	string pin;
	long double money;
};
vector<People> all_customers; 
set<string> find_id;

void print_number(string s){
	string num[10][5]={{"   ___  ","  / _ \\ "," | | | |"," | |_| |","  \\___/ "},{"  _ "," / |"," | |"," | |"," |_|"	},	{"  ____  "," |___ \\ ","   __) |","  / __/ "," |_____|"	},
	{"  _____ "," |___ / ","   |_ \\ ","  ___) |"," |____/ "	},
	{"  _  _   "," | || |  "," | || |_ "," |__   _|","    |_|  "	},
	{"  ____  "," | ___| "," |___ \\ ","  ___) |"," |____/ "	},
	{"   __   ","  / /_  "," | '_ \\ "," | (_) |","  \\___/ "	},
	{"  _____ "," |___  |","    / / ","   / /  ","  /_/   "	},
	{"   ___  ","  ( _ ) ","  / _ \\ "," | (_) |","  \\___/ "	},
	{"   ___  ","  / _ \\ "," | (_) |","  \\__, |","    /_/ "	}};

	for(int i=0;i<5;i++){
		cout<<"                                                       ";
		for(int j=0;j<s.size();j++){
			int k=s[j]-48;
			cout<<num[k][i];
			
		}
		cout<<endl;
	}
}


void print_logo(){
	char e=92;
/*	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	cout<<endl;*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	for(int i=0;i<10;i++){
		cout<<"\n";
	}
	for(int i=0;i<54;i++){
		cout<<" ";
	}
	printf(" _______  _______  _______      ______   _______  _        _ \n");      
	for(int i=0;i<54;i++){
		cout<<" ";
	}
	printf("(  ____ %c(  ____ )(  ____ %c    (  ___ %c (  ___  )( (    /|| %c    /%c\n",e,e,e,e,e);
	for(int i=0;i<54;i++){
		cout<<" ";
	}
	printf("| (    %c/| (    )|| (    %c/    | (   ) )| (   ) ||  %c  ( ||  %c  / /\n",e,e,e,e);
	for(int i=0;i<54;i++){
		cout<<" ";
	}
	printf("| |      | (____)|| (__        | (__/ / | (___) ||   %c | ||  (_/ / \n",e);
	for(int i=0;i<54;i++){
		cout<<" ";
	}
 	printf("| |      |  _____)|  __)       |  __ (  |  ___  || (%c %c) ||   _ (  \n",e,e);
 	for(int i=0;i<54;i++){
		cout<<" ";
	}
    printf("| |      | (      | (          | (  %c %c | (   ) || | %c   ||  ( %c %c \n",e,e,e,e,e);
    	for(int i=0;i<54;i++){
		cout<<" ";
	}	printf("| (____/%c| )      | (____/%c    | )___) )| )   ( || )  %c  ||  /  %c %c\n",e,e,e,e,e);
	for(int i=0;i<54;i++){
		cout<<" ";
	}printf("(_______/|/       (_______/    |/ %c___/ |/     %c||/    )_)|_/    %c/\n",e,e,e);
    
	cout<<endl;cout<<endl;
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
	for(int i=0;i<3;i++){
		cout<<"\n";
	}
	for(int i=0;i<7;i++){
		cout<<"        ";
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
			for(int j=0;j<5;j++){
				cout<<" ";
			}
		}else if(i==3||i==4){
			for(int j=0;j<9;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
			cout<<"   ";
		}else if(i==2||i==5){
			for(int j=0;j<8;j++){
				cout<<" ";
			}
				for(int j=0;j<2;j++){
				cout<<a;
			}
			for(int j=0;j<4;j++){
				cout<<" ";
			}
		}else{
			for(int j=0;j<14;j++){
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
		char a=219;cout<<"          ";
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
			}cout<<"   ";
		
		}else if(i==2){
			
				for(int j=0;j<7;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
		
		cout<<"  ";
		}else{
			for(int j=0;j<9;j++){
				cout<<" ";
			}cout<<"  ";
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);

	/*string exit[4]={	" _____  __ __  _____  _____ ",                            
						"|   __||  |  ||     ||_   _|",                           
						"|   __||-   -||-   -|  | |  ",                            
						"|_____||__|__||_____|  |_|  ", };*/
	cout<<endl;
	for(int i=0;i<4;i++){
		cout<<"       ";
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
			}cout<<"   ";
		
		}else if(i==2){
			
				for(int j=0;j<7;j++){
				cout<<" ";
			}
			for(int j=0;j<2;j++){
				cout<<a;
			}
		cout<<"  ";
		
		}else{
			for(int j=0;j<11;j++){
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
cfi.dwFontSize.X =0;                   // Width of each character in the font
cfi.dwFontSize.Y = s;
wcscpy(cfi.FaceName, L"Terminal"); // Choose your font

SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cfi);

}
void find_id_all(string no){
	
	if(find_id.count(no)!=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("\n\n\t\t\t\t\t.___.__..  ..  ..__ \n");
		printf("\t\t\t\t\t [__ |  ||  ||\\ ||  \\\n");
		printf("\t\t\t\t\t |   |__||__|| \\||__/\n");
	}else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		
		printf("\n\n\t\t\t\t\t     __ .__..  ..  ..__..___.  .___.__..  ..  ..__   .__. __  __ .__..  ..  ..___.  .  .      \n");
		printf("\t\t\t\t\t    /  `[__]|\\ ||\\ ||  |  |    [__ |  ||  ||\\ ||  \\  [__]/  `/  `|  ||  ||\\ |  |    |\\ | _    \n");
		printf("\t\t\t\t\t    \\__.|  || \\|| \\||__|  |    |   |__||__|| \\||__/  |  |\\__.\\__.|__||__|| \\|  |    | \\|(_) * \n");
		
	}
}
void login(){//Login page func()
string acc_no="";	
	while(true){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n                                                    _    ____ ____ ___  _   _ _   _ _____   _   _ _   _ __  __ ____  _____ ____      \n"); 
	printf("                                                   / \\  / ___/ ___/ _ \\| | | | \\ | |_   _| | \\ | | | | |  \\/  | __ )| ____|  _ \\      \n");
	printf("                                                  / _ \\| |  | |  | | | | | | |  \\| | | |   |  \\| | | | | |\\/| |  _ \\|  _| | |_) |     \n");
	printf("                                                 / ___ \\ |__| |__| |_| | |_| | |\\  | | |   | |\\  | |_| | |  | | |_) | |___|  _ <      \n");
	printf("                                                /_/   \\_\\____\\____\\___/ \\___/|_| \\_| |_|   |_| \\_|\\___/|_|  |_|____/|_____|_| \\_\\      \n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	
		if(acc_no.size()<9){
			if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			acc_no=acc_no+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			acc_no=acc_no+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			acc_no=acc_no+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			acc_no=acc_no+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			acc_no=acc_no+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			acc_no=acc_no+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			acc_no=acc_no+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			acc_no=acc_no+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			acc_no=acc_no+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
			acc_no=acc_no+"9";
		}
		}
		
		if(GetAsyncKeyState(VK_BACK) != 0&&acc_no.size()>0){
			acc_no=acc_no.substr(0,acc_no.size()-1);
		}
		cout<<endl;
		print_number(acc_no);
		if(GetAsyncKeyState(VK_RETURN) != 0){
			find_id_all(acc_no);
		}else{
			cout<<"\n\n";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__]/  `|_/ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  [__)|  |\\__.|  \\\n");
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="main";
			break;
		}
			
}
}

void regis(){//register page func()
	
}

void password(){//Enter password page func()
	
}
void main_menu(){
	while(true){
		
	
	if(GetAsyncKeyState(VK_UP) != 0){//Up State
			if(cursor>0&&cursor<3){
				cursor--;
			}
		}else
		if(GetAsyncKeyState(VK_DOWN) != 0){//Down State
			if(cursor>=0&&cursor<2){
				cursor++;
			}
		}else
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			if(cursor==0){//Login
			 ::page="login";
			 break;
			}
			if(cursor==2){//Exit
			::end=1;
				break;
			}
			
		}
		print_logo();
		print_login(cursor);
		cout<<endl<<endl;
		print_regis(cursor);
		cout<<endl<<endl;
		print_exit(cursor);
		
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		
		system("cls");
		}
}
int main(){srand(time(0));
	ifstream in("test_data.txt");
	string textline;
	
	
	
	text_size(16);
	
	string A[3]={"LOGIN","REGISTER","EXIT"};
	//Main Menu
	while(getline(in,textline)){
		
		string a,b,c;
		a=textline.substr(0,9);
		int find=textline.find_first_of(",",10);
		b=textline.substr(10,find-10);
		c=textline.substr(find+1,6);
		string mon=textline.substr(find+8,textline.size()-(find+7));
		long double mone=strtold(mon.c_str(),NULL);
		People input={a,b,c,mone};
		all_customers.push_back(input);
		find_id.insert(a);
	}in.close();
	
	while(::end!=1){
		if(page=="main"){
			main_menu();
		}else if(page=="login"){
			login();
		}
		
		
		//Sleep(Gamespeed);
		
		
		system("cls");
		
		
		
	}
	
	ofstream out("test_data.txt");
	for(int i=0;i<all_customers.size();i++){
		out<<all_customers[i].id<<","<<all_customers[i].name<<","<<all_customers[i].pin<<","<<all_customers[i].money<<endl;
	}
	out.close();
	
}
