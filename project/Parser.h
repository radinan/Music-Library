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
    std::string co; //think about white spaces

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
        std::istringstream ss2(co);
        ss2 >> one;
        ss2 >> two;
        ss2.get(); //white space
        std::getline(ss2, three);

        //switch case not suitable for strings
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
            //wrong
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
            //wrong
        }

        //validation?
        opt = three;
    }
public:
    Command(const std::string& _co)
        : co(_co)
    {
        parse_command();
    }
    //think about returning empty tree
    AVLTree& do_command(Library& lib, AVLTree& original) //return type???
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
    std::string st;
    std::queue<Command> q_co; //all commands (separated by &&)
private:
    void parse_statement() //adds to queue
    {
        char delimeter('&');
        std::stringstream ss1(st);
        while (std::getline(ss1, st, delimeter)) //reads and splits: command && command...
        {
            Command co(st);
            q_co.push(co); //pushing it parsed
        }
    }
public:
    Statement() {}
    Statement(const std::string& _st)
        : st(_st)
    {
        parse_statement();
    }
    ~Statement() {}
    AVLTree& do_statement(Library& lib, AVLTree& original) //bool node* or tree&
    {
        while (!q_co.empty()) //all elements
        {
            q_co.front().do_command(lib, original); //change the playlist tree
            if (original.is_empty()) //doesn't find matching songs
                break;
            q_co.pop(); //get next command
        }
        return original; //returns either empty or playlist tree
    }
};

class Expression //WHITE SPACES!!!!!
{
private:
    std::string input; //user's input
    std::queue<Statement> q_st; //all statements (separated by ||)
private:
    void parse_expression() //adds to queue
    {
        char delimeter('|');
        std::stringstream ss(input);
        while (std::getline(ss, input, delimeter)) //reads and splits: statement || statement...
        {
            Statement st(input);
            q_st.push(st); //pushing it parsed
        }
    }
public:
    Expression() {}
    Expression(const std::string& _input)
        : input(_input)
    {
        parse_expression();
    }
    ~Expression() {}

    AVLTree& do_expression(Library& lib, AVLTree& main)
    {

        while (!q_st.empty()) //all elements
        {
            AVLTree original(main);
            q_st.front().do_statement(lib, original); //playlist tree
            if (original.is_empty()) //if no tree for the criteria => empty
                q_st.pop(); //check next statement
            else
            {
                main = original;
                return main; //return the playlist
            }
        }
        //return empty?
    }
};

