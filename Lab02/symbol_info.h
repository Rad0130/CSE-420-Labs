#include<bits/stdc++.h>
using namespace std;

class symbol_info
{
private:
    string name;
    string type;

    string symbol_kind; // Variable / Array / Function
    string data_type;   // int / float / void
    int array_size = -1;

    vector<pair<string,string>> parameters; // type,name

public:
    symbol_info(string name, string type)
    {
        this->name = name;
        this->type = type;
    }

    string get_name(){ return name; }
    string get_type(){ return type; }

    void set_name(string name){ this->name = name; }
    void set_type(string type){ this->type = type; }

    void set_symbol_kind(string k){ symbol_kind = k; }
    string get_symbol_kind(){ return symbol_kind; }

    void set_data_type(string t){ data_type = t; }
    string get_data_type(){ return data_type; }

    void set_array_size(int s){ array_size = s; }
    int get_array_size(){ return array_size; }

    void add_parameter(string type,string name)
    {
        parameters.push_back({type,name});
    }

    vector<pair<string,string>> get_parameters()
    {
        return parameters;
    }

    int get_parameter_count()
    {
        return parameters.size();
    }

    ~symbol_info(){}
};