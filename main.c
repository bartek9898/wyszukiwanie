#include <stdio.h>
#include <stdlib.h>

int liniowe(int n ,int tab[] ,int szukana)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(tab[i]==szukana)
        {
           return i;
        }
    }
}

int bisekcyjne(int n ,int tab[] ,int szukana)
{
    int l=0, p=n-1 ,s ,bisekcyjne;
    while(l<p)
    {
        s=(l+p)/2;
        if(szukana>tab[s])
        {
            l=s+1;
        }else p=s;
    }
    if(szukana=tab[p])
    {
        bisekcyjne=p;
    }else bisekcyjne=0;
    return bisekcyjne;
}

int rekurencyjne(int szukana, int l, int p, int tab[])
{
   int s;
   if(l==p)
   {
       if(szukana=tab[p])
       {
           return p;
       }else return 0;
   }
   else
   {
    s=(l+p)/2;
   if(szukana>tab[s])
   {
       return rekurencyjne(szukana,s+1,p,tab);
   }else return rekurencyjne(szukana,l,s,tab);
   }
}

int wczytaj(int n, int tab[] ,int szukana)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Podaj %d element",i+1);
        scanf("%d",&tab[i]);
    }
    printf("Podaj wartosc ktora chcesz wyszukac ");
    scanf("%d",&szukana);
    return szukana;
}

int main()
{
    int n;
    do
    {
        printf("Podaj ilosc elementow: ");
        scanf("%d",&n);
    }while(n<=0);

    int tab[n];

    int szukana;
    szukana=wczytaj(n,tab,szukana);

    int indeksszukana;

    indeksszukana=liniowe(n,tab,szukana);
    printf("szukana wartosc to %d (liniowe)\n",tab[indeksszukana]);
    indeksszukana=bisekcyjne(n,tab,szukana);
    printf("szukana wartosc to %d (bisekcyjne)\n",tab[indeksszukana]);

    int l=1;
    int p=n-1;

    indeksszukana=rekurencyjne(szukana,l,p,tab);

    printf("szukana wartosc to %d (rekurencyjne)\n",tab[indeksszukana]);

    return 0;
}
