#include <iostream>
#include <math.h>

using namespace std;

typedef long double l_float;
typedef unsigned long long ul_int;

l_float strToInt(string value) {
    bool minus = false;
    if (value[0] == '-') {
        value = value.substr(1);
        minus = true;
    }

    l_float r_val = 0;
    int _len = value.length();

    for (int i = 0; i < _len; i++) {
        r_val += (ul_int)(((ul_int)value[i] - 48) * (l_float)pow(10, (_len - i - 1)));
    }
    if (minus) {
        r_val *= -1;
    }
    return r_val;
}

string intToStr(l_float value) {
    bool minus = false;
    if (value < 0) {
        value *= -1;
        minus = true;
    }
    value = (ul_int)value;

    string r_val = ""; ul_int _b = 1;
    ul_int val_b = value / _b;

    while (val_b != 0) {
        r_val = (char)((val_b % 10) + 48) + r_val;
        _b *= 10;
        val_b = (ul_int)(value / _b);
    }
    if (minus) {
        r_val = '-' + r_val;
    }
    return r_val;
}

class str {
private:
    string my_str;
public:
};

class str_list {
private:
    string my_list[100];
    unsigned int list_len = 0;
public:
    int index(string value) {
        for (int i=0; i<list_len; i++)
            if (my_list[i] == value)
                return i;
        return -1;
    }
    unsigned int len() {
        return list_len;
    }
    bool isContains(string value) {
        int indx = index(value);
        if (indx != -1)
            return true;
        return false;
    }
    void extend(string values[], int val_len) {
        for (int i=0; i<val_len; i++)
            if (list_len < 100) {
                my_list[list_len] = values[i];
                list_len++;
            }
            else
                break;
    }
    void append(string value) {
        string values[] = {value};
        extend(values, 1);
    }
    void print_all() {
        int n = 0;
        for (int i=0; i<list_len; i++) {
            n++;
            cout << my_list[i] << ", ";
            if (n == 10) {
                cout << endl;
                n = 0;
            }
        }
    }
};

class str_dict {
private:
    string my_dict[100][2];
    unsigned int dict_len = 0;
    //////////////////////////////////
    int index(string key) {
        for (int i=0; i<dict_len; i++)
            if (my_dict[i][0] == key)
                return i;
        return -1;
    }
public:
    unsigned int len() {
        return dict_len;
    }
    bool isContains(string key) {
        int indx = index(key);
        if (indx != -1)
            return true;
        return false;
    }
    string get(string key, string default_val="None") {
        int indx = index(key);
        if (indx != -1)
            return my_dict[indx][1];
        return default_val;
    }
    void update(string key, string value) {
        int indx = index(key);
        if (indx != -1) {
            my_dict[indx][0] = key;
            my_dict[indx][1] = value;
        }
        else
            if (dict_len < 100) {
                my_dict[dict_len][0] = key;
                my_dict[dict_len][1] = value;
                dict_len++;
            }
    }
    string pop(string key, string default_val="None") {
        int indx = index(key);
        if (indx != -1) {
            string r_vl = my_dict[indx][1];
            for (int i=indx; i<(dict_len-1); i++) {
                my_dict[i][0] = my_dict[i+1][0];
                my_dict[i][1] = my_dict[i+1][1];
            }
            my_dict[dict_len-1][0] = "";
            my_dict[dict_len-1][1] = "";
            dict_len--;
            return r_vl;
        }
        return default_val;
    }
    void clear() {
        for (int i=0; i<dict_len; i++) {
            my_dict[i][0] = "";
            my_dict[i][1] = "";
        }
        dict_len = 0;
    }
    void print_all() {
        int n = 0;
        for (int i=0; i<dict_len; i++) {
            n++;
            cout << my_dict[i][0] << ": " << my_dict[i][1] << ", ";
            if (n == 10) {
                cout << endl;
                n = 0;
            }
        }
    }
};

int main() {
    // str_dict oby1;

    // oby1.update("isim", "Elyor");
    // oby1.update("familiya", "Tuxtamuratov");
    // oby1.update("yosh", "18");

    // oby1.print_all();
    // cout << endl << oby1.len() << endl << endl;

    // cout << oby1.pop("familiya") << endl << endl;

    // oby1.print_all();
    // cout << endl << oby1.len() << endl << endl;

    // cout << oby1.get("isim") << endl;

    // //////////////////////////////////////

    // str_list oby2;
    // oby2.append("Salom");
    // oby2.print_all();
    // cout << endl << oby2.len() << endl;

    // string arr[] = {"afcew", "svrsa", "afwefffffr"};
    // oby2.extend(arr, 3);
    // oby2.print_all();
    // cout << endl << oby2.len() << endl;

    // //////////////////////////////////////

    string a = "457"; int b = 457;
    cout << (strToInt(a) == b) << endl;
    cout << (intToStr(b) == a) << endl;

    return 0;
}
