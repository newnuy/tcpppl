#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void remove_comment(istream &input, ostream &output);

enum {
    NORMAL,
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    BLOCK_COMMENT,
    LINE_COMMENT
};


int main()
{
    remove_comment(cin, cout);

    return 0;
}


void remove_comment(istream &input, ostream &output)
{
    char status = NORMAL;
    char c;
    char next_char;
    bool have_code_line = false;
    bool have_comment_line = false;
    string str;

    while (input.get(c)) {
        bool is_output = false;
        switch (c) {
            case '\'':
                switch (status) {
                    case NORMAL:
                        status = SINGLE_QUOTE;
                        is_output = true;
                        break;
                    case SINGLE_QUOTE:
                        status = NORMAL;
                        is_output = true;
                        break;
                    case DOUBLE_QUOTE:
                        is_output = true;
                        break;
                    case BLOCK_COMMENT:
                    case LINE_COMMENT:
                        is_output = false;
                        break;
                    default:
                        is_output = false;
                        break;
                }
                break;

            case '"':
                switch (status) {
                    case NORMAL:
                        status = DOUBLE_QUOTE;
                        is_output = true;
                        break;
                    case SINGLE_QUOTE:
                        is_output = true;
                        break;
                    case DOUBLE_QUOTE:
                        status = NORMAL;
                        is_output = true;
                        break;
                    case BLOCK_COMMENT:
                    case LINE_COMMENT:
                        is_output = false;
                        break;
                    default:
                        is_output = false;
                        break;
                }
                break;

            case '\n':
                switch (status) {
                    case BLOCK_COMMENT:
                        break;
                    case LINE_COMMENT:
                        status = NORMAL;
                        break;
                    default:
                        break;
                }
                if (!have_code_line && have_comment_line)
                    is_output = false;
                else
                    is_output = true;
                break;

            case '/':
                switch (status) {
                    case NORMAL:
                        if (input.get(next_char)) {
                            switch (next_char) {
                                case '*':
                                    status = BLOCK_COMMENT;
                                    c = next_char;
                                    is_output = false;
                                    break;
                                case '/':
                                    status = LINE_COMMENT;
                                    c = next_char;
                                    is_output = false;
                                    break;
                                default:
                                    input.putback(next_char);
                                    is_output = true;
                                    break;
                            }
                        }
                        else {
                            is_output = true;
                        }
                        break;
                    case SINGLE_QUOTE:
                    case DOUBLE_QUOTE:
                        is_output = true;
                        break;
                    case BLOCK_COMMENT:
                    case LINE_COMMENT:
                        is_output = false;
                        break;
                    default:
                        is_output = false;
                        break;
                }
                break;

            case '*':
                switch (status) {
                    case NORMAL:
                    case SINGLE_QUOTE:
                    case DOUBLE_QUOTE:
                        is_output = true;
                        break;
                    case BLOCK_COMMENT:
                        if (input.get(next_char)) {
                            switch (next_char) {
                                case '/':
                                    status = NORMAL;
                                    c = next_char;
                                    is_output = false;
                                    break;
                                default:
                                    input.putback(next_char);
                                    is_output = false;
                                    break;
                            }
                        }
                        else {
                            is_output = false;
                        }
                        break;
                    case LINE_COMMENT:
                        is_output = false;
                        break;
                    default:
                        is_output = false;
                        break;
                }
                break;

            default:
                switch (status) {
                    case NORMAL:
                    case SINGLE_QUOTE:
                    case DOUBLE_QUOTE:
                        is_output = true;
                        break;
                    case BLOCK_COMMENT:
                    case LINE_COMMENT:
                        is_output = false;
                        break;
                    default:
                        is_output = false;
                        break;
                }
                break;
        }

        if (!is_output && c != '\n')
            have_comment_line = true;
        if (is_output) {
            if (!isspace(c))
                have_code_line = true;
            str.push_back(c);
        }
        if (c == '\n') {
            for (string::iterator iter = str.end()-1; iter != str.begin()-1;
                    --iter) {
                if (isspace(*iter) && *iter != '\n')
                    str.erase(iter);
                else
                    break;
            }
            output << str;
            str = "";
            have_code_line = false;
            have_comment_line = false;
        }
    }
}
