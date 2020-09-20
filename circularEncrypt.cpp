#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <vector>

using namespace std;

string decrypt(string encrypted, int k){
    for (int i=0; i<encrypted.size();i++){
      char replacement = encrypted[i]-k;
      if (replacement>='A' and replacement<='Z'){
          encrypted[i]=replacement;
      }else if(replacement<'A'){
          replacement = 'Z'-('A'-replacement-1)%26; 
          encrypted[i]=replacement; 
      }
    } 
    return encrypted;
}
int main()
{
  time_t now = time(0);
  char* dt = ctime(&now);
  vector<string> ciphers;
  vector<int> shifts;
  int n;
  cout<<"ENTER NUMBER OF STRINGS YOU WANT TO ENCRYPT: "<<endl;
  cin>>n;
  for (int i=0;i<n;i++){
    string cipher;
    int shift;
    if(i==0){
      cout<<"ENTER FIRST STRING TO ENCRYPT(Aa-Zz ONLY): "<<endl;
    }
    else if(i==n-1){
       cout<<"ENTER FINAL STRING TO ENCRYPT(Aa-Zz ONLY): "<<endl;
    }else {
      cout<<"ENTER NEXT STRING TO ENCRYPT(Aa-Zz ONLY): "<<endl;
    }
    cin>>cipher;
    for(size_t i = 0; i < cipher.size(); i++){
        cipher[i] = toupper(cipher[i]);
        }
    ciphers.push_back(cipher);
    cout<<"ENTER LEFT SHIFT FACTOR(0-99999999 ONLY): "<<endl;
    cin>>shift;
    shifts.push_back(shift);  
  }
 
  for (int j=0;j<n;j++){
    string s = ciphers[j];
    int x = shifts[j];
   cout<<s<<" was encrypted to "<<decrypt(s,x)<<" after "<<x<<" shift(s) to the left"<<endl; 
  }
  cout<<" "<<endl;
  cout<<"anesum165_projects, © "<<dt<<endl;
  return 0;
}
