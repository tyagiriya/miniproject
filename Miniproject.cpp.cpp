#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void count(char[]);
int main()
    {
    ifstream fin;
    int i=0,j,p,para=0;
    char ch;
    char temp[1000];
    fin.open("testcase2.txt");
    if(!fin)
    {
        cout<<"Error occured while opening file"<<endl;
        return 1;
    }
    else
    {
        cout<<"Enter the number of paragraphs to be scanned"<<endl;
        cin>>p;
      while(!fin.eof()&&(para<p))
      {
        fin.get(ch);
        if(fin.eof()||ch=='\n')
        {   count(temp);
            i=0;
            para++;
        }

        temp[i]=ch;
        i++;
      }
        fin.close();
    }
    return 0;
    }
void count(char t[])
{
    char xy[100];
    int i=0,j=0,ac1=0,anc2=0,thec3=0,c4=0;
    while(t[i]!='\0')
      {

          xy[j]=t[i];
       if(xy[j]==' '||xy[j]==','||xy[j]=='.'||xy[j]=='\n')
       {
           xy[j]='\0';
           for(j=0;xy[j]!='\0';j++)
           {
               xy[j]=tolower(xy[j]);
           }
           if(strcmp(xy,"a")==0)
           ac1++;
           else if(strcmp(xy,"an")==0)
           anc2++;
           else if(strcmp(xy,"the")==0)
           thec3++;
           else if(xy[j-3]=='-'&&xy[j-6]=='-'||xy[j-3]=='/'&&xy[j-6]=='/'||xy[j-5]=='/'&&xy[j-8]=='/'||xy[j-5]=='-'&&xy[j-8]=='-'||xy[j-2]=='/'&&xy[j-4]=='/'||xy[j-2]=='-'&&xy[j-4]=='-')
            c4++;
            j=-1;
        }
         i++;
         j++;

       }
       cout<<ac1<<",";
       cout<<anc2<<",";
       cout<<thec3<<",";
       cout<<c4<<endl;
}
