#include <iostream>
#include <string>
#include <vector>       // predstavlja nize, ki se lahko spremenijo v velikosti
#include <algorithm>     // zbirka algoritmicnih operacij
#include <cctype>     // niz funkcij za razvrscanje in preoblikovanje posameznih znakov 

using namespace std;

int main()
{
 
    const int NAJVEC_POSKUSOV = 3;     // stevilo poskusov

    vector<string> besede; 
    besede.push_back("JUHA");                    // skrivna beseda,  push.back doda nov element k prejsnemo vedno ko je prejsnji prebran
    besede.push_back("KNJIGA");                    //  skrivna beseda 
    besede.push_back("AKCIJA");              // skrivna beseda

    srand(static_cast<unsigned int>(time(0)));     // ta funkcija nakljucno izbere besedo iz seznama skrivnih besed
    random_shuffle(besede.begin(), besede.end());       // random shuffle zamenja vrednost vsakega elementa z vrednostjo drugega nakljucno izbranega elementa. Ko je element dolocen, funkcijski gen doloci, kateri element je izbran v vsakem primeru.  Zaradi tega program ve ce je vpisana crka v besedi.  
    const string B_BESEDA = besede[0];            
    int napacno = 0;                               
    string doZdaj(B_BESEDA.size(), '-');      // pokaze koliko crk v besedi smo ugotovili zaenkrat     - so prazna polja
    string uporabljeno = "";                  // kaj smo vpisali                  

    cout << "\t\t\tZacnite izbirati crke";               // navodila za igro
	cout<<"\n\t\t\t**********************\n\n";          
	cout<<"Imate " <<(NAJVEC_POSKUSOV - napacno)<< " poskusov";        // pokaze koliko poskusov imamo


    while ((napacno < NAJVEC_POSKUSOV) && (doZdaj != B_BESEDA))
    {
        cout << "\nVpisali ste:\n" << uporabljeno << endl;
        cout << "Do zdaj imamo: " << doZdaj << endl;

        char vpis;
        cout << "\n\nVpisite crko: ";
        cin >> vpis;
        vpis = toupper(vpis); // naredi velike crke kljub temu ce vpisujemo male

        while (uporabljeno.find(vpis) != string::npos)
        {
            cout << "\nZe ste vpisali " << vpis << endl;
            cout << "Vpisite crko: ";
            cin >> vpis;
            vpis = toupper(vpis);
        }

        uporabljeno += vpis;

        if (B_BESEDA.find(vpis) != string::npos)
        {
            cout << "Pravilno " << vpis << " je v besedi\n";
            for (unsigned int i = 0; i < B_BESEDA.length(); ++i)
			{
                if (B_BESEDA[i] == vpis)
				{
                    doZdaj[i] = vpis;
				}
			}
        }
        else
        {
			++napacno;
            cout << "Narobe, " << vpis << " ni v besedi\n";
			cout<<"Imate se " <<(NAJVEC_POSKUSOV - napacno)<< " poskusov\n";
     
        }
    }
    if (napacno == NAJVEC_POSKUSOV)
	{
        cout << "Izgubili ste !";
		
	}
    else
	{
        cout << "Cestitamo ! Nasli ste skrivno besedo";
	}
    
    return 0;
}
