#include <iostream>
#include <cstdlib>
using namespace std;

class Person
{
protected:
    string name;
    char gender;
    string contactNumber;

public:
    Person() {}
    Person(string name, char gender, string contactNumber)
    {
        this->name = name;
        this->gender = gender;
        this->contactNumber = contactNumber;
    }
};

class passGenerator : public Person
{
    int passLength;
    int numSpecialCharacters;
    int numbers;
    string specialChars;

public:
    passGenerator(string name, char gender, string contactNumber) : Person(name, gender, contactNumber)
    {
        specialChars = "#$%&()*+,-./:;<=>?@[_{|}`~";
    }

    string securePassGenerator()
    {
        string password = "";
        srand(time(NULL));
        int randomNumber = (rand() % name.length());

        for (int i = 0; i < (passLength - (numSpecialCharacters + numbers)); i++)
        {
            password += name[randomNumber];
            randomNumber = (rand() % (name.length()));
        }

        randomNumber = (rand() % contactNumber.length());
        for (int i = 0; i < numbers; i++)
        {
            password += contactNumber[randomNumber];
            randomNumber = (rand() % contactNumber.length());
        }

        randomNumber = (rand() % specialChars.length());
        for (int i = 0; i < numSpecialCharacters; i++)
        {
            password += specialChars[i];
            randomNumber = (rand() % specialChars.length());
        }

        return password;
    }

    inline void Display()
    {
        cout << "What's the minimum length? ";
        cin >> passLength;

        cout << "How many special Characters? ";
        cin >> numSpecialCharacters;

        cout << "How many numbers? ";
        cin >> numbers;

        cout << "Your Password is: " << securePassGenerator() << endl;
    }
};

int main()
{
    string name;
    string number;

    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter Number: ";
    cin >> number;
    cout << endl;

    passGenerator myPass(name, 'M', number);
    myPass.Display();

    return 0;
}