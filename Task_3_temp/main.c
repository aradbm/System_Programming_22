#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    // char cmd_ch;
    pnode *head = (pnode *)malloc(sizeof(pnode));
    build_graph_cmd(head);
    // while ((cmd_ch = getchar()) != EOF)
    // {
    //     switch (cmd_ch)
    //     {
    //     case 'A':
    //         // printf("A\n");
    //         deleteGraph_cmd(*head);
    //         build_graph_cmd(*head);
    //         break;
    //     case 'B':
    //         insert_node_cmd(*head);
    //         break;
    //     case 'D':
    //         delete_node_cmd(*head);
    //         break;
    //     case 'S':
    //         shortsPath_cmd(head);
    //         break;
    //     case 'T':
    //         TSP_cmd(head);
    //         break;
    //     }
    //     printGraph_cmd(head);
    //     cmd_ch = getchar();
    // }
    return 0;
}
