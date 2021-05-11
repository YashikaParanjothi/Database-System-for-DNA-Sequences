#include<iostream>
#include<bitset>
#include<string>
#include<string.h>
#include"tree.h"
using namespace std;
void print(int seq_id);
string str_bit(string &seq)
{
    string bseq;
    char s[40];
    int i=0,j=0;
    for(i=0;i<seq.length();i++)
    {
        if(seq[i]=='A')
        {
            s[j]='0';
            j++;
            s[j]='0';
        }
        else if(seq[i]=='C')
        {
            s[j]='0';
            j++;
            s[j]='1';
        }
        else if(seq[i]=='G')
        {
            s[j]='1';
            j++;
            s[j]='0';
        }
        else if(seq[i]=='T')
        {
            s[j]='1';
            j++;
            s[j]='1';
        }
        j++;
    }
    s[j]='\0';

    //cout<<"\n\t\t\t THE BIT STRING IS :\n\t\t\t "<<s<<endl;

    for (i=0;s[i]!='\0';i++)
    {
        bseq=bseq+s[i];
    }
    return bseq;
}
void insert_seq()
{
    int length,seq_id;
    string seq,bseq;
    cout<<"\n\t\t\tENTER THE LENGTH OF THE DNA SEQUENCE => ";
    cin>>length;
    cout<<"\n\t\t\tENTER THE DNA SEQUENCE(IN CAPS)\n\t\t\t=>";
    cin>>seq;
    bseq=str_bit(seq);
    seq_id=stoi(bseq,0,2);
    cout<<"\n\t\t\tThe SEQUENCE ID FOR THE GIVEN DNA SEQUENCE IS : "<<seq_id<<endl;
    insert_elt(root,seq_id,length);
}
void search_seq()
{
    char choice;
    int seq_id;
    int val;
    if (root==NULL)
    {
        cout<<"\n\t\t\tDATABASE IS EMPTY!!\n";
    }
    else
    {
        cout<<"\n\t\t\tENTER THE SEQUENCE ID OF THE DNA SEQUENCE\n\t\t\tWHICH IS TO BE SEARCHED FOR => ";
        cin>>seq_id;
        val=search_elt(root,seq_id);
        if(val==1)
        {
            cout<<"\n\t\t\tDNA SEQUENCE IS FOUND IN THE DATABASE!"<<endl;
            cout<<"\n\t\t\tDO YOU WANT THE DNA SEQUENCE TO BE PRINTED?(Y/N) => ";
            cin>>choice;
            if(choice=='Y')
                print(seq_id);
        }
        else
        {
            cout<<"\n\t\t\tSORRY! DNA SEQUENCE IS NOT FOUND IN THE DATABASE!"<<endl;
        }
    }
}
void print(int seq_id)
{
    char req_str[40];
    int length,i,j=0;
    string str,subs;
    bitset <50> b(seq_id);
    str=b.to_string();
    length=2*curr->data2;
    for(i=str.length()-length;i<str.length();i=i+2)
    {
        subs=str.substr(i,2);
        if(subs.compare("00")==0)
            req_str[j]='A';
        else if(subs.compare("01")==0)
            req_str[j]='C';
        else if(subs.compare("10")==0)
            req_str[j]='G';
        else if(subs.compare("11")==0)
            req_str[j]='T';
        j++;
    }
    req_str[j]='\0';
    cout<<"\n\t\t\tTHE DNA SEQUENCE IS :"<<endl;
    cout<<"\t\t\t"<<req_str<<endl;
}
void print_seq()
{
    int val;
    int seq_id;
    if (root==NULL)
    {
        cout<<"\n\t\t\tDATABASE IS EMPTY!!\n";
    }
    else
    {
        cout<<"\n\t\t\tENTER THE SEQUENCE ID OF THE DNA SEQUENCE\n\t\t\t THAT HAS TO BE PRINTED => ";
        cin>>seq_id;
        val=search_elt(root,seq_id);
        if(val==1)
        {
            print(seq_id);
        }
        else
        {
            cout<<"\n\t\t\tSORRY! DNA SEQUENCE IS NOT FOUND IN THE DATABASE!"<<endl;
        }
    }

}
void remove_seq()
{
    int val;
    int seq_id;
    if (root==NULL)
    {
        cout<<"\n\t\t\tDATABASE IS EMPTY!!\n";
    }
    else
    {
        cout<<"\n\t\t\tENTER THE SEQUENCE ID OF THE DNA SEQUENCE\n\t\t\t THAT HAS TO BE REMOVED FROM THE DATABASE => ";
        cin>>seq_id;
        val=search_elt(root,seq_id);
        if(val==1)
        {
            print(seq_id);
            remove_elt();
            cout<<"\n\t\t\tTHE DNA SEQUENCE WAS SUCCESSFULLY REMOVED!"<<endl;
        }
        else
        {
            cout<<"\n\t\t\tSORRY! DNA SEQUENCE IS NOT FOUND IN THE DATABASE!"<<endl;
        }
    }
}
int main()
{
    int choice;
    char ch='Y';
    cout<<"\n\n\n\t================DATABASE SYSTEM FOR DNA SEQUENCES================\n\n\n";
    while(ch=='Y')
    {
        cout<<"\t\t\t1] INSERT A SEQUENCE\n\t\t\t2] SEARCH A SEQUENCE\n\t\t\t3] PRINT FOR A SEQUENCE\n\t\t\t4] REMOVE A SEQUENCE\n";
        cout<<"\n\t\t\tENTER YOUR CHOICE => ";
        cin>>choice;
        switch(choice)
        {
            case 1 : insert_seq();
                     break;
            case 2 : search_seq();
                     break;
            case 3 : print_seq();
                     break;
            case 4 : remove_seq();
                     break;
            default: cout<<"\n\t\t\tINVALID CHOICE !!\n";
        }
        cout<<"\n\t\t\tDO YOU WANT TO CONTINUE(Y/N)? => ";
        cin>>ch;
        system("cls");

        cout<<"\n\n";
    }
    //display(root);
}
