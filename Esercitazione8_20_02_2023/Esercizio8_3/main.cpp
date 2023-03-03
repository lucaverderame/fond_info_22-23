#include <fstream>
#include <iostream>

using namespace std;

struct dataCompleanno
{
    int giorno;
    int mese;
    int anno;
};

int main()
{
    int dim = 5;
    dataCompleanno arrayDate[dim];
    fstream fin("date.txt", ios::in);
    for(int i=0;i<dim;i++)
    {
        fin>>arrayDate[i].giorno;
        fin>>arrayDate[i].mese;
        fin>>arrayDate[i].anno;
    }
    fin.close();

    dataCompleanno oggi;
    cout<<"inserisci la data di oggi ";
    cin>>oggi.giorno>>oggi.mese>>oggi.anno;

    int maggiorenni=0;
    for(int i=0;i<dim;i++)
    {
        if(oggi.anno-arrayDate[i].anno>18)
        {
            maggiorenni++;
        }
        else
        {
            if(oggi.anno-arrayDate[i].anno==18)
            {
                if(oggi.mese-arrayDate[i].mese>0)
                {
                    maggiorenni++;
                }
                else
                {
                    if(oggi.mese-arrayDate[i].mese==0)
                    {
                        if(oggi.giorno-arrayDate[i].giorno>=0)
                        {
                            maggiorenni++;
                        }
                    }
                }
            }
        }
    }

    cout<<"ci sono "<<maggiorenni<<" maggiorenni";
}