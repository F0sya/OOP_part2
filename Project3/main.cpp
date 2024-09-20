#include <iostream>
#include <string>
using namespace std;

struct GameTime
{
    int hours;
    int minutes;
    int seconds;
};

struct Price
{
    int value_1; //ex: dollars
    int value_2; //ex: cents
    string currency_symbol_v1; //ex: $
    string currency_symbol_v2; //ex: c.
    Price()
    {
        value_1 = 0;
        value_2 = 0;
    }
    Price(int v1, int v2)
    {
        value_1 = v1;
        value_2 = v2;
        currency_symbol_v1 = '$';
    }
};

enum Platform
{
    Windows,
    MacOS,
    Linux
};

class Game
{
private:
    string _name;
    string _genre;
    Platform _platform;
    GameTime _timePlayed;
    string _author;
    Price _price;
public:
    Game()
    {
        _name = "";
        _genre = "";
        _platform = Windows;
        _timePlayed.hours = 0;
        _timePlayed.minutes = 0;
        _timePlayed.seconds = 0;
        _author = "";
        _price.value_1 = 0;
        _price.value_2 = 0;
        _price.currency_symbol_v1 = "";
        _price.currency_symbol_v2 = "";
    }
    Game(string name, string genre, Platform platform, GameTime timePlayed, string author, Price price)
    {
        _name = name;
        _genre = genre;
        _platform = platform;
        _timePlayed = timePlayed;
        _author = author;
        _price = price;
    }
    string GetName()
    {
        return _name;
    }
    string GetGenre()
    {
        return _genre;
    }
    Platform GetPlatform()
    {
        return _platform;
    }
    GameTime GetTimePlayed()
    {
        return _timePlayed;
    }
    string GetAuthor()
    {
        return _author;
    }
    Price GetPrice()
    {
        return _price;
    }
    void SetName(string name)
    {
        _name = name;
    }
    void SetGenre(string genre)
    {
        _genre = genre;
    }
    void SetPlatform(Platform platform)
    {
        _platform = platform;
    }
    void SetTimePlayed(GameTime timePlayed)
    {
        _timePlayed = timePlayed;
    }
    void SetAuthor(string author)
    {
        _author = author;
    }
    void SetPrice(Price price)
    {
        _price = price;
    }
    void PrintInfo()
    {
        cout << "Name: " << _name << endl;
        cout << "Genre: " << _genre << endl;
        cout << "Platform: ";
        switch (_platform)
        {
        case Windows:
            cout << "Windows" << endl;
            break;
        case MacOS:
            cout << "MacOS" << endl;
            break;
        case Linux:
            cout << "Linux" << endl;
            break;
        }
        cout << "Time Played: " << _timePlayed.hours << "h " << _timePlayed.minutes << "m " << _timePlayed.seconds << "s" << endl;
        cout << "Author: " << _author << endl;
        cout << "Price: " << _price.currency_symbol_v1 << _price.value_1 << "." << _price.value_2 << _price.currency_symbol_v2 << endl;
    }
    void EditGame()
    {
        int choice;
        cout << "Select field to edit: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Genre" << endl;
        cout << "3. Platform" << endl;
        cout << "4. Time Played" << endl;
        cout << "5. Author" << endl;
        cout << "6. Price" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: {
            string name;
            cout << "Enter new name: ";
            getline(cin, name);
            SetName(name);
            break;
        }
        case 2: {
            string genre;
            cout << "Enter new genre: ";
            getline(cin, genre);
            SetGenre(genre);
            break;
        }
        case 3: {
            int platform;
            cout << "Select new platform (0 - Windows, 1 - MacOS, 2 - Linux): ";
            cin >> platform;
            SetPlatform(static_cast<Platform>(platform));
            break;
        }
        case 4: {
            GameTime timePlayed;
            cout << "Enter new time played (hours minutes seconds): ";
            cin >> timePlayed.hours >> timePlayed.minutes >> timePlayed.seconds;
            SetTimePlayed(timePlayed);
            break;
        }
        case 5: {
            string author;
            cout << "Enter new author: ";
            cin.ignore();
            getline(cin, author);
            SetAuthor(author);
            break;
        }
        case 6: {
            Price price;
            cout << "Enter new price (dollars and cents): ";
            cin >> price.value_1 >> price.value_2;
            SetPrice(price);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }
};

class Steam
{
private:
    Game* _games;
    int _gamesCount;
public:
    Steam()
    {
        _games = nullptr;
        _gamesCount = 0;
    }
    Steam(Game* games, int gamesCount)
    {
        _games = games;
        _gamesCount = gamesCount;
    }

    Game& GetGame(int index)
    {
        if (index >= 0 && index < _gamesCount)
        {
            return _games[index];
        }
    }

    int GetGamesCount(){
        return _gamesCount;
    }
    void AddGame(Game game)
    {
        Game* newGames = new Game[_gamesCount + 1];
        for (int i = 0; i < _gamesCount; i++)
        {
            newGames[i] = _games[i];
        }
        newGames[_gamesCount] = game;
        _gamesCount++;
        delete[] _games;
        _games = newGames;
    }

    void RemoveGamebyName(string target) {
        Game* newGames = new Game[_gamesCount - 1];
        int index = -1;
        for (int i = 0; i < _gamesCount; i++) {
            if (_games[i].GetName() == target) {
                index = i;
            }
        }
        if (index != -1) {
            for (int i = 0; i < index; i++)
            {
                newGames[i] = _games[i];
            }
            for (int i = index + 1; i < _gamesCount; i++)
            {
                newGames[i - 1] = _games[i];
            }
            _gamesCount--;
            delete[] _games;
            _games = newGames;
        }
        else {
            cout << "No occurencies" << endl;
        }

    }
    void RemoveGame(int index)
    {
        Game* newGames = new Game[_gamesCount - 1];
        for (int i = 0; i < index; i++)
        {
            newGames[i] = _games[i];
        }
        for (int i = index + 1; i < _gamesCount; i++)
        {
            newGames[i - 1] = _games[i];
        }
        _gamesCount--;
        delete[] _games;
        _games = newGames;
    }

    void FindGamebyName(string target){
        cout << "-----------------------------" << endl;
        cout << "Result:" << endl;
        for (int i = 0; i < _gamesCount; i++) {
            if (_games[i].GetName() == target) {
                _games[i].PrintInfo();
                cout << endl;
            }
        }

    }
    void FindGamebyAuthor(string target) {
        cout << "-----------------------------" << endl;
        cout << "Result:" << endl;
        for (int i = 0; i < _gamesCount; i++) {
            if (_games[i].GetAuthor() == target) {
                _games[i].PrintInfo();
                cout << endl;
            }
        }
    }
    void FindGamebyCurrency(string target) {
        cout << "-----------------------------" << endl;
        cout << "Result:" << endl;
        for (int i = 0; i < _gamesCount; i++) {
            if (_games[i].GetPrice().currency_symbol_v1 == target) {
                _games[i].PrintInfo();
                cout << endl;
            }
        }
    }
    void PrintGames()
    {
        for (int i = 0; i < _gamesCount; i++)
        {
            cout << "Game " << i + 1 << ":" << endl;
            _games[i].PrintInfo();
            cout << endl;
        }
    }
    void DeleteGameByName(string name) {
        for (int i = 0; i < _gamesCount; i++) {
            if (_games[i].GetName() == name) {
                RemoveGame(i);
                break;
            }
        }
    }
};


int main() {
    int choice;
    Steam steam;
    Game game1("CS:GO", "Genre1", Windows, { 1, 2, 3 }, "Author1", { 10, 50 });
    Game game2("CS2", "Genre2", MacOS, { 4, 5, 6 }, "Author1", { 20, 60 });
    Game game3("The Witcher 3", "Genre3", Linux, { 7, 8, 9 }, "Author3", { 30, 70 });
    steam.AddGame(game1);
    steam.AddGame(game2);
    steam.AddGame(game3);
    steam.PrintGames();
    

    while (true) {
        cout << "1.Show the list of games" << endl;
        cout << "2.Add game to list" << endl;
        cout << "3.Edit game from list" << endl;
        cout << "4.Delete game" << endl;
        cout << "5.Search game" << endl;
        cout << "6.Exit" << endl;
        cout << "--------------------------" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1: 
            steam.PrintGames();
            break;
        case 2: {
            string name, genre, author;
            int platform, hours = 0, minutes = 0, seconds = 0, price_main, price_secondary;
            cout << "Enter a game name:" << endl;
            getline(cin, name);
            cout << "Enter a game genre:" << endl;
            getline(cin, genre);
            cout << "Enter a game author:" << endl;
            getline(cin, author);
            cout << "Enter platform (0 - Windows, 1 - MacOS, 2 - Linux): " << endl;
            cin >> platform;
            cout << "Enter price (dollars and cents): " << endl;
            cin >> price_main >> price_secondary;
            Game newGame(name, genre, static_cast<Platform>(platform), { hours, minutes, seconds }, author, { price_main, price_secondary });
            steam.AddGame(newGame);
            break;
        }
        case 3: {
            string name;
            cout << "Enter game name to edit: ";
            getline(cin, name);
            steam.FindGamebyName(name);
            bool found = false;
            for (int i = 0; i < steam.GetGamesCount(); i++) {
                if (steam.GetGame(i).GetName() == name) {
                    steam.GetGame(i).EditGame();
                    found = true;
                    break;
                }
            }
            if (found == false) {
                cout << "Game with name \"" << name << "\" not found." << endl;
            }
            break;
        }
        case 4: {
            string deletename;
            cout << "Enter game name to delete: ";
            getline(cin, deletename);
            steam.DeleteGameByName(deletename);
            break;
        }
        case 5: {
            string searchName;
            cout << "Enter game name to search: ";
            getline(cin, searchName);
            steam.FindGamebyName(searchName);
            break;
        }
        case 6:
            exit(0);
        default:
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}