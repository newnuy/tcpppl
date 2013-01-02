#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

enum Token_value {
    NAME,       NUMBER,      END,
    PLUS='+',   MINUS='-',   MUL='*',  DIV='/',
    PRINT=';',  ASSIGN='=',  LP='(',   RP=')'
};

Token_value curr_tok = PRINT;
double number_value;
string string_value;
map<string, double> table;
int no_of_errors;

struct function {
    vector<string> vari;
    string expre;
};

map<string, function> func;


istream *input;
bool second_istream = false;

double expr(bool get);
double term(bool get);
double prim(bool get);
Token_value get_token();
double error(const string &s);


int main(int argc, char *argv[])
{
    switch (argc) {
        case 1:
            input = &cin;
            break;
        case 2:
            input = new istringstream(argv[1]);
            break;
        default:
            error("too many arguments");
            return 1;
    }

    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;

    while (*input) {
        get_token();
        if (curr_tok == END)
            break;
        if (curr_tok == PRINT)
            continue;
        cout << expr(false) << endl;
    }

    if (input != &cin)
        delete input;
    return no_of_errors;
}


double expr(bool get)
{
    double left = term(get);

    for (; ;)
        switch (curr_tok) {
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -= term(true);
                break;
            default:
                return left;
        }
}


double term(bool get)
{
    double left = prim(get);

    for (; ;)
        switch (curr_tok) {
            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if (double d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
}


double prim(bool get)
{
    if (get)
        get_token();

    switch (curr_tok) {
        case NUMBER:
            {
                double v = number_value;
                get_token();
                return v;
            }
        case NAME:
            if (func.find(string_value) != func.end()) {
                string expand_expre = func[string_value].expre;
                for (vector<string>::iterator iter
                        = func[string_value].vari.begin();
                        iter != func[string_value].vari.end(); ++iter) {
                    string str_temp;
                    char c;
                    while (input->get(c) && !isalnum(c))
                        ;
                    str_temp.push_back(c);
                    while (input->get(c) && isalnum(c))
                        str_temp.push_back(c);
                    int position = expand_expre.find(*iter);
                    while (position != expand_expre.npos) {
                        expand_expre.replace(position, iter->size(), str_temp);
                        position = expand_expre.find(*iter);
                    }
                }
                istream *input_temp = input;
                input = new istringstream(expand_expre);
                second_istream = true;
                double e = expr(true);
                delete input;
                input = input_temp;
                second_istream = false;
                get_token();
                return e;
            }
            {
                double &v = table[string_value];
                if (get_token() == ASSIGN)
                    v = expr(true);
                return v;
            }
        case MINUS:
            return -prim(true);
        case LP:
            {
                double e = expr(true);
                if (curr_tok != RP)
                    return error(") expected");
                get_token();
                return e;
            }
        default:
            return error("primary expected");
    }
}


Token_value get_token()
{
    char ch;

    do {
        if (!input->get(ch))
            return curr_tok = END;
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
        case ';':
        case '\n':
            return curr_tok = PRINT;
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok = Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            input->putback(ch);
            *input >> number_value;
            return curr_tok = NUMBER;
        case '?':
            {
                string function_name;
                while (input->get(ch) && isalnum(ch))
                    function_name.push_back(ch);
                while (ch == '?') {
                    string temp;
                    while (input->get(ch) && isalnum(ch))
                        temp.push_back(ch);
                    func[function_name].vari.push_back(temp);
                }
                if (ch == ':') {
                    while (input->get(ch) && ch != ';' && ch != '\n')
                        func[function_name].expre.push_back(ch);
                }
                else
                    error("bad function");
            }
            if (*input)
                return get_token();
            else
                return curr_tok = END;
        default:
            if (isalpha(ch)) {
                string_value = ch;
                while (input->get(ch) && isalnum(ch))
                    string_value.push_back(ch);
                input->putback(ch);
                return curr_tok = NAME;
            }
            error("bad token");
            return curr_tok = PRINT;
    }
}


double error(const string &s)
{
    ++no_of_errors;
    cerr << "error: " << s << endl;
    return 1;
}
