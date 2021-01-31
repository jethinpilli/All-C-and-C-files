#include <iostream>
#include <string>
#include <vector>

using namespace std;

class countermode
{
	private:
		int IV;
		string key;
		
	public:
		countermode()
		{
									
			key="11001100";
		}
		vector <int> encryption(string pt,int ptno)			//ptno=plaintext number
		{
			IV=255;
			int counter[8];
			vector <int> result;
			vector <int> im;
			IV=IV+ptno;
			
			int i=7;
			while(i>=0)
			{
				if(IV/2!=0)
				{
				
				counter[i]=IV%2;
				IV=IV/2;
				}
				else{
				
				counter[i]=IV%2;
				}
				
				i--;
			}
			
			
			for( i=0;i<key.size();i++ )							//XNOR OPERATION
			{
				if((key[i]=='0' && counter[i]==1)||(key[i]=='1' && counter[i]==0))
				{
					im.push_back(0);
				}
				else if((key[i]=='0' && counter[i]==0)||(key[i]=='1' && counter[i]==1))
				{
					im.push_back(1);
				}
			}
			
			
		
			for( i=0;i<pt.size();i++ )							//XOR OPERATION
			{
				if(im[i]==0 &&pt[i]=='1'||im[i]==1 &&pt[i]=='0')
				{
					result.push_back(1);
				}
				else if(im[i]==0 &&pt[i]=='0'||im[i]==1 &&pt[i]=='1')
				{
					result.push_back(0);
				}
			}
			
			return result;	
		}
			
			
		
		vector <int> decryption(vector <int> ct,int j)
		{
			IV=255;
			int counter[8];vector <int> result;vector <int> im;
			IV=IV+j;
			int i=7;
			while(i>=0)
			{
				if(IV/2!=0)
				{
				
				counter[i]=IV%2;
				IV=IV/2;
				}
				else
				counter[i]=IV%2;
				
				i--;
			}
			
		
			for( i=0;i<key.size();i++ )							//XNOR OPERATION
			{
				if((key[i]=='0' && counter[i]==1)||(key[i]=='1' && counter[i]==0))
				{
					im.push_back(0);
				}
				else if((key[i]=='0' && counter[i]==0)||(key[i]=='1' && counter[i]==1))
				{
					im.push_back(1);
				}
			}
			i=0;
			for(int k=8*j;i<im.size()&&k<=(j*8)+7;k++ )							//XOR OPERATION
			{
				if(im[i]==0 &&ct[k]==1||im[i]==1 &&ct[k]==0)
				{
					result.push_back(1);//cout<<result[i];
				}
				else if(im[i]==0 &&ct[k]==0||im[i]==1 &&ct[k]==1)
				{
					result.push_back(0);//cout<<result[i];
				}
				i++;
			}
			return result;
			
		}
		
		
	
		
};

int main()
{

	int nofpt=0;
	cout<<"...............counter mode encryption and decryption............"<<endl;
	
		countermode c1;
		//encryption
		cout<<"enter the no of plain texts:"<<flush;
		cin>>nofpt;
		vector <int> allciphertext;
		
		//encryption
		for(int i=0;i<nofpt;i++)
		{
			string plaintext;
			vector <int> ciphertext;
			cout<<"enter the plain text"<<i<<"(of 1 byte size):"<<flush;
			cin>>plaintext;
			cout<<"performing encryption................."<<endl;
			ciphertext=c1.encryption(plaintext,i);
			cout<<"the ciphertext"<<i<<" is:";
			for(int i=0;i<ciphertext.size();i++)
			{
				cout<<ciphertext[i];
				allciphertext.push_back(ciphertext[i]);
			}
			cout<<endl;
		}
		
		
		cout<<"performing decryption................."<<endl;
		for(int i=0;i<nofpt;i++)
		{
		
			vector <int> plaintext1;
			
			plaintext1=c1.decryption(allciphertext,i);
			cout<<"the plaintext"<<i<<" is:";
			for(int i=0;i<plaintext1.size();i++)
			cout<<plaintext1[i];
			cout<<endl;
		}	
		
		
		
	
	
	return 0;
	
}
