#include "symbol_info.h"

class scope_table
{
private:
    int bucket_count;
    int unique_id;
    scope_table *parent_scope = NULL;
    vector<list<symbol_info *>> table;

    int hash_function(string name)
    {
        unsigned long hash = 0;
        for(char c: name)
            hash = (hash*31 + c) % bucket_count;
        return hash % bucket_count;
    }

public:

    scope_table(){}

    scope_table(int bucket_count, int unique_id, scope_table *parent_scope)
    {
        this->bucket_count = bucket_count;
        this->unique_id = unique_id;
        this->parent_scope = parent_scope;

        table.resize(bucket_count);
    }

    scope_table *get_parent_scope()
    {
        return parent_scope;
    }

    int get_unique_id()
    {
        return unique_id;
    }

    symbol_info *lookup_in_scope(symbol_info* symbol)
    {
        int idx = hash_function(symbol->get_name());

        for(auto s : table[idx])
        {
            if(s->get_name() == symbol->get_name())
                return s;
        }

        return NULL;
    }

    bool insert_in_scope(symbol_info* symbol)
    {
        int idx = hash_function(symbol->get_name());

        for(auto s : table[idx])
        {
            if(s->get_name() == symbol->get_name())
                return false;
        }

        table[idx].push_back(symbol);
        return true;
    }

    void print_scope_table(ofstream& outlog)
    {
        outlog<<"ScopeTable # "<<unique_id<<endl;

        for(int i=0;i<bucket_count;i++)
        {
            if(table[i].empty()) continue;

            outlog<<i<<" --> "<<endl;

            for(auto s : table[i])
            {
                outlog<<"< "<<s->get_name()<<" : "<<s->get_type()<<" >"<<endl;
            }
        }

        outlog<<endl;
    }

};