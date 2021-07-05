
#include "linked_list.hpp"


/*A sample program demonstrating the use of the template in linked list, creating a 16D linked list*/

LIST_t <LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>>>>>>>t_list;


int main()
{
    while (1)
    {
        
        t_list.add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>>>>>>());
        t_list[0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>>>>>());
        t_list[0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>>>>());
        t_list[0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>>>());
        t_list[0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>>());
        t_list[0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>>());
        t_list[0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>>());
        t_list[0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>>());
        t_list[0][0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>>());
        t_list[0][0][0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>>());
        t_list[0][0][0][0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<LIST_t<int>>>>>());
        t_list[0][0][0][0][0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<LIST_t<int>>>>());
        t_list[0][0][0][0][0][0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<LIST_t<int>>>());
        t_list[0][0][0][0][0][0][0][0][0][0][0][0][0].add_end(LIST_t<LIST_t<int>>());
        t_list[0][0][0][0][0][0][0][0][0][0][0][0][0][0].add_end(LIST_t<int>());
        t_list[0][0][0][0][0][0][0][0][0][0][0][0][0][0][0].add_end(69);

        t_list.splice(0,t_list.length());       /* Memory leak proof */
    }
    return 0;
}