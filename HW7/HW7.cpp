
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Token
{
    Rock = 'r',
    Paper = 'p',
    Scissor = 's',
};

enum class Result
{
    Win,
    Lose,
    Drow,
};

Token ComputerResult() {
    const int GeneratingRange = 3;
    const int GeneratedNum = std::rand() % GeneratingRange + 1;
#ifdef _DEBUG
    std::cout << "*** RANDOM NUMBER *** // " << GeneratedNum << " // *** RANDOM NUMBER ***" << std::endl;
#endif // DEBUG
    switch (GeneratedNum)
    {
    case 1:
        std::cout << "Computer choice Rock" << std::endl;
        return Token::Rock;
    case 2:
        std::cout << "Computer choice Paper" << std::endl;
        return Token::Paper;
    case 3:
        std::cout << "Computer choice Scissor" << std::endl;
        return Token::Scissor;
    }
}

Result calculateResult(Token enteredKey, Token Computer) {
    if (enteredKey == Computer) {
        return Result::Drow;
    }
    else
    {
        if (enteredKey == Token::Rock) {
            if (Computer == Token::Paper) {
                return Result::Lose;
            }
            if (Computer == Token::Scissor) {
                return Result::Win;
            }
        }
        if (enteredKey == Token::Paper) {
            if (Computer == Token::Scissor) {
                return Result::Lose;
            }
            if (Computer == Token::Rock) {
                return Result::Win;
            }
        }
        if (enteredKey == Token::Scissor) {
            if (Computer == Token::Rock) {
                return Result::Lose;
            }
            if (Computer == Token::Paper) {
                return Result::Win;
            }
        }
    }
}


void message(Result r) {
    if (r == Result::Lose) {
        std::cout << "/--Computer Win--/" << std::endl;
    }
    else {
        if (r == Result::Win) {
            std::cout << "/++You Win++/" << std::endl;
        }
        else {
            std::cout << "/..Drow../" << std::endl;
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::srand((unsigned int)time(NULL));

    int wins, losses, draws;
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
                    Token key = static_cast<Token>(k);
                    switch (key)
                    {
                    case (Token::Rock):
                        std::cout << "You chose Rock" << std::endl;
                        break;
                    case (Token::Paper):
                        std::cout << "You chose Paper" << std::endl;
                        break;
                    case (Token::Scissor):
                        std::cout << "You chose Scissor" << std::endl;
                        break;
                    default:
                        std::cout << "You do not choose,  round lost" << std::endl;
                        std::cout << std::endl;
                        losses++;
                        continue;
                    }
                    Result r = calculateResult(key, ComputerResult());
                    message(r);
                    switch (r) {
                    case (Result::Lose):
                        losses++;
                        break;
                    case (Result::Win):
                        wins++;
                        break;
                    case (Result::Drow):
                        draws++;
                    }
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
