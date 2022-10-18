#include <iostream>
#include <string>
#include <random> // for random();
#include <windows.h> // for sleep();

using std::cout; using std::cin; using std::string; using std::getline; using std::ws; using std::to_string; using std::system; // silly

// written by chapel1337
// made on 10/18/2022
// started making the bare minimum of this program during school on paper
// made this to help a friend study
// not much else to say about this

char variable{ 'x' };

int maxNumber{ 20 };
int minNumber{ 1 };
int times{ 1 };

bool noteSent{ false };

string colorsList[]{ "black", "blue", "green", "aqua", "red", "purple", "yellow", "white", "gray", "light blue", "light green", "light aqua", "light red", "light purple", "light yellow", "bright white" };

// ------- \\

void returnTo(string returnFunction);

int getRandom(int min, int max)
{
    std::mt19937 mt{ std::random_device{}() };

    std::uniform_int_distribution random{ min, max };
    return random(mt);
}

void sleep(int time)
{
    Sleep(1000 * time);
}

void title(string title)
{
    system(("title " + title).c_str());
}

void title(string title, int time)
{
    system(("title " + title + " " + to_string(time)).c_str()); // comedic amount of parenthesis
}

void clear()
{
    system("cls");
}

void invalidInput(string message, string returnFunction)
{
    clear();
    title("algebraic order of operations problem generator - invalid input");

    cout << message << '\n';

    sleep(2);
    returnTo(returnFunction);
}

void pause()
{
    cout << "press enter to continue...\n";

    cin.get();
    cin.ignore();
}

// ------- \\

void addSpace()
{
    cout << ' ';
}

void addRandomOperator()
{
    switch (getRandom(1, 4))
    {
    case 1:
        cout << '+';
        break;

    case 2:
        cout << '-';
        break;

    case 3:
        cout << '*';
        break;

    case 4:
        cout << '/';
        break;
    }

    addSpace();
}

void randomNegative()
{
    if (getRandom(1, 3) == 1)
    {
        cout << '-';
    }
}

void addRandomNumber()
{
    switch (getRandom(1, 2))
    {
    case 1:
        randomNegative();

        cout << getRandom(1, maxNumber);
        cout << variable;
        break;

    case 2:
        randomNegative();
        cout << getRandom(1, maxNumber);
        break;
    }

    addSpace();
}

// ------- \\

void changeColor(string textColor, string backgroundColor)
{
    // string because
    // 'olor' is not recognized as an internal or external command, operable program or batch file.
    // i have no idea how this is not working, so i'll just go the more inefficient working route
    system(("color " + textColor + backgroundColor).c_str());

    clear();

    cout << "changed text color to " << textColor << '\n';
    cout << "changed background color to " <<  backgroundColor << '\n';

    sleep(2);
    returnTo("settings");
}

void listColors()
{
    for (int i{ 0 }; i <= 8; i++)
    {
        cout << colorsList[i] << " - " << i << '\n';
    }

    char character = 'a';
    for (int i{ 0 }; i <= 7; i++)
    {
        cout << colorsList[i + 8] << " - " << character << '\n';

        character++;
    }
    cout << '\n';
}

void changeColorMenu()
{
    title("algebraic order of operations problem generator - change color");
    clear();

    string response{};
    string textColor{ 0 };
    string backgroundColor{ 7 }; // preset to default text and background

    listColors();

    cout << "new text color: \n";
    cin >> textColor;

    clear();

    listColors();

    cout << "new background color: \n";
    cin >> backgroundColor;

    clear();

    cout << "are you sure you want to change the color? (y/n)\n";
    cin >> response;

    if (response == "yes" || response == "y")
    {
        changeColor(textColor, backgroundColor);
    }
    else if (response == "no" || response == "n")
    {
        returnTo("settings");
    }
    else
    {
        invalidInput("invalid input: please specify yes or no", "settings");
    }
}

// ------- \\

void changeMinMax()
{
    title("algebraic order of operations problem generator - change minimum and maximum"); // comedic
    clear();

    cout << "input a minimum number: \n";
    cin >> minNumber;

    clear();

    cout << "input a maximum number: \n";
    cin >> maxNumber;

    clear();

    cout << "input times: \n";
    cin >> times;

    clear();

    cout << "changed minimum number to: " << minNumber << '\n';
    cout << "changed maximum number to: " << maxNumber << "\n\n";
    cout << "changed times to: " << times << '\n';

    sleep(2);
    returnTo("settings");
}

void changeVariable()
{
    title("algebraic order of operations problem generator - change variable");
    clear();

    cout << "input a variable: \n";
    cin >> variable;

    clear();

    cout << "changed variable to: " << variable << '\n';
    
    sleep(2);
    returnTo("settings");
}

// ------- \\

void resetSettings()
{
    title("algebraic order of operations problem generator - reset settings");
    clear();

    system("color 07");

    maxNumber = 20;
    minNumber = 1;
    variable = 'x';

    cout << "reset the settings\n";

    sleep(2);
    returnTo("settings");
}

void settings()
{
    title("algebraic order of operations problem generator - settings");
    clear();

    char response{};

    cout << "1. change minimum/maximum number and times\n";
    cout << "2. change variable\n";
    cout << "3. change color\n";
    cout << "4. reset settings\n";
    cout << "5. back\n\n";

    cout << "> ";
    cin >> response;

    switch (response)
    {
    case '1':
        changeMinMax();
        break;

    case '2':
        changeVariable();
        break;

    case '3':
        changeColorMenu();
        break;

    case '4':
        resetSettings();
        break;

    case '5':
        returnTo("menu");
        break;

    default:
        invalidInput("invalid input: please specify 1, 2, or 3", "menu");
        break;
    }
}

// ------- \\

void start(int times)
{
    title("algebraic order of operations problem generator - results");
    clear();

    if (!noteSent)
    {
        cout << "note: you can edit the maximum number, minimum number, times, and variable in the settings\n\n";

        pause();
        clear();

        noteSent = true;
    }

    while (times > 0) // silly
    {
        times--;

        addRandomNumber();
        addRandomOperator();
        addRandomNumber();

        cout << "= ";

        addRandomNumber();
        addRandomOperator();
        addRandomNumber();

        cout << "\n\n";
    }

    pause();
    returnTo("menu");
}

// ------- \\

void quit()
{
    title("algebraic order of operations problem generator - quit");
    clear();

    for (int i{ 3 }; i >= 1; i--)
    {
        cout << "okay, exiting in " << i;
        title("algebraic order of operations problem generator - quitting in", i);

        sleep(1);
        clear();
    }

    exit(1);
}

// ------- \\

void menu()
{
    title("algebraic order of operations problem generator - menu"); // very comedic
    clear();

    char response{};

    cout << "1. start\n";
    cout << "2. settings\n";
    cout << "3. quit\n\n";

    cout << "> ";
    cin >> response;

    switch (response) 
    {
    case '1':
        start(times);
        break;

    case '2':
        settings();
        break;

    case '3':
        quit();
        break;

    default:
        invalidInput("invalid input: please specify 1, 2, or 3", "menu");
        break;
    }
}

void returnTo(string returnFunction)
{
    if (returnFunction == "menu")
    {
        menu();
    }
    else if (returnFunction == "settings")
    {
        settings();
    }
}

int main()
{
    cout << "written by chapel1337\n";
    cout << "made on 10/18/2022\n";

    // sleep(2);
	menu();
}

// ------- \\