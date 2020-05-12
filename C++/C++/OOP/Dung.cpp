#include<iostream>
#include<string.h>
using namespace std;
class CString
        {
            private:
                    int doDai;
                    char* Xau;
            public:
                    CString()
                    {
                        doDai=0;
                        Xau=new char[80];
                    } 
                    friend istream &operator>>(istream&os,CString&s)                    {
                        fflush(stdin);
                        cin.getline(is,s)
                        cin.getline(s,80);
                        doDai=strlen(s);
                        return is;
                    }
                    friend ostream &operator<<(ostream&os,CString&s)                    {
                        os<<s;
                        return os;
                    }
                    CString operator+(const CString& s2)
                    {
                        CString tam;
                        tam.doDai=doDai+s2.doDai;
                        strcpy(tam.Xau,Xau);
                        strcat(tam.Xau,s2.Xau);
                        return tam;
                    }
                    CString operator+=(const CString& s2)
                    {
                        CString tam;
                        tam.doDai=doDai+s2.doDai;
                        strcpy(tam.Xau,Xau);
                        strcat(tam.Xau,s2.Xau);
                        doDai=tam.doDai;
                        strcpy(Xau,tam.Xau);
                        return tam;
                    }
                    CString operator=(const CString& s2)
                    {
                        CString tam;
                        tam.doDai=s2.doDai;
                        strcat(tam.Xau,s2.Xau);
                        doDai=tam.doDai;
                        strcpy(Xau,tam.Xau);
                        return tam;
                    }
                    CString operator==(CString& s2)
                    {
                        if(doDai!=s2.doDai)
                            return 0;
                        for(int i=0;i<doDai;i++)
                            if(Xau[i]!=s2.Xau[i])
                                return 0;
                        return 1;
                    }
                    CString bool operator<(CString &s2)
                    {
                        if(strcmpi(Xau,s2.Xau)<0)
                            return 1;
                        else return 0;
                    }
                    CString bool operator<=(CString& s2)
                    {
                        if(strcmpi(Xau,s2.Xau)<=0)
                            return 1;
                        else return 0;
                    }
                    CString bool operator>(CString& s2)
                    {
                        if(strcmpi(Xau,s2.Xau)>0)
                            return 1;
                        else return 0;
                    }
                    CString bool operator>=(CString& s2)
                    {
                        if(strcmpi(Xau,s2.Xau)>=0)
                            return 1;
                        else return 0;
                    }
                    CString bool operator!=(CString& s2)
                    {
                        if(strcmpi(Xau,s2.Xau)!=0)
                            return 1;
                        else return 0;
                    }
                    
        };
        mail(){
		char a;
		strcpy (a,'help');
		cout << a;
		cin>>a;
		char b;
		strcpy (b,'me');
		cout << b;
		cin>>b;
		char c;
		c=a+b;
		a+=b;
		a==b;
		a=b;
		a<b;
		a<=b;
		a>b;
		a>=b;
		a!=b;
		};
