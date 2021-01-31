#include <iostream>
#include <string>
#include <vector>

using namespace std;

class cipherblockchaining
{
	private:
		string IV;									
		string key;
	public:
		cipherblockchaining()
		{
			IV="11111111";
			key="11001100";
		}
		vector <int> encryption(string pt)
		{
			vector <int> result;
			string ct;
			
			
			for(int i=0;i<pt.size();i++ )							//XOR OPERATION between PLAINTEXT and IV
			{
				if((pt[i]=='0' && IV[i]=='1')||(pt[i]=='1' &&IV[i]=='0'))
				{
					ct[i]='1';
				}
				else if((pt[i]=='0' && IV[i]=='0')||(pt[i]=='1' && IV[i]=='1'))
				{
					ct[i]='0';
				}
			}
			
			
		
			for(int i=0;i<sizeof(ct);i++ )							//XNOR OPERATION between INTERMEDIATE VALUE ane KEY
			{
				if(ct[i]=='0' &&key[i]=='1'||ct[i]=='1' &&key[i]=='0')
				{
					result.push_back(0);
				}
				else if(ct[i]=='0' &&key[i]=='0'||ct[i]=='1' &&key[i]=='1')
				{
					result.push_back(1);
				}
			}
			
			return result;	
			
		}
		vector <int> decryption(vector <int> ct)
		{
			vector <int> im;
			vector <int> pt;
			
			
			
			for(int i=0;i<ct.size();i++ )							//XNOR OPERATION between CIPHERTEXT and KEY
			{
				if((ct[i]==0 && key[i]=='1')||(ct[i]==1 &&key[i]=='0'))
				{
					im.push_back(0);
				}
				else if((ct[i]==0 && key[i]=='0')||(ct[i]==1 && key[i]=='1'))
				{
					im.push_back(1);
				}
			}
			
			
			
		
			for(int i=0;i<im.size();i++ )							//XOR OPERATION between intermediate value and IV
			{
				if(im[i]==0 &&IV[i]=='1'||im[i]==1 &&IV[i]=='0')
				{
					pt.push_back(1);
				}
				else if(im[i]==0&&IV[i]=='0'||im[i]==1&&IV[i]=='1')
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
	cipherblockchaining CBC1;
	vector <int> ciphertext=CBC1.encryption(plaintext);
	
	for(int i=0;i<ciphertext.size();i++)
	{
		
		cout<<ciphertext[i];
	
	}
	
	cout<<endl;
	//decryption
	cout<<"performing decryption................"<<endl;
	vector <int> pt=CBC1.decryption(ciphertext);
	cout<<"plain text is:"<<flush;
	for(int i=0;i<pt.size();i++)
		cout<<pt[i];
	
	return 0;
	
}
