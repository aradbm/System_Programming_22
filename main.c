#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    int a = 1;
    pnode *head = (pnode *)malloc(sizeof(pnode));
    char cmd_ch = 'b';
    while (scanf(" %c", &cmd_ch) == 1)
    {
        switch (cmd_ch)
        {
        case 'A':
            if (a)
            {
                build_graph_cmd(head);
                a = 0;
            }
            else
            {
                deleteGraph_cmd(head);
                build_graph_cmd(head);
            }
            break;
        case 'B':
            insert_node_cmd(head);
            break;
        case 'D':
            delete_node_cmd(head);
            break;
        case 'S':
            shortsPath_cmd(*head);
            break;
        case 'T':
            TSP_cmd(*head);
            break;
        case 'P':
            printGraph_cmd(*head);
            break;
        }
    }
    deleteGraph_cmd(head);
    free(head);
    return 0;
}
