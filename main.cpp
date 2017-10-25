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
bool isTorchDropped;
bool isTorchTaken;
bool isFlashlightOn;

void moveCharacter(string direction)
{
    cout << "Poruszasz sie w " << direction << endl;
    displayCLI();
}

void displayCLI()
{
    cout << endl << playerNickname << ">>";
    string CLICommand;
    getline(cin, CLICommand);
    handleCLICommand(CLICommand);
}

void handleCLICommand(string commandFromCLI)
{
    if (commandFromCLI == "wyczysc ekran")
    {
            system("clear");
            cout << "Ekran wyczyszczony";
    }
    else if (commandFromCLI == "zakoncz gre")
    {
            cout << "Do widzenia!" << endl;
            exit(0);
    }
    else if (commandFromCLI == "co trzymam w lewej rece?")
    {
            cout << "W lewej rece trzymasz: " << leftHandItem;
    }
    else if (commandFromCLI == "co trzymam w prawej rece?")
    {
            cout << "W prawej rece trzymasz: " << rightHandItem;
    }
    else if (commandFromCLI == "wyrzuc z lewej reki")
    {
            cout << "Z lewej reki wyrzucasz: " << leftHandItem;
            if (leftHandItem == "latarka")
            {
                isTorchDropped = true;
            }
            leftHandItem = "pustka";
    }
    else if (commandFromCLI == "wyrzuc z prawej reki")
    {
            cout << "Z prawej reki wyrzucasz: " << rightHandItem;
            if (rightHandItem == "latarka")
            {
                isTorchDropped = true;
            }
            rightHandItem = "pustka";
    }
    else if (commandFromCLI == "uciekaj!")
    {
        cout << "Uciekasz!";
        place = "dwor";
        nearPlace = "pustka";
    }
    else if (commandFromCLI == "wejdz")
    {
            if (nearPlace == "ciemnosc" && !isFlashlightOn)
            {
                cout << "Widzisz tylko ciemnosc, nie mozesz nigdzie wejsc.";
            }
            else if (nearPlace == "ciemnosc" && isFlashlightOn)
            {
                nearPlace = "sciana";
                place = "pokoj za drewnianymi drzwiami";
                cout << "Wchodzisz do: " << place;
            }
            else if (nearPlace == "pustka")
            {
                cout << "Nic nie widzisz, nie mozesz nigdzie wejsc.";
            }
            else if (nearPlace == "sciana")
            {
                cout << "Nie wejdziesz przeciez w sciane...";
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
    else if (commandFromCLI == "wyjdz")
    {
        if (nearPlace == "ciemnosc")
        {
            cout << "Nie wyjdziesz stad, widzisz tylko ciemnosc...";
        }
        else if (nearPlace == "pustka")
        {
            cout << "Nic nie widzisz, nie mozesz wyjsc!";
        }
        else if (place == "kuchnia")
        {
            nearPlace = place;
            place = "dom";
            cout << "Wyszedles do: " << place;
        }
        else if (place == "dom")
        {
            nearPlace = place;
            place = "dwor";
            cout << "Wyszedles do: " << place;
        }
        else if (place == "pokoj za drewnianymi drzwiami")
        {
            nearPlace = "ciemnosc";
            place = "tajemniczy pokoj";
            cout << "Wyszedles do: " << place;
        }
        else if (place == "dwor")
        {
            cout << "Jak niby chcesz wyjsc z dworu?";
        }
    }
    else if (commandFromCLI == "gdzie jestem?")
    {
            cout << "Jestes w: " << place;
    }
    else if (commandFromCLI == "rozejrzyj sie")
    {
            cout << "W okolicy widzisz: " << nearPlace;
            if (nearPlace == "ciemnosc" && isFlashlightOn)
            {
                cout << endl << "Dostrzegasz jednak, tam gdzie skierowales latarke, drewniane drzwi.";
            }
    }
    else if (commandFromCLI == "poszukaj przedmiotow")
    {
        if (place == "pokoj za drewnianymi drzwiami")
        {
            cout << "Widzisz przedmiot: stara skrzynia zamknieta na klucz";
        }
        else if (place == "kuchnia")
        {
            cout << "Widzisz przedmiot: latarka";
        }
        else
        {
            cout << "Nie widzisz zadnych przedmiotow.";
        }
    }
    else if (commandFromCLI == "uzyj lewej reki")
    {
        if (leftHandItem == "mlotek")
        {
            if (place == "tajemniczy pokoj")
            {
                cout << "Wybiles szybe mlotkiem, wydostales sie z pokoju.";
                place = "dwor";
                nearPlace = "dom";
            }
            else if (place == "pokoj za drewnianymi drzwiami")
            {
                if (isFlashlightOn)
                {
                    cout << "******************************" << endl;
                    cout << "Rozwaliles skrzynie mlotkiem." << endl;
                    cout << "W niej znalazles klucz." << endl;
                    cout << "Brawo, " << playerNickname << "! PRZESZEDLES GRE!" << endl;
                    cout << "******************************" << endl;
                }
                else
                {
                    leftHandItem = "pustka";
                    cout << "Nic nie widzisz, dlatego trafiles mlotkiem w podloge.";
                }
            }
            else
            {
                cout << "To, co masz w tej rece, nie pomoze ci teraz!";
            }
        }
        else if (leftHandItem == "latarka")
        {
            isFlashlightOn = true;
            cout << "Wlaczasz latarke.";
        }
        else if (leftHandItem == "pustka")
        {
            cout << "Nic nie masz w tej rece.";
        }
        else
        {
            cout << "To, co masz w tej rece, nie pomoze ci teraz!";
        }
    }
    else if (commandFromCLI == "uzyj prawej reki")
    {
        if (rightHandItem == "pluszowy pingwin")
        {
            cout << "Ten pingwin do niczego ci sie nie przyda.";
        }
        else if (rightHandItem == "latarka")
        {
            if (isFlashlightOn)
            {
                isFlashlightOn = false;
                cout << "Wylaczasz latarke.";
            }
            else
            {
                isFlashlightOn = true;
                cout << "Wlaczasz latarke.";
            }
        }
        else if (rightHandItem == "pustka")
        {
            cout << "Nic nie masz w tej rece.";
        }
        else
        {
            cout << "To, co masz w tej rece, nie pomoze ci teraz!";
        }
    }
    else if (commandFromCLI == "podnies lewa reka")
    {
        if (place == "kuchnia" && !isTorchDropped && !isTorchTaken && leftHandItem == "pustka")
        {
            leftHandItem = "latarka";
            isTorchTaken = true;
            cout << "Podniosles: latarka.";
        }
        else
        {
            cout << "Nie mozna podniesc. Czy reka jest pusta? Czy jest co podniesc?";
        }
    }
    else if (commandFromCLI == "podnies prawa reka")
    {
        if (place == "kuchnia" && !isTorchDropped && !isTorchTaken && rightHandItem == "pustka")
        {
            rightHandItem = "latarka";
            isTorchTaken = true;
            cout << "Podniosles: latarka.";
        }
        else
        {
            cout << "Nie mozna podniesc. Czy reka jest pusta? Czy jest co podniesc?";
        }
    }
    else if (commandFromCLI == "zmien nick")
    {
            cout << "Wybierz nowy nick: " << endl;
            getline(cin, playerNickname);
            cout << "Nowy nick: " << playerNickname;
    }
    else if (commandFromCLI == "wskazowka")
    {
        if (place == "dwor")
        {
            cout << "Wpisz 'wejdz', aby wejsc do domu.";
        }
        else if (place == "dom")
        {
            cout << "Musisz gdzies wejsc.";
        }
        else if (place == "tajemniczy pokoj")
        {
            cout << "Rozjasnij sobie teren.";
        }
        else
        {
            cout << "Rozgladaj sie, szukaj przedmiotow...";
        }
    }
    else if (commandFromCLI == "najlepszy system")
    {
            cout << "pluszowy pingwin";
    }
    else if (commandFromCLI == "polecenia")
    {
            cout << "Polecenia:" << endl;
            cout << "wyczysc ekran, zakoncz gre, co trzymam w lewej rece?" << endl;
            cout << "co trzymam w prawej rece?, wyrzuc z lewej reki, wyrzuc z prawej reki" << endl;
            cout << "uciekaj!, wejdz, gdzie jestem?" << endl;
            cout << "rozejrzyj sie, poszukaj przedmiotow, uzyj lewej reki, uzyj prawej reki" << endl;
            cout << "podnies lewa reka, podnies prawa reka, zmien nick" << endl;
            cout << "wskazowka, polecenia";
    }
    else
    {
        cout << "Nieznane polecenie. Aby zobaczyc liste polecen, wpisz 'polecenia'.";
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
    isTorchDropped = false;
    isTorchTaken = false;
    cout << "Witaj, " << playerNickname << + ", milej gry!" << endl;
    cout << "Aby zapoznac sie z poleceniami, wpisz 'polecenia'." << endl;
    cout << "Widzisz przed soba dom. Jest noc. Jestes na dworzu." << endl;
    cout << "Musisz znalezc klucz." << endl;
    cout << "Wskazowka: Wpisz 'wejdz', aby wejsc do domu." << endl;
    cout << "Wiecej wskazowek w poleceniu 'wskazowka'.";
    displayCLI();
}

int main()
{
    cout << ">>>><Best><Story><Ever><<<<" << endl;
    cout << "Wpisz swoj nick:" << endl;
    getline(cin, playerNickname);
    startGame();
    return 0;
}
