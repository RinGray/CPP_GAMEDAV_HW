
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class gameVariable
{
    Rock = 'r',
    Paper = 'p',
    Scissor = 's',
    Zero = 0
};

int calculateResult(gameVariable enteredKey, gameVariable two, gameVariable three, gameVariable four) {
    //std::srand(std::time(nullptr));
    if (((enteredKey == two) and (enteredKey == three)) and (enteredKey == four)) {
        if (enteredKey == gameVariable::Rock) {
            std::cout << "Computer choice Paper" << std::endl;
        }
        if (enteredKey == gameVariable::Paper) {
            std::cout << "Computer choice Scissor" << std::endl;
        }
        if (enteredKey == gameVariable::Scissor) {
            std::cout << "Computer choice Rock" << std::endl;
        }
#ifdef _DEBUG
        std::cout << "!!!!!!!!!!!!!!!!!!!!! STREAK !!!!!!!!!!!!!!!!!!!!!" << std::endl;
#endif // DEBUG
        return 0;
    }
    else {
        std::srand((unsigned int)time(NULL));
        const int GeneratingRange = 3;
        const double GeneratedNum = std::rand() % GeneratingRange + 1;
#ifdef _DEBUG
        std::cout << "*** RANDOM NUMBER *** // " << GeneratedNum << " // *** RANDOM NUMBER ***" << std::endl;
#endif // DEBUG
        if (GeneratedNum == 1) {
            std::cout << "Computer choice Rock" << std::endl;
            if (enteredKey == gameVariable::Rock) {
                return 99;
            }
            else {
                if (enteredKey == gameVariable::Paper) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        else {
            if (GeneratedNum == 2) {
                std::cout << "Computer choice Paper" << std::endl;
                if (enteredKey == gameVariable::Paper) {
                    return 99;
                }
                else {
                    if (enteredKey == gameVariable::Scissor) {
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
            }
            else {
                std::cout << "Computer choice Scissor" << std::endl;
                if (enteredKey == gameVariable::Scissor) {
                    return 99;
                }
                else {
                    if (enteredKey == gameVariable::Rock) {
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
            }
        }
    }
}

int message(int r) {
    if (r == 0) {
        std::cout << "/--Computer Win--/" << std::endl;
    }
    else {
        if (r == 1) {
            std::cout << "/++You Win++/" << std::endl;
        }
        else {
            std::cout << "/..Drow../" << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}

int main()
{
    gameVariable two = gameVariable::Zero;
    gameVariable three = gameVariable::Zero;
    gameVariable four = gameVariable::Zero;
    int r=6, wins, losses, draws;
    char rounds, k;
    std::cout << "Welcom to game" << std::endl;
    while (true) {
        wins = losses = draws = 0;
        std::cout << std::endl;
        std::cout << "Enter rounds number (-1 to quit): ";
        std::cin >> rounds;
        cin.get();
        if (rounds == '-') {
            std::cout << "Exit..." << std::endl;
            break;
        }
        if (std::isalpha(rounds)) {
            std::cout << "Incorrect, enter number" << std::endl;
            continue;
        }
        else {
            if (std::isalnum(rounds)) {
                rounds = rounds - '0';
                for (int i = 0; i < rounds; i++) {
                    std::cout << std::endl;
                    std::cout << "Round number: " << i + 1 << std::endl;
                    std::cout << "Press Key:" << std::endl;
                    std::cout << "r (rock), p (paper), s (scissor): ";
                    k = getchar();
                    cin.get();
                    std::cout << std::endl;
                    gameVariable key = static_cast<gameVariable>(k);
                    switch (key)
                    {
                    case (gameVariable::Rock):
                        std::cout << "You chose Rock" << std::endl;
                        break;
                    case (gameVariable::Paper):
                        std::cout << "You chose Paper" << std::endl;
                        break;
                    case (gameVariable::Scissor):
                        std::cout << "You chose Scissor" << std::endl;
                        break;
                    default:
                        std::cout << "You do not choose,  round lost" << std::endl;
                        std::cout << std::endl;
                        losses++;
                        continue;
                    }
                    r = calculateResult(key, two, three, four);
                    message(r);
                    switch (r) {
                    case (0):
                        losses++;
                        break;
                    case (1):
                        wins++;
                        break;
                    case (99):
                        draws++;
                    }
                    four = three;
                    three = two;
                    two = key;
#ifdef _DEBUG
                    std::cout << " ++++++++R++++++++: " << r << std::endl;
                    std::cout << "two: " << static_cast<char>(two) << std::endl;
                    std::cout << "three: " << static_cast<char>(three) << std::endl;
#endif // DEBUG
                }
                std::cout << "wins: " << wins << std::endl;
                std::cout << "losses: " << losses << std::endl;
                std::cout << "draws: " << draws << std::endl;
                if ((wins > losses) and (wins > draws)) {
                    std::cout << " + + + You're better + + +" << std::endl;
                }
                else {
                    if ((losses > wins) and (losses > draws)) {
                        std::cout  << " ! ! ! Computer better ! ! !" << std::endl;
                    }
                    else {
                        std::cout  << "/ / / draw with computer / / /" << std::endl;
                    }
                }
            }
        }
    }
}
