#include <iostream>
#include <cstdlib>

using namespace std;
string playerNickname;
void displayCLI();
void handleCLICommand(string commandFromCLI);
string leftHandItem;
string rightHandItem;
string place;
string nearPlace;

void moveCharacter(string direction)
{
    cout << "Poruszasz się w " << direction << endl;
    displayCLI();
}

void displayCLI()
{
    cout << endl << playerNickname << ">>";
    string CLICommand;
    cin >> CLICommand;
    handleCLICommand(CLICommand);
}

void handleCLICommand(string commandFromCLI)
{
    if (commandFromCLI == "wyczysc_ekran")
    {
            system("clear");
            cout << "Ekran wyczyszczony";
    }
    else if (commandFromCLI == "zakoncz_gre")
    {
            cout << "Do widzenia!" << endl;
            exit(0);
    }
    else if (commandFromCLI == "lewa_reka")
    {
            cout << "W lewej ręce trzymasz: " << leftHandItem;
    }
    else if (commandFromCLI == "prawa_reka")
    {
            cout << "W prawej ręce trzymasz: " << rightHandItem;
    }
    else if (commandFromCLI == "wyrzuc_z_lewej_reki")
    {
            cout << "Z lewej ręki wyrzucasz: " << leftHandItem;
            leftHandItem = "pustka";
    }
    else if (commandFromCLI == "wyrzuc_z_prawej_reki")
    {
            cout << "Z prawej ręki wyrzucasz: " << rightHandItem;
            rightHandItem = "pustka";
    }
    else if (commandFromCLI == "uciekaj")
    {
        cout << "Uciekasz!";
        place = "dwor";
        nearPlace = "pustka";
    }
    else if (commandFromCLI == "wejdz")
    {
            if (nearPlace == "ciemnosc")
            {
                cout << "Widzisz tylko ciemnosc, nie mozesz wejsc dalej.";
            }
            if (nearPlace == "pustka")
            {
                cout << "Nie wiesz gdzie jestes, nie mozesz wejsc dalej.";
            }
            else
            {
                cout << "Wchodzisz do: " << nearPlace;
                place = nearPlace;
                if (place == "dwor")
                {
                    nearPlace = "dom";
                }
                if (place == "dom")
                {
                    nearPlace = "kuchnia";
                }
                if (place == "kuchnia")
                {
                    nearPlace = "tajemniczy pokoj";
                }
                if (place == "tajemniczy pokoj")
                {
                    nearPlace = "ciemnosc";
                }
            }
    }
    else if (commandFromCLI == "gdzie_jestem")
    {
            cout << "Jesteś w: " << place;
    }
    else if (commandFromCLI == "rozejrzyj_sie")
    {
            cout << "W okolicy widzisz: " << nearPlace;
    }
    else if (commandFromCLI == "uzyj_lewa")
    {
        if (leftHandItem == "mlotek")
        {
            if (place == "tajemniczy pokoj")
            {
                cout << "Wybiłeś szybę młotkiem, wydostałeś się z pokoju.";
                place = "dwor";
                nearPlace = "dom";
            }
            else
            {
                cout << "To, co masz w tej ręce, nie pomoże ci teraz!";
            }
        }
        else
        {
            cout << "To, co masz w tej ręce, nie pomoże ci teraz!";
        }
    }
    else if (commandFromCLI == "uzyj_prawa")
    {
        if (rightHandItem == "pluszowy pingwin")
        {
            cout << "Ten pingwin do niczego ci się nie przyda.";
        }
    }
    else if (commandFromCLI == "zmien_nick")
    {
            cout << "Wybierz nowy nick: " << endl;
            cin >> playerNickname;
            cout << "Nowy nick: " << playerNickname;
            rightHandItem = "pustka";
    }
    else if (commandFromCLI == "najlepszy_system")
    {
            cout << "Linux";
    }
    else if (commandFromCLI == "polecenia")
    {
            cout << "Polecenia:" << endl;
            cout << "wyczysc_ekran, zakoncz_gre, lewa_reka" << endl;
            cout << "prawa_reka, wyrzuc_z_lewej_reki, wyrzuc_z_prawej_reki" << endl;
            cout << "uciekaj, wejdz, gdzie_jestem" << endl;
            cout << "rozejrzyj_sie, uzyj_lewa, uzyj_prawa" << endl;
            cout << "zmien_nick, polecenia";
    }
    else
    {
        cout << "Nieznane polecenie. Aby zobaczyć listę poleceń, wpisz 'polecenia'.";
    }
    displayCLI();
}

void startGame()
{
    system("clear");
    leftHandItem = "mlotek";
    rightHandItem = "pluszowy pingwin";
    place = "dwor";
    nearPlace = "dom";
    cout << "Miłej gry!" << endl;
    cout << "Aby zapoznać się z poleceniami, wpisz 'polecenia'." << endl;
    cout << "Widzisz przed sobą: " << nearPlace << ". Jest noc. Jesteś w: " << place;
    displayCLI();
}

int main()
{
    cout << "BestStoryEver" << endl;
    cout << "Wpisz swój nick:" << endl;
    cin >> playerNickname;
    startGame();
    return 0;
}
