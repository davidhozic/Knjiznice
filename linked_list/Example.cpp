
#include <string.h>
#include <stdlib.h>

#include "linked_list.hpp"




using namespace std;

struct PERSON_t
{
    char *name;
    uint32_t money;

    PERSON_t(const char *name, const uint32_t money)
    {
        this->name = (char *) malloc(strlen(name));
        strcpy(this->name, name);
        this->money = money;
    }
};


int compare (PERSON_t a , PERSON_t b)
{
    return strcmp(a.name, b.name);
}






LIST_t <PERSON_t> people;

int main()
{
    

        people = PERSON_t("Lucifer", 50)  +   people;
        people = PERSON_t("David", 5000)  +   people;
        people = PERSON_t("Britney", 100) +   people;
        people = PERSON_t("Amanda", 1232) +   people;
        people = PERSON_t("Teja", 10000)  +   people;
        people = people + PERSON_t("Johny", 100000);
    

    cout << "Before sort: "
         << endl;
    for (uint32_t i = 0, l = people.length(); i < l; i++)
        cout << people[i].name << endl;


    people.sort(compare);
    cout  << endl
          << "After sort:"
          << endl;

    for (uint32_t i = 0, l = people.length(); i < l; i++)
        cout << people[i].name << endl; 


    return 0;
}