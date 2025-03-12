#include <bits/stdc++.h>

using namespace std;

struct Renas
{
    string nome;
    int peso;
    int idade;
    float altura;
};

bool ordena (Renas a, Renas b)
{
  if (a.peso != b.peso) return a.peso>b.peso;
  else if(a.idade != b.idade) return a.idade<b.idade;
  else if(a.altura != b.altura) return a.altura<b.altura;
  else return a.nome<b.nome;
}

int main()
{
  int n;

  scanf("%d", &n);

  for(int t=1; t<=n;t++)
  {
      int total_r, r;
      scanf("%d%d", &total_r, &r);

      Renas renas[total_r+5];

      string s;
      int p,id;
      float h;

      for(int i=0;i<total_r;i++)
      {
        cin>>s;
        scanf("%d %d %f", &p, &id, &h);    

        renas[i].nome = s;
        renas[i].peso = p;
        renas[i].idade = id;
        renas[i].altura = h;
      }

      sort(renas, renas+total_r, ordena);

      printf("CENARIO {%d}\n", t);

      for(int i=0;i<r;i++)
      {
          cout<<i+1<<" - "<<renas[i].nome<<endl;
      }
  }


  return 0;
}