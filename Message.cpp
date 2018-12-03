#include <iostream>
#include "Message.h"


#ifndef MARMOSET_TESTING
int main();
#endif

// Class NODE
Node *Node :: get_next()
{
    return this -> p_next;
}
std :: string Node :: get_fragment()
{
    return this -> fragment;
}

// Constructor : Initialization of variables and assign them
Node :: Node (unsigned int id, std::string frag)
{
    this->identifier = id;
    this->fragment = frag;
    this->p_next = nullptr;
}

// Class MESSAGE
void Message :: insert(unsigned int id, std::string fragment)
{
    Node* n = new Node(id, fragment); // making node object and constructing it; id = num and str = fragment;
    
    if (head == nullptr)
    {
        head = n;
    }
    
    else
    {
        bool key = true;
        Node *previous_pointer = head;
        Node *search_pointer = head;
        if (n->identifier < head -> identifier)
        {
            n->p_next = head;
            head = n;
            key = false;
        }
        else
        {
            search_pointer = head -> p_next;
            while (key)
            {
                if (search_pointer == nullptr)
                {
                    previous_pointer -> p_next = n;
                    n->p_next = nullptr;
                    key = false;              // places it - so we break
                }
                
                else if ((previous_pointer->identifier < n->identifier) && (n->identifier < search_pointer->identifier))
                {
                    previous_pointer -> p_next = n;                   // places the new block
                    n->p_next = search_pointer;
                    key = false;
                }
                else
                {
                    search_pointer = search_pointer ->get_next();            // advcances the two pointers
                    previous_pointer = previous_pointer ->get_next();
                }

            }
        }
    }
    
}

void Message :: print_message()
{
    Node *search_pointer = head;
    Node *previous_pointer = head;
    std :: string final_print_string;
    if (search_pointer != nullptr)
    {
        for (int i=0; i< search_pointer->identifier; i++)
        {
            final_print_string += "... ";
        }
    }
    else
    {
        final_print_string += "???";
    }
    
    while (search_pointer != nullptr)
    {
        int diff = (search_pointer->identifier - previous_pointer ->identifier);
        for (int i=0; i < diff-1; i++)
        {
            final_print_string += "... ";
        }
        
        if (search_pointer -> get_fragment() != "EOT")
        {
            final_print_string += search_pointer->get_fragment() + " ";             //std :: cout << n -> get_fragment();
        }
        
        previous_pointer = search_pointer;
        search_pointer = search_pointer -> get_next();    // gets the pointer to the next node
    }
    if (previous_pointer != nullptr)
    {
        if (previous_pointer -> get_fragment() != "EOT")
        {
            final_print_string += "???";
        }
        else
        {
            final_print_string = final_print_string.substr(0, final_print_string.length() - 1);
        }
    }
    std :: cout << final_print_string << std :: endl;
}

// Constructor : Initialization of variables and assign them
Message :: Message ()
{
    head = nullptr;
}
// Destructor
Message :: ~Message()
{
    while (head != nullptr)
    {
        Node * temp = head;     // temp is making a copy of head and deleting it!
        head = temp -> p_next;
        delete temp;
    }
    
}

#ifndef MARMOSET_TESTING
int main ()
{
    //std :: cout << "abvad" << std :: endl;
    Message msg = Message(); // Constructing
    bool chk = true;
    while (chk)
    {
        int num=0;
        std :: cin >> num;
        
        switch (num)
        {
            case -1:
                msg.print_message();
                break;
            case -2:
                chk = false;
                return 0;
                break;
            default:
                if(num >= 0)
                {
                    std :: string str = "";
                    std :: cin >> str;
                    msg.insert((unsigned int)num, str); // This inserts the node obj to the linked list
                }
                break;
        }
    }
    return 0;
}
#endif
