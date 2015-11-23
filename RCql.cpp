#include<fstream>
#include<iostream>
#include<cstring>
#include<cctype>
#include<conio.h>
#include<cstdio> 


using namespace std;

void convert(char[]);
void create(char[],ifstream&);
void desc(char[],ifstream&);
int descprintcount(char[]);
void descprint(char[],int);
void infuseinto(char[],ifstream&);
int checkinfuse(char[],char[]);
char checkcheckinfuse(char[]);
void displayhash(char[],ifstream&);
void displayhashcount(char []);

int main(void)
{
	char ch[100]="XYZ",input[1000];int fof;

	while(strcmp("xit",ch)!=0)
	{

	ofstream f("RCql.rcql");

	cout<<"\nRCql-> ";
	
	fof=getch();
	
	if(fof==13)
	{ continue;}
	
	cout<<(char)fof;
	cin.getline(input,1000,';');
	
	f<<input;
 
    f.close();

	ifstream f1("RCql.rcql");

	
	while(!(f1.eof()))
	{
	   f1>>ch;  
 
       convert(ch);
	   
	   create(ch,f1);
	   
	   desc(ch,f1);
	   
	   infuseinto(ch,f1);
	   
	   displayhash(ch,f1);
}
	
	
	f1.close();
	remove("RCql.rcql");
	
	
	
}
}

void convert(char b[])
{
	for(int i=0;b[i]!='\0';++i)
	{
		b[i]=tolower(b[i]);
	}
	

}

void create(char ch[],ifstream& f1)
{
	   if(strcmp("reate",ch)==0)
	   {
	  f1>>ch;
	  convert(ch);

	  if(strcmp("table",ch)==0)
	  {
		 f1>>ch;
		convert(ch);
		char ch1[20],ch2[20];
	
		strcpy(ch1,ch);
		strcpy(ch2,ch);
		strcat(ch1,".rcql");

		
		
		f1>>ch;
		
		if(strcmp(ch,"--")==0)
{
		ofstream g(ch1);
		g<<ch2<<"\n";
		
		int check;
		check=0;
		
		
		while(f1>>ch)

	       {   
		   convert(ch);
		   if(check!=0)
		   {
		   	  if(strcmp(ch,"/")!=0)
		   	  {
		   	  	
		   	  	cout<<"\n SYNTAX ERROR -- missing '/' "<<endl;
		   	  	g.close();
		   	  	remove(ch1);
		   	  	break;
		   	  	
				 }
				 
				 else f1>>ch;
		   }
		   
		if(strcmp("int",ch)==0)
		{   
		    f1>>ch;
		    
		    convert(ch);
			g<<ch<<" ! ";
			++check;
			  }

		 else if(strcmp("varchar",ch)==0)
		 {
			f1>>ch;
		    convert(ch);
			g<<ch<<" @ ";
			++check;
			   }

		 else if(strcmp("fpt",ch)==0)
		 {
			f1>>ch;
		    convert(ch);
			g<<ch<<" # ";
			++check;

			   }

			   else cout<<endl<<" ERROR "<<endl<<endl;
		}
		
		g<<"&& \n";

        g.close();
        
		  }
		  
	}
		  
	   }
	   
	 
}

void desc(char ch[],ifstream& f1)
{
	char ch1[20],ch2[1000],ch11[100];
	ifstream f;
   	    
   	if(strcmp("esc",ch)==0)
   	{
   		f1>>ch;
   		strcpy(ch11,ch);
   		strcat(ch,".rcql");
   		strcat(ch11,"!@#$$#@!!#.rcql");
   	    
   	    ofstream f3(ch11);
   		
   		int count =descprintcount(ch);
   	
   		ifstream f2(ch);
   		
   	    
   	    f2.getline(ch2,1000,'\n');
   	    f3<<ch2<<"\n";
   	    
   	    f2.getline(ch2,1000,'\n');
   	    f3<<ch2<<"\n";
   	    
   	    f2.close();
   	    f3.close();
   	       	    
   	    f.open(ch11);
   	    
   	    f>>ch;
   	    
	    cout<<endl<<endl;
	    cout<<" Table -- "<<ch<<endl<<endl;
	    
	    f>>ch;
	    while(strcmp(ch,"&&")!=0)
   	    {
	    
	    
	    descprint(ch,count);
	    f>>ch;
	    
	    
	    if(strcmp(ch,"!")==0)
	    {cout<<"  int        integer"<<endl<<endl;
		}
		
		else if(strcmp(ch,"@")==0)
		{cout<<"  varchar    text field"<<endl<<endl;
		}
		
		else if(strcmp(ch,"#")==0)
		{cout<<"  fpt        floating point -- decimal"<<endl<<endl;
		}
		
		f>>ch;
	    
	}
   		
   	
   
   	
  
	   }
	   f.close();	
	   remove(ch11);
}


int descprintcount(char ch1[])
{    
    char ch2[20];
    int x,x1;
    x1=0;
    
	ifstream f1(ch1);
	
	f1>>ch2;
	f1>>ch2;
	while(strcmp(ch2,"&&")!=0)
	{   
		if(strcmp(ch2,"!")!=0||strcmp(ch2,"@")!=0||strcmp(ch2,"#")!=0)
		{
			x=strlen(ch2);
			
		}
		
		
		if(x>x1)
		{x1=x;}
		
		f1>>ch2;
	}
	
	f1.close();
	
return(x1);
}


void descprint(char ch[],int count)
{
	int comp=strlen(ch);
	
	if(count>=comp){
		count=count-comp;
	}
	
	cout<<" ";
	for(int i=0;ch[i]!='\0';++i)
	{
	    cout<<ch[i];	
	}
	
	cout<<" ";
	if(count>0)
	
	{ for(int v=1;v<=count;++v)
	{   
	    
		cout<<" ";
	}

}
}

void infuseinto(char ch[],ifstream&f1)
{
	if(strcmp(ch,"nfuse")==0)
	{
		f1>>ch;
		if(strcmp(ch,"data")==0)
		{
			f1>>ch;
		    if(strcmp(ch,"into")==0)
		    {
		    	f1>>ch;
		    	char ch1[30];
		    	strcpy(ch1,ch);
		    	
		    	strcat(ch1,".rcql");
		    	
		    	char ch9[1000];
		    	f1.getline(ch9,1000,'\n');
		    	
		
		    	if(ch9[1]=='(')
		    	{
		    		ofstream f4("jmd!@##@!$.rcql");
		    		
		    		
		    		f4<<ch9;
		    		f4<<"&&";
		    		
		    		
					f4.close();
					
					char jh[]="jmd!@##@!$.rcql";
		    		
		    		int ans=checkinfuse(jh,ch1);
		    	
		    		if(ans==1)
		    		{
		    			fstream f;
		    		    ifstream f5("jmd!@##@!$.rcql");
		    		    
		    			f.open(ch1,ios::in|ios::out);
		    			f.seekp(0,ios::end);
		    			
		    			char c,ch2[100];
		    			c=f5.get();
		    			c=f5.get();
		    			c=f5.get();
		    			
		    			
		    			while(c!=')')
		    			{
		    				
		    				f<<c;
		    				c=f5.get();
						}
		    			
		    		    f<<",,\n";
		    			
		    		    f.close();
		    		    f5.close();
		    		    remove("jmd!@##@!$.rcql");
		    		    remove("check!@#$$#@!.rcql");
		    		
		    			
					}
					
			else if(ans==0) 
			{
			cout<<"\n\n Values does not match column "<<endl<<endl;
		    remove("jmd!@##@!$.rcql");   
			remove("check!@#$$#@!.rcql");   }
			
			else if(ans==3)
		   {
			 cout<<"\n\n '(' , ')' and ',' not permissible in varchar "<<endl<<endl;
			 remove("jmd!@##@!$.rcql");  
			 remove("check!@#$$#@!.rcql"); }
		    		
		    		
				}else cout<<"\n\n Syntax error -- '"<<ch<<"' "<<endl<<endl;
		    	
		    	
			}  else cout<<"\n\nNo such command -- "<<ch<<endl<<endl;
		}  else cout<<"\n\nNo such command -- "<<ch<<endl<<endl;
	}
}

int checkinfuse(char ch[],char ch1[])//ch-jmd    ch1--main file
{
	
	ifstream f(ch1);
	
	int ans;
	
	ofstream f3("check!@#$$#@!.rcql");
	
	char ch3[1000];
	f.getline(ch3,1000,'\n');
	f.getline(ch3,1000,'\n');
	
	
	for(int i=0;ch3[i]!='\0';++i)
	{  
			if(ch3[i]=='!'||ch3[i]=='@'||ch3[i]=='#')
		{
			f3<<ch3[i]<<" ";
		}
	}
	
	f3.close();
	f.close();
	
	ifstream f4("check!@#$$#@!.rcql");
	
	int check=0;
	while(f4>>ch3)
	{
		++check;
	}
	
	f4.close();
	
	ifstream f5("check!@#$$#@!.rcql");
	ifstream f1(ch);//ch-- jmd!@@@# something like that .rcql
	
    char c;
    c=f1.get();
    c=f1.get();
    
    int jk;
    jk=0;
  
 
    for(int i=1;i<=check;++i)
    {  c=f1.get();
    	
    	
    	f5>>ch3;
    
    	
    	if(ch3[0]=='!')
    	{
    		while(c!=','&&c!=')')
    		{
    			
    			
    			if(c!=',')
    		{    
					if(!(isdigit(c)))
    			{     f1.close();
                      f5.close();
                      
					  return 0;
				}
				
				}
    		c=f1.get();	
			
			}
		}
		
	else if(ch3[0]=='@')
		{
			while(c!=','&&c!=')')
			{
			
			
			if(c=='('||c==')'||c==',')
			{     f1.close();
                  f5.close();
				  return 3;
			}
			
		 c=f1.get();
		}}
		
		else if(ch3[0]=='#')
		{
			while(c!=','&&c!=')')
			{ 
				
				if(c!='.')
			{
				if(!(isdigit(c)))
				{    f1.close();
                     f5.close();
					 return 0;
				}
				
				}
				
				else 
				{   ++jk;
				    
				    if(jk>=2)
				    {
				    	f1.close();
                        f5.close();
					    return 0;
					}
					
				}
				c=f1.get();
			}
		}
    	
    	
	}
	
	c=f1.get();
	
	if(c=='&')
	{
		c=f1.get();
		if(c=='&')
		{
			f1.close();
            f5.close();
	        return 1;
		}
		
		
		else 
		{    f1.close();
             f5.close();
             return 0;     }
	}
	
	else 
	{    f1.close();
         f5.close();
	     return 0;   }
	
}

// display all from tablename;

void displayhash(char ch[],ifstream& f)
{
	if(strcmp(ch,"isplay")==0)
	{
		f>>ch;
		
		if(strcmp(ch,"all")==0)
		{
			f>>ch;
			
			if(strcmp(ch,"from")==0)
			{
				f>>ch;
				
				strcat(ch,".rcql");
				
				displayhashcount(ch);
				
				fstream f1;
				f1.open(ch,ios::in);
				
				char ch1[1000];
				
				f1>>ch1;
				f1>>ch1;
				
				cout<<endl<<endl;
				
				while(strcmp(ch1,"&&")!=0)
				{
					if(strcmp(ch1,"!")!=0&&strcmp(ch1,"@")!=0&&strcmp(ch1,"#")!=0)
					{
						cout<<ch1<<"         ";
					}
					
					f1>>ch1;
				}
				
				cout<<endl;
				char c;
				
				while(f1.getline(ch1,1000,','))
				{
					cout<<ch1<<"     ";
					
				}
				
			cout<<endl;
				
			f1.close();	
			} else cout<<"\n\n Syntax error -- '"<<ch<<"' "<<endl<<endl;
			
			
		} else cout<<"\n\n Syntax error -- '"<<ch<<"' "<<endl<<endl;
	}
}

void displayhashcount(char ch[])
{
	ifstream f(ch);
	
	char ch1[1000];
	f>>ch1;
	int a[500],check,comp,no;
	
	check=0;comp=0;no=0;
	
	f>>ch1;
	
	while(strcmp(ch1,"&&")!=0)
	{   
	
		if(strcmp(ch1,"!")!=0 && strcmp(ch1,"@")!=0 && strcmp(ch1,"#")!=0)
		{
			++no;
			int y=strlen(ch1);
			a[check]=y;
			++check;
		}
		
		f>>ch1;
	}
	
    while(!(f.eof()))
	{
		
	 for(int i=0;i<=(no-1);++i)
	{
		f.getline(ch1,1000,','); 
		
		int y=strlen(ch1);
		
		
		if(y>a[i])
		{
			a[i]=y;
			
		}
	 } 
	
}

ofstream f1("countedno!@#$#@!.rcql");

for(int k=0;k<=(no-1);++k)
{
	f1<<a[k]<<" ";
}

f.close();
	
}




