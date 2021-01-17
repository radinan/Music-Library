#pragma once
//#include "AVLTree.h"
#include "Library.h"
#include <string>
#include <queue>
#include <sstream>
//:)))))))))))))
//change enum to enum class

class Command
{
private:
    std::string str_command; //think about white spaces

    enum Type { rating, genre, year }; //type
    Type type;
    enum Op { plus = '+', minus = '-', smaller = '<', bigger = '>', equals = '=', only = '!' }; //operator
    Op op;
    std::string opt; //option
private:
    void parse_command() //think about setters or making it private
    {
        //perfect case with valid input
        std::string one, two, three; //allowing further validation inside this func
        std::istringstream ss2(str_command);
        ss2 >> one;
        ss2 >> two;
        ss2.get(); //white space
        std::getline(ss2, three);

        if (one == "rating")
        {
            Command::type = Type::rating;
        }
        else if (one == "genre")
        {
            Command::type = Type::genre;
        }
        else if (one == "year")
        {
            Command::type = Type::year;
        }
        else
        {
            //throw
        }

        if (two == "+")
        {
            Command::op = Op::plus;
        }
        else if (two == "-")
        {
            Command::op = Op::minus;
        }
        else if (two == "<")
        {
            Command::op = Op::smaller;
        }
        else if (two == ">")
        {
            Command::op = Op::bigger;
        }
        else if (two == "=")
        {
            Command::op = Op::equals;
        }
        else if (two == "!")
        {
            Command::op = Op::only;
        }
        else
        {
            //throw
        }

        //validation?
        opt = three;
    }
public:
    Command(const std::string& _co)
        : str_command(_co)
    {
        parse_command();
    }
    //think about returning empty tree
    AVLTree& do_command(Library& lib, AVLTree& original)
    {
        switch (type) //depending on the type and operator calling diff funcs
        {
        case Type::rating:
            switch (op)
            {
            case Op::bigger: //rating > [opt]
            {
                Song::priority = Priority::rating;
                AVLTree prior; //empty tree for the func
                original.rating_bigger(stod(opt), prior); //stod converts string into double (covers white space)
                return original;
            }
            }
        case Type::genre:
            switch (op)
            {
            case Op::plus:
            {
                Song::priority = Priority::genre;
                AVLTree prior;
                original.genre_plus(opt, prior);
                return original;
            }
            case Op::minus:
            {
                Song::priority = Priority::genre;
                AVLTree prior;
                original.genre_minus(opt, prior);
                return original;
            }
            case Op::only:
            {
                Song::priority = Priority::genre;
                AVLTree prior;
                std::unordered_set<std::string> genres = lib.get_user().get_fav_genres();
                original.genres_fav(genres, prior);
                return original;
            }
            }
        case Type::year:
            switch (op)
            {
            case Op::equals:
            {
                Song::priority = Priority::release_year;
                if (stoi(opt) > 0)
                {
                    size_t x = stoi(opt);
                    AVLTree prior; //empty tree
                    original.year_equals(x, prior);
                    return original;
                }
                else break; //default?
            }
            case Op::bigger:
            {
                Song::priority = Priority::release_year;
                if (stoi(opt) > 0)
                {
                    size_t x = stoi(opt);
                    AVLTree prior;
                    original.year_bigger(x, prior);
                    return original;
                }
                else break;
            }
            case Op::smaller:
            {
                Song::priority = Priority::release_year;
                if (stoi(opt) > 0)
                {
                    size_t x = stoi(opt);
                    AVLTree prior;
                    original.year_smaller(x, prior);
                    return original;
                }
                else break;
            }
            }
        }
    }
};

class Statement
{
private:
    std::string str_statement;
    std::queue<Command> q_command; //all commands (separated by &&)
private:
    void parse_statement() //adds to queue
    {
        std::stringstream ss1(str_statement);
        while (std::getline(ss1, str_statement, '&')) //reads and splits: command & command...
        {
            std::string str = str_statement;
            while (str.back() == ' ')
            {
                str.pop_back();
            }
            while (str.front() == ' ')
            {
                str.erase(0, 1);
            }
            Command command(str); //removes spaces at the beginning and the end of the string
            q_command.push(command); //pushing it parsed
        }
    }
public:
    Statement() {}
    Statement(const std::string& _st)
        : str_statement(_st)
    {
        parse_statement();
    }
    ~Statement() {}
    AVLTree& do_statement(Library& lib, AVLTree& original) 
    {
        while (!q_command.empty()) //all elements
        {
            q_command.front().do_command(lib, original); //change the playlist tree
            if (original.is_empty()) //doesn't find matching songs
                break;
            q_command.pop(); //get next command
        }
        return original; //returns either empty or playlist tree
    }
};

class Expression //WHITE SPACES!!!!!
{
private:
    std::string str_expression; //user's input
    std::queue<Statement> q_statetement; //all statements (separated by |)
private:
    void parse_expression() //adds to queue
    {
        std::stringstream ss(str_expression);
        while (std::getline(ss, str_expression, '|')) //reads and splits: statement | statement...
        {
            std::string str1 = str_expression;
            while (str1.back() == ' ')
            {
                str1.pop_back();
            }
            while (str1.front() == ' ')
            {
                str1.erase(0, 1);
            }
            Statement statement(str1); //removing spaces at the beginning and end of the string
            q_statetement.push(statement); //pushing it parsed
        }
    }
public:
    Expression() {}
    Expression(const std::string& _input)
        : str_expression(_input)
    {
        parse_expression();
    }
    ~Expression() {}

    AVLTree& do_expression(Library& lib, AVLTree& main)
    {

        while (!q_statetement.empty()) //all elements
        {
            AVLTree original(main);
            q_statetement.front().do_statement(lib, original); //playlist tree
            if (original.is_empty()) //if no tree for the criteria => empty
                q_statetement.pop(); //check next statement
            else
            {
                main = original;
                return main; //return the playlist
            }
        }
        //return empty?
    }
};


