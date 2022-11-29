#include <iostream>
#include <string>
#include <vector>

enum CMD {
    ERR, R, pF, pB, D
};

class Command {
private:
    std::vector<CMD> vec;
    std::size_t d_cnt, r_cnt;
public:
    Command(std::string str) {
        str = this->erase_consecutive_R(str);
        std::cout << str << std::endl;
        //str = this->optimize_commands(str);
    }
private:
    std::string erase_consecutive_R(std::string &str) {
        std::string temp_r; // temporary R;
        std::string r_str;
        for (std::size_t i = 0; i < str.size(); ++i) {
            if (str[i] == 'D') {
                r_str += temp_r + str[i];
                temp_r.clear();
            } else {
                temp_r += str[i];
                if (temp_r.size() == 2) temp_r.clear();
            }
        }
        return r_str;
    }

    std::string optimize_commands(std::string &str) {
        std::string r_str;
        std::size_t h_ridx, t_ridx;  // head and tail of ridx
        h_ridx = str.find('R');
        while(h_ridx != std::string::npos) {
            t_ridx = str.substr(h_ridx).find('R');
            if (t_ridx != std::string::npos) {

            }
        }
        return "";
    }
};

class Array {
private:
    std::vector<int> vec;
public:
    Array(std::string str) {
        str.erase(str.find('['), 1); str.erase(str.find(']'), 1);
        std::size_t sidx = 0;
        auto cidx = str.find(',');
        while (cidx != std::string::npos) {
            this->vec.push_back(std::stoi(str.substr(sidx, cidx - sidx)));
            str = str.substr(cidx + 1);
            sidx = 0; cidx = str.find(',');
        }
        this->vec.push_back(std::stoi(str));
        return;
    }

    void print(void) const {
        std::cout << "[";
        for (std::size_t i = 0; i < this->vec.size(); ++i)
            std::cout << this->vec[i] << (i != this->vec.size() - 1 ? "," : "");
        std::cout << "]";
        return;
    }
};

class Handler {
private:
    Array *arr;
    Command *cmd;
public:
    Handler(Array *arr, Command *cmd): arr(arr), cmd(cmd) {}
    Handler &process(void) {
        return *this;
    }
    void printArray(void) const {
        this->arr->print();
        return;
    }
};


int main(void) {
    int T; std::cin >> T;
    for (std::size_t i = 0; i < T; ++i) {
        std::string cmd_str; std::cin >> cmd_str;
        std::size_t arr_size; std::cin >> arr_size; // Why Size..? 
        std::string arr_str; std::cin >> arr_str;
        Handler(new Array(arr_str), new Command(cmd_str)).process().printArray();
    }
    return 0;
}
