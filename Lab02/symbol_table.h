#include "scope_table.h"

class symbol_table
{
private:
    scope_table *current_scope;
    int bucket_count;
    int current_scope_id;

public:

    symbol_table(int bucket_count)
    {
        this->bucket_count = bucket_count;
        current_scope = NULL;
        current_scope_id = 0;
    }

    void enter_scope()
    {
        current_scope_id++;

        scope_table* new_scope =
            new scope_table(bucket_count,current_scope_id,current_scope);

        current_scope = new_scope;

        cout<<"New ScopeTable with ID "<<current_scope_id<<" created"<<endl;
    }

    void exit_scope()
    {
        if(current_scope==NULL) return;

        scope_table* temp=current_scope;
        current_scope=current_scope->get_parent_scope();

        delete temp;
    }

    bool insert(symbol_info* symbol)
    {
        if(current_scope==NULL) return false;

        return current_scope->insert_in_scope(symbol);
    }

    symbol_info* lookup(symbol_info* symbol)
    {
        scope_table* temp=current_scope;

        while(temp!=NULL)
        {
            symbol_info* res=temp->lookup_in_scope(symbol);

            if(res!=NULL) return res;

            temp=temp->get_parent_scope();
        }

        return NULL;
    }

    void print_current_scope(ofstream& outlog)
    {
        if(current_scope)
            current_scope->print_scope_table(outlog);
    }
};