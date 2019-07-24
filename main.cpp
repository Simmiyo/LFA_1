#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct tranzitie{int s1;int s2;char litera;};

bool verificare(int q0,int &nr_tranzitii,tranzitie T[],int card_F,int F[],string cuvant)
{
    if(cuvant.length()==0)
    {
        for(int i=1;i<=card_F;i++)
            if(q0==F[i])
                return 1;
        return 0;
    }
    else{
        string lp = cuvant;
        for(int i=1;i<=nr_tranzitii;i++)
            if(T[i].s1==q0 && T[i].litera==cuvant[0])
                if(verificare(T[i].s2,nr_tranzitii,T,card_F,F,lp.erase(0,1)))
                    return 1;
                 else lp = cuvant;
        return 0;
    }
}

int main()
{
    ifstream f("date");
    int card_Q, q0, card_F, nr_tranzitii;
    f>>card_Q;
    f>>q0;
    f>>card_F;
    int F[card_F];
    for(int i=1;i<=card_F;i++)
        f>>F[i];
    f>>nr_tranzitii;
    tranzitie T[nr_tranzitii];
    for(int i=1;i<=nr_tranzitii;i++)
    {
        f>>T[i].s1;
        f>>T[i].s2;
        f>>T[i].litera;
    }
    string cuvant;
    f>>cuvant;

    if(verificare(q0,nr_tranzitii,T,card_F,F,cuvant))
        cout<<"Cuvantul a fost acceptat.";
    else cout<<"Cuvantul NU a fost acceptat.";
    return 0;
}
