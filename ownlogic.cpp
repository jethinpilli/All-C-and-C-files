#include <iostream>
#include <string>
#include <vector>

using namespace std;

class mylogicckt
{
	private:
		string IV;
		string key;
		
	public:
		mylogicckt()
		{
			IV="11111111";						
			key="11001100";
		}
		vector <int> encryption(string pt)			//ptno=plaintext number
		{
		
			vector <int> result;
			vector <int> im;
			vector <int> im2;
			for(int i=0;i<pt.size();i++ )							//XOR OPERATION between IV and PLAINTEXT
			{
				if((pt[i]=='0' && IV[i]=='1')||(pt[i]=='1' &&IV[i]=='0'))
				{
					im.push_back(1);
				}
				else if((pt[i]=='0' && IV[i]=='0')||(pt[i]=='1' && IV[i]=='1'))
				{
					im.push_back(0);
				}
			}
			for(int i=0;i<key.size();i++ )							//XOR OPERATION between intermediate value and KEY
			{
				if((key[i]=='0' && im[i]==1)||(key[i]=='1' &&im[i]==0))
				{
					im2.push_back(1);
				}
				else if((key[i]=='0' && im[i]==0)||(key[i]=='1' && im[i]==1))
				{
					im2.push_back(0);
				}
			}
			for(int i=0;i<im2.size();i++ )							//XNOR OPERATION between IV and intermediate value
			{
				if((im2[i]==0 && IV[i]=='1')||(im2[i]==1 &&IV[i]=='0'))
				{
					result.push_back(0);
				}
				else if((im2[i]==0 && IV[i]=='0')||(im2[i]==1 && IV[i]=='1'))
				{
					result.push_back(1);
				}
			}
			
			return result;	
			
		}
		vector <int> decryption(vector <int> ct)
		{
			vector <int> result;
			vector <int> im;
			vector <int> im2;
			for(int i=0;i<ct.size();i++ )							//XOR OPERATION between KEY and CIPHERTEXT
			{
				if((ct[i]==0 && key[i]=='1')||(ct[i]==1 &&key[i]=='0'))
				{
					im.push_back(1);
				}
				else if((ct[i]==0 && key[i]=='0')||(ct[i]==1 && key[i]=='1'))
				{
					im.push_back(0);
				}
			}
			for(int i=0;i<key.size();i++ )							//XNOR OPERATION between intermediate value and IV
			{
				if((IV[i]=='0' && im[i]==1)||(IV[i]=='1' &&im[i]==0))
				{
					im2.push_back(0);
				}
				else if((IV[i]=='0' && im[i]==0)||(IV[i]=='1' && im[i]==1))
				{
					im2.push_back(1);
				}
			}
			for(int i=0;i<im2.size();i++ )							//XOR OPERATION between IV and intermediate value
			{
				if((im2[i]==0 && IV[i]=='1')||(im2[i]==1 &&IV[i]=='0'))
				{
					result.push_back(1);
				}
				else if((im2[i]==0 && IV[i]=='0')||(im2[i]==1 && IV[i]=='1'))
				{
					result.push_back(0);
				}
			}
			
			return result;	
			
			
			
		}
		
		
	
		
};

int main()
{
	string plaintext;
	cout<<"...............encryption and decryption using my own logic circuit............"<<endl;
	
		mylogicckt c1;
	
			vector <int> ciphertext;
			cout<<"enter the plain text(of 1 byte size):"<<flush;
			cin>>plaintext;
			cout<<"performing encryption................."<<endl;
			ciphertext=c1.encryption(plaintext);
			cout<<"the ciphertext is:";
			for(int i=0;i<ciphertext.size();i++)
			{
				cout<<ciphertext[i];
				
			}
			cout<<endl;
		
		
		cout<<"performing decryption................."<<endl;
			vector <int> plaintext1;
			plaintext1=c1.decryption(ciphertext);
			cout<<"the plaintext is:";
			for(int i=0;i<plaintext1.size();i++)
			cout<<plaintext1[i];
			cout<<endl;
		
		
	return 0;
	
}
