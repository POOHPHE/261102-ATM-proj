#include<bits/stdc++.h>
#include<windows.h>

using namespace std;


int cursor=0;
int end=0;
string page="main";
struct People{
	string id;
	string name;
	string pin;
	long double money;
};
string file_name="bank_data.txt";
vector<People> all_customers;  
set<string> find_id;
set<string>::iterator del_id;
int num,num_transfer,state;
long double pin_mon;
void update_data(){
	ofstream out(file_name);
	for(int i=0;i<all_customers.size();i++){
		out<<all_customers[i].id<<","<<all_customers[i].name<<","<<all_customers[i].pin<<","<<all_customers[i].money<<endl;
	}
	out.close();
}
void history(string acc,string add)
{	
	string textline;
	ifstream his(acc+".txt");
	vector<string> n;
	while(getline(his,textline))
	{
		n.push_back(textline);
	}his.close();
	ofstream hist(acc+".txt");
	for(int i=0;i<n.size();i++){
		hist<<n[i]<<endl;
	}
	hist<<add<<endl;
	hist.close();
	
}
void update_mon_data(){
	for(int i=0;i<all_customers.size();i++){
		history(all_customers[i].id,"+"+to_string(all_customers[i].money*0.014)+" From Interest [Money]--->"+to_string(all_customers[i].money*1.014));
		all_customers[i].money=all_customers[i].money*1.014;
		
	}
}
void find_id_all(string,string);
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

void print_money(string s,string space){
	string text[11][4]={	{"  __  ",  " /  \\ ",  "| () |",  " \\__/ "},//0
	{" _ ", 	"/ |", 	"| |", 	"|_|"	},//1
	{" ___ ", "|_  )", " / / ", "/___|"	},//2
	{" ____", "|__ /", " |_ \\", "|___/"	},//3
	{" _ _  "   , "| | | " , "|_  _|", "  |_| " 	},//4
	{" ___ ", "| __|", "|__ \\", "|___/"	},//5
	{"  __ "  , " / / ", "/ _ \\", "\\___/"	},//6
	{ " ____ " , "|__  |", "  / / ", " /_/  " 	},//7
	{" ___ ", "( _ )", "/ _ \\", "\\___/"	},//8
	{ " ___ " , "/ _ \\", "\\_, /", " /_/ "	},//9
	{"   "	,  "   " ,  " _ ",  "(_)"}//.
	};

	for(int i=0;i<4;i++){
 			cout<<space<<" ";
 			for(int j=0;j<s.size();j++){
 				int index=s[j]-48;
 				if(s[j]=='.'){
 					index=10;
				 }
 				cout<<text[index][i];
			 }cout<<endl;
		 }
}
void print_text_small(string s,string space){
	for(int i=0;i<s.size();i++){
		s[i]=toupper(s[i]);
	}  

	string text_char[38][3]={
							{" __ ","/  \\","\\__/"},//0
							{"   "," /|","  |"},	//1
							{" __ ","  _)"," /__"},//2
							{" __ ","  _)"," __)"},//3
							{"     "," |__|","    |"},//4
							{" __ "," |_ "," __)"},//5
							{" __ ","/__ ","\\__)"	},//6
							{" ___","   /","  / "},//7
							{" __ ","(__)","(__)"},//8
							{" __ ","(__\\"," __/"},//9
							{"    "," /\\ ","/--\\"},//a
 							{" __ ","|__)","|__)"},//b
 							{" __","/  ","\\__"},//c
 							{" __ ","|  \\","|__/"},//d
 							{" __","|_ ","|__"},//e
 							{" __","|_ ","|  "},//f
 							{" __ ","/ _ ","\\__)"},//g
 							{"    ","|__|","|  |"},//h
 							{"  ","| ","| "},//i
 							{"   ","  |","__)"},//j
 							{"   ","|_/","| \\"},//k
 							{"   ","|  ","|__"},//l
 							{"    ","|\\/|","|  |"},//m
 							{"    ","|\\ |","| \\|"},//n
 							{" __ ","/  \\","\\__/"},//o
 							{" __ ","|__)","|   "},//p
 							{" __ ","/  \\","\\_\\/"},//q
 							{" __ ","|__)","| \\ "},//r
 							{" __ ","(_  ","__) "},//s
 							{"___"," | "," | "},//t
 							{"    ","/  \\","\\__/"},//u
 							{"    ","\\  /"," \\/ "},//v
 							{"    ","|  |","|/\\|"},//w    
 							{"   ","\\_/","/ \\"},//x    
 							{"   ","\\_/"," | "},//y     
 							{"___"," _/","/__"},//z 
 							{" ", " "  ,  "."},//. 
 							{"  ",	"  ","  "}//space
 							};
 		for(int i=0;i<3;i++){
 			cout<<space;
 			for(int j=0;j<s.size();j++){
 				int index=s[j]-55;
 				if(s[j]>=48&&s[j]<=57){
 					index=s[j]-48;
				 }
				 if(s[j]=='.'){
				 	index=36;
				 }
				 if(s[j]==' '){
				 	index=37;
				 }
 				cout<<text_char[index][i]<<" ";
			 }cout<<endl;
		 }
}
void print_text(string s,string space){
	for(int i=0;i<s.size();i++){
		s[i]=toupper(s[i]);
	}
	string text_char[38][5]={
							{"   ___  ","  / _ \\ "," | |_| |"," | |_| |","  \\___/ "},//0
							{"  _ "," / |"," | |"," | |"," |_|"	},	//1
							{"  ____  "," |___ \\ ","   __) |","  / __/ "," |_____|"	},//2
							{"  _____ "," |___ / ","   |_ \\ ","  ___) |"," |____/ "	},//3
							{"  _  _   "," | || |  "," | || |_ "," |__   _|","    |_|  "	},//4
							{"  ____  "," | ___| "," |___ \\ ","  ___) |"," |____/ "	},//5
							{"   __   ","  / /_  "," | '_ \\ "," | (_) |","  \\___/ "	},//6
							{"  _____ "," |___  |","    / / ","   / /  ","  /_/   "	},//7
							{"   ___  ","  ( _ ) ","  / _ \\ "," | (_) |","  \\___/ "	},//8
							{"   ___  ","  / _ \\ "," | (_) |","  \\__, |","    /_/ "	},//9
							{"    _    " ,"   / \\   " ,"  / _ \\  " ," / ___ \\ ", "/_/   \\_\\"},//a
 							{ " ____  " ,"| __ ) " ,"|  _ \\ " ,"| |_) |", "|____/ "},//b
 							{ "  ____ ", " / ___|" ,"| |    " ,"| |___ " ," \\____|"},//c
 							{" ____  " ,"|  _ \\ " ,"| | | |" ,"| |_| |" ,"|____/ " },//d
 							{ " _____ " , "| ____|", "|  _|  ", "| |___ ", "|_____|"},//e
 							{ " _____ ", "|  ___|", "| |_   ", "|  _|  ", "|_|    "},//f
 							{ "  ____ ", " / ___|", "| |  _ ", "| |_| |", " \\____|" },//g
 							{" _   _ ", "| | | |", "| |_| |", "|  _  |", "|_| |_|"},//h
 							{" ___ ", "|_ _|", " | | ", " | | ", "|___|"},//i
 							{"     _ ", "    | |", " _  | |", "| |_| |", " \\___/ "},//j
 							{" _  __", "| |/ /", "| ' / ", "| . \\ ", "|_|\\_\\"},//k
 							{" _     ", "| |    ", "| |    ", "| |___ ", "|_____|"},//l
 							{" __  __ ", "|  \\/  |", "| |\\/| |", "| |  | |", "|_|  |_|"},//m
 							{" _   _ ", "| \\ | |", "|  \\| |", "| |\\  |", "|_| \\_|"},//n
 							{"  ___  ", " / _ \\ ", "| | | |", "| |_| |", " \\___/ "},//o
 							{" ____  ", "|  _ \\ ", "| |_) |", "|  __/ ", "|_|    "},//p
 							{"  ___  ", " / _ \\ ", "| | | |", "| |_| |", " \\__\\_\\"},//q
 							{" ____  ", "|  _ \\ ", "| |_) |", "|  _ < ", "|_| \\_\\"},//r
 							{" ____  ", "/ ___| ", "\\___ \\ ", " ___) |", "|____/ "},//s
 							{" _____ ", "|_   _|", "  | |  ", "  | |  ", "  |_|  "},//t
 							{" _   _ ", "| | | |", "| | | |", "| |_| |", " \\___/ "},//u
 							{"__     __", "\\ \\   / /", " \\ \\ / / ", "  \\ V /  ", "   \\_/   "},//v
 							{"__        __", "\\ \\      / /", " \\ \\ /\\ / / ", "  \\ V  V /  ", "   \\_/\\_/   "},//w
 							{"__  __", "\\ \\/ /", " \\  / ", " /  \\ ", "/_/\\_\\"},//x
 							{"__   __", "\\ \\ / /", " \\ V / ", "  | |  ", "  |_|  "},//y
 							{" _____", "|__  /", "  / / ", " / /_ ", "/____|"},//z
 							{			"   ", "   "  ,  "   ", " _ " ,"(_)"				 },//. 
 							{"   ",	"   ","   ","   ","   "	 }//space
 							};
 		for(int i=0;i<5;i++){
 			cout<<space;
 			for(int j=0;j<s.size();j++){
 				int index=s[j]-55;
 				if(s[j]>=48&&s[j]<=57){
 					index=s[j]-48;
				 }
				 if(s[j]=='.'){
				 	index=36;
				 }
				 if(s[j]==' '){
				 	index=37;
				 }
 				cout<<text_char[index][i]<<" ";
			 }cout<<endl;
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
	for(int i=0;i<47;i++){
		cout<<" ";
	}
	printf(" _______  _______  _______      ______   _______  _        _ \n");      
	for(int i=0;i<47;i++){
		cout<<" ";
	}
	printf("(  ____ %c(  ____ )(  ____ %c    (  ___ %c (  ___  )( (    /|| %c    /%c\n",e,e,e,e,e);
	for(int i=0;i<47;i++){
		cout<<" ";
	}
	printf("| (    %c/| (    )|| (    %c/    | (   ) )| (   ) ||  %c  ( ||  %c  / /\n",e,e,e,e);
	for(int i=0;i<47;i++){
		cout<<" ";
	}
	printf("| |      | (____)|| (__        | (__/ / | (___) ||   %c | ||  (_/ / \n",e);
	for(int i=0;i<47;i++){
		cout<<" ";
	}
 	printf("| |      |  _____)|  __)       |  __ (  |  ___  || (%c %c) ||   _ (  \n",e,e);
 	for(int i=0;i<47;i++){
		cout<<" ";
	}
    printf("| |      | (      | (          | (  %c %c | (   ) || | %c   ||  ( %c %c \n",e,e,e,e,e);
    	for(int i=0;i<47;i++){
		cout<<" ";
	}	printf("| (____/%c| )      | (____/%c    | )___) )| )   ( || )  %c  ||  /  %c %c\n",e,e,e,e,e);
	for(int i=0;i<47;i++){
		cout<<" ";
	}printf("(_______/|/       (_______/    |/ %c___/ |/     %c||/    )_)|_/    %c/\n",e,e,e);
    
	cout<<endl;cout<<endl;
}

void wrong_pass(){
	cout<<"\t\t\t\t\t\t          .  ..__ .__..  ..__   .__ .__. __. __..  ..__..__ .__ "<<endl;
	cout<<"\t\t\t\t\t\t          |  |[__)|  ||\\ |[ __  [__)[__](__ (__ |  ||  |[__)|  \\"<<endl;
	cout<<"\t\t\t\t\t\t          |/\\||  \\|__|| \\|[_./  |   |  |.__).__)|/\\||__||  \\|__/"<<endl;
}

void otp_page(){
	string otp=create_otp();
	string s="";
	int wrong=0;
	while(true){
		
		system("cls");
		cout<<"\n\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		//print_text("OTP","\t\t\t\t\t\t\t\t      ");
		cout<<"\t\t\t\t\t               ####### ####### ######      #####  ####### ######  ####### "<<endl;
 		cout<<"\t\t\t\t\t               #     #    #    #     #    #     # #     # #     # #       "<<endl;
 		cout<<"\t\t\t\t\t               #     #    #    #     #    #       #     # #     # #       "<<endl;
 		cout<<"\t\t\t\t\t               #     #    #    ######     #       #     # #     # #####   "<<endl;
 		cout<<"\t\t\t\t\t               #     #    #    #          #       #     # #     # #       "<<endl;
 		cout<<"\t\t\t\t\t               #     #    #    #          #     # #     # #     # #       "<<endl;
 		cout<<"\t\t\t\t\t               #######    #    #           #####  ####### ######  ####### "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout<<"\n\n\n\n\n\n\n";
		print_text(otp,"\t\t\t\t\t\t\t  ");
		if(s.size()<6){
			if(GetAsyncKeyState(0x41) != 0){
			s=s+"A";
		}
		else if(GetAsyncKeyState(0x42) != 0){
			s=s+"B";
		}
		else if(GetAsyncKeyState(0x43) != 0){
			s=s+"C";
		}
		else if(GetAsyncKeyState(0x44) != 0){
			s=s+"D";
		}
		else if(GetAsyncKeyState(0x45) != 0){
			s=s+"E";
		}
		else if(GetAsyncKeyState(0x46) != 0){
			s=s+"F";
		}
		else if(GetAsyncKeyState(0x47) != 0){
			s=s+"G";
		}
		else if(GetAsyncKeyState(0x48) != 0){
			s=s+"H";
		}
		else if(GetAsyncKeyState(0x49) != 0){
			s=s+"I";
		}
		else if(GetAsyncKeyState(0x4A) != 0){
			s=s+"J";
		}
		else if(GetAsyncKeyState(0x4B) != 0){
			s=s+"K";
		}
		else if(GetAsyncKeyState(0x4C) != 0){
			s=s+"L";
		}
		else if(GetAsyncKeyState(0x4D) != 0){
			s=s+"M";
		}
		else if(GetAsyncKeyState(0x4E) != 0){
			s=s+"N";
		}
		else if(GetAsyncKeyState(0x4F) != 0){
			s=s+"O";
		}
		else if(GetAsyncKeyState(0x50) != 0){
			s=s+"P";
		}
		else if(GetAsyncKeyState(0x51) != 0){
			s=s+"Q";
		}
		else if(GetAsyncKeyState(0x52) != 0){
			s=s+"R";
		}
		else if(GetAsyncKeyState(0x53) != 0){
			s=s+"S";
		}
		else if(GetAsyncKeyState(0x54) != 0){
			s=s+"T";
		}
		else if(GetAsyncKeyState(0x55) != 0){
			s=s+"U";
		}
		else if(GetAsyncKeyState(0x56) != 0){
			s=s+"V";
		}else if(GetAsyncKeyState(0x57) != 0){
			s=s+"W";
		}else if(GetAsyncKeyState(0x58) != 0){
			s=s+"X";
		}else if(GetAsyncKeyState(0x59) != 0){
			s=s+"Y";
		}else if(GetAsyncKeyState(0x5A) != 0){
			s=s+"Z";
		}else if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			s=s+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			s=s+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			s=s+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			s=s+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			s=s+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			s=s+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			s=s+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			s=s+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			s=s+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
			s=s+"9";
		}
		}
		
		if(GetAsyncKeyState(VK_BACK) != 0){
			s=s.substr(0,s.size()-1);
		}cout<<"\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		
		print_text(s,"\t\t\t\t\t\t\t  ");
		if(wrong==1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			wrong_pass();
			wrong=0;
		}else{
			cout<<"\n\n\n";
		}
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__]/  `|_/ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  [__)|  |\\__.|  \\\n");//cout<<page;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="login";
			break;
		}
		if(GetAsyncKeyState(VK_RETURN) != 0){
			if(s==otp){
				::page="profile";
				break;
			}else{
				wrong=1;
			}
			
		}
	}
	
}
void pin_state(){
	
	string s="";
	
		int wrong=0;
	
	while(true){cout<<endl<<endl<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		print_text("ENTER PIN","\t\t\t\t\t\t\t");
		
		
		if(s.size()<6){
		if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			s=s+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			s=s+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			s=s+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			s=s+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			s=s+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			s=s+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			s=s+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			s=s+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			s=s+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
			s=s+"9";
		}
		}
		if(GetAsyncKeyState(VK_BACK) != 0){
			s=s.substr(0,s.size()-1);
		}cout<<"\n\n\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		
		print_text(s,"\t\t\t\t\t\t\t  ");
		if(wrong==1){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			wrong_pass();
			wrong=0;
		}else{
			cout<<"\n\n\n";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__ .__..___._..   .___\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__)|  |[__  | |   [__ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  |   |  \\|__||   _|_|___[___\n");
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="profile";
			break;
		}
		if(GetAsyncKeyState(VK_RETURN) != 0){
			if(s==all_customers[::num].pin){
				if(::state==0){
					all_customers[::num].money+=pin_mon;
					history(all_customers[::num].id,"+"+to_string(pin_mon)+"   From Deposit [Money]---> "+to_string(all_customers[::num].money));
				}else if(::state==1){
					all_customers[::num].money-=pin_mon;
					history(all_customers[::num].id,"-"+to_string(pin_mon)+"   From Withdraw [Money]---> "+to_string(all_customers[::num].money));
				}else if(::state==2){
					all_customers[::num_transfer].money+=pin_mon;
					all_customers[::num].money-=pin_mon;
					history(all_customers[::num].id,"-"+to_string(pin_mon)+"   From Transfer to "+all_customers[::num_transfer].id+" [Money]---> "+to_string(all_customers[::num].money));
				}
				::page="profile";
				if(::state==4){
					all_customers.erase(all_customers.begin()+::num);
    				del_id=find_id.find(all_customers[::num].id);
    				find_id.erase(del_id);
    				::page="main";
				}
				break;
			}else{
				wrong=1;
			}
			
		}
		system("cls");
	}
	
	
	update_data();
		
		
		
}
void deposit(){string s="";
	while(true){
		
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t########  ######## ########   #######   ######  #### ######## "<<endl;
	cout<<"\t\t\t\t\t\t\t##     ## ##       ##     ## ##     ## ##    ##  ##     ##    "<<endl;
	cout<<"\t\t\t\t\t\t\t##     ## ##       ##     ## ##     ## ##        ##     ##    "<<endl;
	cout<<"\t\t\t\t\t\t\t##     ## ######   ########  ##     ##  ######   ##     ##    "<<endl;
	cout<<"\t\t\t\t\t\t\t##     ## ##       ##        ##     ##       ##  ##     ##    "<<endl;
	cout<<"\t\t\t\t\t\t\t##     ## ##       ##        ##     ## ##    ##  ##     ##    "<<endl;
	cout<<"\t\t\t\t\t\t\t########  ######## ##         #######   ######  ####    ##    "<<endl<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	print_text("ENTER MONEY AMOUNT","\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(s.size()<7){
		if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			s=s+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			s=s+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			s=s+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			s=s+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			s=s+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			s=s+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			s=s+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			s=s+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			s=s+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
			s=s+"9";
		}else if(GetAsyncKeyState(0x6E)){
			
			s=s+".";
		}
		}
		if(GetAsyncKeyState(VK_BACK) != 0){
			s=s.substr(0,s.size()-1);
		}cout<<"\n\n\n\n";
			
		
	print_money(s,"\t\t\t\t\t\t\t\t");
	
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			pin_mon=strtold(s.c_str(),NULL);
			/*if(pin_mon>all_customers[num].money){
				
			}else{
				cout<<".  ..__..___.  .___.  ..__..  ..__ .  .  .  ..__..  ..___.   ,"<<endl;
				cout<<"|\\ ||  |  |    [__ |\\ ||  ||  |[ __|__|  |\\/||  ||\\ |[__  \\./ "<<endl;
				cout<<"| \\||__|  |    [___| \\||__||__|[_./|  |  |  ||__|| \\|[___  |  "<<endl;
				
				
				break;
			}*/
			::page="pin";
			::state=0;
			break;
		}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__ .__..___._..   .___\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__)|  |[__  | |   [__ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  |   |  \\|__||   _|_|___[___\n");
		
		




		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="profile";
			break;
		}
	
	}
}
void withdraw(){string s="";
	while(true){system("cls");cout<<"\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	
	cout<<"\t\t\t\t\t\t\t##      ## #### ######## ##     ## ########  ########     ###    ##      ## "<<endl;
	cout<<"\t\t\t\t\t\t\t##  ##  ##  ##     ##    ##     ## ##     ## ##     ##   ## ##   ##  ##  ## "<<endl;
	cout<<"\t\t\t\t\t\t\t##  ##  ##  ##     ##    ##     ## ##     ## ##     ##  ##   ##  ##  ##  ## "<<endl;
	cout<<"\t\t\t\t\t\t\t##  ##  ##  ##     ##    ######### ##     ## ########  ##     ## ##  ##  ## "<<endl;
	cout<<"\t\t\t\t\t\t\t##  ##  ##  ##     ##    ##     ## ##     ## ##   ##   ######### ##  ##  ## "<<endl;
	cout<<"\t\t\t\t\t\t\t##  ##  ##  ##     ##    ##     ## ##     ## ##    ##  ##     ## ##  ##  ## "<<endl;
	cout<<"\t\t\t\t\t\t\t ###  ###  ####    ##    ##     ## ########  ##     ## ##     ##  ###  ###  "<<endl<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	print_text("ENTER MONEY AMOUNT","\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(s.size()<7){
		if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			s=s+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			s=s+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			s=s+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			s=s+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			s=s+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			s=s+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			s=s+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			s=s+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			s=s+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
			s=s+"9";
		}
		}
		if(GetAsyncKeyState(VK_BACK) != 0){
			s=s.substr(0,s.size()-1);
		}cout<<"\n\n\n\n";
			
		
	print_money(s,"\t\t\t\t\t\t\t\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			pin_mon=strtold(s.c_str(),NULL);
			if(pin_mon<all_customers[::num].money){
				::page="pin";
			::state=1;
			break;
			}else{
				cout<<".  ..__..___.  .___.  ..__..  ..__ .  .  .  ..__..  ..___.   ,"<<endl;
				cout<<"|\\ ||  |  |    [__ |\\ ||  ||  |[ __|__|  |\\/||  ||\\ |[__  \\./ "<<endl;
				cout<<"| \\||__|  |    [___| \\||__||__|[_./|  |  |  ||__|| \\|[___  |  "<<endl;
				
				
				
			}
			
			
		}else{
			cout<<"\n\n\n";
		}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__ .__..___._..   .___\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__)|  |[__  | |   [__ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  |   |  \\|__||   _|_|___[___\n");
		
		




		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="profile";
			break;
		}
}
}
void transfer(){
	
	string s="",acc_no="";
	while(true){system("cls");cout<<"\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"\t\t\t\t\t\t\t######## ########     ###    ##    ##  ######  ######## ######## ########  "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##     ##   ## ##   ###   ## ##    ## ##       ##       ##     ## "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##     ##  ##   ##  ####  ## ##       ##       ##       ##     ## "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ########  ##     ## ## ## ##  ######  ######   ######   ########  "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##   ##   ######### ##  ####       ## ##       ##       ##   ##   "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##    ##  ##     ## ##   ### ##    ## ##       ##       ##    ##  "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##     ## ##     ## ##    ##  ######  ##       ######## ##     ## "<<endl<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	print_text("ENTER PAYEE ACC. NO.","\t");
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
		print_text(acc_no,"\t\t\t\t\t\t  ");
	
		if(GetAsyncKeyState(VK_RETURN) != 0){
			find_id_all(acc_no,"pin");
			if(::page=="pin"){
				for(int i=0;i<all_customers.size();i++){
					if(acc_no==all_customers[i].id){
						::num_transfer=i;
					}
				}
				if(all_customers[::num_transfer].id==all_customers[::num].id){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		::page="transfer";
		printf("\n\n\t\t\t\t\t     __ .__..  ..  ..__..___.  .___.__..  ..  ..__   .__. __  __ .__..  ..  ..___.  .  .      \n");
		printf("\t\t\t\t\t    /  `[__]|\\ ||\\ ||  |  |    [__ |  ||  ||\\ ||  \\  [__]/  `/  `|  ||  ||\\ |  |    |\\ | _    \n");
		printf("\t\t\t\t\t    \\__.|  || \\|| \\||__|  |    |   |__||__|| \\||__/  |  |\\__.\\__.|__||__|| \\|  |    | \\|(_) * \n");
				}else{
					break;
				}
				
			}
		}else{
			cout<<"\n\n\n";
		}
		
	
	
	
	
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__ .__..___._..   .___\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__)|  |[__  | |   [__ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  |   |  \\|__||   _|_|___[___\n");
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="profile";
			break;
		}
	}
	while(::page=="pin"){system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);cout<<"\n\n";
	cout<<"\t\t\t\t\t\t\t######## ########     ###    ##    ##  ######  ######## ######## ########  "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##     ##   ## ##   ###   ## ##    ## ##       ##       ##     ## "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##     ##  ##   ##  ####  ## ##       ##       ##       ##     ## "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ########  ##     ## ## ## ##  ######  ######   ######   ########  "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##   ##   ######### ##  ####       ## ##       ##       ##   ##   "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##    ##  ##     ## ##   ### ##    ## ##       ##       ##    ##  "<<endl;
	cout<<"\t\t\t\t\t\t\t   ##    ##     ## ##     ## ##    ##  ######  ##       ######## ##     ## "<<endl<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			print_text("ENTER AMOUNT OF MONEY","\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(s.size()<7){
		if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			s=s+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			s=s+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			s=s+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			s=s+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			s=s+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			s=s+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			s=s+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			s=s+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			s=s+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
			s=s+"9";
		}
		}
		if(GetAsyncKeyState(VK_BACK) != 0){
			s=s.substr(0,s.size()-1);
		}cout<<"\n\n\n\n";
			
		
	print_money(s,"\t\t\t\t\t\t\t\t");
	
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			pin_mon=strtold(s.c_str(),NULL);
			if(pin_mon<all_customers[::num].money){
				::page="pin";
			::state=2;
			break;
			}else{
				cout<<".  ..__..___.  .___.  ..__..  ..__ .  .  .  ..__..  ..___.   ,"<<endl;
				cout<<"|\\ ||  |  |    [__ |\\ ||  ||  |[ __|__|  |\\/||  ||\\ |[__  \\./ "<<endl;
				cout<<"| \\||__|  |    [___| \\||__||__|[_./|  |  |  ||__|| \\|[___  |  "<<endl;
				
				
				
			}
			
			
		}else{
			cout<<"\n\n\n";
		}
		
		
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__ .__..___._..   .___\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__)|  |[__  | |   [__ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  |   |  \\|__||   _|_|___[___\n");
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="transfer";
			break;
		}
	}
}

void print_deposit(int w){
	char a=219;cout<<"\t\t\t";
	cout<<"     ____  _____ _____ _____ _____ _____ _____ "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==0){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|    \\|   __|  _  |     |   __|     |_   _|"<<endl;cout<<"\t\t\t";
	cout<<" ";
	for(int i=0;i<2;i++){
		if(w==0){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<" ";
	cout<<"|  |  |   __|   __|  |  |__   |-   -| | |  "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==0){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|____/|_____|__|  |_____|_____|_____| |_|  "<<endl;
}
void print_withdraw(int w){
	char a=219;
	cout<<"\t\t\t";
	cout<<"     _ _ _ _____ _____ _____ ____  _____ _____ _ _ _ "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==1){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"| | | |     |_   _|  |  |    \\| __  |  _  | | | |"<<endl;cout<<"\t\t\t";
	cout<<" ";
	for(int i=0;i<2;i++){
		if(w==1){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<" ";
	cout<<"| | | |-   -| | | |     |  |  |    -|     | | | |"<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==1){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|_____|_____| |_| |__|__|____/|__|__|__|__|_____|"<<endl;
}
void print_transfer(int w){
	char a=219;cout<<"\t\t\t";
	cout<<"     _____ _____ _____ _____ _____ _____ _____ _____ "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==2){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|_   _| __  |  _  |   | |   __|   __|   __| __  |"<<endl;cout<<"\t\t\t";
	cout<<" ";
	for(int i=0;i<2;i++){
		if(w==2){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<" ";
	cout<<"  | | |    -|     | | | |__   |   __|   __|    -|"<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==2){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"  |_| |__|__|__|__|_|___|_____|__|  |_____|__|__|"<<endl;
}
void print_his(int w){
	char a=219;cout<<"\t\t\t";
	cout<<"     _  _ ___ ___ _____ ___  _____   __"<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==3){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"| || |_ _/ __|_   _/ _ \\| _ \\ \\ / /"<<endl;cout<<"\t\t\t";
	cout<<" ";
	for(int i=0;i<2;i++){
		if(w==3){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<" ";
	cout<<"| __ || |\\__ \\ | || (_) |   /\\ V / "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==3){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|_||_|___|___/ |_| \\___/|_|_\\ |_|  "<<endl;
}
void print_del(int w){
	char a=219;cout<<"\t\t\t";
	cout<<"     ___  ___ _    ___ _____ ___     _   ___ ___ "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==4){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|   \\| __| |  | __|_   _| __|   /_\\ / __/ __|  "<<endl;cout<<"\t\t\t";
	cout<<" ";
	for(int i=0;i<2;i++){
		if(w==4){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<" ";
	cout<<"| |) | _|| |__| _|  | | | _|   / _ \\ (_| (__ _ "<<endl;cout<<"\t\t\t";
	for(int i=0;i<2;i++){
		if(w==4){
			cout<<a;
		}else{
			cout<<" ";
		}
	}cout<<"  ";
	cout<<"|___/|___|____|___| |_| |___| /_/ \\_\\___\\___(_)"<<endl;
}

void pro_his(){
	string textline;
	ifstream his(all_customers[::num].id+".txt");
	vector<string> n;
	while(getline(his,textline))
	{
		n.push_back(textline);
	}his.close();
	
	while(true){
		
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"\n\n\n\t\t\t\t\t\t#     # ###  #####  ####### ####### ######  #     # "<<endl;
		cout<<"\t\t\t\t\t\t#     #  #  #     #    #    #     # #     #  #   #  "<<endl;
		cout<<"\t\t\t\t\t\t#     #  #  #          #    #     # #     #   # #   "<<endl;
		cout<<"\t\t\t\t\t\t#######  #   #####     #    #     # ######     #    "<<endl;
		cout<<"\t\t\t\t\t\t#     #  #        #    #    #     # #   #      #    "<<endl;
		cout<<"\t\t\t\t\t\t#     #  #  #     #    #    #     # #    #     #    "<<endl;
		cout<<"\t\t\t\t\t\t#     # ###  #####     #    ####### #     #    #    "<<endl<<endl<<endl;
		
		for(int i=0;i<n.size();i++){
			if(n[i][0]=='+'){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			}
			cout<<"\t\t\t"<<n[i]<<endl;
		}
		if(n.size()==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<"\t\t\t"<<"You have no history.\n";
		}
		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__]/  `|_/ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  [__)|  |\\__.|  \\\n");
		
		
		
 

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="profile";
			break;
		}
	}
	
	
	
	
	
	
}

void profile(){
	int pro_cur=0;
	
	while(true){system("cls");
	cout<<"\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		print_text("PROFILE","\t\t\t\t\t\t    ");
	cout<<"\n\n";
	string s=to_string(all_customers[::num].money);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	
	print_text_small("ACC. NO. "+all_customers[::num].id,"\t\t");
	print_text_small("NAME     "+all_customers[::num].name,"\t\t");	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	cout<<endl;
	print_text_small("AMOUNT OF MONEY","\t\t\t\t\t\t  ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"\n\n";
	print_money(s,"\t\t\t\t\t\t");
	//cout<<all_customers[::num].name;
	if(GetAsyncKeyState(VK_UP) != 0){//Up State
			if(pro_cur>0&&pro_cur<5){
				pro_cur--;
			}
		}else if(GetAsyncKeyState(VK_DOWN) != 0){//Down State
			if(pro_cur>=0&&pro_cur<4){
				pro_cur++;
			}
		}else	if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			if(pro_cur==0){
			 ::page="deposit";
			 break;
			}else if(pro_cur==1){
			::page="withdraw";
			break;
		}
			else if(pro_cur==2){
			::page="transfer";
				break;
			}
			else if(pro_cur==4){
			::page="pin";
			::state=4;
			
				break;
			}else if(pro_cur==3){
				::page="his";
				break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		cout<<"\n\n";
		print_deposit(pro_cur);cout<<"\n";
		print_withdraw(pro_cur);cout<<"\n";
		print_transfer(pro_cur);cout<<"\n";
		print_his(pro_cur);cout<<"\n";
		print_del(pro_cur);cout<<"\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .   .__..__   .__..  ..___.\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  |   |  |[ __  |  ||  |  | \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  |___|__|[_./  |__||__|  |  \n");
		
		
 

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="main";
			break;
		}
	
	}
	
	
	
	
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
		
		for(int j=0;j<38;j++){
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

							cout<<endl;
	for(int i=0;i<4;i++){
		char a=219;cout<<"          ";
		if(w!=1){
								a=' ';
							}
							for(int j=0;j<34;j++){
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

	cout<<endl;
	for(int i=0;i<4;i++){
		cout<<"       ";
		char a=219;
			for(int j=0;j<11;j++){
					cout<<" ";
				}
				for(int j=0;j<38;j++){
			cout<<" ";
			
		}
		if(w!=3){
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

void print_interest(int w){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);

	cout<<endl<<endl<<endl;
	for(int i=0;i<4;i++){
		cout<<"       ";
		char a=219;
			for(int j=0;j<11;j++){
					cout<<" ";
				}
				for(int j=0;j<33;j++){
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
					printf(" ___ _  _ _____ ___ ___ ___ ___ _____ \n");
				}	
				if(i==1){
					printf("|_ _| \\| |_   _| __| _ \\ __/ __|_   _|\n",e,e);
				}	
				if(i==2){
					printf(" | || .` | | | | _||   / _|\\__ \\ | |  \n"); 
				}	
				if(i==3){
					printf("|___|_|\\_| |_| |___|_|_\\___|___/ |_|  \n",e,e);
				}						
		//cout<<exit[i]<<endl;
	}
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
void find_id_all(string no,string w){
	
	if(find_id.count(no)!=0){
		::page=w;
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
	printf("\n\n\n\n\n\n\n\n\n                                           _    ____ ____ ___  _   _ _   _ _____   _   _ _   _ __  __ ____  _____ ____      \n"); 
	printf("                                          / \\  / ___/ ___/ _ \\| | | | \\ | |_   _| | \\ | | | | |  \\/  | __ )| ____|  _ \\      \n");
	printf("                                         / _ \\| |  | |  | | | | | | |  \\| | | |   |  \\| | | | | |\\/| |  _ \\|  _| | |_) |     \n");
	printf("                                        / ___ \\ |__| |__| |_| | |_| | |\\  | | |   | |\\  | |_| | |  | | |_) | |___|  _ <      \n");
	printf("                                       /_/   \\_\\____\\____\\___/ \\___/|_| \\_| |_|   |_| \\_|\\___/|_|  |_|____/|_____|_| \\_\\      \n\n\n");
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
		print_text(acc_no,"\t\t\t\t\t\t  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<"\n\nPress Backspace to delete";
		if(GetAsyncKeyState(VK_RETURN) != 0){
			find_id_all(acc_no,"otp");
			if(page=="otp"){
				for(int i=0;i<all_customers.size();i++){
					if(acc_no==all_customers[i].id){
						::num=i;
					}
				}
				break;
			}
		}
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
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

void regist(){//register page func()
	string acc_no="",acc_name="",acc_pin="";
	int name_size=0;
	while(true){//state enter id
	cout<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		print_text("Enter Acc. No.","\t\t\t\t  ");
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
		}cout<<endl<<endl;
			print_text(acc_no,"\t\t\t\t  ");
			if(GetAsyncKeyState(VK_RETURN) != 0){
			if(acc_no.size()==9){
				if(find_id.count(acc_no)>0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					print_text_small("Account Number has already"," \t");
				}else{
					
					break;
				}
			}
		}else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<"Press Backspace to delete\n\n";
		}
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__]/  `|_/ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  [__)|  |\\__.|  \\\n");
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		
				system("pause");
		
	
		
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="main";
			break;
		}
		system("cls");
	}
	system("cls");acc_name="";
	while(::page!="main"){//state enter name
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		print_text("Enter Acc. name","\t\t      ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		if(acc_name.size()<15){
			if(GetAsyncKeyState(0x41) != 0){
			acc_name=acc_name+"A";
		}
		else if(GetAsyncKeyState(0x42) != 0){
			acc_name=acc_name+"B";
		}
		else if(GetAsyncKeyState(0x43) != 0){
			acc_name=acc_name+"C";
		}
		else if(GetAsyncKeyState(0x44) != 0){
			acc_name=acc_name+"D";
		}
		else if(GetAsyncKeyState(0x45) != 0){
			acc_name=acc_name+"E";
		}
		else if(GetAsyncKeyState(0x46) != 0){
			acc_name=acc_name+"F";
		}
		else if(GetAsyncKeyState(0x47) != 0){
			acc_name=acc_name+"G";
		}
		else if(GetAsyncKeyState(0x48) != 0){
			acc_name=acc_name+"H";
		}
		else if(GetAsyncKeyState(0x49) != 0){
			acc_name=acc_name+"I";
		}
		else if(GetAsyncKeyState(0x4A) != 0){
			acc_name=acc_name+"J";
		}
		else if(GetAsyncKeyState(0x4B) != 0){
			acc_name=acc_name+"K";
		}
		else if(GetAsyncKeyState(0x4C) != 0){
			acc_name=acc_name+"L";
		}
		else if(GetAsyncKeyState(0x4D) != 0){
			acc_name=acc_name+"M";
		}
		else if(GetAsyncKeyState(0x4E) != 0){
			acc_name=acc_name+"N";
		}
		else if(GetAsyncKeyState(0x4F) != 0){
			acc_name=acc_name+"O";
		}
		else if(GetAsyncKeyState(0x50) != 0){
			acc_name=acc_name+"P";
		}
		else if(GetAsyncKeyState(0x51) != 0){
			acc_name=acc_name+"Q";
		}
		else if(GetAsyncKeyState(0x52) != 0){
			acc_name=acc_name+"R";
		}
		else if(GetAsyncKeyState(0x53) != 0){
			acc_name=acc_name+"S";
		}
		else if(GetAsyncKeyState(0x54) != 0){
			acc_name=acc_name+"T";
		}
		else if(GetAsyncKeyState(0x55) != 0){
			acc_name=acc_name+"U";
		}
		else if(GetAsyncKeyState(0x56) != 0){
			acc_name=acc_name+"V";
		}else if(GetAsyncKeyState(0x57) != 0){
			acc_name=acc_name+"W";
		}else if(GetAsyncKeyState(0x58) != 0){
			acc_name=acc_name+"X";
		}else if(GetAsyncKeyState(0x59) != 0){
			acc_name=acc_name+"Y";
		}else if(GetAsyncKeyState(0x5A) != 0){
			acc_name=acc_name+"Z";
		}else if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			acc_name=acc_name+" ";
		}
		}
		if(GetAsyncKeyState(VK_BACK) != 0&&acc_no.size()>0){
			acc_name=acc_name.substr(0,acc_name.size()-1);
		}
		cout<<endl;
		print_text(acc_name," ");
		name_size=acc_name.size();
		if(GetAsyncKeyState(VK_RETURN) != 0){
			if(acc_name.size()>0){
				
					break;
				
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				print_text_small("please enter name","   ");
			}
		}else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<"Press 0 to space name.\nPress 1 to check name\nPress Backspace to delete\n";
		}
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__]/  `|_/ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  [__)|  |\\__.|  \\\n");
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="main";
			break;
		}
		
		system("cls");
	}
	while(name_size<acc_name.size()){
		acc_name=acc_name.substr(0,acc_name.size()-1);
	}
	system("cls");acc_pin="";
	while(::page!="main"){//state enter pin
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		print_text("Enter Acc. PIN","\t\t           ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	
		if(acc_pin.size()<6){
			if(GetAsyncKeyState(0x30) != 0||GetAsyncKeyState(VK_NUMPAD0) != 0){
			acc_pin=acc_pin+"0";
		}else
		if(GetAsyncKeyState(0x31) != 0||GetAsyncKeyState(VK_NUMPAD1) != 0){
			acc_pin=acc_pin+"1";
		}else
		if(GetAsyncKeyState(0x32) != 0||GetAsyncKeyState(VK_NUMPAD2) != 0){
			acc_pin=acc_pin+"2";
		}else
		if(GetAsyncKeyState(0x33) != 0||GetAsyncKeyState(VK_NUMPAD3) != 0){
			acc_pin=acc_pin+"3";
		}else
		if(GetAsyncKeyState(0x34) != 0||GetAsyncKeyState(VK_NUMPAD4) != 0){
			acc_pin=acc_pin+"4";
		}else
		if(GetAsyncKeyState(0x35) != 0||GetAsyncKeyState(VK_NUMPAD5) != 0){
			acc_pin=acc_pin+"5";
		}else
		if(GetAsyncKeyState(0x36) != 0||GetAsyncKeyState(VK_NUMPAD6) != 0){
			acc_pin=acc_pin+"6";
		}else
		if(GetAsyncKeyState(0x37) != 0||GetAsyncKeyState(VK_NUMPAD7) != 0){
			acc_pin=acc_pin+"7";
		}else
		if(GetAsyncKeyState(0x38) != 0||GetAsyncKeyState(VK_NUMPAD8) != 0){
			acc_pin=acc_pin+"8";
		}else
		if(GetAsyncKeyState(0x39) != 0||GetAsyncKeyState(VK_NUMPAD9) != 0){
		acc_pin=acc_pin+"9";
		}
		}
		
		if(GetAsyncKeyState(VK_BACK) != 0&&acc_no.size()>0){
			acc_pin=acc_pin.substr(0,acc_pin.size()-1);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		
		print_text(acc_pin,"\t\t\t\t\t\t\t      ");
		if(GetAsyncKeyState(VK_RETURN) != 0){
			if(acc_pin.size()==6){
				
					find_id.insert(acc_no);
		People s={acc_no,acc_name,acc_pin,500};
		all_customers.push_back(s);
				update_data();
				::page="main";
					break;
			}else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				print_text_small("please enter 6 digit pin","   ");
			}
		}else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<"Press Backspace to delete\n\n";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t.__ .__ .___ __. __.   __..__ .__. __ .___.__ .__..__   .___..__.  .__ .__. __ .  .\n");
		printf("\t[__)[__)[__ (__ (__   (__ [__)[__]/  `[__ [__)[__][__)    |  |  |  [__)[__]/  `|_/ \n");
		printf("\t|   |  \\[___.__).__)  .__)|   |  |\\__.[___[__)|  ||  \\    |  |__|  [__)|  |\\__.|  \\\n");
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		if(GetAsyncKeyState(VK_SPACE) != 0){system("cls");
		::page="main";
			break;
		}
		
		system("cls");
	}
	
}

void main_menu(){
	while(true){
		
	
	if(GetAsyncKeyState(VK_UP) != 0){//Up State
			if(cursor>0&&cursor<4){
				cursor--;
			}
		}else
		if(GetAsyncKeyState(VK_DOWN) != 0){//Down State
			if(cursor>=0&&cursor<3){
				cursor++;
			}
		}else
		if(GetAsyncKeyState(VK_RETURN) != 0){//Enter State
			if(cursor==0){//Login
			 ::page="login";
			 break;
			}
			else if(cursor==1){//Register
			::page="regis";
				break;
			}
			else if(cursor==3){//Exit
			::end=1;
				break;
			}
			else if(cursor==2){
				update_mon_data();
				update_data();
			}
			
		}
		print_logo();
		print_login(cursor);
		cout<<endl<<endl;
		print_regis(cursor);
		print_interest(cursor);
		cout<<endl<<endl;
		print_exit(cursor);
		cout<<endl<<endl;
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		system("pause");
		
		system("cls");
		}
}
int main(){srand(time(0));
	ifstream in(file_name);
	string textline;
	
	
	
	
	
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
		if(::page=="main"){
			main_menu();
		}else if(::page=="login"){
			login();
		}else if(::page=="otp"){
			otp_page();
		}else if(::page=="profile"){
			profile();
		}else if(::page=="deposit"){
			deposit();
		}else if(::page=="withdraw"){
			withdraw();
		}else if(::page=="transfer"){
			transfer();
		}else if(::page=="pin"){
			pin_state();
		}else if(::page=="regis"){
			regist();
		}else if(::page=="his"){
			pro_his();
		}

		system("cls");		
	}
	
	ofstream out(file_name);
	for(int i=0;i<all_customers.size();i++){
		out<<all_customers[i].id<<","<<all_customers[i].name<<","<<all_customers[i].pin<<","<<all_customers[i].money<<endl;
	}
	out.close();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<"\n\n\n\n\n\n";
	print_text("THANK FOR USING","\t\t\t\t   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
