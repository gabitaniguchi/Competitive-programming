#include <bits/stdc++.h>

using namespace std;

int main()
{
  string emoticon;
  int diver = 0, chat = 0;
    
  while(cin>>emoticon)
  {
    int tam = (int)emoticon.size();
    if(tam < 3) continue;
      for( int i=0; i<(tam-2);i++)
      {
         if(emoticon[i] == ':'&& emoticon[i+1] == '-' && emoticon[i+2] == ')') 
         {
           diver ++;
         }
      else if(emoticon[i] == ':' && emoticon[i+1] == '-' && emoticon[i+2] == '(') 
         {
          chat ++;
          }
       }
   }
    
    if(diver == chat) printf("neutro\n");
    
    else if (diver > chat) printf("divertido\n");
    
    else printf("chateado\n");
    
    return 0;
}