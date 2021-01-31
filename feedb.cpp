#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cipherfeedbackmode
{
	private:
		string IV;
		string key;
	public:
		cipherfeedbackmode()
		{
			IV="11111111";
			key="11001100";
		}
		vector <int> encryption(string pt)
		{
			vector <int> result;
			vector <int> ct;
			
			
			for(int i=0;i<key.size();i++ )							//XNOR OPERATION between KEY nad IV
			{
				if((key[i]=='0' && IV[i]=='1')||(key[i]=='1' &&IV[i]=='0'))
				{
					ct.push_back(0);
				}
				else if((key[i]=='0' && IV[i]=='0')||(key[i]=='1' && IV[i]=='1'))
				{
					ct.push_back(1);
				}
			}
			
			
		
			for(int i=0;i<ct.size();i++ )							//XOR OPERATION between intermediate value and PLAINTEXT
			{
				if(ct[i]==0 &&pt[i]=='1'||ct[i]==1 &&pt[i]=='0')
				{
					result.push_back(1);//cout<<result[i];
				}
				else if(ct[i]==0 &&pt[i]=='0'||ct[i]==1 &&pt[i]=='1')
				{
					result.push_back(0);//cout<<result[i];
				}
			}
			
			return result;	
			
		}
		vector <int> decryption(vector <int> ct)
		{
			vector <int> im;
			vector <int> pt;
			
			
			
			for(int i=0;i<key.size();i++ )							//XNOR OPERATION between KEY and IV
			{
				if((key[i]=='0' && IV[i]=='1')||(key[i]=='1' &&IV[i]=='0'))
				{
					im.push_back(0);
				}
				else if((key[i]=='0' && IV[i]=='0')||(key[i]=='1' && IV[i]=='1'))
				{
					im.push_back(1);
				}
			}
			
			
		
			for(int i=0;i<im.size();i++ )							//XOR OPERATION between intermediate value and CIPHERTEXT
			{
				if(im[i]==0 &&ct[i]==1||im[i]==1 &&ct[i]==0)
				{
					pt.push_back(1);
				}
				else if(im[i]==0&&ct[i]==0||im[i]==1&&ct[i]==1)
				{
					pt.push_back(0);
				}
			}
			
			return pt;
			
		}
		
		
	
		
};

int main()
{

	
	string plaintext;
	
	cout<<"enter the plain text(of 1 byte size):"<<flush;
	cin>>plaintext;
	//encryption
	
	cout<<"performing encryption................."<<endl;
	cout<<"cipher text is:";
	cipherfeedbackmode CFB1;
	vector <int> ciphertext=CFB1.encryption(plaintext);
	
	for(int i=0;i<ciphertext.size();i++)
	{
		
		cout<<ciphertext[i];
	
	}
	
	cout<<endl;
	
	cout<<"performing decryption................."<<endl;
	
	vector <int> pt=CFB1.decryption(ciphertext);
	cout<<"plain text is:"<<flush;
	for(int i=0;i<pt.size();i++)
		cout<<pt[i];
	
	return 0;
	
}
