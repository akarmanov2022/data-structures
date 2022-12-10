//
// Created by akarmanov on 27-11-2022.
//

#include <string>
#include <iostream>

int InputInt(const char *string)
{
    std::string input;
    bool valid;
    while (true)
    {
        valid = true;
        std::cout << string;
        std::cin >> input;
        for (char c : input)
        {
            if (c < '0' || c > '9')
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            break;
        }
        std::cout << "Invalid input" << std::endl;
    }
    return std::stoi(input);
}

int main()
{

}