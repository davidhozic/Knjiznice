#include <stdint.h>
#include "../linked_list.hh"
#include <stdio.h>


class_LIST <unsigned int> list_1 = class_LIST <unsigned int>(); // Single list
class_LIST < class_LIST <int> > list_2 = class_LIST <class_LIST <int>> (); // 2D list

int main()
{

    /*            1D LINKED LIST              */
    for(uint8_t i = 0; i < 255; i++)
    {
        list_1.add_end(i+1);
        printf("%d\n", list_1[i]);
    }
    printf("Size: %d\n", list_1.length());

    /* Clears the list */
    list_1.clear(); 
    printf("Size: %d\n", list_1.length());

    /*            2D LINKED LIST              */
    for(uint8_t i = 0; i < 3; i++)
    {
        list_2.add_end( class_LIST<int>() );
        for(uint8_t j = 0; j < 5; j++)
        {
            list_2[i].add_end(j+1);
            printf("list2[%d][%d] == %d\n", i, j, list_2[i][j]);
        }
    }

    list_2.clear();

    return 0;
}


